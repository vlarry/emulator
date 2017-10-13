#ifndef QCOMMAND_H
    #define QCOMMAND_H
    //----------------
    #include <QWidget>
    #include <QListWidgetItem>
    #include <QFontMetrics>
    #include <QApplication>
    #include <QDesktopWidget>
    #include <QShowEvent>
    #include <QCloseEvent>
    #include <QDebug>
    #include "qcmd.h"
    //----------
    namespace Ui
    {
        class QCommand;
    }
    //----------------------------
    class QCommand: public QWidget
    {
        Q_OBJECT

        public:
            explicit QCommand(QWidget* parent = Q_NULLPTR);
            ~QCommand();

        protected:
            void showEvent(QShowEvent* event);
            void closeEvent(QCloseEvent* event);

        signals:
            void closeCommand(bool);
            void doubleClickCmd(QString);

        private slots:
            void cmdDoubleClicked(QListWidgetItem* item);

        private:
            Ui::QCommand* ui;
            QCmd::cmd_t   m_cmd;
            QWidget*      m_parent;
    };
#endif // QCOMMAND_H
