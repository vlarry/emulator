#include "mainwindow.h"
#include <QApplication>
//------------------------------
int main(int argc, char* argv[])
{
    QCoreApplication::setOrganizationName("РПА");
    QCoreApplication::setApplicationName("FS9 emulator");

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
