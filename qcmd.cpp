#include "qcmd.h"
//--------------------------
QCmd::QCmd(QWidget* parent):
    QComboBox(parent)
{
    m_cmd.insert(tr("0x00"), qMakePair(tr("Чтение дискретных каналов входов"), 4));
    m_cmd.insert(tr("0x01"), qMakePair(tr("Чтение дискретных каналов выходов"), 2));
    m_cmd.insert(tr("0x02"), qMakePair(tr("Чтение расчетных величин 1..4 формата FLOAT"), 17));
    m_cmd.insert(tr("0x03"), qMakePair(tr("Чтение регистра расширения дискретных каналов входов"), 4));
    m_cmd.insert(tr("0x04"), qMakePair(tr("Чтение регистра расширения дискретных каналов выходов"), 4));
    m_cmd.insert(tr("0x05"), qMakePair(tr("запись регистра расширения дискретных каналов выходов"), 2));
    m_cmd.insert(tr("0x06"), qMakePair(tr("Установка на дискретном выходе 0 значения \"0\""), 2));
    m_cmd.insert(tr("0x07"), qMakePair(tr("Установка на дискретном выходе 1 значения \"0\""), 2));
    m_cmd.insert(tr("0x08"), qMakePair(tr("Установка на дискретном выходе 2 значения \"0\""), 2));
    m_cmd.insert(tr("0x09"), qMakePair(tr("Установка на дискретном выходе 3 значения \"0\""), 2));
    m_cmd.insert(tr("0x0A"), qMakePair(tr("Установка на дискретном выходе 4 значения \"0\""), 2));
    m_cmd.insert(tr("0x0B"), qMakePair(tr("Установка на дискретном выходе 5 значения \"0\""), 2));
    m_cmd.insert(tr("0x0C"), qMakePair(tr("Установка на дискретном выходе 6 значения \"0\""), 2));
    m_cmd.insert(tr("0x0D"), qMakePair(tr("Установка на дискретном выходе 7 значения \"0\""), 2));
    m_cmd.insert(tr("0x0E"), qMakePair(tr("Установка на дискретном выходе 0 значения \"1\""), 2));
    m_cmd.insert(tr("0x0F"), qMakePair(tr("Установка на дискретном выходе 1 значения \"1\""), 2));
    m_cmd.insert(tr("0x10"), qMakePair(tr("Установка на дискретном выходе 2 значения \"1\""), 2));
    m_cmd.insert(tr("0x11"), qMakePair(tr("Установка на дискретном выходе 3 значения \"1\""), 2));
    m_cmd.insert(tr("0x12"), qMakePair(tr("Установка на дискретном выходе 4 значения \"1\""), 2));
    m_cmd.insert(tr("0x13"), qMakePair(tr("Установка на дискретном выходе 5 значения \"1\""), 2));
    m_cmd.insert(tr("0x14"), qMakePair(tr("Установка на дискретном выходе 6 значения \"1\""), 2));
    m_cmd.insert(tr("0x15"), qMakePair(tr("Установка на дискретном выходе 7 значения \"1\""), 2));
    m_cmd.insert(tr("0x16"), qMakePair(tr("Чтение корфигурации"), 10));
    m_cmd.insert(tr("0x17"), qMakePair(tr("Запись конфигурации"), 2));
    m_cmd.insert(tr("0x18"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x19"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x1A"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x1B"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x1C"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x1D"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x1E"), qMakePair(tr("Чтение ID"), 9));
    m_cmd.insert(tr("0x1F"), qMakePair(tr("Чтение времени срабатывания выделенного входного дискретного канала"), 4));
    m_cmd.insert(tr("0x20"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x21"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x22"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x23"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x24"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x25"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x26"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x27"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x28"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x29"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x2A"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x2B"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x2C"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x2D"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x2E"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x2F"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x30"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x31"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x32"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x33"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x34"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x35"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x36"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x37"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x38"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x39"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x3A"), qMakePair(tr("Резерв"), 0));
    m_cmd.insert(tr("0x3B"), qMakePair(tr("Чтение из памяти"), 2));
    m_cmd.insert(tr("0x3C"), qMakePair(tr("Запись в память"), 2));
    m_cmd.insert(tr("0x3D"), qMakePair(tr("Чтение ошибок"), 7));
    m_cmd.insert(tr("0x3E"), qMakePair(tr("Установка общих настроек фильтра"), 2));
    m_cmd.insert(tr("0x3F"), qMakePair(tr("Установка настроек входа"), 2));

    foreach(QString cmd, m_cmd.keys())
    {
        this->addItem(cmd);
    }

    connect(this, SIGNAL(activated(int)), this, SLOT(slotActivated(int)));
}
//----------------------------------------
QString QCmd::description(int index) const
{
    return m_cmd.value(this->itemText(index)).first;
}
//-----------------------------------------
quint8 QCmd::size(const QString& cmd) const
{
    quint8 s = m_cmd.value(cmd).second;
    return s;
}
//---------------------------------
void QCmd::slotActivated(int index)
{
    emit changeDescription(m_cmd.value(this->itemText(index)).first);
}
