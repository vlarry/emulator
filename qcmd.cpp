#include "qcmd.h"
//--------------------------
QCmd::QCmd(QWidget* parent):
    QComboBox(parent)
{
    this->addItem(tr("0x00"), tr("Reading discrete input channels"));
    this->addItem(tr("0x01"), tr("Reading discrete output channels"));
    this->addItem(tr("0x02"), tr("Reading FLOAT format calculated values 1..4"));
    this->addItem(tr("0x03"), tr("Reading of the register for the expansion of discrete input channels"));
    this->addItem(tr("0x04"), tr("Reading of the register for the expansion of discrete output channels"));
    this->addItem(tr("0x05"), tr("Record of the register of expansion of discrete output channels"));
    this->addItem(tr("0x06"), tr("Setting on the digital output 0 value 0"));
    this->addItem(tr("0x07"), tr("Setting on the digital output 1 value 0"));
    this->addItem(tr("0x08"), tr("Setting on the digital output 2 value 0"));
    this->addItem(tr("0x09"), tr("Setting on the digital output 3 value 0"));
    this->addItem(tr("0x0A"), tr("Setting on the digital output 4 value 0"));
    this->addItem(tr("0x0B"), tr("Setting on the digital output 5 value 0"));
    this->addItem(tr("0x0C"), tr("Setting on the digital output 6 value 0"));
    this->addItem(tr("0x0D"), tr("Setting on the digital output 7 value 0"));
    this->addItem(tr("0x0E"), tr("Setting on the digital output 0 value 1"));
    this->addItem(tr("0x0F"), tr("Setting on the digital output 1 value 1"));
    this->addItem(tr("0x10"), tr("Setting on the digital output 2 value 1"));
    this->addItem(tr("0x11"), tr("Setting on the digital output 3 value 1"));
    this->addItem(tr("0x12"), tr("Setting on the digital output 4 value 1"));
    this->addItem(tr("0x13"), tr("Setting on the digital output 5 value 1"));
    this->addItem(tr("0x14"), tr("Setting on the digital output 6 value 1"));
    this->addItem(tr("0x15"), tr("Setting on the digital output 7 value 1"));
    this->addItem(tr("0x16"), tr("Read configuration"));
    this->addItem(tr("0x17"), tr("Save configuration"));
    this->addItem(tr("0x18"), tr("Reserve"));
    this->addItem(tr("0x19"), tr("Reserve"));
    this->addItem(tr("0x1A"), tr("Reserve"));
    this->addItem(tr("0x1B"), tr("Reserve"));
    this->addItem(tr("0x1C"), tr("Reserve"));
    this->addItem(tr("0x1D"), tr("Reserve"));
    this->addItem(tr("0x1E"), tr("Read ID"));
    this->addItem(tr("0x1F"), tr("Reading of the response time of the dedicated input discrete channel"));
    this->addItem(tr("0x20"), tr("Reserve"));
    this->addItem(tr("0x21"), tr("Reserve"));
    this->addItem(tr("0x22"), tr("Reserve"));
    this->addItem(tr("0x23"), tr("Reserve"));
    this->addItem(tr("0x24"), tr("Reserve"));
    this->addItem(tr("0x25"), tr("Reserve"));
    this->addItem(tr("0x26"), tr("Reserve"));
    this->addItem(tr("0x27"), tr("Reserve"));
    this->addItem(tr("0x28"), tr("Reserve"));
    this->addItem(tr("0x29"), tr("Reserve"));
    this->addItem(tr("0x2A"), tr("Reserve"));
    this->addItem(tr("0x2B"), tr("Reserve"));
    this->addItem(tr("0x2C"), tr("Reserve"));
    this->addItem(tr("0x2D"), tr("Reserve"));
    this->addItem(tr("0x2E"), tr("Reserve"));
    this->addItem(tr("0x2F"), tr("Reserve"));
    this->addItem(tr("0x30"), tr("Reserve"));
    this->addItem(tr("0x31"), tr("Reserve"));
    this->addItem(tr("0x32"), tr("Reserve"));
    this->addItem(tr("0x33"), tr("Reserve"));
    this->addItem(tr("0x34"), tr("Reserve"));
    this->addItem(tr("0x35"), tr("Reserve"));
    this->addItem(tr("0x36"), tr("Reserve"));
    this->addItem(tr("0x37"), tr("Reserve"));
    this->addItem(tr("0x38"), tr("Reserve"));
    this->addItem(tr("0x39"), tr("Reserve"));
    this->addItem(tr("0x3A"), tr("Reserve"));
    this->addItem(tr("0x3B"), tr("Reserve"));
    this->addItem(tr("0x3C"), tr("Reserve"));
    this->addItem(tr("0x3D"), tr("Reserve"));
    this->addItem(tr("0x3E"), tr("Reserve"));
    this->addItem(tr("0x3F"), tr("Reserve"));

    connect(this, SIGNAL(activated(int)), this, SLOT(slotActivated(int)));
}
//---------------------------------
void QCmd::slotActivated(int index)
{
    emit changeDescription(this->itemData(index).toString());
}
