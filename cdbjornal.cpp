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
        CDbJournalItem* itemSaveDate = new CDbJournalItem(QDate::fromString(sn.date, "yyyy-MM-dd").toString("dd.MM.yyyy"));
        itemSaveDate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        itemSaveDate->setData(Qt::UserRole, sn.id);
        ui->tableWidgetDbSerialNumber->setItem(row, 0, itemSaveDate);

        CDbJournalItem* itemSaveTime = new CDbJournalItem(sn.time);
        itemSaveTime->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 1, itemSaveTime);

        CDbJournalItem* itemModule = new CDbJournalItem((sn.dev_code == 0)?tr("МДВВ-01"):(sn.dev_code == 1)?tr("МДВВ-02"):tr("МИК-01"));
        itemModule->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 2, itemModule);

        CDbJournalItem* itemNumber = new CDbJournalItem(QString::number(sn.dev_num));
        itemNumber->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 3, itemNumber);

        CDbJournalItem* itemNumberParty = new CDbJournalItem(QString::number(sn.dev_party));
        itemNumberParty->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 4, itemNumberParty);

        CDbJournalItem* itemFirmwareVariant = new CDbJournalItem(QString::number(sn.dev_firmware_var));
        itemFirmwareVariant->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 5, itemFirmwareVariant);

        CDbJournalItem* itemFirmwareDate = new CDbJournalItem(QDate::fromString(sn.dev_firmware_date, "yyyy-MM-dd").toString("dd.MM.yyyy"));
        itemFirmwareDate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 6, itemFirmwareDate);

        CDbJournalItem* itemModification = new CDbJournalItem(sn.modification);
        itemModification->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 7, itemModification);

        CDbJournalItem* itemRevision = new CDbJournalItem(sn.revision);
        itemModification->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbSerialNumber->setItem(row, 8, itemRevision);

        CDbJournalItem* itemCustomer = new CDbJournalItem(sn.customer);
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
//---------------------------------------------
void CDbJornal::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Delete)
    {
        if(ui->tableWidgetDbSerialNumber->rowCount() == 0)
        {
            QMessageBox::warning(this, tr("Удаление серийных номеров"), tr("Список серийных номеров пуст!"));
            return;
        }

        QModelIndexList rowList = ui->tableWidgetDbSerialNumber->selectionModel()->selectedRows();

        if(rowList.isEmpty())
        {
            QMessageBox::warning(this, tr("Удаление серийных номеров"), tr("Вы не выбрали ни одного серийного номера!\nПопробуйте ещё раз."));
            return;
        }

        QString text = (rowList.count() == 1)?tr("выбранный серийный номер"):tr("выбранные серийные номера");

        QMessageBox messageBox;
        messageBox.setWindowTitle(tr("Удаление серийных номеров"));
        messageBox.setText(tr("Вы действительно хотите удалить %1?").arg(text));
        QPushButton* buttonDelete = messageBox.addButton(tr("Удалить"), QMessageBox::ActionRole);
        messageBox.setStandardButtons(QMessageBox::Cancel);
        messageBox.setButtonText(QMessageBox::Cancel, tr("Отмена"));
        messageBox.setIcon(QMessageBox::Question);
        messageBox.exec();

        if(messageBox.clickedButton() == buttonDelete)
        {
            qDebug() << rowList;
            for(QModelIndex index: rowList)
            {
                QTableWidgetItem* item = ui->tableWidgetDbSerialNumber->item(index.row(), 0);

                if(item)
                    emit deleteJournalRow(item->data(Qt::UserRole).toInt());

                ui->tableWidgetDbSerialNumber->removeRow(index.row());
            }
        }
    }
}
