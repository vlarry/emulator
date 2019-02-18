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
                int     id; // id записи в БД
                int     dev_code; // код изделия
                int     dev_num; // номер устройства
                int     dev_party; // номер партии
                int     dev_firmware_var; // вариант прошивки
                QString dev_firmware_date; // дата прошивки модуля
                QString date;
                QString time;
                QString modification; // модификация модуля
                QString revision; // ревизия платы
                QString customer; // заказчик
            };
            //-----------
            struct data_t
            {
                int id;
                QString text;
            };
            //----------------------------------------------
            typedef QVector<serial_num_t> serial_num_list_t;
            typedef QVector<data_t> data_list_t;

        public:
            CDbController(const QString& path);
            ~CDbController();
            serial_num_t serialNumberRead();
            serial_num_list_t serialNumberListRead();
            bool serialNumberWrite(const serial_num_t& sn);
            data_list_t dataListFromTable(const QString &table);
            bool findEqualData(int num);
            const QString &lastError() const;

        public slots:
            void writeDataToTable(const QString table_name, const QString data);
            void deleteDataFromTable(const QString& table_name, int id);

        private:
            void createDb();

        private:
            QSqlDatabase* m_db;
            QString       m_last_error;
    };
#endif // CDBCONTROLLER_H
