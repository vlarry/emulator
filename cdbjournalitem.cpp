#include "cdbjournalitem.h"
//------------------------------------------------------------
CDbJournalItem::CDbJournalItem(const QString& text, int type):
    QTableWidgetItem (text, type)
{

}
//-----------------------------------------------------------------
bool CDbJournalItem::operator<(const QTableWidgetItem& other) const
{
    switch(column())
    {
        case 0:
        case 6:
            return QDate::fromString(other.text(), "dd.MM.yyyy") > QDate::fromString(text(), "dd.MM.yyyy");

        case 1:
            return QTime::fromString(other.text(), "hh:mm:ss") > QTime::fromString(text(), "hh:mm:ss");

        case 2:
        case 7:
        case 8:
        case 9:
            return other.text().compare(text());

        case 3:
        case 4:
        case 5:
            return other.text().toInt() > text().toInt();
    }

    return false;
}
