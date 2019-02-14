#ifndef CDBJORNAL_H
    #define CDBJORNAL_H
    //----------------
    #include <QWidget>
    #include <QCloseEvent>
    #include <QShowEvent>
    #include <QDateTime>
    #include <QLineEdit>
    #include <QKeyEvent>
    #include <QDebug>
    #include <QMessageBox>
    #include <QModelIndexList>
    #include <QPushButton>
    #include "cdbcontroller.h"
    #include "cdbjournalitem.h"
    //----------
    namespace Ui
    {
        class CDbJornal;
    }
    //------------------------------
    class CDbJournal: public QWidget
    {
        Q_OBJECT

        public:
            enum class DataBase
            {
                SERIAL_DB,
                MODIFICATION_DB,
                REVISION_DB,
                CUSTOMER_DB
            };

        public:
            explicit CDbJournal(const DataBase& db_type, QWidget* parent = Q_NULLPTR);
            ~CDbJournal();
            void setDataToTable(const CDbController::serial_num_list_t &list);
            void setDataToTable(const CDbController::data_list_t &list);

        public slots:
            void filterSlot(const QString& text);

        signals:
            void closeJournal();
            void deleteJournalRow(DataBase, int);

        protected:
            void closeEvent(QCloseEvent* event);
            void keyPressEvent(QKeyEvent* event);

        private:
            Ui::CDbJornal* ui;
            DataBase       m_db_type;
    };
#endif // CDBJORNAL_H
