/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSettings;
    QAction *actionProfile;
    QAction *actionHelp;
    QAction *actionNotifications;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *timeLabel;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QVBoxLayout *checkBoxLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *sussyBaka;
    QMenuBar *menubar;
    QMenu *mainMenu;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(314, 417);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName("actionSettings");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon);
        actionSettings->setIconVisibleInMenu(true);
        actionSettings->setShortcutVisibleInContextMenu(true);
        actionProfile = new QAction(MainWindow);
        actionProfile->setObjectName("actionProfile");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/download.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        actionProfile->setIcon(icon1);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName("actionHelp");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/img/download (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon2);
        actionNotifications = new QAction(MainWindow);
        actionNotifications->setObjectName("actionNotifications");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/img/download (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNotifications->setIcon(icon3);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        horizontalLayout_2->addWidget(label_5);

        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");

        horizontalLayout_2->addWidget(timeLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        checkBoxLayout = new QVBoxLayout();
        checkBoxLayout->setObjectName("checkBoxLayout");

        horizontalLayout->addLayout(checkBoxLayout);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_3);

        sussyBaka = new QPushButton(centralwidget);
        sussyBaka->setObjectName("sussyBaka");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sussyBaka->sizePolicy().hasHeightForWidth());
        sussyBaka->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(sussyBaka);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 314, 36));
        mainMenu = new QMenu(menubar);
        mainMenu->setObjectName("mainMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(mainMenu->menuAction());
        mainMenu->addAction(actionSettings);
        mainMenu->addAction(actionProfile);
        mainMenu->addAction(actionHelp);
        mainMenu->addAction(actionNotifications);
        toolBar->addAction(actionSettings);
        toolBar->addAction(actionProfile);
        toolBar->addAction(actionHelp);
        toolBar->addAction(actionNotifications);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionProfile->setText(QCoreApplication::translate("MainWindow", "Profile", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionNotifications->setText(QCoreApplication::translate("MainWindow", "Notifications", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Time:", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Your prescriptions", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Next refill...", nullptr));
        label_4->setText(QString());
        sussyBaka->setText(QCoreApplication::translate("MainWindow", "Manage your prescriptions", nullptr));
        mainMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
