#include "cbzuinterface.h"
#include "ui_bzuinterface.h"
//--------------------------------------------
CBZUInterface::CBZUInterface(QWidget* parent):
    QWidget(parent),
    ui(new Ui::CBZUInterface)
{
    ui->setupUi(this);

    m_keyboard.append(ui->key_1);
    m_keyboard.append(ui->key_7);
    m_keyboard.append(ui->key_2);
    m_keyboard.append(ui->key_8);
    m_keyboard.append(ui->key_3);
    m_keyboard.append(ui->key_9);
    m_keyboard.append(ui->key_on);
    m_keyboard.append(ui->key_up);
    m_keyboard.append(ui->key_ok);
    m_keyboard.append(ui->key_right);
    m_keyboard.append(ui->key_4);
    m_keyboard.append(ui->key_esc);
    m_keyboard.append(ui->key_5);
    m_keyboard.append(ui->key_0);
    m_keyboard.append(ui->key_6);
    m_keyboard.append(ui->key_point);
    m_keyboard.append(ui->key_off);
    m_keyboard.append(ui->key_left);
    m_keyboard.append(ui->key_down);
    m_keyboard.append(ui->key_reset);

    ui->led_11->setColor(QLed::LED_GREEN);

    m_led.append(ui->led_1);
    m_led.append(ui->led_2);
    m_led.append(ui->led_3);
    m_led.append(ui->led_4);
    m_led.append(ui->led_5);
    m_led.append(ui->led_6);
    m_led.append(ui->led_7);
    m_led.append(ui->led_8);
    m_led.append(ui->led_9);
    m_led.append(ui->led_10);
    m_led.append(ui->led_11);
    m_led.append(ui->led_12);

    setWindowTitle(tr("Интерфейс МИК-01"));
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    setFixedSize(this->width(), this->height());
}
//-----------------------------
CBZUInterface::~CBZUInterface()
{
    delete ui;
}
/*!
 * \brief CBZUInterface::setKeyboardKeyState
 * \param key
 * \param state
 */
void CBZUInterface::setKeyboardKeyState(int key, bool state)
{
    if(key < m_keyboard.count())
        m_keyboard[key]->setState(state);
}
//------------------------------------------------
void CBZUInterface::closeEvent(QCloseEvent* event)
{
    emit closed(false);

    for(QKey* key: m_keyboard)
        key->setState(false);

    for(QLed* led: m_led)
        led->setState(QLed::LED_OFF);

    QWidget::closeEvent(event);
}
