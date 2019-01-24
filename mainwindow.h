#ifndef MAINWINDOW_H
    #define MAINWINDOW_H
    //--------------------
    #include <QMainWindow>
    #include <QDebug>
    #include <QSerialPort>
    #include <QSerialPortInfo>
    #include <QMessageBox>
    #include <QSettings>
    #include <QTimer>
    #include <QFile>
    #include <QDate>
    #include <QTextStream>
    #include <QDir>
    #include <QShowEvent>
    #include <QEvent>
    #include <QScrollBar>
    #include "qcmd.h"
    #include "ciodevice.h"
    #include "qkeyboard.h"
    #include "qcommand.h"
    #include "cconfigurationmodulewidget.h"
    #include "csetinput.h"
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
    //--
    enum DEVICE_Type
    {
        MDVV_01 = 0x00,
        MDVV_02 = 0x01,
        MIK_01  = 0x02
    };
    //----------------------------------
    class MainWindow: public QMainWindow
    {
        Q_OBJECT

        public:
            explicit MainWindow(QWidget* parent = Q_NULLPTR);
            ~MainWindow();

        private:
            Ui::MainWindow*             ui;
            QSerialPort*                m_port; // COM-порт
            QLabel*                     m_lblMessage; // вывод сообщений в статус бар
            QSettings*                  m_settings; // настройки
            QByteArray                  m_query; // массив байт запроса
            quint8                      m_query_count; // количество отправленных байт
            QByteArray                  m_responce; // массив байт ответа устройства
            QString                     m_cmd_last; // последняя отправленная команда
            QVector<CIODevice*>         m_input_dev;
            QVector<CIODevice*>         m_output_dev;
            QVector<QLineEdit*>         m_ain_dev;
            QVector<QString>            m_queue_cmd;
            QTimer*                     m_timerAutoRepeatInput;
            QTimer*                     m_timerAutoRepeatAIN;
            QTimer*                     m_timerTimeoutQuery;
            QTimer*                     m_timerRefreshPort;
            QFile*                      m_file_ain;
            bool                        m_block_send;
            QString                     m_port_name; // имя порта по умолчанию
            QKeyboard*                  m_keyboard;
            QCommand*                   m_command;
            CConfigurationModuleWidget* m_conf_widget;
            CSetInput*                  m_set_intput_widget;

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
            void   keyReleaseEvent(QKeyEvent* evt);
            void   showEvent(QShowEvent* evt);
            void   fileAinOpen();
            void   blockSend();
            void   unblockSend();
            bool   is_blockSend();

        protected:
            void keyPressEvent(QKeyEvent *event);

        public slots:
            void refreshSerialPort();
            void ctrlSerialPort(bool state);
            void readData();
            void sendCmd(const QString& cmd_str = "");
            void sendData(const QString& data = "");
            void write(const QString& cmd_str = "", const QByteArray& data = QByteArray());
            void BytesWriten(qint64 byte);
            void cmdDescription(const QString& description);
            void addrChanged(int addr);
            void outputStateChanged(quint8 id, bool state);
            void initFilter(const QString& text);
            void autoRepeatInputs(bool state);
            void autoRepeatAIN(bool state);
            void autoRepeatTimInputs();
            void autoRepeatTimAIN();
            void timeoutTim();
            void visiblityTerminal(bool visible);
            void visiblityKeyboard(bool visible);
            void visiblityCommand(bool visible);
            void configurationWindow();
            void visiblitySerialNumber(bool state = false);
            void setupDiscretInput();
            void discretInputProcess();
    };
    //--------------
    #define EMULATOR // для эмуляции на PC (Rx замкнут на Tx)
#endif // MAINWINDOW_H
