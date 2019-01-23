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
            QByteArray intputSettings(int type);

        public slots:
            void open(int type);
            void typeInput(const QString& text);

        signals:
            void apply();

        private:
            Ui::CSetInput*      ui;
            QVector<QCheckBox*> m_inputs;
    };
#endif // CSETINPUT_H
