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
            void set_id(quint8 id);

            quint8 get_id() const;

        private slots:
            void slotState(bool state);

        signals:
            void stateChanged(quint8, bool); // id io and state

        private:
            state_t m_state;
            quint8  m_id;
            bool    m_type; // тип - вход или выход (false - вход, true - выход)
    };
#endif // CIODEVICE_H
