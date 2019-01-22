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
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &CSetInput::hide);
}
//---------------------
CSetInput::~CSetInput()
{
    delete ui;
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
