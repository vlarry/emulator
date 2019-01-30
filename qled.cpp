#include "qled.h"
//--------------------------
QLed::QLed(QWidget* parent):
    QToolButton(parent),
    m_state(LED_OFF),
    m_flash(false),
    m_color(LED_RED),
    m_id(0)
{
    setState(LED_OFF);
    connect(this, &QLed::clicked, this, &QLed::ledClick);
}
//--------------------------------
QLed::LedState QLed::state() const
{
    LedState state = m_state;

    if(m_flash)
        state = LED_FLASH;

    return state;
}
//-------------------------------------------
void QLed::setColor(const LedColor led_color)
{
    m_color = led_color;
}
//---------------------------------
void QLed::setState(LedState state)
{
    QIcon icon;

    m_state = state;

    if(m_state == LED_ON)
    {
        icon = QIcon((m_color == LED_RED)?QPixmap(":/images/resource/images/led_red.png"):(m_color == LED_GREEN)?
                                          QPixmap(":/images/resource/images/led_green.png"):QPixmap(":/images/resource/images/led_yellow.png"));
    }
    else
    {
        icon = QIcon(QPixmap(":/images/resource/images/led_gray.png"));
    }

    setIcon(icon);
}
//-------------------
void QLed::ledClick()
{
    LedState state;

    if(m_flash)
    {
        m_flash = false;
        state = LED_OFF;
    }
    else
    {
        state = ((m_state == LED_OFF)?LED_ON:LED_OFF);
    }

    setState(state);
}
//---------------------------
bool QLed::stateFlash() const
{
    return m_flash;
}
//--------------------------------------------------
void QLed::mouseDoubleClickEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        if(!m_flash)
            setLedModeFlash();
    }
}
//--------------------------
void QLed::setLedModeFlash()
{
    m_flash = true;
}
//----------------
void QLed::reset()
{
    m_state = LED_OFF;
    m_flash = false;
    setState(m_state);
}
//-------------------------
void QLed::setID(quint8 id)
{
    m_id = id;
}
//---------------------
quint8 QLed::id() const
{
    return m_id;
}
