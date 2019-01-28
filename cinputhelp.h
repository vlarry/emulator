#ifndef CINPUTHELP_H
    #define CINPUTHELP_H
    //----------------
    #include <QWidget>
    #include <QPixmap>
    //----------
    namespace Ui
    {
        class CInputHelp;
    }
    //------------------------------
    class CInputHelp: public QWidget
    {
        Q_OBJECT

        public:
            explicit CInputHelp(const QPixmap& pixmap, QWidget *parent = Q_NULLPTR);
            ~CInputHelp();
            void setPixmap(const QPixmap& pixmap);

        private:
            Ui::CInputHelp* ui;
    };
#endif // CINPUTHELP_H
