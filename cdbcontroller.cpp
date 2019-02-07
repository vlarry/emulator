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
    serial_num_t sn = { -1, -1, -1, -1, "", "", "", "", "", "" };

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
            sn.dev_firmware_var = query.value("dev_firmware_var").toInt();
            sn.dev_firmware_date = query.value("dev_firmware_date").toString();
            sn.date = query.value("date").toString();
            sn.time = query.value("time").toString();
            sn.modification = query.value("modification").toString();
            sn.revision = query.value("revision").toString();
            sn.customer = query.value("customer").toString();
        }
    }
    else
        m_last_error = m_db->lastError().text();

    return sn;
}
//--------------------------------------------------------------------
CDbController::serial_num_list_t CDbController::serialNumberListRead()
{
    serial_num_list_t list;

    if(!m_db || !m_db->isOpen())
    {
        m_last_error = "Can't open a data base";
        return list;
    }

    QSqlQuery query(*m_db);

    if(query.exec(QString("SELECT * FROM serial;")))
    {
        while(query.next())
        {
            serial_num_t sn;

            sn.dev_code = query.value("dev_code").toInt();
            sn.dev_num = query.value("dev_num").toInt();
            sn.dev_party = query.value("dev_party").toInt();
            sn.dev_firmware_var = query.value("dev_firmware_var").toInt();
            sn.dev_firmware_date = query.value("dev_firmware_date").toString();
            sn.date = query.value("date").toString();
            sn.time = query.value("time").toString();
            sn.modification = query.value("modification").toString();
            sn.revision = query.value("revision").toString();
            sn.customer = query.value("customer").toString();

            list.append(sn);
        }
    }
    else
        m_last_error = m_db->lastError().text();

    return list;
}
//--------------------------------------------------------------------------
bool CDbController::serialNumberWrite(const CDbController::serial_num_t& sn)
{
    QSqlQuery query(*m_db);

    query.prepare("INSERT INTO serial (date, time, dev_code, dev_num, dev_party, dev_firmware_var, dev_firmware_date, modification, revision, customer) "
                  "VALUES (:date, :time, :dev_code, :dev_num, :dev_party, :dev_firmware_var, :dev_firmware_date, :modification, :revision, :customer);");
    query.bindValue(":date", sn.date);
    query.bindValue(":time", sn.time);
    query.bindValue(":dev_code", sn.dev_code);
    query.bindValue(":dev_num", sn.dev_num);
    query.bindValue(":dev_party", sn.dev_party);
    query.bindValue(":dev_firmware_var", sn.dev_firmware_var);
    query.bindValue(":dev_firmware_date", sn.dev_firmware_date);
    query.bindValue(":modification", sn.modification);
    query.bindValue(":revision", sn.revision);
    query.bindValue(":customer", sn.customer);

    if(!query.exec())
    {
        m_last_error = query.lastError().text();
        return false;
    }

    return true;
}
//----------------------------------------------------------------
QStringList CDbController::dataListFromTable(const QString& table)
{
    QStringList list;

    if(m_db && m_db->isOpen())
    {
        QSqlQuery query(*m_db);

        if(query.exec(QString("SELECT data FROM %1;").arg(table)))
        {
            while(query.next())
            {
                list << query.value("data").toString();
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
                        "date STRING NOT NULL, "                             // дата записи серийного номера
                        "time STRING NOT NULL, "                             // время записи серийного номера
                        "dev_code INTEGER NOT NULL, "                        // код изделия (0х48 - МДВВ-01, 0х49 - МДВВ-02, 0х50 - МИК-01)
                        "dev_num INTEGER NOT NULL, "                         // номер устройства (0 - 999)
                        "dev_party INTEGER NOT NULL, "                       // номер в партии (0 - 99)
                        "dev_firmware_var INTEGER NOT NULL, "                // вариант прошивки (0 - 99)
                        "dev_firmware_date STRING NOT NULL, "                // дата прошивки
                        "modification STRING NOT NULL, "                     // модификация модуля
                        "revision STRING NOT NULL, "                         // ревизия платы (формат: ver.1.0 MM.yy)
                        "customer STRING);";                                 // заказчик

    if(!query.exec(query_str))
    {
        m_last_error = query.lastError().text();
        qDebug() << QString("Error: %1").arg(m_last_error);
        return;
    }

    query_str = "CREATE TABLE IF NOT EXISTS modification("
                "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                "data STRING UNIQ NOT NULL);";

    if(!query.exec(query_str))
    {
        m_last_error = query.lastError().text();
        qDebug() << QString("Error: %1").arg(m_last_error);
        return;
    }

    query_str = "CREATE TABLE IF NOT EXISTS customer("
                "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                "data STRING UNIQ NOT NULL);";

    if(!query.exec(query_str))
    {
        m_last_error = query.lastError().text();
        qDebug() << QString("Error: %1").arg(m_last_error);
        return;
    }

    query_str = "CREATE TABLE IF NOT EXISTS revision("
                "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                "data STRING UNIQ NOT NULL);";

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

    if(query.exec(QString("SELECT * FROM serial WHERE dev_num = %1 AND dev_party = %2 AND dev_firmware_var = %3;").arg(sn.dev_num).arg(sn.dev_party).
                                                                                                                   arg(sn.dev_firmware_var)))
    {
        return query.next();
    }

    return false;
}
//--------------------------------------------------------------------------------
void CDbController::writeDataToTable(const QString table_name, const QString data)
{
    if(!m_db || !m_db->isOpen())
        return;

    QString query_str = QString("INSERT INTO %1 (data) VALUES(\'%2\');").arg(table_name).arg(data);
    QSqlQuery query(*m_db);

    if(!query.exec(query_str))
    {
        m_last_error = m_db->lastError().text();
    }
}
