#include "mainwindow.h"

#include <QApplication>
//#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}

/*
 * error i get when switching tabs, pointer being freed was not allocated
 * i may have fixed it though
 *
 *
 *
 *
 */
