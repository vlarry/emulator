#ifndef MAINWINDOW_H
    #define MAINWINDOW_H
    //--------------------
    #include <QMainWindow>
    #include <windows.h>
    #include <QDebug>
    #include <QtSerialPort/QSerialPort>
    #include <QtSerialPort/QSerialPortInfo>
    #include <QMessageBox>
    #include <QDataStream>
    #include "ftd2xx.h"
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
            Ui::MainWindow* ui;
            QLabel*         m_lblStatusBar;
            FT_HANDLE       m_ftHandle;

        public slots:
            void refreshComPort();
            void changeStateComPort(bool);
            void send();
    };
#endif // MAINWINDOW_H
