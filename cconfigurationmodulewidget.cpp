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
    ui->lineEditModuleNumber->setInputMask("9999");
    ui->lineEditModuleNumberParty->setInputMask("99");
    ui->lineEditModuleFirmwareVariant->setInputMask("99");

    ui->lineEditModuleKeyCurrent->setText("00000000");
    ui->lineEditModuleKeyNew->setText("00000000");
    ui->lineEditModuleNumber->setText("0000");
    ui->lineEditModuleNumberParty->setText("00");
    ui->lineEditModuleFirmwareVariant->setText("00");

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
}
//-------------------------------------------------------
CConfigurationModuleWidget::~CConfigurationModuleWidget()
{
    delete ui;
}
