#include "qled.h"
//--------------------------
QLed::QLed(QWidget* parent):
    QToolButton(parent),
    m_state(LED_OFF),
    m_flash(false),
    m_color(LED_RED)
{
    setState(LED_OFF);
    connect(this, &QLed::clicked, this, &QLed::ledClick);
    connect(&m_timer, &QTimer::timeout, this, &QLed::timeout);
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
        icon = QIcon((m_color == LED_RED)?QPixmap(":/images/resource/images/led_red.png"):QPixmap(":/images/resource/images/led_green.png"));
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
        m_timer.stop();
        m_flash = false;
        state = LED_OFF;
    }
    else
    {
        state = ((m_state == LED_OFF)?LED_ON:LED_OFF);
    }

    setState(state);
}
//------------------
void QLed::timeout()
{
    LedState state = ((m_state == LED_OFF)?LED_ON:LED_OFF);
    setState(state);
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
    timeout();
    m_timer.start(250);
}
