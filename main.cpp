#include <QApplication>
#include <QIcon>  // Include QIcon for setting the window icon
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set the application icon from the resource file
    a.setWindowIcon(QIcon(":images/icon.png"));

    MainWindow w;
    w.show();
    return a.exec();
}
