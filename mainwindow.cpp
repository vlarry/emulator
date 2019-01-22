#include "mainwindow.h"
#include "ui_mainwindow.h"
//--------------------------------------
MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_port(Q_NULLPTR),
    m_lblMessage(Q_NULLPTR),
    m_query_count(0),
    m_timerAutoRepeatInput(Q_NULLPTR),
    m_timerAutoRepeatAIN(Q_NULLPTR),
    m_timerTimeoutQuery(Q_NULLPTR),
    m_timerRefreshPort(Q_NULLPTR),
    m_file_ain(Q_NULLPTR),
    m_block_send(false),
    m_keyboard(Q_NULLPTR),
    m_command(Q_NULLPTR),
    m_set_intput_widget(Q_NULLPTR)
{
    ui->setupUi(this);

    QPalette p = ui->pteConsole->palette();

    p.setColor(QPalette::Base, QColor(Qt::black));
    p.setColor(QPalette::Text, QColor(Qt::green));

    ui->pteConsole->setPalette(p);

    m_lblMessage = new QLabel(ui->statusBar);
    ui->statusBar->addWidget(m_lblMessage);

    m_settings = new QSettings("settings.cnf", QSettings::IniFormat);

    m_timerAutoRepeatInput = new QTimer(this);
    m_timerAutoRepeatAIN   = new QTimer(this);
    m_timerTimeoutQuery    = new QTimer(this);
    m_timerRefreshPort     = new QTimer(this);
    m_conf_widget          = new CConfigurationModuleWidget(this);
    m_file_ain             = new QFile;
    m_set_intput_widget    = new CSetInput(this);

    m_conf_widget->hide();
    m_set_intput_widget->hide();
}
//-----------------------
MainWindow::~MainWindow()
{
    if(m_file_ain->isOpen())
        m_file_ain->close();

    delete ui;
}
//----------------------------
void MainWindow::initConnect()
{
    connect(ui->tbPortRefresh, SIGNAL(clicked()), this, SLOT(refreshSerialPort()));
    connect(m_timerRefreshPort, SIGNAL(timeout()), this, SLOT(refreshSerialPort()));
    connect(ui->pbCtrlPort, SIGNAL(clicked(bool)), this, SLOT(ctrlSerialPort(bool)));
    connect(m_port, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(ui->pbCmdSend, SIGNAL(clicked()), this, SLOT(sendCmd()));
    connect(m_port, SIGNAL(bytesWritten(qint64)), this, SLOT(BytesWriten(qint64)));
    connect(ui->cbCmdList, SIGNAL(changeDescription(QString)), this, SLOT(cmdDescription(QString)));
    connect(ui->sbDeviceAddress, SIGNAL(valueChanged(int)), SLOT(addrChanged(int)));

    connect(m_output_dev.at(0), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(1), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(2), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(3), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(4), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(5), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(6), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(7), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(8), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(9), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(10), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));
    connect(m_output_dev.at(11), SIGNAL(stateChanged(quint8, bool)), this, SLOT(outputStateChanged(quint8, bool)));

    connect(ui->cbCmdList, SIGNAL(currentTextChanged(const QString&)), this, SLOT(initFilter(const QString&)));

    connect(ui->cboxRepeatInputs, SIGNAL(clicked(bool)), this, SLOT(autoRepeatInputs(bool)));
    connect(ui->cboxRepeatAIN, SIGNAL(clicked(bool)), this, SLOT(autoRepeatAIN(bool)));
    connect(m_timerAutoRepeatInput, SIGNAL(timeout()), this, SLOT(autoRepeatTimInputs()));
    connect(m_timerAutoRepeatAIN, SIGNAL(timeout()), this, SLOT(autoRepeatTimAIN()));
    connect(m_timerTimeoutQuery, SIGNAL(timeout()), this, SLOT(timeoutTim()));

    connect(ui->dwTerminal, SIGNAL(visibilityChanged(bool)), this, SLOT(visiblityTerminal(bool)));
    connect(ui->cboxTerminal, SIGNAL(toggled(bool)), this, SLOT(visiblityTerminal(bool)));
    connect(ui->cbKeyboard, SIGNAL(toggled(bool)), this, SLOT(visiblityKeyboard(bool)));
    connect(ui->cbCommand, SIGNAL(toggled(bool)), this, SLOT(visiblityCommand(bool)));
    connect(m_command, &QCommand::doubleClickCmd, this, &MainWindow::sendCmd);
    connect(m_command, &QCommand::clickCmd, this, &MainWindow::initFilter);

    connect(ui->checkBoxSerialConfig, &QCheckBox::clicked, this, &MainWindow::configWindowVisiblity);
    connect(ui->pushButtonInputSet, &QPushButton::clicked, this, &MainWindow::setupDiscretInput);
}
//-------------------------------
void MainWindow::initSerialPort()
{
    m_port = new QSerialPort(this);

    QStringList baudrate_list = QStringList() << "1200" << "2400" << "4800" << "9600" << "14400" << "19200" << "28800" <<
                                                 "38400" << "57600" << "115200" << "230400" << "460800" << "921600";

    ui->cbBaudrate->addItems(baudrate_list);
    ui->cbBaudrate->setCurrentIndex(9);
}
//-----------------------
void MainWindow::initIO()
{
    ui->IN1->set_id(0);
    ui->IN2->set_id(1);
    ui->IN3->set_id(2);
    ui->IN4->set_id(3);
    ui->IN5->set_id(4);
    ui->IN6->set_id(5);
    ui->IN7->set_id(6);
    ui->IN8->set_id(7);
    ui->IN9->set_id(8);
    ui->IN10->set_id(9);
    ui->IN11->set_id(10);
    ui->IN12->set_id(11);

    ui->OUT1->set_id(0);
    ui->OUT2->set_id(1);
    ui->OUT3->set_id(2);
    ui->OUT4->set_id(3);
    ui->OUT5->set_id(4);
    ui->OUT6->set_id(5);
    ui->OUT7->set_id(6);
    ui->OUT8->set_id(7);
    ui->OUT9->set_id(8);
    ui->OUT10->set_id(9);
    ui->OUT11->set_id(10);
    ui->OUT12->set_id(11);

    m_input_dev.append(ui->IN1);
    m_input_dev.append(ui->IN2);
    m_input_dev.append(ui->IN3);
    m_input_dev.append(ui->IN4);
    m_input_dev.append(ui->IN5);
    m_input_dev.append(ui->IN6);
    m_input_dev.append(ui->IN7);
    m_input_dev.append(ui->IN8);
    m_input_dev.append(ui->IN9);
    m_input_dev.append(ui->IN10);
    m_input_dev.append(ui->IN11);
    m_input_dev.append(ui->IN12);

    m_output_dev.append(ui->OUT1);
    m_output_dev.append(ui->OUT2);
    m_output_dev.append(ui->OUT3);
    m_output_dev.append(ui->OUT4);
    m_output_dev.append(ui->OUT5);
    m_output_dev.append(ui->OUT6);
    m_output_dev.append(ui->OUT7);
    m_output_dev.append(ui->OUT8);
    m_output_dev.append(ui->OUT9);
    m_output_dev.append(ui->OUT10);
    m_output_dev.append(ui->OUT11);
    m_output_dev.append(ui->OUT12);

    setIO(m_input_dev, false);
    setIO(m_output_dev, true);

    m_ain_dev.append(ui->leAIN1);
    m_ain_dev.append(ui->leAIN2);
    m_ain_dev.append(ui->leAIN3);
    m_ain_dev.append(ui->leAIN4);
}
//------------------------------------------------------------------
void MainWindow::setIO(const QVector<CIODevice*>& io_dev, bool type)
{
    for(CIODevice* io: io_dev)
    {
        if(type)
            io->set_type(true);
        else
            io->set_type(false);

        io->set_state(CIODevice::STATE_OFF);
    }
}
//--------------------------------------------------
void MainWindow::showMessage(const QString& message)
{
    m_lblMessage->setText(message);
}
//---------------------------------------------------------------------
quint8 MainWindow::getChecksum(const QByteArray& ba, const quint8 size)
{
    quint8 check_sum = 0;

    check_sum += size;

    for(quint8 i = 0; i < size; ++i)
    {
        check_sum += ba.at(i);
    }

    check_sum ^= 0xFF;

    return check_sum;
}
//-------------------------------------------------------------------
void MainWindow::cmdParser(const QByteArray& data, const quint8 size)
{
    if(data.isEmpty())
        return;

    quint8 cmd  = static_cast<quint8>(QString(m_cmd_last).remove(QRegExp("0x")).toInt(Q_NULLPTR, 16));

    Float_t ain;
    QTextStream in(m_file_ain);
    int tdata = 0;

    QString s;

    union
    {
        quint16 data;
        quint8  byte[2];
    } temp;

    temp.data = 0;

    switch(cmd)
    {
        case 0x00:
            if(ui->sbDeviceAddress->value() != MIK_01)
            {
                for(quint8 i = 0; i < size; ++i)
                {
                    quint8 byte = static_cast<quint8>(data.at(i));

                    for(quint8 j = 0; j < 8; j += 2)
                    {
                        quint8 channels = byte;

                        channels >>= j;

                        quint8 ch_state = channels & 0x03;
                        quint8 ch_num   = j/2 + (i*4);

                        CIODevice* io = m_input_dev.at(ch_num);

                        setChannel(io, ch_state);
                    }
                }
            }
        break;

        case 0x01:
            if(ui->sbDeviceAddress->value() != MIK_01)
            {
                if(size == 1)
                {
                    quint8 channels = static_cast<quint8>(data.at(0));

                    for(quint8 i = 0; i < 8; ++i)
                    {
                        quint8 ch_state = (channels >> i)&0x01;

                        CIODevice* io = m_output_dev.at(i);

                        setChannel(io, ch_state);
                    }
                }
            }
        break;

        case 0x02:
            for(quint8 i = 0; i < size; i += 4)
            {
                quint8 j;

                for(j = 0; j < 4; ++j)
                {
                    ain.byte[j] = data.at(i + j);
                }

                QString str;

                // запись аналоговых величин в файл
                in << QString(QString::number(ain.number) + '\t');

                if(i == 8)
                {
                    str = QString::number(ain.number, 'f', 2) + " " + QString(QChar(176)) + "C";

                    m_ain_dev.at(2)->setToolTip(tr("Внутрення температура процессора"));
                }

                if(ui->sbDeviceAddress->value() == MDVV_01) // МДВВ-01
                {
                    if(i == 0) // первая ячейка AIN
                    {
                        str = QString::number(ain.number, 'f', 2) + tr(" В");
                        m_ain_dev.at(0)->setToolTip(tr("Наличие питания 5VP"));
                    }
                    else if(i == 4)
                    {
                        str = QString::number(ain.number*1000, 'f', 3) + tr(" mA");
                        m_ain_dev.at(1)->setToolTip(tr("Ток потребления"));
                    }
                    else if(i == 12)
                    {
                        QPalette p = m_ain_dev[3]->palette();

                        p.setColor(QPalette::Text, QColor(Qt::black));

                        if(ain.number == 126.0f || ain.number == 127.0f)
                        {
                            p.setColor(QPalette::Text, QColor(Qt::red));
                        }

                        m_ain_dev[3]->setPalette(p);

                        str = QString::number(ain.number, 'f', 2) + " " + QString(QChar(176)) + "C";
                        m_ain_dev.at(2)->setToolTip(tr("Внутрення температура, DS18B20"));
                    }
                }
                else if(ui->sbDeviceAddress->value() == MDVV_02) // МДВВ-02
                {
                    if(i == 0 || i == 4)
                    {
                        str = QString::number(ain.number, 'f', 2) + " " + QString(QChar(176)) + "C"; // добавление знака градусов
                    }

                    m_ain_dev.at(0)->setToolTip(tr("Температура по первому каналу"));
                    m_ain_dev.at(1)->setToolTip(tr("Температура по второму каналу"));
                }

                m_ain_dev.at(i/4)->setText(str);
            }

            in << '\n';
        break;

        case 0x03:
            if(ui->sbDeviceAddress->value() == MIK_01)
            {
                for(quint8 i = 0; i < size; ++i)
                {
                    quint8 byte = static_cast<quint8>(data.at(i));

                    for(quint8 j = 0; j < 8; ++j)
                    {
                        quint8 channels = byte;

                        channels >>= j;

                        quint8 ch_state = channels&0x01;
                        quint8 ch_num   = j + (i*8);

                        // кнопки 1, 2 и 3 попутаны с кнопками 7, 8 и 9 аппаратно, поэтому меняем номер канала
                        if(ch_num >= 0 && ch_num < 3)
                        {
                            ch_num += 6;
                        }
                        else if(ch_num >= 6 && ch_num < 9)
                            ch_num -= 6;

                        m_keyboard->setStateKey(ch_num, ch_state);
                    }
                }
            }
        break;

        case 0x04:
            if(ui->sbDeviceAddress->value() == MIK_01)
            {
                for(quint8 i = 0; i < size; ++i)
                {
                    quint8 byte = static_cast<quint8>(data.at(i));

                    for(quint8 j = 0; j < 8; j += 2)
                    {
                        quint8 channels = byte;

                        channels >>= j;

                        quint8 ch_state = channels & 0x03;
                        quint8 ch_num   = j/2 + (i*4);

                        CIODevice* io = m_output_dev.at(ch_num);

                        setChannel(io, ch_state);
                    }
                }
            }
        break;

        case 0x1E:
            ui->leDeviceID->setEnabled(true);
            ui->leDeviceNumber->setEnabled(true);
            ui->leDeviceLotNum->setEnabled(true);
            ui->leDeviceFirmwareVar->setEnabled(true);
            ui->leDeviceFirmwareDate->setEnabled(true);

            ui->twPeriphery->setCurrentIndex(1);

            s = "0x";

            if(data.at(0) < 16)
                s += "0";

            s += QString::number(data.at(0), 16);

            if(data.at(0) == 0x48)
            {
                s += " " + tr("(МДВВ-01)");
            }
            else if(data.at(0) == 0x49)
            {
                s += " " + tr("(МДВВ-02)");
            }
            else if(data.at(0) == 0x50)
            {
                s += " " + tr("(МИК-01)");
            }

            ui->leDeviceID->setText(s);
            m_conf_widget->setModuleType(data.at(0) - 0x48);

            tdata = static_cast<quint8>(data.at(1));
            tdata = ((tdata >> 4)&0x0F)*1000 + (tdata&0x0F)*100;
            tdata += ((static_cast<quint8>(data.at(2))) >> 4)*10 + ((static_cast<quint8>(data.at(2)))&0x0F);
            ui->leDeviceNumber->setText(QString::number(tdata, 10));
            m_conf_widget->setModuleNumber(tdata);

            tdata = static_cast<quint8>(data.at(3));
            tdata = ((tdata >> 4)&0x0F)*10 + (tdata&0x0F);
            ui->leDeviceLotNum->setText(QString::number(tdata, 10));
            m_conf_widget->setModuleNumberParty(tdata);

            tdata = static_cast<quint8>(data.at(4));
            tdata = ((tdata >> 4)&0x0F)*10 + (tdata&0x0F);
            ui->leDeviceFirmwareVar->setText(QString::number(tdata, 10));
            m_conf_widget->setModuleFirmwareVariant(tdata);

            tdata = static_cast<quint8>(data.at(7));
            tdata = (((tdata >> 4)&0x0F)*10 + (tdata&0x0F));
            s = QString::number(tdata, 10) + ".";

            if(data.at(6) < 10)
                s += "0";

            tdata = data.at(6);
            tdata = (((tdata >> 4)&0x0F)*10 + (tdata&0x0F));
            s += QString::number(tdata, 10);

            tdata = data.at(5);
            tdata = (((tdata >> 4)&0x0F)*10 + (tdata&0x0F));
            s += ".20" + QString::number(tdata, 10);

            ui->leDeviceFirmwareDate->setText(s);
            m_conf_widget->setModuleFirmwareDate(s);
        break;

        case 0x1F:
            if(size == 3)
            {
                quint8 byte = static_cast<quint8>(data.at(0));

                switch(byte)
                {
                    case 0xA1:
                        ui->leStateDSDIN->setText(tr("Установлен уровень \"0\""));
                    break;

                    case 0xF5:
                        ui->leStateDSDIN->setText(tr("Установлен уровень \"1\""));
                    break;

                    case 0xB8:
                        ui->leStateDSDIN->setText(tr("Срабатывание не зафиксировано"));
                    break;

                    case 0xEA:
                        ui->leStateDSDIN->setText(tr("Функция не поддерживается"));
                    break;
                }

                temp.byte[0] = data.at(1);
                temp.byte[1] = data.at(2);

                ui->leTimeDSDIN->setText(QString::number(temp.data));
            }
        break;

        case 0x3D:
            if(size == 6)
            {
                temp.byte[static_cast<quint8>(data.at(0))];
                temp.byte[static_cast<quint8>(data.at(1))];

                ui->leErrorAddr->setText(QString::number(temp.data));

                temp.byte[static_cast<quint8>(data.at(2))];
                temp.byte[static_cast<quint8>(data.at(3))];

                ui->leErrorCmd->setText(QString::number(temp.data));

                temp.byte[static_cast<quint8>(data.at(4))];
                temp.byte[static_cast<quint8>(data.at(5))];

                ui->leErrorChecksum->setText(QString::number(temp.data));
            }
        break;
    }
}
//---------------------------------------------------------
void MainWindow::setChannel(CIODevice* io, quint8 ch_state)
{
    switch(ch_state)
    {
        case 0x00: // сигнал отсутствует
            io->set_state(CIODevice::STATE_OFF);
        break;

        case 0x01: // сигнал присутствует
            io->set_state(CIODevice::STATE_ON);
        break;

        case 0x02: // ошибка
        case 0x03: // канала
            CIODevice::state_t state;
            quint8 addr = io->get_addr();

            if(addr == 2) // устройство МИК-01
            {
                state = CIODevice::STATE_ALT;
            }
            else
            {
                state = CIODevice::STATE_ERR;
            }

            io->set_state(state);
        break;
    }
}
//-----------------------------
void MainWindow::loadSettings()
{
    QString baudrate;

    m_settings->beginGroup("COM");
        m_port_name = m_settings->value(tr("port"), "").toString();
        baudrate    = m_settings->value(tr("baudrate"), 115200).toString();
    m_settings->endGroup();

    m_settings->beginGroup("TERMINAL");
        ui->cboxTerminal->setChecked(m_settings->value(tr("visiblity"), true).toBool());
        visiblityTerminal(ui->cboxTerminal->isChecked());
    m_settings->endGroup();

    m_settings->beginGroup("KEYBOARD");
        ui->cbKeyboard->setChecked(m_settings->value(tr("visiblity"), true).toBool());
    m_settings->endGroup();

    m_settings->beginGroup("COMMAND");
        ui->cbCommand->setChecked(m_settings->value(tr("visiblity"), true).toBool());
    m_settings->endGroup();

    m_settings->beginGroup("GUI");
        restoreGeometry(m_settings->value(tr("geometry")).toByteArray());
    m_settings->endGroup();

    if(!baudrate.isEmpty())
    {
        int index = ui->cbBaudrate->findText(baudrate);

        if(index >= ui->cbBaudrate->count())
        {
            if(ui->cbBaudrate->count() > 0)
                index = 0;
            else
                index = -1;
        }

        ui->cbBaudrate->setCurrentIndex(index);
    }
}
//-----------------------------
void MainWindow::saveSettings()
{
    m_settings->beginGroup("COM");
        m_settings->setValue(tr("port"), ui->cbPortNames->currentText());
        m_settings->setValue(tr("baudrate"), ui->cbBaudrate->currentText());
    m_settings->endGroup();

    m_settings->beginGroup("TERMINAL");
        m_settings->setValue(tr("visiblity"), ui->cboxTerminal->isChecked());
    m_settings->endGroup();

    m_settings->beginGroup("KEYBOARD");
        m_settings->setValue(tr("visiblity"), ui->cbKeyboard->isChecked());
    m_settings->endGroup();

    m_settings->beginGroup("COMMAND");
        m_settings->setValue(tr("visiblity"), ui->cbCommand->isChecked());
    m_settings->endGroup();

    m_settings->beginGroup("GUI");
        m_settings->setValue(tr("geometry"), this->saveGeometry());
    m_settings->endGroup();
}
//-------------------------------------------
void MainWindow::closeEvent(QCloseEvent* evt)
{
    saveSettings();
    QMainWindow::closeEvent(evt);
}
//----------------------------------------------
void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        CIODevice::set_modifier(Qt::ControlModifier);
    }

    switch(event->key())
    {
        case Qt::Key_C:
            if(event->modifiers() == Qt::ALT)
            {
                ui->pteConsole->clear();
            }
        break;

        case Qt::Key_F7:
            configurationWindow();
        break;
    }

    QMainWindow::keyPressEvent(event);
}
//----------------------------------------------
void MainWindow::keyReleaseEvent(QKeyEvent *evt)
{
    CIODevice::set_modifier(0);
    QMainWindow::keyReleaseEvent(evt);
}
//-----------------------------------------
void MainWindow::showEvent(QShowEvent* evt)
{
    if(m_command == Q_NULLPTR)
    {
        m_command = new QCommand(this);

        connect(m_command, SIGNAL(closeCommand(bool)), this, SLOT(visiblityCommand(bool)));
        m_command->hide();
    }

    initSerialPort();
    initIO();
    initConnect();

    loadSettings();
    refreshSerialPort();

    ui->cbCmdList->slotActivated(0);
    ui->twPeriphery->setCurrentIndex(0);
    initFilter(ui->cbCmdList->currentText());
    addrChanged(ui->sbDeviceAddress->value());
    fileAinOpen();
    ui->cbKeyboard->hide();

    QMainWindow::showEvent(evt);
}
//----------------------------
void MainWindow::fileAinOpen()
{
    QDate date;
    QDir  dir;

    if(!dir.exists(dir.currentPath() + "/AIN"))
    {
        dir.mkdir(dir.currentPath() + "/AIN");
    }

    m_file_ain->setFileName(tr("AIN/AIN_") + date.currentDate().toString("dd_MM_yyyy") + tr(".txt"));

    if(!m_file_ain->open(QIODevice::Append | QIODevice::Text))
    {
        showMessage(tr("Ошибка: ") + m_file_ain->errorString());
    }
}
//--------------------------
void MainWindow::blockSend()
{
    m_block_send = true;

    m_timerTimeoutQuery->start(100); // таймаут отправки 100 мс
}
//----------------------------
void MainWindow::unblockSend()
{
    m_block_send = false;

    m_timerTimeoutQuery->stop(); // останавливаем таймер таймаута
}
//-----------------------------
bool MainWindow::is_blockSend()
{
    return m_block_send;
}
//------------------------------------
void MainWindow::configurationWindow()
{
    if(m_conf_widget->isHidden())
    {
        if(!ui->checkBoxSerialConfig->isChecked())
            ui->checkBoxSerialConfig->setChecked(true);

        sendData("0x1E");
        if(m_conf_widget->exec() == QDialog::Accepted)
        {
            QString    cmd          = "0x3A";
            QByteArray keyCurrent   = m_conf_widget->moduleKeyCurrent();
            QByteArray keyNew       = m_conf_widget->moduleKeyNew();
            int        num          = m_conf_widget->moduleNumber();
            int        numParty     = m_conf_widget->moduleNumberParty();
            int        firmwareVar  = m_conf_widget->moduleFirmwareVariant();

/* FORMAT SERIAL NUMBER CMD
* -----------------------------------------------------------------------------------------------------------------------------
* | cmd | key_cur | key_cur | key_cur | key_cur | key_new | key_new | key_new | key_new | num | num | party | firmware | CRC8 |
* -----------------------------------------------------------------------------------------------------------------------------
*/
            QByteArray ba;

            ba.append(keyCurrent);
            ba.append(keyNew);
            ba.append(QByteArray::fromHex(QByteArray::number(((num/1000 << 4) | (num%1000)/100), 16)));
            num = num%100;
            ba.append(QByteArray::fromHex(QByteArray::number(((num/10 << 4) | (num%10)), 16)));
            ba.append(QByteArray::fromHex(QByteArray::number(((numParty/10 << 4) | (numParty%10)), 16)));
            ba.append(QByteArray::fromHex(QByteArray::number(((firmwareVar/10 << 4) | (firmwareVar%10)), 16)));

            write(cmd, ba);
        }

        ui->checkBoxSerialConfig->setChecked(false);
    }
}
//------------------------------------------------
void MainWindow::configWindowVisiblity(bool state)
{
    if(!state)
    {
        if(m_conf_widget->isVisible())
            m_conf_widget->hide();
    }
    else
    {
        configurationWindow();
    }
}
/*!
 * \brief MainWindow::setupDiscretInput
 *
 * Вызов окна настройки дискретных входов
 */
void MainWindow::setupDiscretInput()
{
    int type = 1;

    if(ui->radioButtonInputSingle->isChecked())
        type = 0;

    if(m_set_intput_widget->isHidden())
        m_set_intput_widget->open(type);
}
//----------------------------------
void MainWindow::refreshSerialPort()
{
    quint8 count = 0;
    QStringList port_list;

    foreach(const QSerialPortInfo& port_info, QSerialPortInfo::availablePorts())
    {
        port_list << port_info.portName();
        count++;
    }

    if(count == 0)
    {
        ui->cbPortNames->clear();
        ui->pbCtrlPort->setDisabled(true);

        if(m_port->isOpen())
        {
            ctrlSerialPort(false);
        }
    }
    else if(count != 0 && ui->cbPortNames->count() == 0)
    {
        int index = -1;

        if(!port_list.isEmpty())
            ui->cbPortNames->addItems(port_list);

        if(m_port_name.isEmpty())
        {
            index = ui->cbPortNames->findText(m_port_name);

            if(index == -1)
            {
                index = 0;
            }
        }
        else
            index = 0;

        ui->cbPortNames->setCurrentIndex(index);
        ui->pbCtrlPort->setEnabled(true);

        m_port_name = ui->cbPortNames->currentText(); // сохраняем порт
    }

    m_timerRefreshPort->start(500); // опрос наличия подлкюченных последовательных портов каждые 500мс
}
//-----------------------------------------
void MainWindow::ctrlSerialPort(bool state)
{
    if(state)
    {
        m_port->setPortName(ui->cbPortNames->currentText());

        if(!m_port->open(QSerialPort::ReadOnly | QSerialPort::WriteOnly))
        {
            QMessageBox::critical(this, tr("Открытие последовательного порта"), m_port->errorString());
            return;
        }

        ui->pbCtrlPort->setText(tr("Close"));

        ui->groupDevices->setEnabled(true);
        ui->pbCmdSend->setEnabled(true);
        ui->gboxAutorepeat->setEnabled(true);
        ui->twPeriphery->setEnabled(true);

        showMessage(ui->cbPortNames->currentText() + " " + tr("открыт"));

        fileAinOpen();

        m_port->setBaudRate(ui->cbBaudrate->currentText().toInt());
        m_port->setFlowControl(QSerialPort::NoFlowControl);
        m_port->setDataBits(QSerialPort::Data8);
        m_port->setStopBits(QSerialPort::OneStop);
        m_port->setParity(QSerialPort::NoParity);

        if(ui->cbCommand->isChecked())
            m_command->show();
    }
    else
    {
        m_port->close();

        ui->pbCtrlPort->setText(tr("Открыть"));

        ui->groupDevices->setDisabled(true);
        ui->pbCmdSend->setDisabled(true);
        ui->gboxAutorepeat->setDisabled(true);
        ui->twPeriphery->setDisabled(true);

        ui->cboxRepeatInputs->setChecked(false);
        ui->cboxRepeatAIN->setChecked(false);

        m_timerAutoRepeatInput->stop();
        m_timerAutoRepeatAIN->stop();

        m_file_ain->close();

        showMessage(ui->cbPortNames->currentText() + " " + tr("закрыт"));

        if(!m_command->isHidden())
            m_command->hide();
    }

    ui->pbCtrlPort->setChecked(state);
}
//-------------------------
void MainWindow::readData()
{
    QByteArray ba = m_port->readAll();

    m_responce.append(ba);

    quint8 cmd_size = ui->cbCmdList->size(m_cmd_last);
    quint8 responce_size = m_responce.size();

    if(responce_size == cmd_size)
    {
        quint8 checksum_calc = getChecksum(m_responce, m_responce.size() - 1);
        quint8 checksum_read = m_responce.at(m_responce.size() - 1);

        if(checksum_calc == checksum_read)
        {
            cmdParser(m_responce, m_responce.size() - 1);
            ui->pteConsole->appendPlainText(tr("ЧТЕНИЕ: 0x%1\n%2").arg(QString(m_responce.toHex().toUpper())).arg("*****"));
        }
        else
            ui->pteConsole->appendPlainText(tr("ЧТЕНИЕ: ОШИБКА CRC\n%1").arg("*****"));

        ui->pteConsole->verticalScrollBar()->setValue(ui->pteConsole->verticalScrollBar()->maximum());

        m_query.clear();
        m_query_count = 0;
        m_responce.clear();
        sendData(); // подтверждаем принятие данных отправкой пустого сообщения
    }
    else if(m_responce.size() > cmd_size)
        m_responce.clear();
}
//----------------------------------------------
void MainWindow::sendCmd(const QString& cmd_str)
{
    QString cmd = ui->cbCmdList->currentText();

    if(!cmd_str.isEmpty())
        cmd = cmd_str;

    if(cmd.toUpper() == "0X3A") // если команда "Запись серийного номера, то открываем дополнительное окно (команду не отправляем)
    {
        if(m_conf_widget->isHidden())
            m_conf_widget->show();
        return;
    }
    else if(cmd.toUpper() == "0X3F") // если команда "Настройка входа", то открываем дополнительное окно (команду не отправляем)
    {
        setupDiscretInput();
        return;
    }

    sendData(cmd);
}
//--------------------------------------------
void MainWindow::sendData(const QString& data)
{
    if(!is_blockSend()) // если не блокирована передача
    {
        if(!data.isEmpty())
        {
            m_cmd_last = data;

            blockSend(); // блокируем передачу
            write(data); // отправляем данные
        }
    }
    else
    {
        if(!data.isEmpty())
        {
            m_queue_cmd.append(data);
        }
        else
        {
            unblockSend(); // снимаем блокировку передачи

            if(!m_queue_cmd.isEmpty())
            {
                QString cmd_cur = m_queue_cmd.takeFirst();

                if(!cmd_cur.isEmpty())
                {
                    m_cmd_last = cmd_cur;

                    blockSend(); // блокируем передачу
                    write(cmd_cur);
                }
            }
        }
    }
}
//--------------------------------------------------------------------
void MainWindow::write(const QString& cmd_str, const QByteArray& data)
{
    if(m_query.isEmpty())
    {
        if(cmd_str.isEmpty())
            return;

        m_cmd_last  = cmd_str;

        quint8 cmd = (quint8)(QString(m_cmd_last).remove(QRegExp(tr("0x"))).toInt(Q_NULLPTR, 16));

        cmd |= ((quint8)ui->sbDeviceAddress->value()) << 6;

        QString cmd_temp;

        cmd_temp.setNum(cmd, 16);
        m_query.append(QByteArray::fromHex(cmd_temp.toLocal8Bit().data()));

        if(data.isEmpty())
        {
            qint8 channel_id                 = -1;
            CIODevice::state_t channel_state = CIODevice::STATE_OFF;

            if(cmd >= 0x06 && cmd <= 0x0D)
            {
                channel_id    = cmd - 0x06;
                channel_state = CIODevice::STATE_OFF;
            }
            else if(cmd >= 0x0E && cmd <= 0x15)
            {
                channel_id    = cmd - 0x0E;
                channel_state = CIODevice::STATE_ON;
            }

            if(channel_id != -1)
            {
                m_output_dev.at(channel_id)->set_state(channel_state);
            }

            QString str;

            if(m_cmd_last == tr("0x05") && ui->sbDeviceAddress->value() == MIK_01) // только для устройства МИК-01
            {
                for(quint8 i = 0; i < 3; ++i) // 3 байта на 12 входов
                {
                    quint8 byte = 0x00;

                    for(quint8 j = 0; j < 8; j += 2) // 8 бит с шагом 2 (т.е. 2 бита на описание состояния одного выхода)
                    {
                        CIODevice* out   = m_output_dev.at(i*4 + j/2);
                        quint8     state = (out->get_state() == CIODevice::STATE_OFF)?0x00:(out->get_state() == CIODevice::STATE_ON)?0x01:0x02;

                        state = state << j;
                        byte |= state;
                    }

                    str.setNum(byte, 16);
                    m_query.append(QByteArray::fromHex(str.toLocal8Bit().data()));
                }
            }
            if(m_cmd_last == tr("0x3E"))
            {
                str.setNum(ui->sbPeriods->value(), 16);
                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // количество периодов

                str.setNum(ui->sbDiscret->value(), 16);
                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // дискретность

                str.setNum(ui->sbSignal->value(), 16);
                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // длительность сигнала
            }
            else if(m_cmd_last == tr("0x3F"))
            {
//                str.setNum(ui->sbInput->value(), 16);
//                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // номер входа

//                quint8 type = (ui->cbInputType->currentText().toUpper() == tr("АНАЛОГОВЫЙ"))?0x00:0x01;

//                str.setNum(type, 16);
//                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // тип входа

//                str.setNum(ui->sbDuration->value(), 16);
//                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // длительность периода

//                str.setNum(ui->sbFaultInput->value(), 16);
//                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // погрешность периода
            }
        }
        else
        {
            m_query.append(data);
        }

        quint8 checksum = getChecksum(m_query, m_query.size()); // создать контрольную сумму
        QString crc_str;

        crc_str.setNum(checksum, 16);
        m_query.append(QByteArray::fromHex(crc_str.toLocal8Bit().data()));
        int index = (QString(m_cmd_last).remove(QRegExp(tr("0x"))).toInt(Q_NULLPTR, 16));
        ui->pteConsole->appendPlainText(tr("КОМАНДА: ") + ui->cbCmdList->description(index));
        ui->pteConsole->appendPlainText(tr("ОТПРАВКА ДАННЫХ: ") + m_query.toHex().toUpper());
        m_port->setParity(QSerialPort::MarkParity); // enable 9 bit
    }

    m_port->write(m_query);
    ui->pteConsole->verticalScrollBar()->setValue(ui->pteConsole->verticalScrollBar()->maximum());
}
//---------------------------------------
void MainWindow::BytesWriten(qint64 byte)
{
    Q_UNUSED(byte);

    if(m_port->parity() == QSerialPort::MarkParity)
        m_port->setParity(QSerialPort::SpaceParity); // reset 9bit - this is data

    m_query_count++;

    if(m_query_count == m_query.count())
    {
        m_query.clear();
        m_query_count = 0;
    }
    else
        write();
}
//---------------------------------------------------------
void MainWindow::cmdDescription(const QString& description)
{
    QString desc = description;
    QPalette p(ui->lblCmdDescription->palette());

    if(desc.toUpper() == tr("РЕЗЕРВ"))
        p.setColor(QPalette::WindowText, QColor(Qt::red));
    else
        p.setColor(QPalette::WindowText, QColor(Qt::blue));

    ui->lblCmdDescription->setPalette(p);
    ui->lblCmdDescription->setToolTip(desc);

    if(desc.count() > 25)
    {
        desc = desc.mid(0, 25) + "...";
    }

    ui->lblCmdDescription->setText(desc);
}
//------------------------------------
void MainWindow::addrChanged(int addr)
{
//    Q_UNUSED(addr);
    quint8 out_count = 0;

    ui->cbKeyboard->hide(); // Вызов клавиатуры МИК-01 становится видимым при выборе адреса 0х02
    ui->gboxInputs->setEnabled(true);

    if(m_keyboard != Q_NULLPTR)
    {
        if(!m_keyboard->isHidden())
            m_keyboard->hide();
    }

    if(addr == MDVV_01)
    {
        ui->groupDevices->setTitle(tr("Устройство МДВВ-01"));
        ui->lblAIN1->setText(tr("Напряжение"));
        ui->lblAIN2->setText(tr("Ток"));
        ui->lblAIN3->setText(tr("Температура"));

        out_count = 6;
    }
    else if(addr == MDVV_02)
    {
        ui->groupDevices->setTitle(tr("Устройство МДВВ-02"));
        ui->lblAIN1->setText(tr("Температура"));
        ui->lblAIN2->setText(tr("Температура"));
        ui->lblAIN3->setText(tr("Температура"));

        out_count = 7;
    }
    else if(addr == MIK_01)
    {
        ui->groupDevices->setTitle(tr("Устройство МИК-01"));
        ui->cbKeyboard->show();
        ui->gboxInputs->setDisabled(true);

        if(m_keyboard == Q_NULLPTR)
        {
            m_keyboard = new QKeyboard(this);

            connect(m_keyboard, SIGNAL(closeKeyboard(bool)), this, SLOT(visiblityKeyboard(bool)));

            if(ui->cbKeyboard->isChecked())
            {
                m_keyboard->show();
            }
            else
            {
                m_keyboard->hide();
            }
        }
        else
        {
            if(ui->cbKeyboard->isChecked())
            {
                m_keyboard->show();
            }
            else
            {
                m_keyboard->hide();
            }
        }

        out_count = 12;
    }
    else
    {
        ui->groupDevices->setTitle(tr("Неопределенное устройство"));
    }

    for(CIODevice* io: m_input_dev)
    {
        io->set_state(CIODevice::STATE_OFF);
        io->set_dev_addr(ui->sbDeviceAddress->value());
    }

    for(CIODevice* io: m_output_dev)
    {
        io->set_state(CIODevice::STATE_OFF);
        io->set_dev_addr(ui->sbDeviceAddress->value());
    }

    for(quint8 i = 0; i < 12; ++i)
    {
        if(i < out_count)
            m_output_dev.at(i)->setEnabled(true);
        else
            m_output_dev.at(i)->setDisabled(true);
    }
}
//--------------------------------------------------------
void MainWindow::outputStateChanged(quint8 id, bool state)
{
    if(id != 255)
    {
        if(ui->sbDeviceAddress->value() != MIK_01)
        {
            quint8 offset = (state)?0x0E:0x06;
            quint8 cmd    = offset + id;

            QString str;

            str.setNum(cmd, 16);

            sendData(((cmd >= 16)?tr("0x"):tr("0x0")) + str.toUpper());
        }
        else
            write(tr("0x05"));
    }
}
//----------------------------------------------
void MainWindow::initFilter(const QString& text)
{
    if(text == tr("0x3D"))
    {
        ui->gboxInputSettings->setEnabled(true);
        ui->gboxInput->setDisabled(true);
        ui->gboxInputSettingsFilter->setDisabled(true);
    }
    else if(text == tr("0x3E"))
    {
        ui->gboxInputSettings->setEnabled(true);
        ui->gboxInput->setDisabled(true);
        ui->gboxInputSettingsFilter->setEnabled(true);
    }
    else if(text == tr("0x3F"))
    {
        ui->gboxInputSettings->setEnabled(true);
        ui->gboxInput->setEnabled(true);
        ui->gboxInputSettingsFilter->setDisabled(true);
    }
    else
        ui->gboxInputSettings->setDisabled(true);
}
//-------------------------------------------
void MainWindow::autoRepeatInputs(bool state)
{
    if(state)
    {
        m_timerAutoRepeatInput->start(ui->sbRepeatInputs->value());
    }
    else
    {
        m_timerAutoRepeatInput->stop();
    }
}
//----------------------------------------
void MainWindow::autoRepeatAIN(bool state)
{
    if(state)
    {
        m_timerAutoRepeatAIN->start(ui->sbRepeatAIN->value());
    }
    else
    {
        m_timerAutoRepeatAIN->stop();
    }
}
//------------------------------------
void MainWindow::autoRepeatTimInputs()
{
    if(ui->sbDeviceAddress->value() != MIK_01) // устройство не МИК-01
    {
        sendData(tr("0x00")); // чтение дискретных каналов входов
    }
    else // устройство МИК-01
    {
        sendData(tr("0x03")); // чтение регистра расширения дискретных каналов входов (клавиатура)
    }

    if(ui->cboxRepeatInputs->isChecked())
        m_timerAutoRepeatInput->start(ui->sbRepeatInputs->value());
}
//---------------------------------
void MainWindow::autoRepeatTimAIN()
{
    sendData(tr("0x02"));

    if(ui->cboxRepeatAIN->isChecked())
        m_timerAutoRepeatAIN->start(ui->sbRepeatAIN->value());
}
//---------------------------
void MainWindow::timeoutTim()
{
    unblockSend();
    sendData();
}
//----------------------------------------------
void MainWindow::visiblityTerminal(bool visible)
{
    ui->cboxTerminal->setChecked(visible);
    ui->dwTerminal->setVisible(visible);
}
//----------------------------------------------
void MainWindow::visiblityKeyboard(bool visible)
{
    ui->cbKeyboard->setChecked(visible);

    if(visible)
    {
        if(m_keyboard != Q_NULLPTR)
        {
            m_keyboard->show();
        }
    }
    else
    {
        if(m_keyboard != Q_NULLPTR)
        {
            m_keyboard->hide();
        }
    }
}
//---------------------------------------------
void MainWindow::visiblityCommand(bool visible)
{
    ui->cbCommand->setChecked(visible);

    if(m_port->isOpen())
    {
        if(visible)
        {
            if(m_command != Q_NULLPTR)
            {
                m_command->show();
            }
        }
        else
        {
            if(m_command != Q_NULLPTR)
            {
                m_command->hide();
            }
        }
    }
}
