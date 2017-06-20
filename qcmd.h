#ifndef QCMD_H
    #define QCMD_H
    //-------------
    #include <QMap>
    #include <QVector>
    #include <QDebug>
    #include <stdint.h>
    //-----------
    enum CMD_DEST // command destination
    {
        READ_DSIN = 0x00,
        READ_DSOUT,
        READ_AIN,
        READ_DSExIN,
        READ_DSExOUT,
        READ_CNF,
        READ_ID,
        READ_TRG_DSDIN,
        WRITE_CNF,
        WRITE_DSExOUT,
        WRITE_DSExOUT_REG,
        WRITE_DSOUT_LOW,
        WRITE_DSOUT_HIGH,
        RESERVE
    };
    //----------
    struct cmd_t
    {
        int      n;
        int      m;
        CMD_DEST dest;
        bool     is_ack;
    };
    //-------------------------------------
    typedef QMap<QString, cmd_t> command_t;
    //------------
    class QCmdList
    {
        private:
            static command_t m_list;

        public:
            static QList<QString> list();
            static cmd_t cmd(const QString& key);
    };
    //--------
    class QCmd
    {
        private:
            QVector<QByteArray> m_data;
            QString             m_code;
            quint8              m_address;

        public:
            QCmd(QString code, quint8 address);
            quint8 checksum(QVector<QByteArray> data, size_t size);
    };
#endif // QCMD_H
