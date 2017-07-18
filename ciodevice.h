#ifndef CIODEVICE_H
    #define CIODEVICE_H
    //--------------------
    #include <QToolButton>
    //---------------------------------
    class CIODevice: public QToolButton
    {
        Q_OBJECT

        public:
            CIODevice(QWidget* parent = Q_NULLPTR);
            void set_type(bool type);
            void set_state(bool state);

        private slots:
            void slotState(bool state);

        private:
            bool m_state;
            bool m_type; // тип - вход или выход (false - вход, true - выход)
    };
#endif // CIODEVICE_H
