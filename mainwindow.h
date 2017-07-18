#ifndef MAINWINDOW_H
    #define MAINWINDOW_H
    //--------------------
    #include <QMainWindow>
    #include <QDebug>
    #include <QSerialPort>
    #include <QSerialPortInfo>
    #include <QMessageBox>
    #include <QSettings>
    #include "qcmd.h"
    #include "ciodevice.h"
    //----------
    namespace Ui
    {
        class MainWindow;
    }
    //----------------------------------
    class MainWindow: public QMainWindow
    {
        Q_OBJECT

        public:
            explicit MainWindow(QWidget* parent = Q_NULLPTR);
            ~MainWindow();

        private:
            Ui::MainWindow*     ui;
            QSerialPort*        m_port; // COM-порт
            QLabel*             m_lblMessage; // вывод сообщений в статус бар
            QSettings*          m_settings; // настройки
            QVector<QByteArray> m_query; // массив байт запроса
            QVector<QByteArray> m_responce; // массив байт ответа устройства
            quint8              m_query_count; // количество отправленных байт
            QString             m_cmd_last; // последняя отправленная команда

        private:
            void initConnect();
            void initSerialPort();
            void showMessage(const QString& message);

        public slots:
            void refreshSerialPort();
            void ctrlSerialPort(bool state);
            void readData();
            void writeData();
            void BytesWriten(qint64 byte);
            void cmdDescription(const QString& description);
    };
#endif // MAINWINDOW_H
