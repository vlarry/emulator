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

        private:
            Ui::CConfigurationModuleWidget* ui;
    };
#endif // CCONFIGURATIONMODULEWIDGET_H
