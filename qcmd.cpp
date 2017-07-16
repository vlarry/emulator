#include "qcmd.h"
//--------------------------
QCmd::QCmd(QWidget* parent):
    QComboBox(parent)
{
    m_cmd.insert(tr("0x00"), qMakePair(tr("Reading discrete input channels"), 4));
    m_cmd.insert(tr("0x01"), qMakePair(tr("Reading discrete output channels"), 2));
    m_cmd.insert(tr("0x02"), qMakePair(tr("Reading FLOAT format calculated values 1..4"), 17));
    m_cmd.insert(tr("0x03"), qMakePair(tr("Reading of the register for the expansion of discrete input channels"), 4));
    m_cmd.insert(tr("0x04"), qMakePair(tr("Reading of the register for the expansion of discrete output channels"), 4));
    m_cmd.insert(tr("0x05"), qMakePair(tr("Record of the register of expansion of discrete output channels"), 2));
    m_cmd.insert(tr("0x06"), qMakePair(tr("Setting on the digital output 0 value 0"), 2));
    m_cmd.insert(tr("0x07"), qMakePair(tr("Setting on the digital output 1 value 0"), 2));
    m_cmd.insert(tr("0x08"), qMakePair(tr("Setting on the digital output 2 value 0"), 2));
    m_cmd.insert(tr("0x09"), qMakePair(tr("Setting on the digital output 3 value 0"), 2));
    m_cmd.insert(tr("0x0A"), qMakePair(tr("Setting on the digital output 4 value 0"), 2));
    m_cmd.insert(tr("0x0B"), qMakePair(tr("Setting on the digital output 5 value 0"), 2));
    m_cmd.insert(tr("0x0C"), qMakePair(tr("Setting on the digital output 6 value 0"), 2));
    m_cmd.insert(tr("0x0D"), qMakePair(tr("Setting on the digital output 7 value 0"), 2));
    m_cmd.insert(tr("0x0E"), qMakePair(tr("Setting on the digital output 0 value 1"), 2));
    m_cmd.insert(tr("0x0F"), qMakePair(tr("Setting on the digital output 1 value 1"), 2));
    m_cmd.insert(tr("0x10"), qMakePair(tr("Setting on the digital output 2 value 1"), 2));
    m_cmd.insert(tr("0x11"), qMakePair(tr("Setting on the digital output 3 value 1"), 2));
    m_cmd.insert(tr("0x12"), qMakePair(tr("Setting on the digital output 4 value 1"), 2));
    m_cmd.insert(tr("0x13"), qMakePair(tr("Setting on the digital output 5 value 1"), 2));
    m_cmd.insert(tr("0x14"), qMakePair(tr("Setting on the digital output 6 value 1"), 2));
    m_cmd.insert(tr("0x15"), qMakePair(tr("Setting on the digital output 7 value 1"), 2));
    m_cmd.insert(tr("0x16"), qMakePair(tr("Read configuration"), 10));
    m_cmd.insert(tr("0x17"), qMakePair(tr("Save configuration"), 2));
    m_cmd.insert(tr("0x18"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x19"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x1A"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x1B"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x1C"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x1D"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x1E"), qMakePair(tr("Read ID"), 5));
    m_cmd.insert(tr("0x1F"), qMakePair(tr("Reading of the response time of the dedicated input discrete channel"), 4));
    m_cmd.insert(tr("0x20"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x21"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x22"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x23"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x24"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x25"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x26"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x27"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x28"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x29"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x2A"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x2B"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x2C"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x2D"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x2E"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x2F"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x30"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x31"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x32"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x33"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x34"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x35"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x36"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x37"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x38"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x39"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x3A"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x3B"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x3C"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x3D"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x3E"), qMakePair(tr("Reserve"), 0));
    m_cmd.insert(tr("0x3F"), qMakePair(tr("Reserve"), 0));

    foreach(QString cmd, m_cmd.keys())
    {
        this->addItem(cmd);
    }

    connect(this, SIGNAL(activated(int)), this, SLOT(slotActivated(int)));
}
//---------------------------------
void QCmd::slotActivated(int index)
{
    emit changeDescription(m_cmd.value(this->itemText(index)).first);
}
