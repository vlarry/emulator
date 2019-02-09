#include "cdbjornal.h"
#include "ui_dbjornal.h"
//------------------------------------
CDbJornal::CDbJornal(QWidget* parent):
    QWidget(parent),
    ui(new Ui::CDbJornal)
{
    ui->setupUi(this);

    QStringList headerList = QStringList() << tr("Дата записи в БД") << tr("Время записи в БД") << tr("Модуль") << tr("Порядковый номер") <<
                                              tr("Номер в партии") << tr("Вариант прошивки") << tr("Дата прошивки") << tr("Модификация") <<
                                              tr("Ревизия модуля") << tr("Заказчик");

    ui->tableWidgetDbSerialNumber->setColumnCount(10);
    ui->tableWidgetDbSerialNumber->setHorizontalHeaderLabels(headerList);
    ui->comboBoxColumnFilter->addItems(headerList);

    ui->tableWidgetDbSerialNumber->resizeColumnsToContents();
    ui->tableWidgetDbSerialNumber->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetDbSerialNumber->setSortingEnabled(true);

    setWindowTitle(tr("Журнал БД"));
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);
    showMaximized();

    connect(ui->lineEditFilter, &QLineEdit::textChanged, this, &CDbJornal::filterSlot);
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
        QTableWidgetItem* itemSaveDate = new QTableWidgetItem(QDate::fromString(sn.date, "yyyy-MM-dd").toString("dd.MM.yyyy"));
        itemSaveDate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 0, itemSaveDate);

        QTableWidgetItem* itemSaveTime = new QTableWidgetItem(sn.time);
        itemSaveTime->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 1, itemSaveTime);

        QTableWidgetItem* itemModule = new QTableWidgetItem((sn.dev_code == 0)?tr("МДВВ-01"):(sn.dev_code == 1)?tr("МДВВ-02"):tr("МИК-01"));
        itemModule->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 2, itemModule);

        QTableWidgetItem* itemNumber = new QTableWidgetItem(QString::number(sn.dev_num));
        itemNumber->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 3, itemNumber);

        QTableWidgetItem* itemNumberParty = new QTableWidgetItem(QString::number(sn.dev_party));
        itemNumberParty->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 4, itemNumberParty);

        QTableWidgetItem* itemFirmwareVariant = new QTableWidgetItem(QString::number(sn.dev_firmware_var));
        itemFirmwareVariant->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 5, itemFirmwareVariant);

        QTableWidgetItem* itemFirmwareDate = new QTableWidgetItem(QDate::fromString(sn.dev_firmware_date, "yyyy-MM-dd").toString("dd.MM.yyyy"));
        itemFirmwareDate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 6, itemFirmwareDate);

        QTableWidgetItem* itemModification = new QTableWidgetItem(sn.modification);
        itemModification->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 7, itemModification);

        QTableWidgetItem* itemRevision = new QTableWidgetItem(sn.revision);
        itemModification->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 8, itemRevision);

        QTableWidgetItem* itemCustomer = new QTableWidgetItem(sn.customer);
        itemCustomer->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 9, itemCustomer);

        QFont f = ui->tableWidgetDbSerialNumber->font();
        QFontMetrics fm(f);

        ui->tableWidgetDbSerialNumber->setRowHeight(row, static_cast<int>(static_cast<float>(fm.height())*1.2f));

        row++;
    }

    ui->tableWidgetDbSerialNumber->resizeColumnsToContents();
}
//---------------------------------------------
void CDbJornal::filterSlot(const QString& text)
{
    int column = ui->comboBoxColumnFilter->currentIndex();

    for(int row = 0; row < ui->tableWidgetDbSerialNumber->rowCount(); row++)
    {
        QTableWidgetItem* item = ui->tableWidgetDbSerialNumber->item(row, column);

        if(item)
        {
            QString data = item->text();

            if(data.contains(text))
                ui->tableWidgetDbSerialNumber->showRow(row);
            else
                ui->tableWidgetDbSerialNumber->hideRow(row);
        }
    }
}
//--------------------------------------------
void CDbJornal::closeEvent(QCloseEvent* event)
{
    ui->tableWidgetDbSerialNumber->clear();
    QWidget::closeEvent(event);
    emit closeJournal();
}
