#ifndef CBZUINTERFACE_H
    #define CBZUINTERFACE_H
    //----------------
    #include <QWidget>
    #include <QCloseEvent>
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
            void setKeyboardKeyState(int key, bool state);

        signals:
            void closed(bool);

        private:
            void closeEvent(QCloseEvent* event);

        private:
            Ui::CBZUInterface* ui;
            QVector<QKey*>     m_keyboard;
            QVector<QLed*>     m_led;
    };
#endif // CBZUINTERFACE_H
