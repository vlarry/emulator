#include "qkeyboard.h"
#include "ui_keyboard.h"
//----------------------------------------
QKeyboard::QKeyboard(QMainWindow* parent):
    QWidget(parent),
    ui(new Ui::QKeyboard)
{
    ui->setupUi(this);

    m_keys.append(ui->key_1);
    m_keys.append(ui->key_7);
    m_keys.append(ui->key_2);
    m_keys.append(ui->key_8);
    m_keys.append(ui->key_3);
    m_keys.append(ui->key_9);
    m_keys.append(ui->key_on);
    m_keys.append(ui->key_up);
    m_keys.append(ui->key_ok);
    m_keys.append(ui->key_right);
    m_keys.append(ui->key_4);
    m_keys.append(ui->key_esc);
    m_keys.append(ui->key_5);
    m_keys.append(ui->key_0);
    m_keys.append(ui->key_6);
    m_keys.append(ui->key_point);
    m_keys.append(ui->key_off);
    m_keys.append(ui->key_left);
    m_keys.append(ui->key_down);
    m_keys.append(ui->key_reset);

    this->setWindowTitle(tr("Клавиатура"));

    setGeometry((parent->x() + parent->width()) - this->width(), (parent->y() + parent->height()) - this->height(), this->width(), this->height());
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    setFixedSize(this->width(), this->height());
}
//---------------------
QKeyboard::~QKeyboard()
{
    delete ui;
}
//--------------------------------------------------
void QKeyboard::setStateKey(int channel, bool state)
{
    if(channel < m_keys.count())
    {
        m_keys.at(channel)->setState(state);
    }
}
//------------------------------
int QKeyboard::key_count() const
{
    return m_keys.count();
}
//--------------------------------------------
void QKeyboard::closeEvent(QCloseEvent* event)
{
    emit closeKeyboard(false);

    QWidget::closeEvent(event);
}
