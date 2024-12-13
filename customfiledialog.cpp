#include "customfiledialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QMessageBox>
#include <QHeaderView>

CustomFileDialog::CustomFileDialog(QWidget *parent)
    : QDialog(parent),
    fileModel(new QFileSystemModel(this)),
    fileTreeView(new QTreeView(this)),
    imagePreviewLabel(new QLabel(this)),
    filePathLineEdit(new QLineEdit(this)),
    openButton(new QPushButton("Open", this))
{
    setupUI();
    setupConnections();
}

void CustomFileDialog::setupUI()
{
    // Configure the file model
    fileModel->setRootPath(QDir::homePath());
    fileModel->setFilter(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);

    // Configure the proxy model
    proxyModel = new ImageFilterProxyModel(this);
    proxyModel->setSourceModel(fileModel);

    // Configure the tree view
    fileTreeView->setModel(proxyModel);
    fileTreeView->setRootIndex(proxyModel->mapFromSource(fileModel->index(QDir::homePath())));

    // Configure the image preview label
    imagePreviewLabel->setFixedSize(300, 300);
    imagePreviewLabel->setAlignment(Qt::AlignCenter);
    imagePreviewLabel->setStyleSheet("border: 1px solid blue;");

    // Layout setup
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(fileTreeView, 1);
    topLayout->addWidget(imagePreviewLabel);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(filePathLineEdit, 1);
    bottomLayout->addWidget(openButton);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);

    setWindowTitle("Select Image");
    resize(1100, 640);

    // Configure auto-resizing of columns in the file tree view
    QHeaderView *header = fileTreeView->header();
    header->setSectionResizeMode(0, QHeaderView::Stretch);  // Auto-resize the first column (name)
    header->setSectionResizeMode(1, QHeaderView::ResizeToContents);  // Size other columns to their contents
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents);  // Example for another column

    // Optional: Set a minimum width for the name column
    header->resizeSection(0, 300);

    // Configure the file model
    fileModel->setRootPath(QDir::homePath());
    fileModel->setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);  // Do not show hidden files
    fileModel->setNameFilterDisables(false);

    // Set up the file tree view
    fileTreeView->setModel(proxyModel);
    fileTreeView->setRootIndex(proxyModel->mapFromSource(fileModel->index(QDir::homePath())));

}

void CustomFileDialog::setupConnections()
{
    // Single click: Preview image
    connect(fileTreeView, &QTreeView::clicked, this, &CustomFileDialog::onFileClicked);

    // Double click: Select image and close
    connect(fileTreeView, &QTreeView::doubleClicked, this, &CustomFileDialog::onFileDoubleClicked);

    // Open button: Confirm selection
    connect(openButton, &QPushButton::clicked, this, [this]() {
        QModelIndex currentIndex = fileTreeView->currentIndex();

        // Map the index to the source model
        QModelIndex sourceIndex = proxyModel->mapToSource(currentIndex);
        if (!sourceIndex.isValid()) {
            qDebug() << "Invalid index when 'Open' button clicked!";
            return;
        }

        // Update the selected file path
        selectedFilePath = fileModel->filePath(sourceIndex);
        qDebug() << "Image selected:" << selectedFilePath;

        accept();  // Close the dialog with an accepted state
    });

    // Connect to selection changes in the file tree view
    QItemSelectionModel *selectionModel = fileTreeView->selectionModel();
    connect(selectionModel, &QItemSelectionModel::currentChanged, this, [this](const QModelIndex &current, const QModelIndex &) {
    QModelIndex sourceIndex = proxyModel->mapToSource(current);
    if (sourceIndex.isValid()) {
        QString filePath = fileModel->filePath(sourceIndex);
        QPixmap pixmap(filePath);
        if (!pixmap.isNull()) {
            imagePreviewLabel->setPixmap(pixmap.scaled(imagePreviewLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        } else {
            imagePreviewLabel->clear();
            imagePreviewLabel->setText("No Preview Available");
        }
    }
});
}

void CustomFileDialog::onFileClicked(const QModelIndex &index)
{
    // Map the proxy index to the source index
    QModelIndex sourceIndex = proxyModel->mapToSource(index);
    QString filePath = fileModel->filePath(sourceIndex);  // Get the correct file path

    QPixmap pixmap(filePath);
    if (!pixmap.isNull()) {
        imagePreviewLabel->setPixmap(pixmap.scaled(imagePreviewLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        filePathLineEdit->setText(filePath);  // Update the line edit
    } else {
        imagePreviewLabel->setText("No Preview Available");
    }
}


void CustomFileDialog::onFileDoubleClicked(const QModelIndex &index)
{
    // Map the proxy index to the source index
    QModelIndex sourceIndex = proxyModel->mapToSource(index);

    // Ensure the source index is valid before proceeding
    if (!sourceIndex.isValid()) {
        qDebug() << "Invalid source index on double-click!";
        return;
    }

    // Retrieve the file path from the source model
    selectedFilePath = fileModel->filePath(sourceIndex);

    // Update the line edit with the selected file path
    filePathLineEdit->setText(selectedFilePath);

    // Close the dialog with an accepted state
    accept();
}

QString CustomFileDialog::getSelectedFilePath() const
{
        return QDir::toNativeSeparators(selectedFilePath); // Ensures compatibility with OS paths
}
void CustomFileDialog::showPreviousImage()
{
    QModelIndex currentIndex = fileTreeView->currentIndex();  // Get the current selection
    if (!currentIndex.isValid()) {
        return;  // No valid selection
    }

    // Move to the previous row in the same directory
    QModelIndex prevIndex = fileModel->index(currentIndex.row() - 1, 0, currentIndex.parent());
    if (prevIndex.isValid()) {
        fileTreeView->setCurrentIndex(prevIndex);  // Highlight the previous file
        onFileClicked(prevIndex);                 // Update the preview
    } else {
        imagePreviewLabel->setText("No previous image available.");
    }
}

void CustomFileDialog::showNextImage()
{
    QModelIndex currentIndex = fileTreeView->currentIndex();  // Get the current selection
    if (!currentIndex.isValid()) {
        return;  // No valid selection
    }

    // Move to the next row in the same directory
    QModelIndex nextIndex = fileModel->index(currentIndex.row() + 1, 0, currentIndex.parent());
    if (nextIndex.isValid()) {
        fileTreeView->setCurrentIndex(nextIndex);  // Highlight the next file
        onFileClicked(nextIndex);                 // Update the preview
    } else {
        imagePreviewLabel->setText("No next image available.");
    }
}
