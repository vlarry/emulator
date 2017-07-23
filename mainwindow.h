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
    //-----------
    typedef union
    {
        quint8 byte[sizeof(float)];
        float  number;
    } Float_t;
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
            quint8              m_query_count; // количество отправленных байт
            QByteArray          m_responce; // массив байт ответа устройства
            QString             m_cmd_last; // последняя отправленная команда
            QVector<CIODevice*> m_input_dev;
            QVector<CIODevice*> m_output_dev;
            QVector<QLineEdit*> m_ain_dev;

        private:
            void   initConnect();
            void   initSerialPort();
            void   initIO();
            void   setIO(const QVector<CIODevice*>& io_dev, bool type);
            void   showMessage(const QString& message);
            quint8 getChecksum(const QByteArray& ba, const quint8 size);
            void   cmdParser(const QByteArray& data, const quint8 size);
            void   setChannel(CIODevice *io, quint8 ch_state);
            void   loadSettings();
            void   saveSettings();
            void   closeEvent(QCloseEvent* evt);
            void   keyPressEvent(QKeyEvent* evt);

        public slots:
            void refreshSerialPort();
            void ctrlSerialPort(bool state);
            void readData();
            void writeData();
            void BytesWriten(qint64 byte);
            void cmdDescription(const QString& description);
            void addrChanged(int addr);
            void outputStateChanged(quint8 id, bool state);
            void initFilter();
    };
    //--------------
    #define EMULATOR // для эмуляции на PC (Rx замкнут на Tx)
#endif // MAINWINDOW_H
