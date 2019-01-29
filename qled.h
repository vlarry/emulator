#ifndef QLED_H
    #define QLED_H
    //----------------
    #include <QWidget>
    #include <QToolButton>
    #include <QMouseEvent>
    #include <QTimer>
    #include <QDebug>
    //----------------------------
    class QLed: public QToolButton
    {
        Q_OBJECT

        public:
            enum LedColor
            {
                LED_RED,
                LED_GREEN
            };

            enum LedState
            {
                LED_OFF,
                LED_ON
            };

        public:
            QLed(QWidget* parent = Q_NULLPTR);
            void setColor(const LedColor led_color);

        public slots:
            void setState(LedState state);
            void ledClick();
            void timeout();

        protected:
            void mouseDoubleClickEvent(QMouseEvent* event);

        private:
            void setLedModeFlash();

        private:
            LedState m_state;
            bool     m_flash;
            LedColor m_color;
            QTimer   m_timer;
    };
#endif // QLED_H
