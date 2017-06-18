#ifndef MAINWINDOW_H
    #define MAINWINDOW_H
    //--------------------
    #include <QMainWindow>
    #include <QDebug>
    #include <QSerialPort>
    #include <QSerialPortInfo>
    #include <QMessageBox>
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
            Ui::MainWindow* ui;
            QLabel*         m_lblMessage;

        private:
            void showMessage(const QString& message);

        public slots:
    };
#endif // MAINWINDOW_H
