#include "cappendinfodialog.h"
#include "ui_appendinfodialog.h"
//--------------------------------------------------------------------------
CAppendInfoDialog::CAppendInfoDialog(const QString& title, QWidget* parent):
    QDialog(parent),
    ui(new Ui::CAppendInfoDialog)
{
    ui->setupUi(this);
    setWindowTitle(title);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Добавить"));
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("Отмена"));
}
//-------------------------------------
CAppendInfoDialog::~CAppendInfoDialog()
{
    delete ui;
}
//-------------------------------------
QString CAppendInfoDialog::text() const
{
    return ui->lineEditText->text();
}
