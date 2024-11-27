#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "readmedialog.h"
#include <QVBoxLayout>
#include <QScreen>
#include <QListView>
#include <QImageReader>
#include <QSplitter>
#include <QMouseEvent>
#include "customfiledialog.h"
#include <QSettings>
#include <QUrl>            // For QUrl operations
#include <QMenu>           // For QMenu context menu
#include <QAction>         // For QAction in the context menu
#include <QModelIndex>     // For QModelIndex manipulation
#include <QDebug>          // For qDebug debugging output


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), readmeDialog(new ReadmeDialog(this))
{
    ui->setupUi(this);

    // Set the initial placeholder or empty image in QLabel
    QPixmap placeholder(":images/placeholder.png");  // Path to a placeholder image (optional)
    ui->imagePreviewLabel->setPixmap(placeholder.scaled(175, 100, Qt::KeepAspectRatio));  // Set to QLabel with scaling

    // Connect the menu action for showing the readme
    connect(ui->actionShow_Readme, &QAction::triggered, this, &MainWindow::on_actionShow_Readme_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete readmeDialog;  // Clean up
}

// Slot to show the readme dialog
void MainWindow::on_actionShow_Readme_triggered()
{
    readmeDialog->show();  // Display the readme dialog
}

void MainWindow::savePlacesForProfileDialog(const QList<QUrl> &places)
{
    QSettings settings("SetBack", "ProfilePlaces");
    settings.beginGroup("Places");
    settings.remove("");  // Clear existing entries

    for (int i = 0; i < places.size(); ++i) {
        settings.setValue(QString::number(i), places[i].toString());
    }

    settings.endGroup();
}

QList<QUrl> MainWindow::loadPlacesForProfileDialog() const
{
    QSettings settings("SetBack", "ProfilePlaces");
    settings.beginGroup("Places");

    QList<QUrl> places;
    QStringList keys = settings.childKeys();
    for (const QString &key : keys) {
        places.append(QUrl(settings.value(key).toString()));
    }

    settings.endGroup();
    return places.isEmpty() ? QList<QUrl>{QUrl::fromLocalFile(QDir::homePath())} : places;  // Default to Home
}

void MainWindow::showPlacesContextMenu(QFileDialog *dialog, const QPoint &pos)
{
    QMenu contextMenu(this);

    // Get the current directory
    QString currentDir = dialog->directory().absolutePath();

    // Add "Save Current Directory" option
    QAction *saveAction = contextMenu.addAction("Save Current Directory");
    connect(saveAction, &QAction::triggered, this, [this, dialog, currentDir]() {
        QList<QUrl> places = dialog->sidebarUrls();
        QUrl newPlace = QUrl::fromLocalFile(currentDir);

        if (!places.contains(newPlace)) {
            places.append(newPlace);  // Add the new directory to Places
            savePlacesForProfileDialog(places);  // Save to settings
            dialog->setSidebarUrls(places);      // Update dialog
        }
    });

    // Add "Remove Place" option if clicked on a Place
    QAction *removeAction = contextMenu.addAction("Remove Place");
    connect(removeAction, &QAction::triggered, this, [this, dialog, pos]() {
        QList<QUrl> places = dialog->sidebarUrls();
        for (int i = 0; i < places.size(); ++i) {
            QRect rect = dialog->geometry();  // Placeholder for actual click detection
            if (rect.contains(pos)) {  // Simulate detecting a clicked Place
                QUrl placeToRemove = places.at(i);
                places.removeOne(placeToRemove);
                savePlacesForProfileDialog(places);
                dialog->setSidebarUrls(places);
                break;
            }
        }
    });

    contextMenu.exec(dialog->mapToGlobal(pos));
    qDebug() << "Context menu triggered at position:" << pos;
}

// Slot for selecting the Firefox profile directory
void MainWindow::on_selectProfileButton_clicked()
{
    QFileDialog dialog(this, tr("Select Firefox Profile Directory"));
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);  // Show directories only
    dialog.setFilter(QDir::AllDirs | QDir::NoDot | QDir::Hidden);

    dialog.resize(960, 540);

    // Add custom Places
    dialog.setSidebarUrls(loadPlacesForProfileDialog());

    // Adjust Sidebar Width
    QWidget *sidebar = dialog.findChild<QWidget *>("sidebar");
    if (sidebar) {
        sidebar->setMinimumWidth(200);  // Set minimum width to 175 pixels
        qDebug() << "Sidebar width adjusted.";
    }

    // Add context menu for sidebar and file list
    QListView *fileList = dialog.findChild<QListView *>();
    if (sidebar) {
        sidebar->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(sidebar, &QWidget::customContextMenuRequested, this, [&dialog, this](const QPoint &pos) {
            showPlacesContextMenu(&dialog, pos);
        });
    }
    if (fileList) {
        fileList->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(fileList, &QWidget::customContextMenuRequested, this, [&dialog, this](const QPoint &pos) {
            showPlacesContextMenu(&dialog, pos);
        });
    }

    // Save Places when dialog finishes
    connect(&dialog, &QDialog::finished, this, [&dialog, this]() {
        QList<QUrl> currentPlaces = dialog.sidebarUrls();
        savePlacesForProfileDialog(currentPlaces);
    });

    // Execute dialog and capture the selected directory
    if (dialog.exec() == QDialog::Accepted) {
        profilePath = dialog.selectedFiles().first();
        ui->profilePathLineEdit->setText(profilePath);  // Update the UI
    }
}


void MainWindow::on_selectImageButton_clicked()
{
    CustomFileDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        imagePath = dialog.getSelectedFilePath();  // Update the imagePath variable
        ui->imagePathLineEdit->setText(imagePath);  // Update the UI
        updateImagePreview(imagePath);  // Optional: Show the preview in the main window
        qDebug() << "Image selected:" << imagePath;
    } else {
        qDebug() << "No image selected.";
    }
}

// Slot for applying the changes
void MainWindow::on_applyChangesButton_clicked()
{
    qDebug() << "Applying changes...";
    qDebug() << "Profile path:" << profilePath;
    qDebug() << "Image path:" << imagePath;

    if (profilePath.isEmpty() || imagePath.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select both the profile directory and an image.");
        return;
    }

    createUserContentCss(profilePath, imagePath);
    ui->statusLabel->setText("Changes applied successfully! Restart Firefox.");
}

// Function to create the chrome directory, img folder, and userContent.css
void MainWindow::createUserContentCss(const QString &profilePath, const QString &imagePath)

{
    QString chromeDir = profilePath + "/chrome";
    QString imgDir = chromeDir + "/img";

    // Create the chrome and img directories if they don't exist
    QDir dir;
    if (!dir.exists(chromeDir)) {
        dir.mkpath(chromeDir);
    }
    if (!dir.exists(imgDir)) {
        dir.mkpath(imgDir);
    }

    // Copy the selected image to the img directory
    QString imageName = QFileInfo(imagePath).fileName();
    QString imageDestPath = imgDir + "/" + imageName;
    QFile::copy(imagePath, imageDestPath);

    // Path to userContent.css
    QString userContentCssPath = chromeDir + "/userContent.css";

    // CSS content that works with the image in the img folder
    QString cssContent = QString(
                             "@-moz-document url(about:home), url(about:newtab), url(about:privatebrowsing) {\n"
                             "    .click-target-container *, .top-sites-list * {\n"
                             "        color: #fff !important;\n"
                             "        text-shadow: 2px 2px 2px #222 !important;\n"
                             "    }\n"
                             "    body::before {\n"
                             "        content: \"\";\n"
                             "        z-index: -1;\n"
                             "        position: fixed;\n"
                             "        top: 0;\n"
                             "        left: 0;\n"
                             "        background: #f9a no-repeat url(img/%1) center;\n"
                             "        background-size: cover;\n"
                             "        width: 100vw;\n"
                             "        height: 100vh;\n"
                             "    }\n"
                             "}").arg(imageName);

    // Write the CSS content to the userContent.css file
    QFile file(userContentCssPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << cssContent;
        file.close();
    }
}
void MainWindow::updateImagePreview(const QString &imagePath)
{
    QPixmap selectedImage(imagePath);  // Load the selected image
    if (!selectedImage.isNull()) {
        // Scale the image to fit the QLabel size
        ui->imagePreviewLabel->setPixmap(selectedImage.scaled(175, 100, Qt::KeepAspectRatio));
    } else {
        // If the image is invalid, reset to the placeholder or clear the label
        ui->imagePreviewLabel->setText("Invalid Image");  // You can also show a placeholder image here
    }
}
