#include "cinputhelp.h"
#include "ui_inputhelp.h"
//-------------------------------------------------------------
CInputHelp::CInputHelp(const QPixmap& pixmap, QWidget* parent):
    QWidget(parent),
    ui(new Ui::CInputHelp)
{
    ui->setupUi(this);
    ui->label->setPixmap(pixmap);
    setWindowFlags((windowFlags() & ~Qt::WindowContextHelpButtonHint) | Qt::Window);
}
//-----------------------
CInputHelp::~CInputHelp()
{
    delete ui;
}
//-----------------------------------------------
void CInputHelp::setPixmap(const QPixmap& pixmap)
{
    ui->label->setPixmap(pixmap);
}
