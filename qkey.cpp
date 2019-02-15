#include "qkey.h"
//--------------------------
QKey::QKey(QWidget* parent):
    QToolButton(parent),
    m_state(false)
{
    setState(m_state);
}
//-----------------------------
void QKey::setState(bool state)
{
    m_state = state;

    QString color_str = ((m_state)?"QToolButton { border: 3px solid red; }":"QToolButton { border: 0px; }");

    this->setStyleSheet(color_str);
}
