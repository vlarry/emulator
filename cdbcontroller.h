#ifndef CDBCONTROLLER_H
    #define CDBCONTROLLER_H
    //---------------------
    #include <QSqlDatabase>
    #include <QSqlQuery>
    #include <QSqlError>
    #include <QDateTime>
    #include <QDebug>
    //-----------------
    class CDbController
    {
        public:
            struct serial_num_t
            {
                int     dev_code; // код изделия
                int     dev_num; // номер устройства
                int     dev_party; // номер партии
                int     dev_firmware_var; // вариант прошивки
                QString dev_firmware_date; // дата прошивки модуля
                QString date;
                QString time;
                QString modification;
                QString customer;
            };

        public:
            CDbController(const QString& path);
            ~CDbController();
            serial_num_t serialNumberRead();
            bool serialNumberWrite(const serial_num_t& sn);
            QStringList dataListFromTable(const QString &table);
            bool findEqualData(const serial_num_t& sn);

        public slots:
            void writeDataToTable(const QString table_name, const QString data);

        private:
            void createDb();

        private:
            QSqlDatabase* m_db;
            QString       m_last_error;
    };
#endif // CDBCONTROLLER_H
