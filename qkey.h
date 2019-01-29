#ifndef QKEY_H
    #define QKEY_H
    //----------------
    #include <QWidget>
    #include <QToolButton>
    //----------------------------
    class QKey: public QToolButton
    {
        public:
            QKey(QWidget* parent = Q_NULLPTR);
            void setState(bool state);

        private:
            bool m_state;
    };
#endif // QKEY_H
