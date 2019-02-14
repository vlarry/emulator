#include "cinterfacemik.h"
#include "ui_cinterfacemik.h"
//--------------------------------------------
CInterfaceMIK::CInterfaceMIK(QWidget *parent):
    QFrame(parent),
    ui(new Ui::CInterfaceMIK),
    m_state_flash(QLed::LED_OFF)
{
    ui->setupUi(this);

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
