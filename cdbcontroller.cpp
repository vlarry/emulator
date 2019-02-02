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
//-----------------------------------------------------------
CDbController::serial_num_t CDbController::serialNumberRead()
{
    serial_num_t sn = { -1, -1, -1, -1, "", "", "", "" };

    if(!m_db || !m_db->isOpen())
    {
        m_last_error = "Can't open a data base";
        return sn;
    }

    QSqlQuery query(*m_db);

    // выборка последней строки по типу, дате и времени
    if(query.exec(QString("SELECT * FROM serial ORDER BY date DESC, time DESC LIMIT 1;")))
    {
        if(query.next()) // если запись существует
        {
            sn.dev_code = query.value("dev_code").toInt();
            sn.dev_num = query.value("dev_num").toInt();
            sn.dev_party = query.value("dev_party").toInt();
            sn.dev_firmware = query.value("dev_firmware").toInt();
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
bool CDbController::serialNumberWrite(const CDbController::serial_num_t& sn)
{
    QSqlQuery query(*m_db);

    query.prepare("INSERT INTO serial (dev_code, dev_num, dev_party, dev_firmware, date, time, modification, customer) "
                  "VALUES (:dev_code, :dev_num, :dev_party, :dev_firmware, :date, :time, :modification, :customer);");
    query.bindValue(":dev_code", sn.dev_code);
    query.bindValue(":dev_num", sn.dev_num);
    query.bindValue(":dev_party", sn.dev_party);
    query.bindValue(":dev_firmware", sn.dev_firmware);
    query.bindValue(":date", sn.date);
    query.bindValue(":time", sn.time);
    query.bindValue(":modification", sn.modification);
    query.bindValue(":customer", sn.customer);

    if(!query.exec())
    {
        m_last_error = query.lastError().text();
        return false;
    }

    return true;
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
                        "dev_code INTEGER NOT NULL, "                        // код изделия (0х48 - МДВВ-01, 0х49 - МДВВ-02, 0х50 - МИК-01)
                        "dev_num INTEGER NOT NULL, "                         // номер устройства (0 - 999)
                        "dev_party INTEGER NOT NULL, "                         // номер в партии (0 - 99)
                        "dev_firmware INTEGER NOT NULL, "                    // вариант прошивки (0 - 99)
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
//----------------------------------------------------------------------
bool CDbController::findEqualData(const CDbController::serial_num_t& sn)
{
    if(!m_db || !m_db->isOpen())
        return false;

    QSqlQuery query(*m_db);

    if(query.exec(QString("SELECT * FROM serial WHERE dev_num = %1 AND dev_party = %2 AND dev_firmware = %3;").arg(sn.dev_num).arg(sn.dev_party).
                                                                                                               arg(sn.dev_firmware)))
    {
        return query.next();
    }

    return false;
}
