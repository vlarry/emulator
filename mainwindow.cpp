#include "mainwindow.h"
#include "ui_mainwindow.h"
//--------------------------------------
MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_port(Q_NULLPTR),
    m_lblMessage(Q_NULLPTR),
    m_cmd_last("")
{
    ui->setupUi(this);

    QPalette p = ui->pteConsole->palette();

    p.setColor(QPalette::Base, QColor(Qt::black));
    p.setColor(QPalette::Text, QColor(Qt::green));

    ui->pteConsole->setPalette(p);

    m_lblMessage = new QLabel(ui->statusBar);
    ui->statusBar->addWidget(m_lblMessage);

    initSerialPort();
    initConnect();

    ui->groupDevices->setDisabled(true);
    ui->groupDevice->setDisabled(true);
    ui->pbCmdSend->setDisabled(true);

    refreshSerialPort();

    ui->cbCmdList->slotActivated(0);

    initIO();
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

    m_output_dev.append((ui->OUT1));
    m_output_dev.append((ui->OUT2));
    m_output_dev.append((ui->OUT3));
    m_output_dev.append((ui->OUT4));
    m_output_dev.append((ui->OUT5));
    m_output_dev.append((ui->OUT6));
    m_output_dev.append((ui->OUT7));
    m_output_dev.append((ui->OUT8));

    setIO(m_input_dev, false);
    setIO(m_output_dev, true);
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
    quint8 addr = (quint8)ui->sbDeviceAddress->value() << 6;
    quint8 cmd_size = ui->cbCmdList->size(m_cmd_last);

    check_sum |= addr;
    check_sum += cmd_size - 1;

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

    switch(m_cmd_last.toInt())
    {
        case 0x00:
            for(quint8 i = 0; i < size; ++i)
            {
                quint8 byte = data.at(i);

                for(quint8 j = 0; j < 8; j += 2)
                {
                    quint8 channels = byte >> j;
                    quint8 ch_state = channels & 0x03;
                    quint8 ch_num   = j/2 + (i*4);

                    qDebug() << "channel: " << ch_num << ", state: " << ch_state;

                    CIODevice* io = m_input_dev.at(ch_num);

                    switch(ch_state)
                    {
                        case 0x00: // сигнал отсутствует на входе
                            io->set_state(CIODevice::STATE_OFF);
                        break;

                        case 0x01: // сигнал присутствует на схода
                            io->set_state(CIODevice::STATE_ON);
                        break;

                        case 0x02: // ошибка
                        case 0x03: // канала
                            io->set_state(CIODevice::STATE_ERR);
                        break;
                    }
                }
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
            QMessageBox::critical(this, tr("Open serial port"), m_port->errorString());
            return;
        }

        ui->pbCtrlPort->setText(tr("Close"));
        ui->groupDevices->setEnabled(true);

        ui->groupDevice->setEnabled(true);
        ui->pbCmdSend->setEnabled(true);

        showMessage(ui->cbPortNames->currentText() + " " + tr("is open"));

        m_port->setBaudRate(ui->cbBaudrate->currentText().toInt());
        m_port->setFlowControl(QSerialPort::NoFlowControl);
        m_port->setDataBits(QSerialPort::Data8);
        m_port->setStopBits(QSerialPort::OneStop);
        m_port->setParity(QSerialPort::NoParity);

        QByteArray ba;
        QString s;

        s.setNum(11162880, 16);

        ba.append(s).toHex();

        cmdParser(ba, 3);
    }
    else
    {
        m_port->close();
        ui->pbCtrlPort->setText(tr("Open"));
        ui->groupDevices->setDisabled(true);
        ui->groupDevice->setDisabled(true);
        ui->pbCmdSend->setDisabled(true);

        showMessage(ui->cbPortNames->currentText() + " " + tr("is close"));
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
        ui->pteConsole->appendPlainText(tr("READ DATA: 0x") + m_responce.toHex().toUpper());

        quint8 check_sum = getChecksum(m_responce, m_responce.size() - 1);

        if(check_sum == m_responce.at(m_responce.size() - 1))
        {
            qDebug() << "check sum is valid";
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
        QString str = m_cmd_last;
        quint8 cmd = (quint8)str.remove(QRegExp("0x")).toInt(Q_NULLPTR, 16);
        quint8 addr = (quint8)ui->sbDeviceAddress->value() << 6;

        cmd |= addr;

        m_port->setParity(QSerialPort::MarkParity); // enable 9 bit

        quint8 chsum = (cmd + 1)^0xFF;

        QString s_cmd, s_chsum;

        s_cmd.setNum(cmd, 16);
        s_chsum.setNum(chsum, 16);

        m_query.append(QByteArray::fromHex(s_cmd.toLocal8Bit().data()));
        m_query.append(QByteArray::fromHex(s_chsum.toLocal8Bit().data()));
    }

    m_port->write(m_query);
    ui->pteConsole->appendPlainText(tr("WRITE DATA: 0x") + m_query.toHex().toUpper());
}
//---------------------------------------
void MainWindow::BytesWriten(qint64 byte)
{
    Q_UNUSED(byte);

    if(m_port->parity() == QSerialPort::MarkParity)
        m_port->setParity(QSerialPort::SpaceParity); // reset 9bit - this is data

    ui->pteConsole->appendPlainText(tr("SEND CMD: ") + ui->cbCmdList->description(ui->cbCmdList->currentIndex()));

    m_query.clear();
}
//---------------------------------------------------------
void MainWindow::cmdDescription(const QString& description)
{
    QString desc = description;
    QPalette p(ui->lblCmdDescription->palette());

    if(desc.toUpper() == tr("RESERVE"))
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
