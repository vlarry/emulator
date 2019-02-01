#ifndef CAPPENDINFODIALOG_H
    #define CAPPENDINFODIALOG_H
    //----------------
    #include <QDialog>
    #include <QPushButton>
    #include <QDialogButtonBox>
    //----------
    namespace Ui
    {
        class CAppendInfoDialog;
    }
    //-------------------------------------
    class CAppendInfoDialog: public QDialog
    {
        Q_OBJECT

        public:
            explicit CAppendInfoDialog(const QString& title, QWidget* parent = Q_NULLPTR);
            ~CAppendInfoDialog();
            QString text() const;

        private:
            Ui::CAppendInfoDialog* ui;
    };
#endif // CAPPENDINFODIALOG_H
