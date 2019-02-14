#ifndef CINTERFACEMIK_H
    #define CINTERFACEMIK_H
    //---------------
    #include <QFrame>
    #include <QCloseEvent>
    #include <QShowEvent>
    #include <QByteArray>
    #include "qkey.h"
    #include "qled.h"
    //----------
    namespace Ui
    {
        class CInterfaceMIK;
    }

    class CInterfaceMIK: public QFrame
    {
        Q_OBJECT

        public:
            explicit CInterfaceMIK(QWidget *parent = nullptr);
            ~CInterfaceMIK();
            void ledReset();
            QByteArray ledStates();
            void setKeyboardState(const QByteArray& keyboards);
            void setLedState(const QByteArray& leds);

        public slots:
            void timeoutLedFlash();

        signals:
            void closed(bool);

        protected:
            void closeEvent(QCloseEvent* event);
            void showEvent(QShowEvent* event);

        private:
            void init();

        private:
            Ui::CInterfaceMIK *ui;
            QVector<QKey*>     m_keyboard;
            QVector<QLed*>     m_led;
            QTimer             m_timer_flash;
            QLed::LedState     m_state_flash;
    };
#endif // CINTERFACEMIK_H
