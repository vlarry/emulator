#include "mainwindow.h"
#include "ui_mainwindow.h"
//--------------------------------------
MainWindow::MainWindow(QWidget* parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_lblStatusBar(Q_NULLPTR),
    m_ftHandle(Q_NULLPTR)
{
    ui->setupUi(this);

    connect(ui->pbtnStatePort, SIGNAL(toggled(bool)), this, SLOT(changeStateComPort(bool)));
    connect(ui->tbtnRefreshComList, SIGNAL(clicked()), this, SLOT(refreshComPort()));

    QPalette p = ui->txtedtConsole->palette();

    p.setColor(QPalette::Base, QColor(Qt::black));
    p.setColor(QPalette::Text, QColor(Qt::green));

    ui->txtedtConsole->setPalette(p);

    QStringList baudrate_list;

    baudrate_list << "1200" << "2400" << "4800" << "9600" << "19200" << "38400" << "57600" << "115200";

    ui->cboxBaudrate->addItems(baudrate_list);

    if(baudrate_list.size() >= 8)
        ui->cboxBaudrate->setCurrentIndex(7);
    else if(baudrate_list.size() != 0)
        ui->cboxBaudrate->setCurrentIndex(0);

    m_lblStatusBar = new QLabel(ui->statusBar);
    ui->statusBar->addWidget(m_lblStatusBar);

    refreshComPort();
}
//-----------------------
MainWindow::~MainWindow()
{
    if(m_ftHandle != Q_NULLPTR)
    {
        FT_Close(m_ftHandle);
    }

    delete ui;
}
//-------------------------------
void MainWindow::refreshComPort()
{
    ui->cboxComPortList->clear();

    FT_STATUS ftStatus;
    DWORD     numDevs;

    ftStatus = FT_CreateDeviceInfoList(&numDevs);

    if(ftStatus != FT_OK)
    {
        QMessageBox::critical(this, tr("Search devices"), tr("Can't find installed devices"));
        return;
    }

    FT_DEVICE_LIST_INFO_NODE* devInfo;

    qDebug() << numDevs;

    if(numDevs > 0)
    {
        devInfo = new FT_DEVICE_LIST_INFO_NODE;
        ftStatus = FT_GetDeviceInfoList(devInfo, &numDevs);

        if(ftStatus != FT_OK)
        {
            QMessageBox::critical(this, tr("Get information"), tr("Can't get device information"));
            return;
        }
    }

    for(DWORD i = 0; i < numDevs; ++i)
    {
        ui->txtedtConsole->appendPlainText(devInfo[i].Description);
        ui->txtedtConsole->appendPlainText(QString::number(devInfo[i].Flags));
        ui->txtedtConsole->appendPlainText(QString::number(devInfo[i].ID));
        ui->txtedtConsole->appendPlainText(QString::number(devInfo[i].LocId));
        ui->txtedtConsole->appendPlainText(devInfo[i].SerialNumber);
        ui->txtedtConsole->appendPlainText(QString::number(devInfo[i].Type));

        ui->cboxComPortList->addItem(devInfo[i].Description);
    }

    ui->cboxComPortList->setCurrentIndex(0);
}
//---------------------------------------------
void MainWindow::changeStateComPort(bool state)
{
    FT_STATUS ftStatus;

    if(state)
    {
        QString ftDescription = ui->cboxComPortList->currentText();

        ftStatus = FT_OpenEx((PVOID)ftDescription.toStdString().c_str(), FT_OPEN_BY_DESCRIPTION, &m_ftHandle);

        if(ftStatus != FT_OK)
        {
            QMessageBox::critical(this, tr("Open serial port"), tr("Can't open the port"));
            m_ftHandle = Q_NULLPTR;

            return;
        }

        ftStatus = FT_SetBaudRate(m_ftHandle, ui->cboxBaudrate->currentText().toLong());

        if(ftStatus != FT_OK)
        {
            QMessageBox::critical(this, tr("Set baudrate"), tr("Can't set the baudrate"));
            m_ftHandle = Q_NULLPTR;

            return;
        }

        ftStatus = FT_SetDataCharacteristics(m_ftHandle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_MARK);

        if(ftStatus != FT_OK)
        {
            QMessageBox::critical(this, tr("Set data characteristics"), tr("Can't set the data characteristics"));
            m_ftHandle = Q_NULLPTR;

            return;
        }

        connect(ui->pbtnCmdSend, SIGNAL(clicked()), this, SLOT(send()));

        ui->pbtnStatePort->setText(tr("Close"));
        m_lblStatusBar->setText(ui->cboxComPortList->currentText() + " is open");
    }
    else
    {
        if(m_ftHandle != Q_NULLPTR)
        {
            ftStatus = FT_Close(m_ftHandle);

            if(ftStatus != FT_OK)
            {
                QMessageBox::critical(this, tr("Close serial port"), tr("Can't close the port"));
                delete m_ftHandle;
                m_ftHandle = Q_NULLPTR;

                return;
            }

            ui->pbtnStatePort->setText(tr("Open"));
            m_lblStatusBar->setText(ui->cboxComPortList->currentText() + " is close");
        }
    }
}
//---------------------
void MainWindow::send()
{
    char cmd = (char)0x45;
    char ans;

    DWORD bytes;

    FT_STATUS ftStatus = FT_SetDataCharacteristics(m_ftHandle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_MARK);

    ftStatus = FT_Write(m_ftHandle, &cmd, 1, &bytes);

    ftStatus = FT_Read(m_ftHandle, &ans, 1, &bytes);

    QString s;
    s.setNum((int)ans, 16);

    ui->txtedtConsole->appendPlainText(tr("Receive: ") + s);

    //------------------------------------------
    static COMSTAT oldCS = {0};
    static DWORD dwOldErrors = 0;
    COMSTAT newCS;
    DWORD dwErrors;
    bool bChanged = false;

    qDebug() << FT_W32_ClearCommError(m_ftHandle, &dwErrors, (FTCOMSTAT*)&newCS);

    qDebug() << dwErrors;
}
