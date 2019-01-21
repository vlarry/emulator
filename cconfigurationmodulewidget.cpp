#include "cconfigurationmodulewidget.h"
#include "ui_configurationmodulewidget.h"
//----------------------------------------------------------------------
CConfigurationModuleWidget::CConfigurationModuleWidget(QWidget* parent):
    QDialog(parent),
    ui(new Ui::CConfigurationModuleWidget)
{
    ui->setupUi(this);

    ui->lineEditModuleKeyCurrent->setInputMask("HH HH HH HH");
    ui->lineEditModuleKeyNew->setInputMask("HH HH HH HH");
    ui->lineEditModuleNumber->setValidator(new QIntValidator(0, 9999));
    ui->lineEditModuleNumberParty->setValidator(new QIntValidator(0, 99));
    ui->lineEditModuleFirmwareVariant->setValidator(new QIntValidator(0, 99));

    ui->lineEditModuleKeyCurrent->setText("00000000");
    ui->lineEditModuleKeyNew->setText("00000000");
    ui->lineEditModuleNumber->setText("0000");
    ui->lineEditModuleNumberParty->setText("00");
    ui->lineEditModuleFirmwareVariant->setText("00");

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    connect(ui->checkBoxNewKey, &QCheckBox::clicked, this, &CConfigurationModuleWidget::newKeyStateChanged);
}
//-------------------------------------------------------
CConfigurationModuleWidget::~CConfigurationModuleWidget()
{
    delete ui;
}
//------------------------------------------------
int CConfigurationModuleWidget::moduleType() const
{
    return ui->comboBoxModuleType->currentIndex() + 0x48;
}
//--------------------------------------------------
int CConfigurationModuleWidget::moduleNumber() const
{
    return ui->lineEditModuleNumber->text().toInt();
}
//-------------------------------------------------------
int CConfigurationModuleWidget::moduleNumberParty() const
{
    return ui->lineEditModuleNumberParty->text().toInt();
}
//-----------------------------------------------------------
int CConfigurationModuleWidget::moduleFirmwareVariant() const
{
    return ui->lineEditModuleFirmwareVariant->text().toInt();
}
//----------------------------------------------------------
QDate CConfigurationModuleWidget::moduleFirmwareDate() const
{
    return ui->dateEdit->date();
}
//-------------------------------------------------------------
QByteArray CConfigurationModuleWidget::moduleKeyCurrent() const
{
    QString hex = ui->lineEditModuleKeyCurrent->text();
    hex.remove(" ");
    return QByteArray::fromHex(hex.toUtf8());
}
//---------------------------------------------------------
QByteArray CConfigurationModuleWidget::moduleKeyNew() const
{
    QString hex;

    if(ui->checkBoxNewKey->isChecked())
        hex = ui->lineEditModuleKeyNew->text();
    else
        hex = "00 00 00 00";

    hex.remove(" ");
    return QByteArray::fromHex(hex.toUtf8());
}
//------------------------------------------------------
void CConfigurationModuleWidget::setModuleType(int type)
{
    if(type < ui->comboBoxModuleType->count())
        ui->comboBoxModuleType->setCurrentIndex(type);
}
//----------------------------------------------------------
void CConfigurationModuleWidget::setModuleNumber(int number)
{
    ui->lineEditModuleNumber->setText(QString::number(number));
}
//---------------------------------------------------------------
void CConfigurationModuleWidget::setModuleNumberParty(int number)
{
    ui->lineEditModuleNumberParty->setText(QString::number(number));
}
//--------------------------------------------------------------------
void CConfigurationModuleWidget::setModuleFirmwareVariant(int variant)
{
    ui->lineEditModuleFirmwareVariant->setText(QString::number(variant));
}
//-----------------------------------------------------------------------
void CConfigurationModuleWidget::setModuleFirmwareDate(const QDate& date)
{
    ui->dateEdit->setDate(date);
}
//-----------------------------------------------------------
void CConfigurationModuleWidget::showEvent(QShowEvent* event)
{
    QDialog::showEvent(event);
    ui->checkBoxNewKey->setChecked(false);
    ui->lineEditModuleKeyNew->setEnabled(false);
}
//--------------------------------------
void CConfigurationModuleWidget::close()
{
    if(!isHidden())
        hide();
}
//-------------------------------------------------------------
void CConfigurationModuleWidget::newKeyStateChanged(bool state)
{
    ui->lineEditModuleKeyNew->setEnabled(state);
}
