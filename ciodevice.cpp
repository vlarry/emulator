#include "ciodevice.h"
//------------------------------------
CIODevice::CIODevice(QWidget* parent):
    QToolButton(parent),
    m_state(false),
    m_type(false)
{
    connect(this, SIGNAL(clicked(bool)), this, SLOT(slotState(bool)));
}
//---------------------------------
void CIODevice::set_type(bool type)
{
    m_type  = type;
}
//-----------------------------------
void CIODevice::set_state(bool state)
{
    m_state = state;

    QString icon_on_path;
    QString icon_off_path;

    this->setChecked(m_state);

    if(m_type)
    {
        icon_on_path = ":/images/resource/images/lamp_active.png";
        icon_off_path = ":/images/resource/images/lamp_inactive.png";
    }
    else
    {
        icon_on_path = ":/images/resource/images/switch_on.png";
        icon_off_path = ":/images/resource/images/switch_off.png";
    }

    this->setIcon((m_state)?QIcon(icon_on_path):QIcon(icon_off_path));
}
//-----------------------------------
void CIODevice::slotState(bool state)
{
    // изменение состояния - только для выходов
    if(m_type)
    {
        set_state(state);
    }
}
