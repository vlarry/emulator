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
//-------------------------------------------------------------------
CDbController::serial_num_t CDbController::serialNumberRead(int type)
{
    serial_num_t sn = { -1, "", "", "", "", "" };

    if(!m_db || !m_db->isOpen())
    {
        m_last_error = "Can't open a data base";
        return sn;
    }

    QSqlQuery query(*m_db);

    // выборка последней строки по типу, дате и времени
    if(query.exec(QString("SELECT * FROM serial WHERE addr = %1 ORDER BY date DESC, time DESC LIMIT 1;").arg(type)))
    {
        if(query.next()) // если запись существует
        {
            sn.serial_num = query.value("sn").toString();
            sn.date = query.value("date").toString();
            sn.time = query.value("time").toString();
            sn.modification = query.value("modification").toString();
            sn.customer = query.value("customer").toString();
        }
    }
    else
        m_last_error = m_db->lastError().text();

    return sn;
}
//--------------------------------------------------------------------------
void CDbController::serialNumberWrite(const CDbController::serial_num_t& sn)
{
    if(!findEqualData("sn", sn.serial_num)) // проверка на совпадение серийных номеров
    {
        // такого серийника в базе нет, значит пишем
        QSqlQuery query(*m_db);
        QString query_str = QString("INSERT INTO serial (add, sn, date, time, modification, customer) "
                                    "VALUES (%1, \'%2\', \'%3\', \'4\', \'5\', \'%6\');").arg(sn.type).arg(sn.serial_num).arg(sn.date).arg(sn.time).
                                    arg(sn.modification).arg(sn.customer);

        if(!query.exec(query_str))
        {
            m_last_error = query.lastError().text();
        }
    }
}
//-------------------------------------------
QStringList CDbController::modificationList()
{
    QStringList list;

    if(m_db && m_db->isOpen())
    {
        QSqlQuery query(*m_db);

        if(query.exec("SELECT variant FROM modification;"))
        {
            while(query.next())
            {
                list << query.value("variant").toString();
            }
        }
        else
            m_last_error = m_db->lastError().text();
    }

    return list;
}
//---------------------------------------
QStringList CDbController::customerList()
{
    QStringList list;

    if(m_db && m_db->isOpen())
    {
        QSqlQuery query(*m_db);

        if(query.exec("SELECT name FROM customer;"))
        {
            while(query.next())
            {
                list << query.value("name").toString();
            }
        }
        else
            m_last_error = m_db->lastError().text();
    }

    return list;
}
//----------------------------
void CDbController::createDb()
{
    QSqlQuery query(*m_db);
    QString query_str = "CREATE TABLE IF NOT EXISTS serial("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "    // id записи
                        "addr INTEGER NOT NULL, "                            // аппаратный адрес модуля (0 - МДВВ-01, 1 - МДВВ-02, 2 - МИК-01)
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
                "variant STRING UNIQ NOT NULL);";

    if(!query.exec(query_str))
    {
        m_last_error = query.lastError().text();
        qDebug() << QString("Error: %1").arg(m_last_error);
        return;
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
//--------------------------------------------------------------------------
bool CDbController::findEqualData(const QString& field, const QString& data)
{
    QSqlQuery query(*m_db);

    if(query.exec(QString("SELECT %1 FROM serial WHERE %2 = \'%3\';").arg(field).arg(field).arg(data)))
    {
        if(query.next())
        {
            return !query.value(0).toString().isEmpty();
        }
    }

    return false;
}
