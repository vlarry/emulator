#ifndef QCMD_H
    #define QCMD_H
    //------------------
    #include <QComboBox>
    #include <QDebug>
    //--------------------------
    class QCmd: public QComboBox
    {
        Q_OBJECT

        public:
            QCmd(QWidget* parent = Q_NULLPTR);

        public slots:
            void slotActivated(int index);

        signals:
            void changeDescription(const QString& description);
    };
#endif // QCMD_H
