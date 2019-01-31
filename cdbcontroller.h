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

        public:
            CDbController(const QString& path);
            ~CDbController();
    };
#endif // CDBCONTROLLER_H
