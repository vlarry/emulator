#ifndef CSETINPUT_H
    #define CSETINPUT_H
    //----------------
    #include <QWidget>
    #include <QCheckBox>
    //----------
    namespace Ui
    {
        class CSetInput;
    }
    //-----------------------------
    class CSetInput: public QWidget
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

        signals:
            void setWrite();

        private:
            Ui::CSetInput*      ui;
            QVector<QCheckBox*> m_inputs;
    };
#endif // CSETINPUT_H
