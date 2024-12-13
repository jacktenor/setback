#ifndef CUSTOMFILEDIALOG_H
#define CUSTOMFILEDIALOG_H
#include <QDialog>
#include <QFileSystemModel>
#include <QTreeView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "imagefilterproxymodel.h"

class CustomFileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomFileDialog(QWidget *parent = nullptr);
    QString getSelectedFilePath() const;

private slots:
    void onFileClicked(const QModelIndex &index);
    void onFileDoubleClicked(const QModelIndex &index);
    void showPreviousImage();
    void showNextImage();
    void setupUI();                 // Sets up the dialog's layout
    void setupConnections();        // Sets up the signal-slot connections

private:
    ImageFilterProxyModel *proxyModel;
    QFileSystemModel *fileModel;    // File system model for traversal
    QTreeView *fileTreeView;        // Widget to display the file system
    QLabel *imagePreviewLabel;      // Widget to show image previews
    QLineEdit *filePathLineEdit;    // To display the selected file path
    QPushButton *openButton;        // Button to confirm file selection
    QString selectedFilePath;       // Holds the path of the selected file


};

#endif // CUSTOMFILEDIALOG_H
