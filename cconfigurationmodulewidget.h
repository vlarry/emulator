#ifndef CCONFIGURATIONMODULEWIDGET_H
    #define CCONFIGURATIONMODULEWIDGET_H
    //----------------
    #include <QDialog>
    //----------
    namespace Ui
    {
        class CConfigurationModuleWidget;
    }
    //----------------------------------------------
    class CConfigurationModuleWidget: public QDialog
    {
        Q_OBJECT

        public:
            explicit CConfigurationModuleWidget(QWidget* parent = nullptr);
            ~CConfigurationModuleWidget();
            int        moduleType() const;
            int        moduleNumber() const;
            int        moduleNumberParty() const;
            int        moduleFirmwareVariant() const;
            QDate      moduleFirmwareDate() const;
            QByteArray moduleKeyCurrent() const;
            QByteArray moduleKeyNew() const;
            void       setModuleType(int type);
            void       setModuleNumber(int number);
            void       setModuleNumberParty(int number);
            void       setModuleFirmwareVariant(int variant);
            void       setModuleFirmwareDate(const QDate& date);

        protected:
            void close();

        private:
            Ui::CConfigurationModuleWidget* ui;
    };
#endif // CCONFIGURATIONMODULEWIDGET_H
