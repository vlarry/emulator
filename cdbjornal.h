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
            explicit CDbJornal(QWidget* parent = Q_NULLPTR);
            ~CDbJornal();
            void setDataToTable(const CDbController::serial_num_list_t& list);

        signals:
            void closeJournal();

        protected:
            void closeEvent(QCloseEvent* event);

        private:
            Ui::CDbJornal* ui;
    };
#endif // CDBJORNAL_H