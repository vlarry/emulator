#ifndef CDBCONTROLLER_H
    #define CDBCONTROLLER_H
    //---------------------
    #include <QSqlDatabase>
    #include <QSqlQuery>
    #include <QSqlError>
    #include <QDebug>
    //-----------------
    class CDbController
    {
        private:
            QSqlDatabase* m_db;
            QString       m_last_error;

        private:
            void createDb();
            bool findEqualData(const QString& field, const QString& data);

        public:
            struct serial_num_t
            {
                int     type; // аппаратный адрес устройства
                QString serial_num;
                QString date;
                QString time;
                QString modification;
                QString customer;
            };

        public:
            CDbController(const QString& path);
            ~CDbController();
            serial_num_t serialNumberRead(int type);
            void         serialNumberWrite(const serial_num_t& sn);
            QStringList modificationList();
            QStringList customerList();
    };
#endif // CDBCONTROLLER_H
