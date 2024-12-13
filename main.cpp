#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    // Set the plugin path explicitly
    QCoreApplication::addLibraryPath("/usr/lib/x86_64-linux-gnu/qt6/plugins");  // Adjust path if different

    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    return a.exec();
}
