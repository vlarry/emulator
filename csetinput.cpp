#include "csetinput.h"
#include "ui_setinput.h"
//------------------------------------
CSetInput::CSetInput(QWidget* parent):
    QDialog(parent),
    ui(new Ui::CSetInput)
{
    ui->setupUi(this);

    // Инициализация массива группы выходов
    m_inputs.append(ui->checkBoxInput_1);
    m_inputs.append(ui->checkBoxInput_2);
    m_inputs.append(ui->checkBoxInput_3);
    m_inputs.append(ui->checkBoxInput_4);
    m_inputs.append(ui->checkBoxInput_5);
    m_inputs.append(ui->checkBoxInput_6);
    m_inputs.append(ui->checkBoxInput_7);
    m_inputs.append(ui->checkBoxInput_8);
    m_inputs.append(ui->checkBoxInput_9);
    m_inputs.append(ui->checkBoxInput_10);
    m_inputs.append(ui->checkBoxInput_11);
    m_inputs.append(ui->checkBoxInput_12);

    ui->comboBoxInputType->addItems(QStringList() << tr("Аналоговый")  << tr("Цифровой"));

    setWindowFlags(windowFlags() & (Qt::Dialog | Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint));
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFixedSize(size());

    connect(ui->comboBoxInputType, &QComboBox::currentTextChanged, this, &CSetInput::typeInput);
    connect(ui->pushButtonWrite, &QPushButton::clicked, this, &CSetInput::accepted);
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &CSetInput::rejected);
    connect(this, &CSetInput::accepted, this, &CSetInput::hide);
    connect(this, &CSetInput::rejected, this, &CSetInput::hide);
    connect(ui->groupBoxInputSetIndividual, &QGroupBox::clicked, this, &CSetInput::groupEnabled);
    connect(ui->groupBoxInputSetGeneral, &QGroupBox::clicked, this, &CSetInput::groupEnabled);
}
//---------------------
CSetInput::~CSetInput()
{
    delete ui;
}
//---------------------------------------------
QByteArray CSetInput::inputIndividualSettings()
{
    quint16 intput = 0x0000;
    QByteArray data;

    if(ui->groupBoxInputSetIndividual->isChecked())
    {
        for(int i = 0; i < m_inputs.count(); i++)
        {
            QCheckBox* checkBox = m_inputs[i];

            if(checkBox)
            {
                if(checkBox->isChecked())
                {
                    intput |= 1 << i;
                }
            }
        }

        intput |= 1 << 16;

        quint8 type_input = (ui->comboBoxInputType->currentText().toUpper() == tr("АНАЛОГОВЫЙ"))?0x00:0x01;
        data = QByteArray::fromHex(QByteArray::number(((intput >> 8)&0x000F), 16));
        data.append(QByteArray::fromHex(QByteArray::number(intput&0x00FF, 16)));
        data.append(QByteArray::fromHex(QByteArray::number(type_input, 16))); // тип входа
        data.append(QByteArray::fromHex(QByteArray::number(ui->spinBoxDuration->value(), 16))); // длительность периода
        data.append(QByteArray::fromHex(QByteArray::number(ui->spinBoxFaultInput->value(), 16))); // погрешность периода
    }

    return data;
}
//-----------------------------------------
QByteArray CSetInput::inputGeneralSetting()
{
    QByteArray data;

    if(ui->groupBoxInputSetGeneral->isChecked())
    {
        data.append(QByteArray::fromHex(QByteArray::number(ui->spinBoxPeriod->value(), 16)));
        data.append(QByteArray::fromHex(QByteArray::number(ui->spinBoxDiscret->value(), 16)));
        data.append(QByteArray::fromHex(QByteArray::number(ui->spinBoxSignal->value(), 16)));
    }

    return data;
}
//------------------------------------------
bool CSetInput::isInputSetIndividual() const
{
    return ui->groupBoxInputSetIndividual->isChecked();
}
//---------------------------------------
bool CSetInput::isInputSetGeneral() const
{
    return ui->groupBoxInputSetGeneral->isChecked();
}
//--------------------------------------------
void CSetInput::typeInput(const QString& text)
{
    if(text.toUpper() == tr("АНАЛОГОВЫЙ"))
    {
        ui->lblTextFault->setText(tr("Погрешность, %"));
        ui->spinBoxFaultInput->setRange(10, 50);
        ui->spinBoxFaultInput->setSingleStep(10);
    }
    else
    {
        ui->lblTextFault->setText(tr("Кол-во лог 0/1, %"));
        ui->spinBoxFaultInput->setRange(80, 100);
        ui->spinBoxFaultInput->setSingleStep(10);
    }
}
//--------------------------------------
void CSetInput::groupEnabled(bool state)
{
    QCheckBox* checkBox = qobject_cast<QCheckBox*>(sender());

    if(checkBox)
        checkBox->setEnabled(state);
}
/*!
 * \brief CSetInput::setInputCount
 * \param addr Количество входов исходя из адреса устройства
 */
void CSetInput::setInputCount(int addr)
{
    if(addr == 0) // МДВВ-01 - 12 входов
    {
        ui->checkBoxInput_11->setEnabled(true);
        ui->checkBoxInput_12->setEnabled(true);
    }
    else // МДВВ-02 - 10 входов
    {
        ui->checkBoxInput_11->setDisabled(true);
        ui->checkBoxInput_12->setDisabled(true);
    }
}
