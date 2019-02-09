#ifndef CDBJOURNALITEM_H
    #define CDBJOURNALITEM_H
    //-------------------------
    #include <QTableWidgetItem>
    #include <QDateTime>
    //-------------------------------------------
    class CDbJournalItem: public QTableWidgetItem
    {
        public:
            explicit CDbJournalItem(const QString &text, int type = Type);
            bool operator< (const QTableWidgetItem&  other) const;
    };
#endif // CDBJOURNALITEM_H
