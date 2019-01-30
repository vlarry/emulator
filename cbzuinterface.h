#ifndef CBZUINTERFACE_H
    #define CBZUINTERFACE_H
    //----------------
    #include <QWidget>
    #include <QCloseEvent>
    #include <QShowEvent>
    #include <QByteArray>
    #include "qkey.h"
    #include "qled.h"
    //----------
    namespace Ui
    {
        class CBZUInterface;
    }
    //---------------------------------
    class CBZUInterface: public QWidget
    {
        Q_OBJECT

        public:
            explicit CBZUInterface(QWidget* parent = Q_NULLPTR);
            ~CBZUInterface();
            void ledReset();
            QByteArray ledStates();
            void setKeyboardState(const QByteArray& keyboards);
            void setLedState(const QByteArray& leds);

        public slots:
            void timeoutLedFlash();

        signals:
            void closed(bool);
            void ledStateSave();

        protected:
            void closeEvent(QCloseEvent* event);
            void showEvent(QShowEvent* event);

        private:
            Ui::CBZUInterface* ui;
            QVector<QKey*>     m_keyboard;
            QVector<QLed*>     m_led;
            QTimer             m_timer_flash;
            QLed::LedState     m_state_flash;
    };
#endif // CBZUINTERFACE_H
