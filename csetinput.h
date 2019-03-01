#ifndef CSETINPUT_H
    #define CSETINPUT_H
    //----------------
    #include <QDialog>
    #include <QCheckBox>
    #include <QShowEvent>
    //----------
    namespace Ui
    {
        class CSetInput;
    }
    //-----------------------------
    class CSetInput: public QDialog
    {
        Q_OBJECT

        public:
            explicit CSetInput(QWidget* parent = Q_NULLPTR);
            ~CSetInput();
            QByteArray inputIndividualSettings();
            QByteArray inputGeneralSetting();
            bool isInputSetIndividual() const;
            bool isInputSetGeneral() const;

        public slots:
            void typeInput(const QString& text);
            void groupEnabled(bool state);
            void setInputCount(int addr);

        private:
            Ui::CSetInput*      ui;
            QVector<QCheckBox*> m_inputs;
    };
#endif // CSETINPUT_H
