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

        private:
            bool m_state;
    };
#endif // CIODEVICE_H
