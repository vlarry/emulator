#include "qcommand.h"
#include "ui_command.h"
//----------------------------------
QCommand::QCommand(QWidget* parent):
    QWidget(parent),
    ui(new Ui::QCommand),
    m_parent(Q_NULLPTR)
{
    ui->setupUi(this);

    m_parent = parent;

    QCmd* cmd = new QCmd;

    m_cmd = cmd->list();

    QFontMetrics fm(ui->lwCmd->font());

    QSize size(0, fm.height());
    int   count = 0;

    for(QCmd::param_t& param: m_cmd)
    {
        if(param.second != 0)
        {
            QListWidgetItem* item = new QListWidgetItem(param.first);
            item->setData(Qt::UserRole, m_cmd.key(param));

            int tlen = fm.width(param.first);

            if(tlen > size.width())
                size.setWidth(tlen);

            count++;

            ui->lwCmd->addItem(item);
        }
    }

    connect(ui->lwCmd, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(cmdDoubleClicked(QListWidgetItem*)));

    size.setHeight(size.height()*count*1.5);

    if(size.height() > parent->geometry().height()/2)
        size.setHeight(parent->geometry().height()/2);

    this->setMaximumSize(size.width()*1.2, parent->height());

    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
}
//-------------------
QCommand::~QCommand()
{
    delete ui;
}
//-----------------------------------------
void QCommand::showEvent(QShowEvent* event)
{
    this->setGeometry(m_parent->x(), m_parent->y(), this->maximumWidth(), m_parent->height()/3);
    this->move(m_parent->x(), m_parent->y());

    QWidget::showEvent(event);
}
//-------------------------------------------
void QCommand::closeEvent(QCloseEvent* event)
{
    emit closeCommand(false);

    QWidget::closeEvent(event);
}
//----------------------------------------------------
void QCommand::cmdDoubleClicked(QListWidgetItem* item)
{
    emit doubleClickCmd(item->data(Qt::UserRole).toString());
}
