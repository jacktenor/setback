#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLabel>  // This fixes the QLabel error by including the necessary header
#include "qfiledialog.h"
#include "readmedialog.h"  // Include the header for the readme dialog

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionShow_Readme_triggered();  // Add the underscore to match the new name
    void on_selectProfileButton_clicked(); // Slot for selecting the Firefox profile directory
    void on_selectImageButton_clicked();   // Slot for selecting the background image
    void on_applyChangesButton_clicked();  // Slot for applying the changes (writing the CSS)

private:
    Ui::MainWindow *ui;             // Pointer to the UI
    ReadmeDialog *readmeDialog;     // Pointer to the readme dialog
    QString profilePath;            // Holds the selected profile path
    QString imagePath;              // Holds the selected image path
    void createUserContentCss(const QString &profilePath, const QString &imagePath, int topSitesRows);
    void updateImagePreview(const QString &imagePath);  // Method to update the QLabel with the selected image
    void savePlacesForProfileDialog(const QList<QUrl> &places);
    QList<QUrl> loadPlacesForProfileDialog() const;
    void showPlacesContextMenu(QFileDialog *dialog, const QPoint &pos);
    void setTopSitesRowsPreference(int topSitesRows); // Add this declaration
};

#endif // MAINWINDOW_H
