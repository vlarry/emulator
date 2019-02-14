#include "cdbjornal.h"
#include "ui_dbjornal.h"
//---------------------------------------------------------------
CDbJournal::CDbJournal(const DataBase &db_type, QWidget* parent):
    QWidget(parent),
    ui(new Ui::CDbJornal),
    m_db_type(db_type)
{
    ui->setupUi(this);

    QStringList headerList;
    QString     title;

    if(m_db_type == DataBase::SERIAL_DB)
    {
        headerList = QStringList() << tr("Дата записи в БД") << tr("Время записи в БД") << tr("Модуль") << tr("Порядковый номер") <<
                                      tr("Номер в партии") << tr("Вариант прошивки") << tr("Дата прошивки") << tr("Модификация") <<
                                      tr("Ревизия модуля") << tr("Заказчик");
        title = tr("Журнал серийных номеров");
    }
    else if(m_db_type == DataBase::MODIFICATION_DB)
    {
        headerList = QStringList() << tr("Модификация");
        title = tr("Журнал модификаций");
        ui->comboBoxColumnFilter->setDisabled(true);
    }
    else if(m_db_type == DataBase::REVISION_DB)
    {
        headerList = QStringList() << tr("Ревизия");
        title = tr("Журнал ревизий");
        ui->comboBoxColumnFilter->setDisabled(true);
    }
    else if(m_db_type == DataBase::CUSTOMER_DB)
    {
        headerList = QStringList() << tr("Заказчик");
        title = tr("Журнал заказчиков");
        ui->comboBoxColumnFilter->setDisabled(true);
    }

    ui->tableWidgetDbJournal->setColumnCount(headerList.count());
    ui->tableWidgetDbJournal->setHorizontalHeaderLabels(headerList);
    ui->comboBoxColumnFilter->addItems(headerList);

    ui->tableWidgetDbJournal->resizeColumnsToContents();
    ui->tableWidgetDbJournal->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetDbJournal->setSortingEnabled(true);

    setWindowTitle(title);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);

    if(m_db_type == DataBase::SERIAL_DB)
        showMaximized();

    connect(ui->lineEditFilter, &QLineEdit::textChanged, this, &CDbJournal::filterSlot);
}
//-----------------------
CDbJournal::~CDbJournal()
{
    delete ui;
}
//---------------------------------------------------------------------------
void CDbJournal::setDataToTable(const CDbController::serial_num_list_t &list)
{
    ui->tableWidgetDbJournal->clearContents();
    ui->tableWidgetDbJournal->setRowCount(list.count());

    int row = 0;

    for(const CDbController::serial_num_t& sn: list)
    {
        CDbJournalItem* itemSaveDate = new CDbJournalItem(QDate::fromString(sn.date, "yyyy-MM-dd").toString("dd.MM.yyyy"));
        itemSaveDate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        itemSaveDate->setData(Qt::UserRole, sn.id);
        ui->tableWidgetDbJournal->setItem(row, 0, itemSaveDate);

        CDbJournalItem* itemSaveTime = new CDbJournalItem(sn.time);
        itemSaveTime->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 1, itemSaveTime);

        CDbJournalItem* itemModule = new CDbJournalItem((sn.dev_code == 0)?tr("МДВВ-01"):(sn.dev_code == 1)?tr("МДВВ-02"):tr("МИК-01"));
        itemModule->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 2, itemModule);

        CDbJournalItem* itemNumber = new CDbJournalItem(QString::number(sn.dev_num));
        itemNumber->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 3, itemNumber);

        CDbJournalItem* itemNumberParty = new CDbJournalItem(QString::number(sn.dev_party));
        itemNumberParty->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 4, itemNumberParty);

        CDbJournalItem* itemFirmwareVariant = new CDbJournalItem(QString::number(sn.dev_firmware_var));
        itemFirmwareVariant->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 5, itemFirmwareVariant);

        CDbJournalItem* itemFirmwareDate = new CDbJournalItem(QDate::fromString(sn.dev_firmware_date, "yyyy-MM-dd").toString("dd.MM.yyyy"));
        itemFirmwareDate->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 6, itemFirmwareDate);

        CDbJournalItem* itemModification = new CDbJournalItem(sn.modification);
        itemModification->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 7, itemModification);

        CDbJournalItem* itemRevision = new CDbJournalItem(sn.revision);
        itemRevision->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 8, itemRevision);

        CDbJournalItem* itemCustomer = new CDbJournalItem(sn.customer);
        itemCustomer->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->tableWidgetDbJournal->setItem(row, 9, itemCustomer);

        QFont f = ui->tableWidgetDbJournal->font();
        QFontMetrics fm(f);

        ui->tableWidgetDbJournal->setRowHeight(row, static_cast<int>(static_cast<float>(fm.height())*1.2f));

        row++;
    }

    ui->tableWidgetDbJournal->resizeColumnsToContents();
}
//---------------------------------------------------------------------
void CDbJournal::setDataToTable(const CDbController::data_list_t &list)
{
    ui->tableWidgetDbJournal->clearContents();
    ui->tableWidgetDbJournal->setRowCount(list.count());

    int row = 0;

    for(const CDbController::data_t &data: list)
    {
        CDbJournalItem* item = new CDbJournalItem(data.text);
        item->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        item->setData(Qt::UserRole, data.id);
        ui->tableWidgetDbJournal->setItem(row, 0, item);

        QFont f = ui->tableWidgetDbJournal->font();
        QFontMetrics fm(f);

        ui->tableWidgetDbJournal->setRowHeight(row, static_cast<int>(static_cast<float>(fm.height())*1.2f));

        row++;
    }
}
//----------------------------------------------
void CDbJournal::filterSlot(const QString& text)
{
    int column = ui->comboBoxColumnFilter->currentIndex();

    for(int row = 0; row < ui->tableWidgetDbJournal->rowCount(); row++)
    {
        QTableWidgetItem* item = ui->tableWidgetDbJournal->item(row, column);

        if(item)
        {
            QString data = item->text();

            if(data.contains(text))
                ui->tableWidgetDbJournal->showRow(row);
            else
                ui->tableWidgetDbJournal->hideRow(row);
        }
    }
}
//---------------------------------------------
void CDbJournal::closeEvent(QCloseEvent* event)
{
    ui->tableWidgetDbJournal->clear();
    QWidget::closeEvent(event);
    emit closeJournal();
}
//----------------------------------------------
void CDbJournal::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Delete)
    {
        QString title;
        QString message;

        if(ui->tableWidgetDbJournal->rowCount() == 0)
        {
            if(m_db_type == DataBase::SERIAL_DB)
            {
                title = tr("Удаление серийных номеров");
                message = tr("Список серийных номеров пуст!");
            }
            else if(m_db_type == DataBase::MODIFICATION_DB)
            {
                title = tr("Удаление модификаций");
                message = tr("Список модификаций пуст!");
            }
            else if(m_db_type == DataBase::REVISION_DB)
            {
                title = tr("Удаление ревизий");
                message = tr("Список ревизий пуст!");
            }
            else if(m_db_type == DataBase::CUSTOMER_DB)
            {
                title = tr("Удаление заказчиков");
                message = tr("Список заказчиков пуст!");
            }

            QMessageBox::warning(this, title, message);
            return;
        }

        QModelIndexList rowList = ui->tableWidgetDbJournal->selectionModel()->selectedRows();

        if(rowList.isEmpty())
        {
            if(m_db_type == DataBase::SERIAL_DB)
            {
                title = tr("Удаление серийных номеров");
                message = tr("Вы не выбрали ни одного серийного номера!\nПопробуйте ещё раз.");
            }
            else if(m_db_type == DataBase::MODIFICATION_DB)
            {
                title = tr("Удаление модификаций");
                message = tr("Вы не выбрали ни одной модификации!\nПопробуйте ещё раз.");
            }
            else if(m_db_type == DataBase::REVISION_DB)
            {
                title = tr("Удаление ревизий");
                message = tr("Вы не выбрали ни одной ревизии!\nПопробуйте ещё раз.");
            }
            else if(m_db_type == DataBase::CUSTOMER_DB)
            {
                title = tr("Удаление заказчиков");
                message = tr("Вы не выбрали ни одного заказчика!\nПопробуйте ещё раз.");
            }

            QMessageBox::warning(this, title, message);
            return;
        }

        if(m_db_type == DataBase::SERIAL_DB)
        {
            title = tr("Удаление серийных номеров");
            message = (rowList.count() == 1)?tr("выбранный серийный номер"):tr("выбранные серийные номера");
        }
        else if(m_db_type == DataBase::MODIFICATION_DB)
        {
            title = tr("Удаление модификаций");
            message = (rowList.count() == 1)?tr("выбранную модификацию"):tr("выбранные модификации");
        }
        else if(m_db_type == DataBase::REVISION_DB)
        {
            title = tr("Удаление ревизий");
            message = (rowList.count() == 1)?tr("выбранную ревизию"):tr("выбранные ревизии");
        }
        else if(m_db_type == DataBase::CUSTOMER_DB)
        {
            title = tr("Удаление заказчиков");
            message = (rowList.count() == 1)?tr("выбранного заказчика"):tr("выбранных заказчиков");
        }

        QMessageBox messageBox;
        messageBox.setWindowTitle(title);
        messageBox.setText(tr("Вы действительно хотите удалить %1?").arg(message));
        QPushButton* buttonDelete = messageBox.addButton(tr("Удалить"), QMessageBox::ActionRole);
        messageBox.setStandardButtons(QMessageBox::Cancel);
        messageBox.setButtonText(QMessageBox::Cancel, tr("Отмена"));
        messageBox.setIcon(QMessageBox::Question);
        messageBox.exec();

        if(messageBox.clickedButton() == buttonDelete)
        {
            std::sort(rowList.begin(), rowList.end(), [](QModelIndex& var1, QModelIndex& var2) { return var1.row() > var2.row(); } );

            for(QModelIndex index: rowList)
            {
                QTableWidgetItem* item = ui->tableWidgetDbJournal->item(index.row(), 0);

                if(item)
                    emit deleteJournalRow(m_db_type, item->data(Qt::UserRole).toInt());

                ui->tableWidgetDbJournal->removeRow(index.row());
            }
        }
    }
}
