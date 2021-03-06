#ifndef CIODEVICE_H
    #define CIODEVICE_H
    //--------------------
    #include <QToolButton>
    #include <QMouseEvent>
    #include <QDebug>
    //--------------
    enum DEVICE_Type
    {
        MDVV_01 = 0x00,
        MDVV_02 = 0x01,
        MIK_01  = 0x02
    };
    //---------------------------------
    class CIODevice: public QToolButton
    {
        Q_OBJECT

        public:
            enum state_t
            {
                STATE_OFF = 0x00,
                STATE_ON  = 0x01,
                STATE_ALT = 0x02,
                STATE_ERR = 0x03
            };

        public:
            CIODevice(QWidget* parent = Q_NULLPTR);
            void set_type(bool type);
            void set_state(state_t state);
            void set_id(quint8 id);
            void set_dev_addr(quint8 addr);

            quint8  get_addr() const;
            quint8  get_id() const;
            state_t get_state() const;

            static void set_modifier(int key_modifier);
            static int  get_modifier();

        private slots:
            void slotState(bool state);

        signals:
            void stateChanged(quint8, bool); // id io and state

        private:
            state_t m_state;
            quint8  m_id;
            bool    m_type; // тип - вход или выход (false - вход, true - выход)
            quint8  m_dev_addr; // адрес устройства

            static bool m_ctrl;
    };
#endif // CIODEVICE_H
