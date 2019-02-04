#ifndef CDBJORNAL_H
    #define CDBJORNAL_H
    //----------------
    #include <QWidget>
    #include <QCloseEvent>
    #include <QShowEvent>
    #include <QDateTime>
    #include "cdbcontroller.h"
    //----------
    namespace Ui
    {
        class CDbJornal;
    }
    //-----------------------------
    class CDbJornal: public QWidget
    {
        Q_OBJECT

        public:
            explicit CDbJornal(const CDbController* controller, QWidget* parent = Q_NULLPTR);
            ~CDbJornal();

        signals:
            void closeJournal();

        protected:
            void closeEvent(QCloseEvent* event);
            void showEvent(QShowEvent* event);

        private:
            Ui::CDbJornal*       ui;
            const CDbController* m_db_controller;
    };
#endif // CDBJORNAL_H
