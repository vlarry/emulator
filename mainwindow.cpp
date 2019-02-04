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
    m_mik_interface(Q_NULLPTR),
    m_command(Q_NULLPTR),
    m_set_intput_widget(Q_NULLPTR),
    m_input_help_widget(Q_NULLPTR),
    m_cmd_save(""),
    m_db_controller(Q_NULLPTR),
    m_db_journal(Q_NULLPTR)
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
    m_input_help_widget    = new CInputHelp(QPixmap(":/images/resource/images/input_help.png"), this);

    QDir dir;

    if(!dir.exists("db"))
        dir.mkdir("db");

    m_db_controller = new CDbController("db/serialdb.db");

    m_conf_widget->hide();
    m_set_intput_widget->hide();

    ui->lineEditMessageQueue->setText("0");
    ui->actionTerminal->setChecked(true);
    ui->actionCommand->setChecked(false);
    ui->actionInterfaceMIK01->setChecked(false);

    // Заполение списка связанных команд
    m_cmd_bind["0x05"] = "0x04";
    m_cmd_bind["0x3A"] = "0x1E";
    m_cmd_bind["0x06"] = "0x01";
    m_cmd_bind["0x07"] = "0x01";
    m_cmd_bind["0x08"] = "0x01";
    m_cmd_bind["0x09"] = "0x01";
    m_cmd_bind["0x0A"] = "0x01";
    m_cmd_bind["0x0B"] = "0x01";
    m_cmd_bind["0x0C"] = "0x01";
    m_cmd_bind["0x0D"] = "0x01";
    m_cmd_bind["0x0E"] = "0x01";
    m_cmd_bind["0x0F"] = "0x01";
    m_cmd_bind["0x10"] = "0x01";
    m_cmd_bind["0x11"] = "0x01";
    m_cmd_bind["0x12"] = "0x01";
    m_cmd_bind["0x13"] = "0x01";
    m_cmd_bind["0x14"] = "0x01";
    m_cmd_bind["0x15"] = "0x01";
}
//-----------------------
MainWindow::~MainWindow()
{
    if(m_file_ain->isOpen())
        m_file_ain->close();

    if(m_db_controller)
    {
        delete m_db_controller;
        m_db_controller = Q_NULLPTR;
    }

    delete ui;
}
//----------------------------
void MainWindow::initConnect()
{
    connect(ui->tbPortRefresh, SIGNAL(clicked()), this, SLOT(refreshSerialPort()));
    connect(m_timerRefreshPort, SIGNAL(timeout()), this, SLOT(refreshSerialPort()));
    connect(ui->pbCtrlPort, SIGNAL(clicked(bool)), this, SLOT(ctrlSerialPort(bool)));
    connect(m_port, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(m_port, SIGNAL(bytesWritten(qint64)), this, SLOT(BytesWriten(qint64)));
    connect(ui->pbCmdSend, SIGNAL(clicked()), this, SLOT(sendCmd()));
    connect(ui->cbCmdList, SIGNAL(changeDescription(QString)), this, SLOT(cmdDescription(QString)));
    connect(ui->cbCmdList, SIGNAL(currentIndexChanged(int)), ui->cbCmdList, SLOT(slotActivated(int)));
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
    connect(ui->cbCmdList, SIGNAL(currentIndexChanged(int)), m_command, SLOT(setCurrentIndex(int)));

    connect(ui->cboxRepeatInputs, SIGNAL(clicked(bool)), this, SLOT(autoRepeatInputs(bool)));
    connect(ui->cboxRepeatAIN, SIGNAL(clicked(bool)), this, SLOT(autoRepeatAIN(bool)));
    connect(m_timerAutoRepeatInput, SIGNAL(timeout()), this, SLOT(autoRepeatTimInputs()));
    connect(m_timerAutoRepeatAIN, SIGNAL(timeout()), this, SLOT(autoRepeatTimAIN()));
    connect(m_timerTimeoutQuery, SIGNAL(timeout()), this, SLOT(timeoutTim()));

    connect(ui->dwTerminal, SIGNAL(visibilityChanged(bool)), this, SLOT(visiblityTerminal(bool)));
    connect(ui->actionTerminal, &QAction::triggered, this, &MainWindow::visiblityTerminal);
    connect(ui->actionCommand, &QAction::triggered, this, &MainWindow::visiblityCommand);
    connect(ui->actionInterfaceMIK01, &QAction::triggered, this, &MainWindow::visiblityInterfaceMIK01);
    connect(m_command, &QCommand::doubleClickCmd, this, &MainWindow::sendCmd);
    connect(m_command, &QCommand::clickCmd, this, &MainWindow::initFilter);
    connect(m_command, &QCommand::closeCommand, this, &MainWindow::visiblityCommand);
    connect(m_mik_interface, &CBZUInterface::closed, this, &MainWindow::visiblityInterfaceMIK01);

    connect(ui->pushButtonInputSet, &QPushButton::clicked, this, &MainWindow::setupDiscretInput);
    connect(m_set_intput_widget, &CSetInput::apply, this, &MainWindow::discretInputProcess);
    connect(m_command, &QCommand::clickCmdIndex, ui->cbCmdList, &QComboBox::setCurrentIndex);
    connect(ui->toolButtonInputHelp, &QToolButton::clicked, this, &MainWindow::discretInputHelp);
    connect(m_mik_interface, &CBZUInterface::ledStateSave, this, &MainWindow::setupExtandOut);
    connect(ui->actionDbJournal, &QAction::triggered, this, &MainWindow::openDbJournal);
    connect(m_conf_widget, &CConfigurationModuleWidget::newValueAppend, this, &MainWindow::writeDataToDb);
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
//----------------------------------------------------------
void MainWindow::initDbController(CDbController* controller)
{
    if(controller)
    {
        QStringList listModification = controller->dataListFromTable("modification");
        QStringList listCustomer = controller->dataListFromTable("customer");

        m_conf_widget->initLIst(listModification, listCustomer);
    }
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
        case 0x00: // чтение дискретных каналов входов
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

        case 0x01: // чтение дискретных каналов выходов
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

        case 0x02: // чтение расчетных величин 1..4 формата FLOAT
            for(quint8 i = 0; i < size; i += 4)
            {
                quint8 j;

                for(j = 0; j < 4; ++j)
                {
                    ain.byte[j] = static_cast<quint8>(data.at(i + j));
                }

                QString str;

                // запись аналоговых величин в файл
                in << QString(QString::number(static_cast<double>(ain.number)) + '\t');

                if(i == 8)
                {
                    str = QString::number(static_cast<double>(ain.number), 'f', 2) + " " + QString(QChar(176)) + "C";

                    m_ain_dev.at(2)->setToolTip(tr("Внутрення температура процессора"));
                }

                if(ui->sbDeviceAddress->value() == MDVV_01) // МДВВ-01
                {
                    if(i == 0) // первая ячейка AIN
                    {
                        str = QString::number(static_cast<double>(ain.number), 'f', 2) + tr(" В");
                        m_ain_dev.at(0)->setToolTip(tr("Наличие питания 5VP"));
                    }
                    else if(i == 4)
                    {
                        str = QString::number(static_cast<double>(ain.number)*1000, 'f', 3) + tr(" mA");
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

                        str = QString::number(static_cast<double>(ain.number), 'f', 2) + " " + QString(QChar(176)) + "C";
                        m_ain_dev.at(2)->setToolTip(tr("Внутрення температура, DS18B20"));
                    }
                }
                else if(ui->sbDeviceAddress->value() == MDVV_02) // МДВВ-02
                {
                    if(i == 0 || i == 4)
                    {
                        str = QString::number(static_cast<double>(ain.number), 'f', 2) + " " + QString(QChar(176)) + "C"; // добавление знака градусов
                    }

                    m_ain_dev.at(0)->setToolTip(tr("Температура по первому каналу"));
                    m_ain_dev.at(1)->setToolTip(tr("Температура по второму каналу"));
                }

                m_ain_dev.at(i/4)->setText(str);
            }

            in << '\n';
        break;

        case 0x03: // чтение регистра расширения дискретных каналов входов
            if(ui->sbDeviceAddress->value() == MIK_01)
            {
                m_mik_interface->setKeyboardState(data);
            }
        break;

        case 0x04: // чтение регистра расширения дискретных каналов выходов
            if(ui->sbDeviceAddress->value() == MDVV_02)
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
            else if(ui->sbDeviceAddress->value() == MIK_01)
            {
                m_mik_interface->setLedState(data);
            }
        break;

        case 0x1D: // вывод отладочной информации (счетчики ошибок)
            ui->twPeriphery->setCurrentIndex(1);
            // чтение количества запросов
            temp.byte[0] = static_cast<quint8>(data[0]);
            temp.byte[1] = static_cast<quint8>(data[1]);

            ui->lineEditRequestCounter->setText(QString::number(temp.data));

            // чтение количества ошибок команд
            temp.byte[0] = static_cast<quint8>(data[2]);
            temp.byte[1] = static_cast<quint8>(data[3]);

            ui->lineEditErrorCmdCounter->setText(QString::number(temp.data));

            // чтение количества ошибок контрольной суммы
            temp.byte[0] = static_cast<quint8>(data[4]);
            temp.byte[1] = static_cast<quint8>(data[5]);

            ui->lineEditErrorChecksumCounter->setText(QString::number(temp.data));

            // чтение количества ошибок отсутствия обработчика команд
            temp.byte[0] = static_cast<quint8>(data[6]);
            temp.byte[1] = static_cast<quint8>(data[7]);

            ui->lineEditErrorProcessCounter->setText(QString::number(temp.data));

            // чтение количества ошибок таймаута
            temp.byte[0] = static_cast<quint8>(data[10]);
            temp.byte[1] = static_cast<quint8>(data[11]);

            ui->lineEditErrorTimeoutCounter->setText(QString::number(temp.data));
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
            m_conf_widget->setModuleType(data.at(0), CConfigurationModuleWidget::CURRENT);

            tdata = static_cast<quint8>(data.at(1));
            tdata = ((tdata >> 4)&0x0F)*1000 + (tdata&0x0F)*100;
            tdata += ((static_cast<quint8>(data.at(2))) >> 4)*10 + ((static_cast<quint8>(data.at(2)))&0x0F);
            ui->leDeviceNumber->setText(QString::number(tdata, 10));
            m_conf_widget->setModuleNumber(tdata, CConfigurationModuleWidget::CURRENT);

            tdata = static_cast<quint8>(data.at(3));
            tdata = ((tdata >> 4)&0x0F)*10 + (tdata&0x0F);
            ui->leDeviceLotNum->setText(QString::number(tdata, 10));
            m_conf_widget->setModuleNumberParty(tdata, CConfigurationModuleWidget::CURRENT);

            tdata = static_cast<quint8>(data.at(4));
            tdata = ((tdata >> 4)&0x0F)*10 + (tdata&0x0F);
            ui->leDeviceFirmwareVar->setText(QString::number(tdata, 10));
            m_conf_widget->setModuleFirmwareVariant(tdata, CConfigurationModuleWidget::CURRENT);

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
            m_conf_widget->setModuleFirmwareDate(s, CConfigurationModuleWidget::CURRENT);
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

                temp.byte[0] = static_cast<quint8>(data[1]);
                temp.byte[1] = static_cast<quint8>(data[2]);

                ui->leTimeDSDIN->setText(QString::number(temp.data));
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

        case 0x02: // ошибка канала для МДВВ-01 (мигание для остальных модулей)
        case 0x03: // ошибка канала для МДВВ-01 (резерв для остальных модулей = миганию)
            CIODevice::state_t state;
            quint8 addr = io->get_addr();

            if(addr == MIK_01) // устройство МИК-01
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

    m_settings->beginGroup("MODULES");
        ui->sbDeviceAddress->setValue(m_settings->value("address", 0).toInt());
        ui->actionTerminal->setChecked(m_settings->value("terminal", true).toBool());
        ui->actionCommand->setChecked(m_settings->value("command_visiblity", false).toBool());
        ui->actionInterfaceMIK01->setChecked(m_settings->value("mik01_visiblity", true).toBool());
        visiblityTerminal(ui->actionTerminal->isChecked());
        visiblityCommand(ui->actionCommand->isChecked());
        m_mik_interface->restoreGeometry(m_settings->value("mik01_widget").toByteArray());
        m_command->restoreGeometry(m_settings->value("command_widget").toByteArray());
    m_settings->endGroup();

    m_settings->beginGroup("INTERFACE");
        ui->cboxRepeatInputs->setChecked(m_settings->value("inputs", false).toBool());
        ui->cboxRepeatAIN->setChecked(m_settings->value("ain", false).toBool());
        ui->sbRepeatInputs->setValue(m_settings->value("inputs_timer", 200).toInt());
        ui->sbRepeatAIN->setValue(m_settings->value("ain_timer", 200).toInt());
    m_settings->endGroup();

    m_settings->beginGroup("GUI");
        restoreGeometry(m_settings->value("main_window").toByteArray());
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

    addrChanged(ui->sbDeviceAddress->value());
}
//-----------------------------
void MainWindow::saveSettings()
{
    m_settings->beginGroup("COM");
        m_settings->setValue("port", ui->cbPortNames->currentText());
        m_settings->setValue("baudrate", ui->cbBaudrate->currentText());
    m_settings->endGroup();

    m_settings->beginGroup("MODULES");
        m_settings->setValue("address", ui->sbDeviceAddress->value());
        m_settings->setValue("terminal", ui->actionTerminal->isChecked());
        m_settings->setValue("command_visiblity", ui->actionCommand->isChecked());
        m_settings->setValue("mik01_visiblity", ui->actionInterfaceMIK01->isChecked());
        if(ui->actionInterfaceMIK01->isChecked())
            m_settings->setValue("mik01_widget", m_mik_interface->saveGeometry());
        if(ui->actionCommand->isChecked())
            m_settings->setValue("command_widget", m_command->saveGeometry());
    m_settings->endGroup();

    m_settings->beginGroup("INTERFACE");
        m_settings->setValue("inputs", ui->cboxRepeatInputs->isChecked());
        m_settings->setValue("ain", ui->cboxRepeatAIN->isChecked());
        m_settings->setValue("inputs_timer", ui->sbRepeatInputs->value());
        m_settings->setValue("ain_timer", ui->sbRepeatAIN->value());
    m_settings->endGroup();

    m_settings->beginGroup("GUI");
        m_settings->setValue("main_window", this->saveGeometry());
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
        m_command->hide();
    }

    if(m_mik_interface == Q_NULLPTR)
    {
        m_mik_interface = new CBZUInterface(this);
        if(ui->actionInterfaceMIK01->isChecked())
        {
            m_mik_interface->show();
        }
        else
        {
            m_mik_interface->hide();
        }
    }

    initSerialPort();
    initIO();
    initConnect();
    initDbController(m_db_controller);

    loadSettings();
    refreshSerialPort();

    ui->cbCmdList->slotActivated(0);
    ui->twPeriphery->setCurrentIndex(0);
    initFilter(ui->cbCmdList->currentText());
    addrChanged(ui->sbDeviceAddress->value());
    ui->actionInterfaceMIK01->setEnabled(false);

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
//-----------------------------------------
QByteArray MainWindow::formatSerialNumber()
{
    QByteArray keyCurrent   = m_conf_widget->moduleKeyCurrent();
    QByteArray keyNew       = m_conf_widget->moduleKeyNew();
    int        num          = m_conf_widget->moduleNumber(CConfigurationModuleWidget::NEW);
    int        numParty     = m_conf_widget->moduleNumberParty(CConfigurationModuleWidget::NEW);
    int        firmwareVar  = m_conf_widget->moduleFirmwareVariant(CConfigurationModuleWidget::NEW);

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

    return ba;
}
//------------------------------------
void MainWindow::configurationWindow()
{
    if(!m_conf_widget->isHidden())
    {
        sendData("0x1E");
        Sleep(100); // засыпаем на 10мс, чтобы данные были прочитаны и записаны

        CDbController::serial_num_t sn = m_db_controller->serialNumberRead();

        m_conf_widget->setModuleType(m_conf_widget->moduleType(CConfigurationModuleWidget::CURRENT), CConfigurationModuleWidget::NEW);
        m_conf_widget->setModuleFirmwareDate(QDate::currentDate().toString("dd.MM.yyyy"), CConfigurationModuleWidget::NEW);

        if(sn.dev_code != -1) // если данные в базе присутствуют
        {
            m_conf_widget->setModuleNumber(sn.dev_num + 1, CConfigurationModuleWidget::NEW);
            m_conf_widget->setModuleNumberParty(sn.dev_party, CConfigurationModuleWidget::NEW);
            m_conf_widget->setModuleFirmwareVariant(sn.dev_firmware_var, CConfigurationModuleWidget::NEW);
        }
        else // данных в базе нет
        {
            m_conf_widget->setModuleNumber(m_conf_widget->moduleNumber(CConfigurationModuleWidget::CURRENT) + 1, CConfigurationModuleWidget::NEW);
            m_conf_widget->setModuleNumberParty(m_conf_widget->moduleNumberParty(CConfigurationModuleWidget::CURRENT), CConfigurationModuleWidget::NEW);
            m_conf_widget->setModuleFirmwareVariant(m_conf_widget->moduleFirmwareVariant(CConfigurationModuleWidget::CURRENT), CConfigurationModuleWidget::NEW);
        }

        if(m_conf_widget->exec() == QDialog::Accepted)
        {
            sn.dev_num      = m_conf_widget->moduleNumber(CConfigurationModuleWidget::NEW);
            sn.dev_party    = m_conf_widget->moduleNumberParty(CConfigurationModuleWidget::NEW);
            sn.dev_firmware_var = m_conf_widget->moduleFirmwareVariant(CConfigurationModuleWidget::NEW);

            QByteArray key = m_conf_widget->moduleKeyCurrent();
            QByteArray key_empty = QByteArray::fromHex(QString("00000000").toUtf8());

            if(key == key_empty ||
               m_conf_widget->moduleKeyCurrent().isEmpty())
            {
                QMessageBox::warning(this, tr("Запись серийного в модуль"), tr("Не валидный ключ разблокировки записи!"));
                return;
            }

            if(m_db_controller->findEqualData(sn))
            {
                QMessageBox::warning(this, tr("Запись серийного номера БД"), tr("Такой серийный номер уже существует!"));
                return;
            }

            QByteArray sn_data = formatSerialNumber();

            write("0x3A", sn_data);
        }
    }
}
//------------------------------------------------
void MainWindow::visiblitySerialNumber(bool state)
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
/*!
 * \brief MainWindow::discretInputProcess
 *
 * Формирование запроса на запись настроек дискретных входов
 */
void MainWindow::discretInputProcess()
{
    int type = 1;

    if(ui->radioButtonInputSingle->isChecked())
    {
        type = 0;
    }

    QByteArray data = m_set_intput_widget->intputSettings(type);
    write("0x3F", data);
}
//---------------------------------
void MainWindow::discretInputHelp()
{
    if(m_input_help_widget->isHidden())
        m_input_help_widget->show();
}
//-------------------------------
void MainWindow::setupExtandOut()
{
    if(ui->sbDeviceAddress->value() == MDVV_02)
    {
        QByteArray data;
        quint8 channels = 0x00;

        for(quint8 i = 0, bits = 0; i < m_output_dev.size(); i++)
        {
            if(bits == 8)
            {
                data.append(QByteArray::fromHex(QByteArray::number(channels, 16)));
                channels = 0x00;
                bits = 0;
            }

            channels |= (static_cast<quint8>(m_output_dev[i]->get_state()) << bits);

            bits += 2;
        }

        write("0x05", data);
    }
    else if(ui->sbDeviceAddress->value() == MIK_01)
    {
        QByteArray data = m_mik_interface->ledStates();
        write("0x05", data);
    }
}
//-----------------------------------
void MainWindow::timeoutCmdBindRead()
{
    QString cmd_read = m_cmd_bind[m_cmd_save];

    if(m_cmd_save == "0x3A") // если это запись серийного номера, т.е. значит она прошла успешно, то заносим данные в базу данных
    {
        CDbController::serial_num_t sn;

        sn.dev_code          = ui->sbDeviceAddress->value();
        sn.dev_num           = m_conf_widget->moduleNumber(CConfigurationModuleWidget::NEW);
        sn.dev_party         = m_conf_widget->moduleNumberParty(CConfigurationModuleWidget::NEW);
        sn.dev_firmware_var  = m_conf_widget->moduleFirmwareVariant(CConfigurationModuleWidget::NEW);
        sn.dev_firmware_date = QDate::fromString(m_conf_widget->moduleFirmwareDate(CConfigurationModuleWidget::CURRENT), "dd.MM.yyyy").toString("yyyy-MM-dd");
        sn.date              = QDate::currentDate().toString("yyyy-MM-dd");
        sn.time              = QTime::currentTime().toString("hh:mm:ss");
        sn.modification      = m_conf_widget->moduleModification();
        sn.customer          = m_conf_widget->moduleCustomer();

        if(!m_db_controller->serialNumberWrite(sn))
            QMessageBox::warning(this, tr("Запись серийного номера БД"), tr("Не удалось записать серийный номер в БД!"));
    }

    m_cmd_save.clear();
    sendCmd(cmd_read); // читаем после записи
}
//------------------------------
void MainWindow::openDbJournal()
{
    if(!m_db_journal)
    {
        m_db_journal = new CDbJornal(this);
        connect(m_db_journal, &CDbJornal::closeJournal, this, &MainWindow::closeDbJournal);
        CDbController::serial_num_list_t list = m_db_controller->serialNumberListRead();
        m_db_journal->setDataToTable(list);
        m_db_journal->show();
    }
}
//-------------------------------
void MainWindow::closeDbJournal()
{
    if(m_db_journal)
    {
        disconnect(m_db_journal, &CDbJornal::closeJournal, this, &MainWindow::closeDbJournal);
        delete m_db_journal;
        m_db_journal = Q_NULLPTR;
    }
}
//--------------------------------------------------------------------------
void MainWindow::writeDataToDb(const QString table_name, const QString data)
{
    m_db_controller->writeDataToTable(table_name, data);
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
    else if(count != 0 && ui->cbPortNames->count() != 0)
    {
        ui->cbPortNames->clear();
        ui->cbPortNames->addItems(port_list);
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

        ui->pbCtrlPort->setText(tr("Закрыть"));

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

        if(static_cast<DEVICE_Type>(ui->sbDeviceAddress->value()) == MIK_01)
        {
            ui->actionInterfaceMIK01->setEnabled(true);
            visiblityInterfaceMIK01(ui->actionInterfaceMIK01->isChecked());
            sendCmd("0x04");
        }
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

        m_mik_interface->ledReset();
    }

    ui->pbCtrlPort->setChecked(state);

    if(ui->cboxRepeatInputs->isChecked())
        autoRepeatInputs(state);
    if(ui->cboxRepeatAIN->isChecked())
        autoRepeatAIN(state);
}
//-------------------------
void MainWindow::readData()
{
    QByteArray ba = m_port->readAll();

    m_responce.append(ba);

    quint8 cmd_size = ui->cbCmdList->size(m_cmd_last);
    quint8 responce_size = static_cast<quint8>(m_responce.size());

    if(responce_size == cmd_size)
    {
        quint8 checksum_calc = getChecksum(m_responce, static_cast<quint8>(m_responce.size()) - 1);
        quint8 checksum_read = static_cast<quint8>(m_responce.at(static_cast<quint8>(m_responce.size()) - 1));

        if(checksum_calc == checksum_read)
        {
            cmdParser(m_responce, static_cast<quint8>(m_responce.size()) - 1);
            ui->pteConsole->appendPlainText(tr("ЧТЕНИЕ: 0x%1\n%2").arg(QString(m_responce.toHex().toUpper())).arg("*****"));
        }
        else
            ui->pteConsole->appendPlainText(tr("ЧТЕНИЕ: ОШИБКА CRC\n%1").arg("*****"));

        ui->pteConsole->verticalScrollBar()->setValue(ui->pteConsole->verticalScrollBar()->maximum());

        m_query.clear();
        m_query_count = 0;
        m_responce.clear();
        sendData(); // подтверждаем принятие данных отправкой пустого сообщения

        if(!m_cmd_save.isEmpty())
        {
            m_cmd_read_timer.singleShot(10, this, &MainWindow::timeoutCmdBindRead);
        }
    }
    else if(m_responce.size() > cmd_size)
    {
        m_responce.clear();
        m_cmd_save.clear();
    }
}
//----------------------------------------------
void MainWindow::sendCmd(const QString& cmd_str)
{
    if(!m_port->isOpen())
        return;

    QString cmd = ui->cbCmdList->currentText();

    if(!cmd_str.isEmpty())
        cmd = cmd_str;

    if(cmd.toUpper() == "0X05")
    {
        setupExtandOut(); // запись регистра расширения дискретных каналов выходов
    }
    else if(cmd.toUpper() == "0X3A") // если команда "Запись серийного номера, то открываем дополнительное окно (команду не отправляем)
    {
        if(m_conf_widget->isHidden())
        {
            m_conf_widget->show();
            configurationWindow();
        }
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
    if(!m_port->isOpen())
        return;

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
    if(!m_port->isOpen())
        return;

    if(m_query.isEmpty())
    {
        if(cmd_str.isEmpty())
            return;

        m_cmd_last  = cmd_str;

        quint8 cmd = static_cast<quint8>(QString(m_cmd_last).remove(QRegExp(tr("0x"))).toInt(Q_NULLPTR, 16));

        cmd |= (static_cast<quint8>(ui->sbDeviceAddress->value())) << 6;

        m_query.append(QByteArray::fromHex(QByteArray::number(cmd, 16)));

        if(data.isEmpty())
        {
            qint8 channel_id                 = -1;
            CIODevice::state_t channel_state = CIODevice::STATE_OFF;

            if(cmd >= 0x06 && cmd <= 0x0D)
            {
                channel_id    = static_cast<qint8>(cmd) - 0x06;
                channel_state = CIODevice::STATE_OFF;
            }
            else if(cmd >= 0x0E && cmd <= 0x15)
            {
                channel_id    = static_cast<qint8>(cmd) - 0x0E;
                channel_state = CIODevice::STATE_ON;
            }

            if(channel_id != -1)
            {
                m_output_dev.at(channel_id)->set_state(channel_state);
            }

            QString str;

            if(m_cmd_last == tr("0x3E"))
            {
                str.setNum(ui->sbPeriods->value(), 16);
                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // количество периодов

                str.setNum(ui->sbDiscret->value(), 16);
                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // дискретность

                str.setNum(ui->sbSignal->value(), 16);
                m_query.append(QByteArray::fromHex(str.toLocal8Bit().data())); // длительность сигнала
            }
        }
        else
        {
            m_query.append(data);
        }

        quint8 checksum = getChecksum(m_query, static_cast<quint8>(m_query.size())); // создать контрольную сумму

        m_query.append(QByteArray::fromHex(QByteArray::number(checksum, 16)));

        int index = ui->cbCmdList->findText(m_cmd_last);
        ui->pteConsole->appendPlainText(tr("КОМАНДА: ") + ui->cbCmdList->description(index));
        ui->pteConsole->appendPlainText(tr("ОТПРАВКА ДАННЫХ: ") + m_query.toHex().toUpper());
        m_port->setParity(QSerialPort::MarkParity); // enable 9 bit

        ui->lineEditMessageQueue->setText(QString::number(m_queue_cmd.count()));

        // Сохранение команды, если она устанавливает параметры на модуле, для автоматического запроса чтения
        if(m_cmd_bind.find(m_cmd_last) != m_cmd_bind.end())
            m_cmd_save = m_cmd_last; // Запись регистра расширения дискретных каналов выходов
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
    ui->labelCmdDescription->setToolTip(description);
    ui->labelCmdDescription->setText(description);
}
//------------------------------------
void MainWindow::addrChanged(int addr)
{
    quint8 out_count = 0;

    ui->actionInterfaceMIK01->setEnabled(false); // Вызов клавиатуры МИК-01 становится видимым при выборе адреса 0х02
    ui->groupBoxDSDIN->hide();

    if(m_mik_interface != Q_NULLPTR)
    {
        if(!m_mik_interface->isHidden())
            m_mik_interface->hide();
    }

    if(addr == MDVV_01)
    {
        ui->groupDevices->setTitle(tr("Устройство МДВВ-01"));
        ui->lblAIN1->setText(tr("Напряжение"));
        ui->lblAIN2->setText(tr("Ток"));
        ui->lblAIN3->setText(tr("Температура"));
        ui->groupBoxInputs->setEnabled(true);
        ui->groupBoxOutputs->setEnabled(true);
        ui->groupBoxDSDIN->show();

        out_count = 6;
    }
    else if(addr == MDVV_02)
    {
        ui->groupDevices->setTitle(tr("Устройство МДВВ-02"));
        ui->lblAIN1->setText(tr("Температура"));
        ui->lblAIN2->setText(tr("Температура"));
        ui->lblAIN3->setText(tr("Температура"));
        ui->groupBoxInputs->setEnabled(true);
        ui->groupBoxOutputs->setEnabled(true);

        out_count = 7;
    }
    else if(addr == MIK_01)
    {
        ui->groupDevices->setTitle(tr("Устройство МИК-01"));
        ui->actionInterfaceMIK01->setEnabled(true);
        ui->groupBoxInputs->setDisabled(true);
        ui->groupBoxOutputs->setDisabled(true);

        visiblityInterfaceMIK01(ui->actionInterfaceMIK01->isChecked());

        out_count = 12;
    }
    else
    {
        ui->groupDevices->setTitle(tr("Неопределенное устройство"));
    }

    for(CIODevice* io: m_input_dev)
    {
        io->set_state(CIODevice::STATE_OFF);
        io->set_dev_addr(static_cast<quint8>(ui->sbDeviceAddress->value()));
    }

    for(CIODevice* io: m_output_dev)
    {
        io->set_state(CIODevice::STATE_OFF);
        io->set_dev_addr(static_cast<quint8>(ui->sbDeviceAddress->value()));
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

            sendData(((cmd >= 16)?"0x":"0x0") + str.toUpper());
        }
        else
            write("0x05");
    }
}
//----------------------------------------------
void MainWindow::initFilter(const QString& text)
{
    if(text == "0x3D")
    {
        ui->gboxInputSettings->setEnabled(true);
        ui->gboxInput->setDisabled(true);
        ui->gboxInputSettingsFilter->setDisabled(true);
    }
    else if(text == "0x3E")
    {
        ui->gboxInputSettings->setEnabled(true);
        ui->gboxInput->setDisabled(true);
        ui->gboxInputSettingsFilter->setEnabled(true);
    }
    else if(text == "0x3F")
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
        sendData("0x00"); // чтение дискретных каналов входов
    }
    else // устройство МИК-01
    {
        sendData("0x03"); // чтение регистра расширения дискретных каналов входов (клавиатура)
    }

    if(ui->cboxRepeatInputs->isChecked())
        m_timerAutoRepeatInput->start(ui->sbRepeatInputs->value());
}
//---------------------------------
void MainWindow::autoRepeatTimAIN()
{
    sendData("0x02");

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
    ui->dwTerminal->setVisible(visible);
}
//----------------------------------------------------
void MainWindow::visiblityInterfaceMIK01(bool visible)
{
    ui->actionInterfaceMIK01->setChecked(visible);

    if(visible)
    {
        m_mik_interface->show();
        if(m_port->isOpen())
        {
            sendCmd("0x04");
        }
    }
    else
    {
        m_mik_interface->hide();
    }
}
//---------------------------------------------
void MainWindow::visiblityCommand(bool visible)
{
    ui->actionCommand->setChecked(visible);

    if(visible)
    {
        m_command->show();
    }
    else
    {
        m_command->hide();
    }
}
