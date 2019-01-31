#ifndef CDBJORNAL_H
    #define CDBJORNAL_H
    //----------------
    #include <QWidget>
    #include <QCloseEvent>
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

        signals:
            void closeJournal();

        protected:
            void closeEvent(QCloseEvent* event);

        private:
            Ui::CDbJornal* ui;
    };
#endif // CDBJORNAL_H
