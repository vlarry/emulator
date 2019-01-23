#include "csetinput.h"
#include "ui_setinput.h"
//------------------------------------
CSetInput::CSetInput(QWidget* parent):
    QWidget(parent),
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

    ui->stackedWidget->setCurrentIndex(1);
    ui->comboBoxInputType->addItems(QStringList() << tr("Аналоговый")  << tr("Цифровой"));
    setWindowFlags((windowFlags() & ~Qt::WindowContextHelpButtonHint) | Qt::Window);

    connect(ui->comboBoxInputType, &QComboBox::currentTextChanged, this, &CSetInput::typeInput);
    connect(ui->pushButtonApply, &QPushButton::clicked, this, &CSetInput::apply);
    connect(this, &CSetInput::apply, this, &CSetInput::hide);
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &CSetInput::hide);
}
//---------------------
CSetInput::~CSetInput()
{
    delete ui;
}
//--------------------------------------------
QByteArray CSetInput::intputSettings(int type)
{
    quint16 intput = 0x0000;

    if(type == 1) // если тип "группа", то устанавливаем старший бит
    {
        intput = 0x8000;
    }

    if(type == 1)
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
    }
    else
    {
        intput = static_cast<quint16>(ui->spinBoxInputSingle->value());
    }

    quint8 type_input = (ui->comboBoxInputType->currentText().toUpper() == tr("АНАЛОГОВЫЙ"))?0x00:0x01;
    QByteArray data = QByteArray::fromHex(QByteArray::number(((intput >> 8)&0x008F), 16));
    data.append(QByteArray::fromHex(QByteArray::number(intput&0x00FF, 16)));
    data.append(QByteArray::fromHex(QByteArray::number(type_input, 16))); // тип входа
    data.append(QByteArray::fromHex(QByteArray::number(ui->spinBoxDuration->value(), 16))); // длительность периода
    data.append(QByteArray::fromHex(QByteArray::number(ui->spinBoxFaultInput->value(), 16))); // погрешность периода

    return data;
}
//----------------------------
void CSetInput::open(int type)
{
    ui->stackedWidget->setCurrentIndex(type);
    show();
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
        ui->spinBoxFaultInput->setRange(50, 100);
        ui->spinBoxFaultInput->setSingleStep(10);
    }
}
