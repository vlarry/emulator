#include "mainwindow.h"
#include "ui_mainwindow.h"
//--------------------------------------
MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_port(Q_NULLPTR),
    m_lblMessage(Q_NULLPTR),
    m_cmd_last(""),
    m_query_count(0),
    m_timerAutoRepeatInput(Q_NULLPTR),
    m_timerAutoRepeatAIN(Q_NULLPTR),
    m_timerTimeoutQuery(Q_NULLPTR),
    m_file_ain(Q_NULLPTR),
    m_block_send(false)
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

    m_file_ain = new QFile;

    initSerialPort();
    initIO();
    initConnect();

    ui->groupDevices->setDisabled(true);
    ui->groupDevice->setDisabled(true);
    ui->pbCmdSend->setDisabled(true);

    refreshSerialPort();

    ui->cbCmdList->slotActivated(0);

    loadSettings();

    ui->cbInputType->addItems(QStringList() << tr("Аналоговый")  << tr("Цифровой"));

    initFilter(ui->cbCmdList->currentText());

    addrChanged(ui->sbDeviceAddress->value());

    fileAinOpen();
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

    connect(ui->cbCmdList, SIGNAL(currentTextChanged(QString)), this, SLOT(initFilter(QString)));
    connect(ui->cbInputType, SIGNAL(currentTextChanged(QString)), this, SLOT(typeInput(QString)));

    connect(ui->cboxRepeatInputs, SIGNAL(clicked(bool)), this, SLOT(autoRepeatInputs(bool)));
    connect(ui->cboxRepeatAIN, SIGNAL(clicked(bool)), this, SLOT(autoRepeatAIN(bool)));
    connect(m_timerAutoRepeatInput, SIGNAL(timeout()), this, SLOT(autoRepeatTimInputs()));
    connect(m_timerAutoRepeatAIN, SIGNAL(timeout()), this, SLOT(autoRepeatTimAIN()));
    connect(m_timerTimeoutQuery, SIGNAL(timeout()), this, SLOT(timeoutTim()));

    connect(ui->dwTerminal, SIGNAL(visibilityChanged(bool)), this, SLOT(visiblityTerminal(bool)));
    connect(ui->cboxTerminal, SIGNAL(toggled(bool)), this, SLOT(visiblityTerminal(bool)));
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

    quint8 cmd  = (quint8)QString(m_cmd_last).remove(QRegExp("0x")).toInt(Q_NULLPTR, 16);

    Float_t ain;
    QTextStream in(m_file_ain);

    union
    {
        quint16 time;
        quint8  byte[2];
    } dsdin;

    switch(cmd)
    {
        case 0x00:
            for(quint8 i = 0; i < size; ++i)
            {
                quint8 byte = data.at(i);

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
        break;

        case 0x01:
            if(size == 1)
            {
                quint8 channels = data.at(0);

                for(quint8 i = 0; i < 8; ++i)
                {
                    quint8 ch_state = (channels >> i)&0x01;

                    CIODevice* io = m_output_dev.at(i);

                    setChannel(io, ch_state);
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

                    m_ain_dev.at(2)->setToolTip(tr("Внутрення температура"));
                }

                if(ui->sbDeviceAddress->value() == 0) // МДВВ-01
                {
                    if(i == 0) // первая ячейка AIN
                    {
                        str = QString::number(ain.number, 'f', 2) + tr(" В");
                    }
                    else if(i == 4)
                    {
                        str = QString::number(ain.number*1000, 'f', 3) + tr(" mA");
                    }

                    m_ain_dev.at(0)->setToolTip(tr("Наличие питания 5VP"));
                    m_ain_dev.at(1)->setToolTip(tr("Ток потребления"));
                }
                else if(ui->sbDeviceAddress->value() == 1) // МДВВ-02
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

        case 0x1F:
            if(size == 3)
            {
                quint8 byte = data.at(0);

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

                dsdin.byte[0] = data.at(1);
                dsdin.byte[1] = data.at(2);

                ui->leTimeDSDIN->setText(QString::number(dsdin.time));
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
            io->set_state(CIODevice::STATE_ERR);
        break;
    }
}
//-----------------------------
void MainWindow::loadSettings()
{
    QString port;
    QString baudrate;

    m_settings->beginGroup("COM");
        port = m_settings->value(tr("port"), "").toString();
        baudrate = m_settings->value(tr("baudrate"), 115200).toString();
    m_settings->endGroup();

    if(!port.isEmpty())
    {
        int index = ui->cbPortNames->findText(port);

        if(index >= ui->cbPortNames->count())
        {
            if(ui->cbPortNames->count() > 0)
                index = 0;
            else
                index = -1;
        }

        ui->cbPortNames->setCurrentIndex(index);
    }

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
}
//-------------------------------------------
void MainWindow::closeEvent(QCloseEvent* evt)
{
    saveSettings();
    QMainWindow::closeEvent(evt);
}
//--------------------------------------------
void MainWindow::keyPressEvent(QKeyEvent* evt)
{
    switch(evt->key())
    {
        case Qt::Key_C:
            if(evt->modifiers() == Qt::ALT)
            {
                ui->pteConsole->clear();
            }
        break;
    }
}
//----------------------------
void MainWindow::fileAinOpen()
{
    QDate date;

    m_file_ain->setFileName(tr("AIN_") + date.currentDate().toString("dd_MM_yyyy") + tr(".txt"));

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
//----------------------------------
void MainWindow::refreshSerialPort()
{
    ui->cbPortNames->clear();

    foreach(const QSerialPortInfo& port_info, QSerialPortInfo::availablePorts())
        ui->cbPortNames->addItem(port_info.portName());

    if(ui->cbPortNames->count() == 0)
    {
        ui->pbCtrlPort->setDisabled(true);
        ui->groupDevices->setDisabled(true);
        ui->pteConsole->setDisabled(true);
    }
    else
    {
        ui->pbCtrlPort->setEnabled(true);
        ui->groupDevices->setEnabled(true);
        ui->pteConsole->setEnabled(true);
    }
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

        ui->groupDevice->setEnabled(true);
        ui->pbCmdSend->setEnabled(true);
        ui->gboxAutorepeat->setEnabled(true);

        showMessage(ui->cbPortNames->currentText() + " " + tr("открыт"));

        fileAinOpen();

        m_port->setBaudRate(ui->cbBaudrate->currentText().toInt());
        m_port->setFlowControl(QSerialPort::NoFlowControl);
        m_port->setDataBits(QSerialPort::Data8);
        m_port->setStopBits(QSerialPort::OneStop);
        m_port->setParity(QSerialPort::NoParity);
    }
    else
    {
        m_port->close();
        ui->pbCtrlPort->setText(tr("Открыть"));
        ui->groupDevices->setDisabled(true);
        ui->groupDevice->setDisabled(true);
        ui->pbCmdSend->setDisabled(true);
        ui->gboxAutorepeat->setDisabled(true);

        ui->cboxRepeatInputs->setChecked(false);
        ui->cboxRepeatAIN->setChecked(false);

        m_timerAutoRepeatInput->stop();
        m_timerAutoRepeatAIN->stop();

        m_file_ain->close();

        showMessage(ui->cbPortNames->currentText() + " " + tr("закрыт"));
    }
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
        ui->pteConsole->appendPlainText(tr("ЧТЕНИЕ: 0x") + m_responce.toHex().toUpper());

        quint8 checksum_calc = getChecksum(m_responce, m_responce.size() - 1);
        quint8 checksum_read = m_responce.at(m_responce.size() - 1);

        if(checksum_calc == checksum_read)
        {
            cmdParser(m_responce, m_responce.size() - 1);
        }

        m_responce.clear();
        sendData(); // подтверждаем принятие данных отправкой пустого сообщения
    }
}
//------------------------
void MainWindow::sendCmd()
{
    sendData(ui->cbCmdList->currentText());
}
//--------------------------------------------
void MainWindow::sendData(const QString& data)
{
//    ui->pteConsole->appendPlainText(data);
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
//--------------------------------------------
void MainWindow::write(const QString& cmd_str)
{
    if(m_query.isEmpty())
    {
        if(cmd_str.isEmpty())
            return;

        m_cmd_last  = cmd_str;

        quint8 cmd = (quint8)(QString(m_cmd_last).remove(QRegExp(tr("0x"))).toInt(Q_NULLPTR, 16));

        cmd |= ((quint8)ui->sbDeviceAddress->value()) << 6;

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

        m_port->setParity(QSerialPort::MarkParity); // enable 9 bit

        QString str;

        str.setNum(cmd, 16);
        m_query.append(QByteArray::fromHex(str.toLocal8Bit().data()));

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
            str.setNum(ui->sbInput->value(), 16);
            m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // номер входа

            quint8 type = (ui->cbInputType->currentText().toUpper() == tr("АНАЛОГОВЫЙ"))?0x00:0x01;

            str.setNum(type, 16);
            m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // тип входа

            str.setNum(ui->sbDuration->value(), 16);
            m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // длительность периода

            str.setNum(ui->sbFaultInput->value(), 16);
            m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // погрешность периода
        }

        QByteArray ba;

        for(QByteArray b: m_query)
        {
            for(quint8 s: b)
                ba.append(s);
        }

        quint8 checksum = getChecksum(ba, m_query.size()); // создать контрольную сумму

        str.setNum(checksum, 16);
        m_query.append(QByteArray::fromHex(str.toLocal8Bit().data()));
    }

    m_port->write(m_query.at(m_query_count));

    ui->pteConsole->appendPlainText(tr("ЗАПИСЬ: ") + m_query.at(m_query_count).toHex().toUpper());
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
        int index = (QString(m_cmd_last).remove(QRegExp(tr("0x"))).toInt(Q_NULLPTR, 16));
        ui->pteConsole->appendPlainText(tr("ЗАПИСЬ КОМАНДЫ: ") + ui->cbCmdList->description(index));

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

    ui->lblCmdDescription->setText(desc);
}
//------------------------------------
void MainWindow::addrChanged(int addr)
{
//    Q_UNUSED(addr);

    if(addr == 0)
    {
        ui->groupDevice->setTitle(tr("Устройство МДВВ-01"));
        ui->lblAIN1->setText(tr("Напряжение"));
        ui->lblAIN2->setText(tr("Ток"));
        ui->lblAIN3->setText(tr("Температура"));
    }
    else if(addr == 1)
    {
        ui->groupDevice->setTitle(tr("Устройство МДВВ-02"));
        ui->lblAIN1->setText(tr("Температура"));
        ui->lblAIN2->setText(tr("Температура"));
        ui->lblAIN3->setText(tr("Температура"));
    }
    else
    {
        ui->groupDevice->setTitle(tr("Неопределенное устройство"));
    }

    for(CIODevice* io: m_input_dev)
    {
        io->set_state(CIODevice::STATE_OFF);
    }

    for(CIODevice* io: m_output_dev)
    {
        io->set_state(CIODevice::STATE_OFF);
    }
}
//--------------------------------------------------------
void MainWindow::outputStateChanged(quint8 id, bool state)
{
    if(id != 255)
    {
        quint8 offset = (state)?0x0E:0x06;
        quint8 cmd    = offset + id;

        QString str;

        str.setNum(cmd, 16);

        sendData(((cmd >= 16)?tr("0x"):tr("0x0")) + str.toUpper());
    }
}
//---------------------------------------
void MainWindow::initFilter(QString text)
{
    if(text == tr("0x3D"))
    {
        ui->gboxInputSettings->setEnabled(true);
        ui->sbDuration->setEnabled(true);
        ui->gboxInput->setDisabled(true);
        ui->gboxInputSettingsFilter->setDisabled(true);
    }
    else if(text == tr("0x3E"))
    {
        ui->gboxInputSettings->setEnabled(true);
        ui->sbDuration->setDisabled(true);
        ui->gboxInput->setDisabled(true);
        ui->gboxInputSettingsFilter->setEnabled(true);
    }
    else if(text == tr("0x3F"))
    {
        ui->gboxInputSettings->setEnabled(true);
        ui->sbDuration->setDisabled(true);
        ui->gboxInput->setEnabled(true);
        ui->gboxInputSettingsFilter->setDisabled(true);
    }
    else
        ui->gboxInputSettings->setDisabled(true);
}
//--------------------------------------
void MainWindow::typeInput(QString text)
{
    if(text.toUpper() == tr("АНАЛОГОВЫЙ"))
    {
        ui->lblTextFault->setText(tr("Погрешность, %"));
        ui->sbFaultInput->setRange(10, 50);
        ui->sbFaultInput->setSingleStep(10);
    }
    else
    {
        ui->lblTextFault->setText(tr("Кол-во лог 0/1, %"));
        ui->sbFaultInput->setRange(50, 100);
        ui->sbFaultInput->setSingleStep(10);
    }
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
    sendData(tr("0x00"));

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
