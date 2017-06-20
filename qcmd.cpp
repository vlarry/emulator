#include "qcmd.h"
//--------------
command_t init()
{
    command_t map;

    map.insert("0x00", cmd_t({ 2, 4, READ_DSIN, false }));
    map.insert("0x01", cmd_t({ 2, 2, READ_DSOUT, false }));
    map.insert("0x02", cmd_t({ 2, 17, READ_AIN, false }));
    map.insert("0x03", cmd_t({ 2, 4, READ_DSExIN, false }));

    return map;
}
//----------------------------------
command_t QCmdList::m_list = init();
//-----------------------------
QList<QString> QCmdList::list()
{
    return m_list.keys();
}
//-------------------------------------
cmd_t QCmdList::cmd(const QString& key)
{
    return m_list.value(key);
}
//---------------------------------------
QCmd::QCmd(QString code, quint8 address):
    m_code(code),
    m_address(address),
    m_bytes(0)
{
    quint8 cmd = (quint8)m_code.toInt();
    quint8 addr = m_address << 6;

    cmd |= addr;

    QString hex;
    hex.setNum(cmd, 16);

    m_data.append(hex.toUpper().toLocal8Bit().data());

    quint8 chsum = checksum(m_data, m_data.size());

    hex.setNum(chsum, 16);

    m_data.append(hex.toUpper().toLocal8Bit().data());

    qDebug() << "Checksum: " << hex.toUpper();
}
//----------------------------------------------------------
quint8 QCmd::checksum(QVector<QByteArray> data, size_t size)
{
    quint8 chsum = 0;

    for(quint8 i = 0; i < size; ++i)
    {
        chsum += (quint8)data.at(i).toInt(Q_NULLPTR, 16);
    }

    chsum += size;
    chsum ^= 0xFF;

    return chsum;
}
//---------------------------
const QByteArray QCmd::next()
{
    QByteArray ba;

    if(m_bytes != m_data.count())
        ba = m_data.at(m_bytes++);

    return ba;
}
//------------------------
size_t QCmd::bytes() const
{
    if(m_data.count() > 0 && m_data.count() != m_bytes - 1)
        return m_bytes;

    return -1;
}
