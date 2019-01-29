#ifndef CBZUINTERFACE_H
    #define CBZUINTERFACE_H
    //----------------
    #include <QWidget>
    #include <QCloseEvent>
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

        signals:
            void closed(bool);
            void ledStateSave();

        private:
            void closeEvent(QCloseEvent* event);

        private:
            Ui::CBZUInterface* ui;
            QVector<QKey*>     m_keyboard;
            QVector<QLed*>     m_led;
    };
#endif // CBZUINTERFACE_H
