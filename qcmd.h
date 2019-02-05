#ifndef QCMD_H
    #define QCMD_H
    //---------------
    #include <QDebug>
    #include <QPair>
    #include <QObject>
    //--------
    class QCmd
    {
        public:
            typedef QPair<QString, quint8> param_t;
            typedef QMap<QString, param_t> cmd_t;

        public:
            QCmd();
            static quint8 size(const QString& key); // количество байт в ответе
            static const cmd_t& list();
            static QString descrition(const QString& key);

        private:
            static void init();

        private:
            static cmd_t m_cmd;
    };
#endif // QCMD_H
