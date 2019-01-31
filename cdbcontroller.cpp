#include "cdbcontroller.h"
//------------------------------------------------
CDbController::CDbController(const QString& path):
    m_db(Q_NULLPTR),
    m_last_error("")
{
    m_db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", "db"));
    m_db->setDatabaseName(path);

    if(!m_db->open())
    {
        m_last_error = m_db->lastError().text();
        delete m_db;
        m_db = Q_NULLPTR;
        qDebug() << QString("Error: %1").arg(m_last_error);
    }

    if(m_db)
    {
        createDb();
    }
}
//-----------------------------
CDbController::~CDbController()
{
    if(m_db)
    {
        if(m_db->isOpen())
            m_db->close();
        delete m_db;
        m_db = Q_NULLPTR;
        QSqlDatabase::removeDatabase("db");
    }
}
//----------------------------
void CDbController::createDb()
{
    QSqlQuery query(*m_db);
    QString query_str = "CREATE TABLE IF NOT EXISTS serial("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    // id записи
                        "sn STRING UNIQ NOT NULL, "                          // серийный номер
                        "date STRING NOT NULL, "                             // дата записи серийного номера
                        "time STRING NOT NULL, "                             // время записи серийного номера
                        "modification STRING NOT NULL, "                     // модификация модуля
                        "customer STRING);";                                 // заказчик

    if(!query.exec(query_str))
    {
        m_last_error = query.lastError().text();
        qDebug() << QString("Error: %1").arg(m_last_error);
        return;
    }

    query_str = "CREATE TABLE IF NOT EXISTS modification("
                "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                "variant STRING NOT NULL);";

    if(!query.exec(query_str))
    {
        m_last_error = query.lastError().text();
        qDebug() << QString("Error: %1").arg(m_last_error);
        return;
    }
    else
    {
        query.exec("INSERT INTO modification(variant) VALUES(\'1\');");
        query.exec("INSERT INTO modification(variant) VALUES(\'2\');");
        query.exec("INSERT INTO modification(variant) VALUES(\'3\');");
        query.exec("INSERT INTO modification(variant) VALUES(\'4\');");
        query.exec("INSERT INTO modification(variant) VALUES(\'5\');");
    }

    query_str = "CREATE TABLE IF NOT EXISTS customer("
                "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                "name STRING);";

    if(!query.exec(query_str))
    {
        m_last_error = query.lastError().text();
        qDebug() << QString("Error: %1").arg(m_last_error);
        return;
    }
}
