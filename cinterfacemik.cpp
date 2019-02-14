#include "cinterfacemik.h"
#include "ui_cinterfacemik.h"
//--------------------------------------------
CInterfaceMIK::CInterfaceMIK(QWidget *parent):
    QFrame(parent),
    ui(new Ui::CInterfaceMIK),
    m_state_flash(QLed::LED_OFF)
{
    ui->setupUi(this);
    init();

    connect(&m_timer_flash, &QTimer::timeout, this, &CInterfaceMIK::timeoutLedFlash);
}
//-----------------------------
CInterfaceMIK::~CInterfaceMIK()
{
    delete ui;
}
//----------------------------
void CInterfaceMIK::ledReset()
{
    for(QLed* led: m_led)
        led->reset();
}
//-----------------------------------
QByteArray CInterfaceMIK::ledStates()
{
    QByteArray data;
    quint8 channel = 0x00;

    for(quint8 i = 0, bits = 0; i < m_led.count(); i++)
    {
        if(bits == 8)
        {
            data.append(QByteArray::fromHex(QByteArray::number(channel, 16)));
            channel = 0x00;
            bits = 0;
        }

        channel |= (static_cast<quint8>(m_led[i]->state()) << bits);

        bits += 2;
    }

    data.append(QByteArray::fromHex(QByteArray::number(channel, 16)));

    return data;
}
/*!
 * \brief CInterfaceMIK::setKeyboardKeyState
 * \param key
 * \param state
 */
void CInterfaceMIK::setKeyboardState(const QByteArray& keyboards)
{
    for(quint8 i = 0; i < 3; ++i)
    {
        quint8 byte = static_cast<quint8>(keyboards[i]);

        for(quint8 j = 0; j < 8; ++j)
        {
            quint8 keys = byte;

            keys >>= j;

            quint8 key_state = keys&0x01;
            quint8 key_num   = j + (i*8);

            if(key_num < m_keyboard.count())
                m_keyboard[key_num]->setState(key_state);
            else
                return;
        }
    }
}
//-----------------------------------------------------
void CInterfaceMIK::setLedState(const QByteArray& leds)
{
    ledReset();

    for(quint8 i = 0; i < 3; i++)
    {
        quint8 byte = static_cast<quint8>(leds[i]);

        for(quint8 bit_pos = 0; bit_pos < 8; bit_pos += 2)
        {
            quint8 mask = static_cast<quint8>(0x03 << bit_pos);
            QLed::LedState led_state = static_cast<QLed::LedState>(((byte & mask) >> bit_pos));
            quint8 led_num = bit_pos/2 + i*4;

            switch(led_state)
            {
                case QLed::LED_OFF:
                case QLed::LED_ON:
                    m_led[led_num]->setState(led_state);
                break;

                case QLed::LED_FLASH:
                case QLed::LED_RESERVE:
                    m_led[led_num]->setLedModeFlash();
                break;
            }
        }
    }
}
//-----------------------------------
void CInterfaceMIK::timeoutLedFlash()
{
    m_state_flash = (m_state_flash == QLed::LED_OFF)?QLed::LED_ON:QLed::LED_OFF;

    for(QLed* led: m_led)
    {
        if(led->stateFlash())
        {
            led->setState(m_state_flash);
        }
    }
}
//------------------------------------------------
void CInterfaceMIK::closeEvent(QCloseEvent* event)
{
    emit closed(false);

    for(QKey* key: m_keyboard)
        key->setState(false);

    m_timer_flash.stop();
    ledReset();

    QWidget::closeEvent(event);
}
//----------------------------------------------
void CInterfaceMIK::showEvent(QShowEvent* event)
{
    m_timer_flash.start(1000);
    QWidget::showEvent(event);
}
//------------------------
void CInterfaceMIK::init()
{
    QKey *key_0     = new QKey(this);
    QKey *key_1     = new QKey(this);
    QKey *key_2     = new QKey(this);
    QKey *key_3     = new QKey(this);
    QKey *key_4     = new QKey(this);
    QKey *key_5     = new QKey(this);
    QKey *key_6     = new QKey(this);
    QKey *key_7     = new QKey(this);
    QKey *key_8     = new QKey(this);
    QKey *key_9     = new QKey(this);
    QKey *key_esc   = new QKey(this);
    QKey *key_dp    = new QKey(this);
    QKey *key_up    = new QKey(this);
    QKey *key_left  = new QKey(this);
    QKey *key_ok    = new QKey(this);
    QKey *key_right = new QKey(this);
    QKey *key_down  = new QKey(this);
    QKey *key_off   = new QKey(this);
    QKey *key_on    = new QKey(this);
    QKey *key_reset = new QKey(this);

    QLed *led_1          = new QLed(this);
    QLed *led_2          = new QLed(this);
    QLed *led_3          = new QLed(this);
    QLed *led_4          = new QLed(this);
    QLed *led_5          = new QLed(this);
    QLed *led_6          = new QLed(this);
    QLed *led_7          = new QLed(this);
    QLed *led_8          = new QLed(this);
    QLed *led_protection = new QLed(this);
    QLed *led_block      = new QLed(this);
    QLed *led_off        = new QLed(this);
    QLed *led_on         = new QLed(this);

    key_0->setIcon(QIcon(QPixmap(":/images/resource/images/key_0.png")));
    key_1->setIcon(QIcon(QPixmap(":/images/resource/images/key_1.png")));
    key_2->setIcon(QIcon(QPixmap(":/images/resource/images/key_2.png")));
    key_3->setIcon(QIcon(QPixmap(":/images/resource/images/key_3.png")));
    key_4->setIcon(QIcon(QPixmap(":/images/resource/images/key_4.png")));
    key_5->setIcon(QIcon(QPixmap(":/images/resource/images/key_5.png")));
    key_6->setIcon(QIcon(QPixmap(":/images/resource/images/key_6.png")));
    key_7->setIcon(QIcon(QPixmap(":/images/resource/images/key_7.png")));
    key_8->setIcon(QIcon(QPixmap(":/images/resource/images/key_8.png")));
    key_9->setIcon(QIcon(QPixmap(":/images/resource/images/key_9.png")));
    key_esc->setIcon(QIcon(QPixmap(":/images/resource/images/key_esc.png")));
    key_dp->setIcon(QIcon(QPixmap(":/images/resource/images/key_dp.png")));
    key_up->setIcon(QIcon(QPixmap(":/images/resource/images/key_arrow_up.png")));
    key_left->setIcon(QIcon(QPixmap(":/images/resource/images/key_arrow_left.png")));
    key_right->setIcon(QIcon(QPixmap(":/images/resource/images/key_arrow_right.png")));
    key_down->setIcon(QIcon(QPixmap(":/images/resource/images/key_arrow_down.png")));
    key_ok->setIcon(QIcon(QPixmap(":/images/resource/images/key_ok.png")));
    key_off->setIcon(QIcon(QPixmap(":/images/resource/images/key_off.png")));
    key_on->setIcon(QIcon(QPixmap(":/images/resource/images/key_on.png")));
    key_reset->setIcon(QIcon(QPixmap(":/images/resource/images/key_reset.png")));

    key_0->setGeometry(377, 165, 39, 39);
    key_1->setGeometry(335, 123, 39, 39);
    key_2->setGeometry(377, 123, 39, 39);
    key_3->setGeometry(420, 123, 39, 39);
    key_4->setGeometry(335, 80, 39, 39);
    key_5->setGeometry(377, 80, 39, 39);
    key_6->setGeometry(420, 80, 39, 39);
    key_7->setGeometry(335, 38, 39, 39);
    key_8->setGeometry(377, 38, 39, 39);
    key_9->setGeometry(420, 38, 39, 39);
    key_esc->setGeometry(335, 165, 39, 39);
    key_dp->setGeometry(420, 165, 39, 39);
    key_up->setGeometry(377, 208, 39, 39);
    key_left->setGeometry(335, 250, 39, 39);
    key_right->setGeometry(420, 250, 39, 39);
    key_down->setGeometry(377, 292, 39, 39);
    key_ok->setGeometry(377, 250, 39, 39);
    key_off->setGeometry(502, 123, 39, 39);
    key_on->setGeometry(502, 208, 39, 39);
    key_reset->setGeometry(502, 292, 39, 39);

    key_0->setIconSize(QSize(39, 39));
    key_1->setIconSize(QSize(39, 39));
    key_2->setIconSize(QSize(39, 39));
    key_3->setIconSize(QSize(39, 39));
    key_4->setIconSize(QSize(39, 39));
    key_5->setIconSize(QSize(39, 39));
    key_6->setIconSize(QSize(39, 39));
    key_7->setIconSize(QSize(39, 39));
    key_8->setIconSize(QSize(39, 39));
    key_9->setIconSize(QSize(39, 39));
    key_esc->setIconSize(QSize(39, 39));
    key_dp->setIconSize(QSize(39, 39));
    key_up->setIconSize(QSize(39, 39));
    key_left->setIconSize(QSize(39, 39));
    key_right->setIconSize(QSize(39, 39));
    key_down->setIconSize(QSize(39, 39));
    key_ok->setIconSize(QSize(39, 39));
    key_off->setIconSize(QSize(39, 39));
    key_on->setIconSize(QSize(39, 39));
    key_reset->setIconSize(QSize(39, 39));

    led_1->setGeometry(14, 234, 16, 16);
    led_2->setGeometry(14, 262, 16, 16);
    led_3->setGeometry(14, 287, 16, 16);
    led_4->setGeometry(14, 313, 16, 16);
    led_5->setGeometry(14, 340, 16, 16);
    led_6->setGeometry(14, 366, 16, 16);
    led_7->setGeometry(14, 393, 16, 16);
    led_8->setGeometry(14, 419, 16, 16);
    led_protection->setGeometry(96, 16, 16, 16);
    led_block->setGeometry(188, 16, 16, 16);
    led_off->setGeometry(472, 136, 16, 16);
    led_on->setGeometry(472, 220, 16, 16);

    led_1->setIconSize(QSize(16, 16));
    led_2->setIconSize(QSize(16, 16));
    led_3->setIconSize(QSize(16, 16));
    led_4->setIconSize(QSize(16, 16));
    led_5->setIconSize(QSize(16, 16));
    led_6->setIconSize(QSize(16, 16));
    led_7->setIconSize(QSize(16, 16));
    led_8->setIconSize(QSize(16, 16));
    led_protection->setIconSize(QSize(16, 16));
    led_block->setIconSize(QSize(16, 16));
    led_off->setIconSize(QSize(16, 16));
    led_on->setIconSize(QSize(16, 16));

    m_keyboard.append(key_7);
    m_keyboard.append(key_1);
    m_keyboard.append(key_8);
    m_keyboard.append(key_2);
    m_keyboard.append(key_9);
    m_keyboard.append(key_3);
    m_keyboard.append(key_on);
    m_keyboard.append(key_up);
    m_keyboard.append(key_ok);
    m_keyboard.append(key_right);
    m_keyboard.append(key_4);
    m_keyboard.append(key_esc);
    m_keyboard.append(key_5);
    m_keyboard.append(key_0);
    m_keyboard.append(key_6);
    m_keyboard.append(key_dp);
    m_keyboard.append(key_off);
    m_keyboard.append(key_left);
    m_keyboard.append(key_down);
    m_keyboard.append(key_reset);

    led_1->setID(0);
    led_2->setID(1);
    led_3->setID(2);
    led_4->setID(3);
    led_5->setID(4);
    led_6->setID(5);
    led_7->setID(6);
    led_8->setID(7);
    led_protection->setID(8);
    led_block->setID(9);
    led_on->setID(10);
    led_off->setID(11);

    led_off->setColor(QLed::LED_GREEN);
    led_protection->setColor(QLed::LED_YELLOW);

    m_led.append(led_1);
    m_led.append(led_2);
    m_led.append(led_3);
    m_led.append(led_4);
    m_led.append(led_5);
    m_led.append(led_6);
    m_led.append(led_7);
    m_led.append(led_8);
    m_led.append(led_protection);
    m_led.append(led_block);
    m_led.append(led_off);
    m_led.append(led_on);
}
