#include "mainwindow.h"
#include "ui_mainwindow.h"
//--------------------------------------
MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_port(Q_NULLPTR),
    m_lblMessage(Q_NULLPTR),
    m_count(0)
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
    ui->groupDevice_01->setDisabled(true);
    ui->groupDevice_02->setDisabled(true);
    ui->pbCmdSend->setDisabled(true);

    refreshSerialPort();

    ui->cbCmdList->slotActivated(0);

//    ui->cbCmdList->addItems(QStringList() << tr("0x00") << tr("0x01") << tr("0x02"));
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
//--------------------------------------------------
void MainWindow::showMessage(const QString& message)
{
    m_lblMessage->setText(message);
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
        ui->groupDevice_01->setEnabled(true);
        ui->groupDevice_02->setEnabled(true);
        ui->pbCmdSend->setEnabled(true);

        showMessage(ui->cbPortNames->currentText() + " " + tr("is open"));

        m_port->setBaudRate(ui->cbBaudrate->currentText().toInt());
        m_port->setFlowControl(QSerialPort::NoFlowControl);
        m_port->setDataBits(QSerialPort::Data8);
        m_port->setStopBits(QSerialPort::OneStop);
        m_port->setParity(QSerialPort::NoParity);
    }
    else
    {
        m_port->close();
        ui->pbCtrlPort->setText(tr("Open"));
        ui->groupDevices->setDisabled(true);
        ui->groupDevice_01->setDisabled(true);
        ui->groupDevice_02->setDisabled(true);
        ui->pbCmdSend->setDisabled(true);

        showMessage(ui->cbPortNames->currentText() + " " + tr("is close"));
    }
}
//-------------------------
void MainWindow::readData()
{
    QByteArray ba = m_port->readAll();

    ui->pteConsole->appendPlainText(tr("READ: 0x") + ba.toHex().toUpper());
}
//--------------------------
void MainWindow::writeData()
{
    if(m_query.isEmpty())
    {
        QString str = ui->cbCmdList->currentText().remove(QRegExp("0x"));
        quint8 cmd = (quint8)str.toInt(Q_NULLPTR, 16);
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

    m_port->write(m_query.at(m_count));
    ui->pteConsole->appendPlainText(tr("WRITE: ") + m_query.at(m_count).toHex().toUpper());
}
//---------------------------------------
void MainWindow::BytesWriten(qint64 byte)
{
    Q_UNUSED(byte);

    if(m_port->parity() == QSerialPort::MarkParity)
        m_port->setParity(QSerialPort::SpaceParity); // reset 9bit - this is data

    m_count++;

    if(m_count == m_query.count())
    {
        ui->pteConsole->appendPlainText(tr("WRITE CMD: ") + ui->cbCmdList->description(ui->cbCmdList->currentIndex()));

        m_query.clear();
        m_count = 0;
    }
    else
        writeData();
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
