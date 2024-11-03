/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionShow_Readme;
    QWidget *centralwidget;
    QPushButton *selectProfileButton;
    QPushButton *selectImageButton;
    QPushButton *applyChangesButton;
    QLineEdit *profilePathLineEdit;
    QLineEdit *imagePathLineEdit;
    QLabel *statusLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *imagePreviewLabel;
    QLabel *websiteLabel;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        MainWindow->setMaximumSize(QSize(600, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(197, 197, 197);"));
        actionShow_Readme = new QAction(MainWindow);
        actionShow_Readme->setObjectName("actionShow_Readme");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        selectProfileButton = new QPushButton(centralwidget);
        selectProfileButton->setObjectName("selectProfileButton");
        selectProfileButton->setGeometry(QRect(50, 100, 121, 30));
        selectProfileButton->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 5, 35);"));
        selectImageButton = new QPushButton(centralwidget);
        selectImageButton->setObjectName("selectImageButton");
        selectImageButton->setGeometry(QRect(50, 140, 121, 30));
        selectImageButton->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 5, 35);"));
        applyChangesButton = new QPushButton(centralwidget);
        applyChangesButton->setObjectName("applyChangesButton");
        applyChangesButton->setGeometry(QRect(50, 180, 121, 30));
        applyChangesButton->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(0, 0, 0);\n"
"background-color: rgb(0, 5, 35);"));
        profilePathLineEdit = new QLineEdit(centralwidget);
        profilePathLineEdit->setObjectName("profilePathLineEdit");
        profilePathLineEdit->setGeometry(QRect(180, 100, 361, 30));
        profilePathLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(1, 10, 61);\n"
"background-color: rgb(199, 199, 199);"));
        imagePathLineEdit = new QLineEdit(centralwidget);
        imagePathLineEdit->setObjectName("imagePathLineEdit");
        imagePathLineEdit->setGeometry(QRect(180, 140, 361, 30));
        imagePathLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(1, 10, 61);\n"
"background-color: rgb(199, 199, 199);"));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(180, 190, 361, 22));
        statusLabel->setStyleSheet(QString::fromUtf8("color: rgb(199, 199, 199);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 0, 141, 41));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 40, 351, 22));
        imagePreviewLabel = new QLabel(centralwidget);
        imagePreviewLabel->setObjectName("imagePreviewLabel");
        imagePreviewLabel->setGeometry(QRect(210, 220, 175, 100));
        imagePreviewLabel->setMaximumSize(QSize(175, 100));
        imagePreviewLabel->setPixmap(QPixmap(QString::fromUtf8("images/placeholder.png")));
        websiteLabel = new QLabel(centralwidget);
        websiteLabel->setObjectName("websiteLabel");
        websiteLabel->setGeometry(QRect(220, 311, 161, 51));
        websiteLabel->setTextFormat(Qt::TextFormat::RichText);
        websiteLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        websiteLabel->setOpenExternalLinks(true);
        MainWindow->setCentralWidget(centralwidget);
        selectImageButton->raise();
        applyChangesButton->raise();
        profilePathLineEdit->raise();
        imagePathLineEdit->raise();
        statusLabel->raise();
        label->raise();
        label_2->raise();
        imagePreviewLabel->raise();
        selectProfileButton->raise();
        websiteLabel->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 27));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionShow_Readme);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SetBack", nullptr));
        actionShow_Readme->setText(QCoreApplication::translate("MainWindow", "Show Readme", nullptr));
        selectProfileButton->setText(QCoreApplication::translate("MainWindow", "Select Profile", nullptr));
        selectImageButton->setText(QCoreApplication::translate("MainWindow", "Select Image", nullptr));
        applyChangesButton->setText(QCoreApplication::translate("MainWindow", "Apply Changes", nullptr));
        statusLabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "SetBack", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Set Background Image of Firefox's Homepage", nullptr));
        imagePreviewLabel->setText(QString());
        websiteLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><a href=\"https://www.beeralator.com\"><span style=\" text-decoration: underline; color:#007af4;\">Visit Beeralator.com</span></a></p></body></html>", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
