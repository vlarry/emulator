#ifndef QLAMP_H
    #define QLAMP_H
    //---------------
    #include <QLabel>
    //------------------------
    class QLamp: public QLabel
    {
        public:
            QLamp(QWidget* parent = Q_NULLPTR);
    };
#endif // QLAMP_H
