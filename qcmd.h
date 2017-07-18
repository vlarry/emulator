#ifndef QCMD_H
    #define QCMD_H
    //------------------
    #include <QComboBox>
    #include <QDebug>
    #include <QPair>
    //--------------------------
    class QCmd: public QComboBox
    {
        Q_OBJECT

        typedef QPair<QString, int>    param_t;
        typedef QMap<QString, param_t> cmd_t;

        public:
            QCmd(QWidget* parent = Q_NULLPTR);

            QString description(int index) const;

        public slots:
            void slotActivated(int index);

        signals:
            void changeDescription(const QString& description);

        private:
            cmd_t m_cmd;
    };
#endif // QCMD_H
