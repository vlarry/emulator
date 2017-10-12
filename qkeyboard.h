#ifndef QKEYBOARD_H
    #define QKEYBOARD_H
    //----------------
    #include <QMainWindow>
    #include <QDebug>
    #include <qkey.h>
    //----------
    namespace Ui
    {
        class QKeyboard;
    }
    //-----------------------------
    class QKeyboard: public QWidget
    {
        Q_OBJECT

        public:
            explicit QKeyboard(QMainWindow* parent = Q_NULLPTR);
            ~QKeyboard();
            void setStateKey(int channel, bool state);
            int  key_count() const;

        private:
            void closeEvent(QCloseEvent* event);

        signals:
            void closeKeyboard(bool state);

        private:
            Ui::QKeyboard* ui;
            QVector<QKey*> m_keys;
    };
#endif // QKEYBOARD_H
