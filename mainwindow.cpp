#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "readmedialog.h"

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
// Slot for selecting the Firefox profile directory
void MainWindow::on_selectProfileButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select Firefox Profile Directory"),
                                                    "/home/tom/snap/firefox/common/.mozilla/firefox",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        profilePath = dir;
        ui->profilePathLineEdit->setText(profilePath); // Display the selected path in the UI
    }
}

// Slot for selecting the image
void MainWindow::on_selectImageButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Select Image"), "",
                                                tr("Images (*.jpg *.jpeg *.png *.gif)"));
    if (!file.isEmpty()) {
        imagePath = file;
        ui->imagePathLineEdit->setText(imagePath); // Display the selected image path in the UI
        updateImagePreview(imagePath);  // Update the image preview
    }
}

// Slot for applying the changes
void MainWindow::on_applyChangesButton_clicked()
{
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
