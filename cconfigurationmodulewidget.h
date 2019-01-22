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
            explicit CConfigurationModuleWidget(QWidget* parent = nullptr);
            ~CConfigurationModuleWidget();
            int        moduleType() const;
            int        moduleNumber() const;
            int        moduleNumberParty() const;
            int        moduleFirmwareVariant() const;
            QByteArray moduleKeyCurrent() const;
            QByteArray moduleKeyNew() const;
            void       setModuleType(int type);
            void       setModuleNumber(int number);
            void       setModuleNumberParty(int number);
            void       setModuleFirmwareVariant(int variant);
            void       setModuleFirmwareDate(const QString& date);

        protected:
            void showEvent(QShowEvent* event);
            void close();

        private slots:
            void newKeyStateChanged(bool state);

        private:
            Ui::CConfigurationModuleWidget* ui;
    };
#endif // CCONFIGURATIONMODULEWIDGET_H
