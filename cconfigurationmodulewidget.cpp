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
    ui->lineEditModuleNumberCurrent->setValidator(new QIntValidator(0, 9999));
    ui->lineEditModuleNumberPartyCurrent->setValidator(new QIntValidator(0, 99));
    ui->lineEditModuleFirmwareVariantCurrent->setValidator(new QIntValidator(0, 99));

    ui->lineEditModuleKeyCurrent->setText("00000000");
    ui->lineEditModuleKeyNew->setText("00000000");
    ui->lineEditModuleNumberCurrent->setText("0000");
    ui->lineEditModuleNumberPartyCurrent->setText("00");
    ui->lineEditModuleFirmwareVariantCurrent->setText("00");
    ui->lineEditModuleFirmwareDateCurrent->setText(QDate::currentDate().toString("dd.MM.yyyy"));

    ui->lineEditModuleKeyCurrent->setInputMask("HH HH HH HH");
    ui->lineEditModuleKeyNew->setInputMask("HH HH HH HH");
    ui->lineEditModuleNumberNew->setValidator(new QIntValidator(0, 9999));
    ui->lineEditModuleNumberPartyNew->setValidator(new QIntValidator(0, 99));
    ui->lineEditModuleFirmwareVariantNew->setValidator(new QIntValidator(0, 99));

    ui->lineEditModuleKeyCurrent->setText("00000000");
    ui->lineEditModuleKeyNew->setText("00000000");
    ui->lineEditModuleNumberNew->setText("0000");
    ui->lineEditModuleNumberPartyNew->setText("00");
    ui->lineEditModuleFirmwareVariantNew->setText("00");
    ui->lineEditModuleFirmwareDateNew->setText(QDate::currentDate().toString("dd.MM.yyyy"));

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    connect(ui->checkBoxNewKey, &QCheckBox::clicked, this, &CConfigurationModuleWidget::newKeyStateChanged);
    connect(ui->toolButtonModificationAppend, &QToolButton::clicked, this, &CConfigurationModuleWidget::appendText);
    connect(ui->toolButtonCustomerAppend, &QToolButton::clicked, this, &CConfigurationModuleWidget::appendText);
}
//-------------------------------------------------------
CConfigurationModuleWidget::~CConfigurationModuleWidget()
{
    delete ui;
}
//-----------------------------------------------------------
int CConfigurationModuleWidget::moduleType(type_t type) const
{
    return (type == CURRENT)?ui->lineEditModuleTypeCurrent->property("TYPE").toInt():ui->lineEditModuleTypeNew->property("TYPE").toInt();
}
//-------------------------------------------------------------
int CConfigurationModuleWidget::moduleNumber(type_t type) const
{
    return (type == CURRENT)?ui->lineEditModuleNumberCurrent->text().toInt():ui->lineEditModuleNumberNew->text().toInt();
}
//------------------------------------------------------------------
int CConfigurationModuleWidget::moduleNumberParty(type_t type) const
{
    return (type == CURRENT)?ui->lineEditModuleNumberPartyCurrent->text().toInt():ui->lineEditModuleNumberPartyNew->text().toInt();
}
//----------------------------------------------------------------------
int CConfigurationModuleWidget::moduleFirmwareVariant(type_t type) const
{
    return (type == CURRENT)?ui->lineEditModuleFirmwareDateCurrent->text().toInt():ui->lineEditModuleFirmwareVariantNew->text().toInt();
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
//------------------------------------------------------------
QString CConfigurationModuleWidget::moduleModification() const
{
    return ui->comboBoxModuleModificationNew->currentText();
}
//--------------------------------------------------------
QString CConfigurationModuleWidget::moduleCustomer() const
{
    return  ui->comboBoxModuleCustomerNew->currentText();
}
//--------------------------------------------------------------------------
void CConfigurationModuleWidget::setModuleType(int module_type, type_t type)
{
    QLineEdit* lineEdit = (type == CURRENT)?ui->lineEditModuleTypeCurrent:ui->lineEditModuleTypeNew;
    QString text = (module_type == 0x48)?tr("МДВВ-01"):(module_type == 0x49)?tr("МДВВ-02"):tr("МИК-01");
    lineEdit->setText(text);
    lineEdit->setProperty("TYPE", module_type);
}
//-----------------------------------------------------------------------
void CConfigurationModuleWidget::setModuleNumber(int number, type_t type)
{
    QLineEdit* lineEdit = (type == CURRENT)?ui->lineEditModuleNumberCurrent:ui->lineEditModuleNumberNew;
    lineEdit->setText(QString::number(number));
}
//----------------------------------------------------------------------------
void CConfigurationModuleWidget::setModuleNumberParty(int number, type_t type)
{
    QLineEdit* lineEdit = (type == CURRENT)?ui->lineEditModuleNumberPartyCurrent:ui->lineEditModuleNumberPartyNew;
    lineEdit->setText(QString::number(number));
}
//---------------------------------------------------------------------------------
void CConfigurationModuleWidget::setModuleFirmwareVariant(int variant, type_t type)
{
    QLineEdit* lineEdit = (type == CURRENT)?ui->lineEditModuleFirmwareVariantCurrent:ui->lineEditModuleFirmwareVariantNew;
    lineEdit->setText(QString::number(variant));
}
//--------------------------------------------------------------------------------------
void CConfigurationModuleWidget::setModuleFirmwareDate(const QString& date, type_t type)
{
    QLineEdit* lineEdit = (type == CURRENT)?ui->lineEditModuleFirmwareDateCurrent:ui->lineEditModuleFirmwareDateNew;
    lineEdit->setText(date);
}
//-----------------------------------------------------------------------------------------------------
void CConfigurationModuleWidget::initLIst(const QStringList& modification, const QStringList& customer)
{
    if(!modification.isEmpty())
        ui->comboBoxModuleModificationNew->insertItems(0, modification);

    if(!customer.isEmpty())
        ui->comboBoxModuleCustomerNew->insertItems(0, customer);
}
//-------------------------------------------
void CConfigurationModuleWidget::appendText()
{
    QToolButton* button = qobject_cast<QToolButton*>(sender());
    QString title = (button == ui->toolButtonModificationAppend)?tr("Новая модификация"):tr("Новый заказчик");
    QComboBox* combobox = (button == ui->toolButtonModificationAppend)?ui->comboBoxModuleModificationNew:ui->comboBoxModuleCustomerNew;
    CAppendInfoDialog* dialog = new CAppendInfoDialog(title, this);

    if(dialog->exec() == QDialog::Accepted)
    {
        QString text = dialog->text();

        if(!text.isEmpty())
        {
            if(combobox->findText(text) == -1)
            {
                combobox->addItem(text);
                combobox->setCurrentText(text);

                QString table_name = (button == ui->toolButtonModificationAppend)?"modification":"customer";

                emit newValueAppend(table_name, text);
            }
        }
    }
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
