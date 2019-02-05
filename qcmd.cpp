#include "qcmd.h"
//----------------------
QCmd::cmd_t QCmd::m_cmd;
//----------
QCmd::QCmd()
{
    init();
}
//---------------
void QCmd::init()
{
    m_cmd.insert(QObject::tr("0x00"), qMakePair(QObject::tr("Чтение дискретных каналов входов"), 4));
    m_cmd.insert(QObject::tr("0x01"), qMakePair(QObject::tr("Чтение дискретных каналов выходов"), 2));
    m_cmd.insert(QObject::tr("0x02"), qMakePair(QObject::tr("Чтение расчетных величин 1..4 формата FLOAT"), 17));
    m_cmd.insert(QObject::tr("0x03"), qMakePair(QObject::tr("Чтение регистра расширения дискретных каналов входов"), 4));
    m_cmd.insert(QObject::tr("0x04"), qMakePair(QObject::tr("Чтение регистра расширения дискретных каналов выходов"), 4));
    m_cmd.insert(QObject::tr("0x05"), qMakePair(QObject::tr("Запись регистра расширения дискретных каналов выходов"), 2));
    m_cmd.insert(QObject::tr("0x06"), qMakePair(QObject::tr("Установка на дискретном выходе 0 значения \"0\""), 2));
    m_cmd.insert(QObject::tr("0x07"), qMakePair(QObject::tr("Установка на дискретном выходе 1 значения \"0\""), 2));
    m_cmd.insert(QObject::tr("0x08"), qMakePair(QObject::tr("Установка на дискретном выходе 2 значения \"0\""), 2));
    m_cmd.insert(QObject::tr("0x09"), qMakePair(QObject::tr("Установка на дискретном выходе 3 значения \"0\""), 2));
    m_cmd.insert(QObject::tr("0x0A"), qMakePair(QObject::tr("Установка на дискретном выходе 4 значения \"0\""), 2));
    m_cmd.insert(QObject::tr("0x0B"), qMakePair(QObject::tr("Установка на дискретном выходе 5 значения \"0\""), 2));
    m_cmd.insert(QObject::tr("0x0C"), qMakePair(QObject::tr("Установка на дискретном выходе 6 значения \"0\""), 2));
    m_cmd.insert(QObject::tr("0x0D"), qMakePair(QObject::tr("Установка на дискретном выходе 7 значения \"0\""), 2));
    m_cmd.insert(QObject::tr("0x0E"), qMakePair(QObject::tr("Установка на дискретном выходе 0 значения \"1\""), 2));
    m_cmd.insert(QObject::tr("0x0F"), qMakePair(QObject::tr("Установка на дискретном выходе 1 значения \"1\""), 2));
    m_cmd.insert(QObject::tr("0x10"), qMakePair(QObject::tr("Установка на дискретном выходе 2 значения \"1\""), 2));
    m_cmd.insert(QObject::tr("0x11"), qMakePair(QObject::tr("Установка на дискретном выходе 3 значения \"1\""), 2));
    m_cmd.insert(QObject::tr("0x12"), qMakePair(QObject::tr("Установка на дискретном выходе 4 значения \"1\""), 2));
    m_cmd.insert(QObject::tr("0x13"), qMakePair(QObject::tr("Установка на дискретном выходе 5 значения \"1\""), 2));
    m_cmd.insert(QObject::tr("0x14"), qMakePair(QObject::tr("Установка на дискретном выходе 6 значения \"1\""), 2));
    m_cmd.insert(QObject::tr("0x15"), qMakePair(QObject::tr("Установка на дискретном выходе 7 значения \"1\""), 2));
    m_cmd.insert(QObject::tr("0x16"), qMakePair(QObject::tr("Чтение корфигурации"), 10));
    m_cmd.insert(QObject::tr("0x17"), qMakePair(QObject::tr("Запись конфигурации"), 2));
    m_cmd.insert(QObject::tr("0x18"), qMakePair(QObject::tr("Чтение байта конфигурации искробезопасных входов"), 2));
    m_cmd.insert(QObject::tr("0x19"), qMakePair(QObject::tr("Запись байта конфигурации искробезопасных входов"), 2));
    m_cmd.insert(QObject::tr("0x1A"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x1B"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x1C"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x1D"), qMakePair(QObject::tr("Чтение ошибок"), 17));
    m_cmd.insert(QObject::tr("0x1E"), qMakePair(QObject::tr("Чтение ID"), 9));
    m_cmd.insert(QObject::tr("0x1F"), qMakePair(QObject::tr("Чтение времени срабатывания выделенного входного дискретного канала"), 4));
    m_cmd.insert(QObject::tr("0x20"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x21"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x22"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x23"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x24"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x25"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x26"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x27"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x28"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x29"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x2A"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x2B"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x2C"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x2D"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x2E"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x2F"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x30"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x31"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x32"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x33"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x34"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x35"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x36"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x37"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x38"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x39"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x3A"), qMakePair(QObject::tr("Запись серийного номера"), 2));
    m_cmd.insert(QObject::tr("0x3B"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x3C"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x3D"), qMakePair(QObject::tr("Резерв"), 0));
    m_cmd.insert(QObject::tr("0x3E"), qMakePair(QObject::tr("Установка общих настроек фильтра"), 2));
    m_cmd.insert(QObject::tr("0x3F"), qMakePair(QObject::tr("Установка настроек входа"), 2));
}
//-----------------------------------
quint8 QCmd::size(const QString& key)
{
    quint8 s = 0;

    if(m_cmd.find(key) != m_cmd.end())
    {
        s = m_cmd[key].second;
    }

    return s;
}
//-----------------------------
const QCmd::cmd_t& QCmd::list()
{
    return m_cmd;
}
//------------------------------------------
QString QCmd::descrition(const QString& key)
{
    QString cmd = "";

    if(m_cmd.find(key) != m_cmd.end())
    {
        cmd = m_cmd[key].first;
    }

    return cmd;
}
