#include "cdbjornal.h"
#include "ui_dbjornal.h"
//---------------------------------------------------------------------
CDbJornal::CDbJornal(const CDbController* controller, QWidget* parent):
    QWidget(parent),
    ui(new Ui::CDbJornal),
    m_db_controller(controller)
{
    ui->setupUi(this);

    ui->tableWidgetDbSerialNumber->setColumnCount(8);
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Модуль")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Порядковый номер")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Номер в партии")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Вариант прошивки")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Дата прошивки")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Дата записи в БД")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Время записи в БД")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(6, new QTableWidgetItem(tr("Модификация")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(7, new QTableWidgetItem(tr("Заказчик")));

    ui->tableWidgetDbSerialNumber->resizeColumnsToContents();
    ui->tableWidgetDbSerialNumber->horizontalHeader()->setStretchLastSection(true);

    setWindowTitle(tr("Журнал БД"));
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
}
//---------------------
CDbJornal::~CDbJornal()
{
    delete ui;
}
//--------------------------------------------
void CDbJornal::closeEvent(QCloseEvent* event)
{
    emit closeJournal();
    ui->tableWidgetDbSerialNumber->clear();
    QWidget::closeEvent(event);
}
//------------------------------------------
void CDbJornal::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);
}
