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
    #include "qcommand.h"
    #include "cconfigurationmodulewidget.h"
    #include "csetinput.h"
    #include "cinputhelp.h"
    #include "cbzuinterface.h"
    #include "cdbcontroller.h"
    #include "cdbjornal.h"
    #include <windows.h> // для вызова задержки Sleep();
    //----------
    namespace Ui
    {
        class MainWindow;
    }
    //------------------
    struct AutoAddress_t
    {
        bool state;
        quint8 currentAddress;
    };
    //-----------
    typedef union
    {
        quint8 byte[sizeof(float)];
        float  number;
    } Float_t;
    //---------------------------------------
    typedef QMap<QString, QString> CmdBind_t; // связанные команды (для реализации отправки автоматического чтения после записи)
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
            QVector<CIODevice*>         m_input_dev; // массив указателей на входы устройства
            QVector<CIODevice*>         m_output_dev; // массив указателей на выходы устройства
            QVector<QLineEdit*>         m_ain_dev;
            QVector<QString>            m_queue_cmd;
            QTimer*                     m_timerAutoRepeatInput;
            QTimer*                     m_timerAutoRepeatAIN;
            QTimer*                     m_timerTimeoutQuery;
            QTimer*                     m_timerRefreshPort;
            QFile*                      m_file_ain;
            bool                        m_block_send;
            QString                     m_port_name; // имя порта по умолчанию
            CBZUInterface*              m_mik_interface;
            QCommand*                   m_command;
            CConfigurationModuleWidget* m_conf_widget;
            CSetInput*                  m_set_intput_widget;
            CInputHelp*                 m_input_help_widget;
            QString                     m_cmd_save; // отправленная команда на запись параметров (сохраняется, если идет запись, чтобы автоматом отправить
                                                    // чтение
            CmdBind_t                   m_cmd_bind; // хранение связанных команд
            QTimer                      m_cmd_read_timer; // таймер для чтения данных после записи
            CDbController*              m_db_controller;
            CDbJornal*                  m_db_journal;
            AutoAddress_t               m_is_connected; // переменная управляющая разрешением передачи (для автоматического подбора адреса устройства)


        private:
            void   initConnect();
            void   initSerialPort();
            void   initIO();
            void   initDbController(CDbController* controller);
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
            QByteArray formatSerialNumber(); // форматирование серийного номера

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
            void addrChanged(int addr);
            void outputStateChanged(quint8 id, bool state);
            void autoRepeatInputs(bool state);
            void autoRepeatAIN(bool state);
            void autoRepeatTimInputs();
            void autoRepeatTimAIN();
            void timeoutTim();
            void visiblityTerminal(bool visible);
            void visiblityInterfaceMIK01(bool visible);
            void visiblityCommand(bool visible);
            void configurationWindow();
            void visiblitySerialNumber(bool state = false);
            void discretInputHelp();
            void setupExtandOut();
            void timeoutCmdBindRead();
            void openDbJournal();
            void closeDbJournal();
            void writeDataToDb(const QString table_name, const QString data);
            void useDeviceAddress(bool state);
            void ctrlInterface(bool state);
            void autoAddressSelect();
            void processCmdFavorite();
            void processDiscretInputSet();
            void removeSerialNumber(int id);
    };
    //--------------
    #define EMULATOR // для эмуляции на PC (Rx замкнут на Tx)
#endif // MAINWINDOW_H
