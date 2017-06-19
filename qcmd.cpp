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
//------------------------------------
QCmd::QCmd(QString code, int address):
    m_code(code),
    m_address(address)
{
    code.remove(QRegExp("0x"));
    int num = code.toInt(Q_NULLPTR, 16);
    QByteArray hex = QString::number(num, 16).toStdString().c_str();
    uint8_t cmd = (uint8_t)hex.at(0);

    cmd |= address << 6;

    qDebug() << cmd;
}
