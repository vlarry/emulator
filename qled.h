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
                LED_GREEN,
                LED_YELLOW
            };

            enum LedState
            {
                LED_OFF,
                LED_ON,
                LED_FLASH,
                LED_RESERVE
            };

        public:
            QLed(QWidget* parent = Q_NULLPTR);
            LedState state() const;
            void setColor(const LedColor led_color);
            void setLedModeFlash();
            void reset();

        public slots:
            void setState(LedState state);
            void ledClick();
            void timeout();

        protected:
            void mouseDoubleClickEvent(QMouseEvent* event);

        private:
            LedState m_state;
            bool     m_flash;
            LedColor m_color;
            QTimer   m_timer;
    };
#endif // QLED_H
