#include "qkey.h"
//--------------------------
QKey::QKey(QWidget* parent):
    QToolButton(parent),
    m_state(false)
{
    changeState(m_state);
}
//--------------------------------
void QKey::changeState(bool state)
{
    m_state = state;

    QString color_str = (m_state)?tr("QToolButton { background: green }"):tr("QToolButton { background: gray; }");

    this->setStyleSheet(color_str);
}
