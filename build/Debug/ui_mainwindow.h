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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        QPalette palette;
        QBrush brush(QColor(197, 197, 197, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(93, 93, 93, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(61, 103, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Link, brush3);
        QBrush brush4(QColor(197, 197, 197, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush3);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8("images/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(197, 197, 197);\n"
"\n"
"QPushButton { border-radius: 8px; background-color: #007BFF; \n"
" color: white; padding: 10px; } QPushButton:hover { background-color: #0056b3; }"));
        actionShow_Readme = new QAction(MainWindow);
        actionShow_Readme->setObjectName("actionShow_Readme");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        selectProfileButton = new QPushButton(centralwidget);
        selectProfileButton->setObjectName("selectProfileButton");
        selectProfileButton->setGeometry(QRect(50, 100, 120, 30));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush5(QColor(7, 0, 88, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush6(QColor(12, 12, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush7(QColor(0, 0, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        QBrush brush8(QColor(24, 28, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush8);
        QBrush brush9(QColor(34, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush7);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        selectProfileButton->setPalette(palette1);
        selectProfileButton->setMouseTracking(true);
        selectProfileButton->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        selectProfileButton->setAutoFillBackground(false);
        selectProfileButton->setStyleSheet(QString::fromUtf8("QPushButton { border-radius: 6px; background-color: rgb(7, 0, 88); color: white; padding: 5px; } QPushButton:hover { background-color: rgb(64, 0, 255); transition: all 0.2s ease; }\n"
"\n"
"QPushButton:pressed { background-color: #000051;\n"
"transform: scale(0.95); }"));
        selectProfileButton->setAutoDefault(false);
        selectProfileButton->setFlat(false);
        selectImageButton = new QPushButton(centralwidget);
        selectImageButton->setObjectName("selectImageButton");
        selectImageButton->setGeometry(QRect(50, 140, 120, 30));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush5);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        selectImageButton->setPalette(palette2);
        selectImageButton->setAcceptDrops(true);
        selectImageButton->setStyleSheet(QString::fromUtf8("QPushButton { border-radius: 6px; background-color: rgb(7, 0, 88); color: white; padding: 5px; } QPushButton:hover { background-color: rgb(64, 0, 255); transition: all 0.2s ease; }\n"
"\n"
"QPushButton:pressed { background-color: rgb(52, 0, 0);; \n"
"transform: scale(0.95); }\n"
"\n"
""));
        selectImageButton->setFlat(false);
        applyChangesButton = new QPushButton(centralwidget);
        applyChangesButton->setObjectName("applyChangesButton");
        applyChangesButton->setGeometry(QRect(50, 180, 120, 30));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush10(QColor(1, 251, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        applyChangesButton->setPalette(palette3);
        applyChangesButton->setStyleSheet(QString::fromUtf8("QPushButton { border-radius: 6px; background-color: rgb(7, 0, 88); color: white; padding: 5px; } QPushButton:hover { background-color: rgb(64, 0, 255); transition: all 0.2s ease; }\n"
"\n"
"QPushButton:pressed { background-color: rgb(52, 0, 0);; \n"
"transform: scale(0.95); }"));
        profilePathLineEdit = new QLineEdit(centralwidget);
        profilePathLineEdit->setObjectName("profilePathLineEdit");
        profilePathLineEdit->setGeometry(QRect(180, 100, 360, 30));
        profilePathLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(199, 199, 199);\n"
"selection-background-color: rgb(21, 0, 255);"));
        imagePathLineEdit = new QLineEdit(centralwidget);
        imagePathLineEdit->setObjectName("imagePathLineEdit");
        imagePathLineEdit->setGeometry(QRect(180, 140, 360, 30));
        imagePathLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(199, 199, 199);\n"
"selection-background-color: rgb(21, 0, 255);"));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(180, 185, 360, 22));
        statusLabel->setStyleSheet(QString::fromUtf8("color: rgb(199, 199, 199);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 5, 136, 41));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(125, 50, 351, 22));
        label_2->setFrameShape(QFrame::Shape::NoFrame);
        imagePreviewLabel = new QLabel(centralwidget);
        imagePreviewLabel->setObjectName("imagePreviewLabel");
        imagePreviewLabel->setGeometry(QRect(215, 220, 175, 100));
        imagePreviewLabel->setMaximumSize(QSize(175, 100));
        imagePreviewLabel->setPixmap(QPixmap(QString::fromUtf8("images/placeholder.png")));
        imagePreviewLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        websiteLabel = new QLabel(centralwidget);
        websiteLabel->setObjectName("websiteLabel");
        websiteLabel->setGeometry(QRect(230, 335, 140, 35));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush11(QColor(255, 255, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Link, brush11);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Link, brush11);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Link, brush11);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        websiteLabel->setPalette(palette4);
        websiteLabel->setAutoFillBackground(false);
        websiteLabel->setStyleSheet(QString::fromUtf8("font: 12pt \"Noto Sans\";\n"
""));
        websiteLabel->setTextFormat(Qt::TextFormat::RichText);
        websiteLabel->setScaledContents(false);
        websiteLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        websiteLabel->setOpenExternalLinks(true);
        websiteLabel->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByKeyboard|Qt::TextInteractionFlag::LinksAccessibleByMouse|Qt::TextInteractionFlag::TextBrowserInteraction|Qt::TextInteractionFlag::TextSelectableByKeyboard|Qt::TextInteractionFlag::TextSelectableByMouse);
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

        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionShow_Readme);

        retranslateUi(MainWindow);

        selectProfileButton->setDefault(false);


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
        websiteLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><a href=\"https://www.beeralator.com\"><span style=\" text-decoration: underline; color:#0000ff;\">Beeralator.com</span></a></p></body></html>", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
