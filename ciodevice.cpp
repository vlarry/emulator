#include "ciodevice.h"
//------------------------------------
CIODevice::CIODevice(QWidget* parent):
    QToolButton(parent),
    m_state(STATE_OFF),
    m_type(false),
    m_id(255),
    m_dev_addr(0)
{
    connect(this, SIGNAL(clicked(bool)), this, SLOT(slotState(bool)));
}
//---------------------------------
void CIODevice::set_type(bool type)
{
    m_type = type;
}
//--------------------------------------
void CIODevice::set_state(state_t state)
{
    m_state = state;

    QString icon_on_path;
    QString icon_off_path;
    QString icon_alt_path;
    QString icon_err_path;

    this->setChecked(m_state);

    if(m_type)
    {
        icon_on_path  = ":/images/resource/images/lamp_active.png";
        icon_off_path = ":/images/resource/images/lamp_inactive.png";
        icon_alt_path = ":/images/resource/images/lamp_alt.png";
        icon_err_path = "";
    }
    else
    {
        icon_on_path  = ":/images/resource/images/switch_on.png";
        icon_off_path = ":/images/resource/images/switch_off.png";
        icon_alt_path = "";
        icon_err_path = ":/images/resource/images/error.png";
    }

    switch(m_state)
    {
        case STATE_OFF:
            this->setIcon(QIcon(icon_off_path));
            this->setToolTip(tr("OFF"));
        break;

        case STATE_ON:
            this->setIcon(QIcon(icon_on_path));
            this->setToolTip(tr("ON"));
        break;

        case STATE_ALT:
            this->setIcon(QIcon(icon_alt_path));
            this->setToolTip(tr("ON ALT"));
        break;

        case STATE_ERR:
            this->setIcon(QIcon(icon_err_path));
            this->setToolTip(tr("ERROR"));
        break;
    }
}
//-------------------------------
void CIODevice::set_id(quint8 id)
{
    m_id = id;
}
//---------------------------------------
void CIODevice::set_dev_addr(quint8 addr)
{
    m_dev_addr = addr;
}
//--------------------------------
quint8 CIODevice::get_addr() const
{
    return m_dev_addr;
}
//------------------------------
quint8 CIODevice::get_id() const
{
    return m_id;
}
//---------------------------------------------
CIODevice::state_t CIODevice::get_state() const
{
    return m_state;
}
//-----------------------------------
void CIODevice::slotState(bool state)
{
    // изменение состояния - только для выходов
    if(m_type)
    {
        if(m_state == STATE_ON)
        {
            if(m_dev_addr == 2)
            {
                m_state = STATE_ALT;
            }
            else
                m_state = STATE_OFF;
        }
        else if(m_state == STATE_OFF)
        {
            m_state = STATE_ON;
        }
        else if(m_state == STATE_ALT)
        {
            m_state = STATE_OFF;
        }

        set_state(m_state);

        emit stateChanged(m_id, state);
    }
}
