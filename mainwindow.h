#ifndef MAINWINDOW_H
    #define MAINWINDOW_H
    //--------------------
    #include <QMainWindow>
    #include <QDebug>
    #include <QSerialPort>
    #include <QSerialPortInfo>
    #include <QMessageBox>
    #include <QSettings>
    #include "qswitch.h"
    #include "qlamp.h"
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
            QSerialPort*        m_port;
            QLabel*             m_lblMessage;
            QSettings*          m_settings;
            QVector<QByteArray> m_query;
            quint8              m_count;

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
    };
#endif // MAINWINDOW_H
