#ifndef CIODEVICE_H
    #define CIODEVICE_H
    //--------------------
    #include <QToolButton>
    //---------------------------------
    class CIODevice: public QToolButton
    {
        Q_OBJECT

        public:
            enum state_t
            {
                STATE_OFF = 0x00,
                STATE_ON  = 0x01,
                STATE_ERR = 0x02
            };

        public:
            CIODevice(QWidget* parent = Q_NULLPTR);
            void set_type(bool type);
            void set_state(state_t state);

        private slots:
            void slotState(bool state);

        private:
            state_t m_state;
            bool    m_type; // тип - вход или выход (false - вход, true - выход)
    };
#endif // CIODEVICE_H
