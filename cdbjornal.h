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
    //-----------------------------
    class CDbJornal: public QWidget
    {
        Q_OBJECT

        public:
            explicit CDbJornal(QWidget* parent = Q_NULLPTR);
            ~CDbJornal();
            void setDataToTable(const CDbController::serial_num_list_t& list);

        public slots:
            void filterSlot(const QString& text);

        signals:
            void closeJournal();
            void deleteJournalRow(int);

        protected:
            void closeEvent(QCloseEvent* event);
            void keyPressEvent(QKeyEvent* event);

        private:
            Ui::CDbJornal* ui;
    };
#endif // CDBJORNAL_H
