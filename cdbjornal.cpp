#include "cdbjornal.h"
#include "ui_dbjornal.h"
//------------------------------------
CDbJornal::CDbJornal(QWidget* parent):
    QWidget(parent),
    ui(new Ui::CDbJornal)
{
    ui->setupUi(this);

    ui->tableWidgetDbSerialNumber->setColumnCount(9);
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("Модуль")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("Порядковый номер")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("Номер в партии")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Вариант прошивки")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(4, new QTableWidgetItem(tr("Дата прошивки")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(5, new QTableWidgetItem(tr("Дата записи в БД")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(6, new QTableWidgetItem(tr("Время записи в БД")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(7, new QTableWidgetItem(tr("Модификация")));
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderItem(8, new QTableWidgetItem(tr("Заказчик")));

    ui->tableWidgetDbSerialNumber->resizeColumnsToContents();
    ui->tableWidgetDbSerialNumber->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetDbSerialNumber->setSortingEnabled(true);

    setWindowTitle(tr("Журнал БД"));
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);
}
//---------------------
CDbJornal::~CDbJornal()
{
    delete ui;
}
//--------------------------------------------------------------------------
void CDbJornal::setDataToTable(const CDbController::serial_num_list_t& list)
{
    ui->tableWidgetDbSerialNumber->clearContents();
    ui->tableWidgetDbSerialNumber->setRowCount(list.count());

    int row = 0;

    for(const CDbController::serial_num_t& sn: list)
    {
        QTableWidgetItem* itemModule = new QTableWidgetItem((sn.dev_code == 0)?tr("МДВВ-01"):(sn.dev_code == 1)?tr("МДВВ-02"):tr("МИК-01"));
        itemModule->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 0, itemModule);

        QTableWidgetItem* itemNumber = new QTableWidgetItem(QString::number(sn.dev_num));
        itemNumber->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 1, itemNumber);

        QTableWidgetItem* itemNumberParty = new QTableWidgetItem(QString::number(sn.dev_party));
        itemNumberParty->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 2, itemNumberParty);

        QTableWidgetItem* itemFirmwareVariant = new QTableWidgetItem(QString::number(sn.dev_firmware_var));
        itemFirmwareVariant->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 3, itemFirmwareVariant);

        QTableWidgetItem* itemFirmwareDate = new QTableWidgetItem(QDate::fromString(sn.dev_firmware_date, "yyyy-MM-dd").toString("dd.MM.yyyy"));
        itemFirmwareDate->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 4, itemFirmwareDate);

        QTableWidgetItem* itemSaveDate = new QTableWidgetItem(QDate::fromString(sn.date, "yyyy-MM-dd").toString("dd.MM.yyyy"));
        itemSaveDate->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 5, itemSaveDate);

        QTableWidgetItem* itemSaveTime = new QTableWidgetItem(sn.time);
        itemSaveTime->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 6, itemSaveTime);

        QTableWidgetItem* itemModification = new QTableWidgetItem(sn.modification);
        itemModification->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 7, itemModification);

        QTableWidgetItem* itemCustomer = new QTableWidgetItem(sn.customer);
        itemCustomer->setTextAlignment(Qt::AlignHCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 8, itemCustomer);

        row++;
    }
}
//--------------------------------------------
void CDbJornal::closeEvent(QCloseEvent* event)
{
    ui->tableWidgetDbSerialNumber->clear();
    QWidget::closeEvent(event);
    emit closeJournal();
}
