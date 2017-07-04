#include "ciodevice.h"
//------------------------------------
CIODevice::CIODevice(QWidget* parent):
    QToolButton(parent),
    m_state(false)
{
    this->setIcon((m_state)?QIcon(":/images/resource/images/lamp_active.png"):QIcon(":/images/resource/images/lamp_inactive.png"));
}
