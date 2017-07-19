#include "ciodevice.h"
//------------------------------------
CIODevice::CIODevice(QWidget* parent):
    QToolButton(parent),
    m_state(STATE_OFF),
    m_type(false)
{
    connect(this, SIGNAL(clicked(bool)), this, SLOT(slotState(bool)));
}
//---------------------------------
void CIODevice::set_type(bool type)
{
    m_type  = type;
}
//--------------------------------------
void CIODevice::set_state(state_t state)
{
    m_state = state;

    QString icon_on_path;
    QString icon_off_path;
    QString icon_err_path;

    this->setChecked(m_state);

    if(m_type)
    {
        icon_on_path  = ":/images/resource/images/lamp_active.png";
        icon_off_path = ":/images/resource/images/lamp_inactive.png";
        icon_err_path = "";
    }
    else
    {
        icon_on_path  = ":/images/resource/images/switch_on.png";
        icon_off_path = ":/images/resource/images/switch_off.png";
        icon_err_path = ":/images/resource/images/error.png";
    }

    switch(m_state)
    {
        case STATE_OFF:
            this->setIcon(QIcon(icon_off_path));
        break;

        case STATE_ON:
            this->setIcon(QIcon(icon_on_path));
        break;

        case STATE_ERR:
            this->setIcon(QIcon(icon_err_path));
        break;
    }
}
//-----------------------------------
void CIODevice::slotState(bool state)
{
    // изменение состояния - только для выходов
    if(m_type)
    {
        state_t st = (state)?STATE_ON:STATE_OFF;
        set_state(st);
    }
}
