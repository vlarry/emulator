#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
//------------------------------
int main(int argc, char* argv[])
{
    QCoreApplication::setOrganizationName("РПА");
    QCoreApplication::setApplicationName("FS9Emulator");

    QApplication a(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("qt_ru",QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    MainWindow w;
    w.show();

    return a.exec();
}
