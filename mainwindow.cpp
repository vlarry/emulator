#include "mainwindow.h"
#include "ui_mainwindow.h"
//--------------------------------------
MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_port(Q_NULLPTR),
    m_lblMessage(Q_NULLPTR),
    m_cmd_last(""),
    m_query_count(0)
{
    ui->setupUi(this);

    QPalette p = ui->pteConsole->palette();

    p.setColor(QPalette::Base, QColor(Qt::black));
    p.setColor(QPalette::Text, QColor(Qt::green));

    ui->pteConsole->setPalette(p);

    m_lblMessage = new QLabel(ui->statusBar);
    ui->statusBar->addWidget(m_lblMessage);

    m_settings = new QSettings("settings.cnf", QSettings::IniFormat);

    initSerialPort();
    initIO();
    initConnect();

    ui->groupDevices->setDisabled(true);
    ui->groupDevice->setDisabled(true);
    ui->pbCmdSend->setDisabled(true);

    refreshSerialPort();

    ui->cbCmdList->slotActivated(0);

    loadSettings();

    initFilter(ui->cbCmdList->currentText());
}
//-----------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//----------------------------
void MainWindow::initConnect()
{
    connect(ui->tbPortRefresh, SIGNAL(clicked()), this, SLOT(refreshSerialPort()));
    connect(ui->pbCtrlPort, SIGNAL(clicked(bool)), this, SLOT(ctrlSerialPort(bool)));
    connect(m_port, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(ui->pbCmdSend, SIGNAL(clicked()), this, SLOT(writeData()));
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
            Float_t ain;

            for(quint8 i = 0; i < size; i += 4)
            {
                quint8 j;

                for(j = 0; j < 4; ++j)
                {
                    ain.byte[j] = data.at(i + j);
                }

                m_ain_dev.at(i/4)->setText(QString::number(ain.number));
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

        showMessage(ui->cbPortNames->currentText() + " " + tr("открыт"));

        m_port->setBaudRate(ui->cbBaudrate->currentText().toInt());
        m_port->setFlowControl(QSerialPort::NoFlowControl);
        m_port->setDataBits(QSerialPort::Data8);
        m_port->setStopBits(QSerialPort::OneStop);
        m_port->setParity(QSerialPort::NoParity);

        // тест входов
//        QByteArray ba_in;
//        QString s_in;

//        s_in.setNum(1, 16);
//        ba_in.append(QByteArray::fromHex(s_in.toLocal8Bit()));

//        s_in.setNum(1, 16);
//        ba_in.append(QByteArray::fromHex(s_in.toLocal8Bit()));

//        s_in.setNum(10, 16);
//        ba_in.append(QByteArray::fromHex(s_in.toLocal8Bit()));

//        cmdParser(ba_in, 3);
        //конец теста входов

        // тест выходов
//        QByteArray ba_out;
//        QString s_out;

//        s_out.setNum(129, 16);
//        ba_out.append(QByteArray::fromHex(s_out.toLocal8Bit()));

//        m_cmd_last = ui->cbCmdList->currentText();
//        cmdParser(ba_out, 1);
        // конец теста выходов

        // тест входов ain
//        Float_t f;

//        QByteArray ba_ain;
//        QString s_ain;

//        f.number = 3.04f;

//        for(quint8 i = 0; i < 4; ++i)
//        {
//            s_ain.setNum(f.byte[i], 16);
//            ba_ain.append(QByteArray::fromHex(s_ain.toLocal8Bit()));
//        }

//        f.number = 1.11f;

//        for(quint8 i = 0; i < 4; ++i)
//        {
//            s_ain.setNum(f.byte[i], 16);
//            ba_ain.append(QByteArray::fromHex(s_ain.toLocal8Bit()));
//        }

//        f.number = 27.12f;

//        for(quint8 i = 0; i < 4; ++i)
//        {
//            s_ain.setNum(f.byte[i], 16);
//            ba_ain.append(QByteArray::fromHex(s_ain.toLocal8Bit()));
//        }

//        f.number = 0.0f;

//        for(quint8 i = 0; i < 4; ++i)
//        {
//            s_ain.setNum(f.byte[i], 16);
//            ba_ain.append(QByteArray::fromHex(s_ain.toLocal8Bit()));
//        }

//        m_cmd_last = tr("0x02");
//        cmdParser(ba_ain, 16);

        // конец теста входов ain
    }
    else
    {
        m_port->close();
        ui->pbCtrlPort->setText(tr("Открыть"));
        ui->groupDevices->setDisabled(true);
        ui->groupDevice->setDisabled(true);
        ui->pbCmdSend->setDisabled(true);

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
    }
}
//--------------------------
void MainWindow::writeData()
{
    if(m_query.isEmpty())
    {
        m_cmd_last  = ui->cbCmdList->currentText();

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

        if(ui->cbCmdList->currentText() == tr("0x3C")) // Установить длительность сигнала
        {
            str.setNum(ui->sbDuration->value(), 16);
            m_query.append(QByteArray::fromHex(str.toLocal8Bit().data()));
        }
        else if(ui->cbCmdList->currentText() == tr("0x3D")) // Установить количество периодов фильтрации
        {
            str.setNum(ui->sbPeriods->value(), 16);
            m_query.append(QByteArray::fromHex(str.toLocal8Bit().data()));
        }
        else if(ui->cbCmdList->currentText() == tr("0x3E")) // Установить количество выборок за период
        {
            str.setNum(ui->sbDiscret->value(), 16);
            m_query.append(QByteArray::fromHex(str.toLocal8Bit().data()));
        }
        else if(ui->cbCmdList->currentText() == tr("0x3F")) // Установить длительность сигнала в мс для фильтрации
        {
            str.setNum(ui->sbSignal->value(), 16);
            m_query.append(QByteArray::fromHex(str.toLocal8Bit().data()));
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
        ui->pteConsole->appendPlainText(tr("ЗАПИСЬ КОМАНДЫ: ") + ui->cbCmdList->description(ui->cbCmdList->currentIndex()));

        m_query.clear();
        m_query_count = 0;
    }
    else
        writeData();
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
    Q_UNUSED(addr);

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

        ui->cbCmdList->setCurrentIndex(cmd);
        cmdDescription(ui->cbCmdList->description(cmd));

        writeData();
    }
}
//---------------------------------------
void MainWindow::initFilter(QString text)
{
    if(text == tr("0x3C") || text == tr("0x3D") || text == tr("0x3E") || text == tr("0x3F"))
    {
        ui->gboxFilter->setEnabled(true);
    }
    else
        ui->gboxFilter->setDisabled(true);
}
