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

    QString color_str = ((m_state)?"QToolButton { background: green }":"QToolButton { background: gray; }");

    this->setStyleSheet(color_str);
}
