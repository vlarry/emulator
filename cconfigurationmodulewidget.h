#ifndef CCONFIGURATIONMODULEWIDGET_H
    #define CCONFIGURATIONMODULEWIDGET_H
    //----------------
    #include <QDialog>
    #include <QDate>
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
            enum type_t
            {
                CURRENT,
                NEW
            };

        public:
            explicit CConfigurationModuleWidget(QWidget* parent = nullptr);
            ~CConfigurationModuleWidget();
            int        moduleType(type_t type) const;
            int        moduleNumber(type_t type) const;
            int        moduleNumberParty(type_t type) const;
            int        moduleFirmwareVariant(type_t type) const;
            QByteArray moduleKeyCurrent() const;
            QByteArray moduleKeyNew() const;
            void       setModuleType(int module_type, type_t type);
            void       setModuleNumber(int number, type_t type);
            void       setModuleNumberParty(int number, type_t type);
            void       setModuleFirmwareVariant(int variant, type_t type);
            void       setModuleFirmwareDate(const QString& date, type_t type);

        protected:
            void showEvent(QShowEvent* event);
            void close();

        private slots:
            void newKeyStateChanged(bool state);

        private:
            Ui::CConfigurationModuleWidget* ui;
    };
#endif // CCONFIGURATIONMODULEWIDGET_H
