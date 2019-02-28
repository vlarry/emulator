#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include <QMessageLogContext>
#include <QFileInfo>
//-----------------------------------------------------------------------------------
void logOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg)
{
    QString message;
    QString end_line = "\n";

#ifdef Q_OS_WIN
    end_line = "\r\n";
#endif

    switch (type)
    {
        case QtDebugMsg:
            message = QObject::tr("Отладка: %1 (%2:%3, %4).").arg(msg).arg(context.file).arg(context.line).
                                                              arg(context.function);
        break;

        case QtInfoMsg:
            message = QObject::tr("Сообщение: %1.").arg(msg);
        break;

        case QtWarningMsg:
            message = QObject::tr("Предупреждение: %1 (%2:%3, %4).").arg(msg).arg(context.file).
                                                                     arg(context.line).arg(context.function);
        break;

        case QtCriticalMsg:
            message = QObject::tr("Критическая ошибка: %1 (%2:%3, %4).").arg(msg).arg(context.file).
                                                                         arg(context.line).arg(context.function);
        break;

        case QtFatalMsg:
            message = QObject::tr("Фатальная ошибка: %1 (%2:%3, %4).").arg(msg).arg(context.file).
                                                                       arg(context.line).arg(context.function);
        break;
    }

    QDir dir;

    if(!message.isEmpty())
    {
        QFile file("log.txt");

        if(!file.open(QFile::WriteOnly | QFile::Append))
        {
            qDebug() << QObject::tr("Невозможно открыть файл логирования для записи");
            file.close();

            return;
        }

        QTextStream out(&file);

        QString dt = QDateTime::currentDateTime().toString("[dd.mm.yyyy - HH:mm:ss.zzz]");

        out <<  QString("%1 -> %2").arg(dt).arg(message) << end_line;

        file.close();
    }
}
//------------------------------
int main(int argc, char* argv[])
{
    QCoreApplication::setOrganizationName("РПА");
    QCoreApplication::setApplicationName("FS9Emulator");

    QFileInfo fileInfo("log.txt");

    if(fileInfo.exists() && fileInfo.isFile())
    {
        QFile file("log.txt");
        file.remove("log.txt");
    }

    qInstallMessageHandler(logOutput);

    QApplication a(argc, argv);

    QTranslator qtTranslator;
    bool isTranslation = qtTranslator.load(":/translations/russian",QLibraryInfo::location(QLibraryInfo::TranslationsPath));

    if(!isTranslation)
        qWarning() << QObject::tr("Не удалось подключить файл перевода \"qt_ru.qm\"");

    a.installTranslator(&qtTranslator);

    MainWindow w;
    w.show();

    return a.exec();
}
