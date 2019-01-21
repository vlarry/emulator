/********************************************************************************
** Form generated from reading UI file 'configurationmodulewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONMODULEWIDGET_H
#define UI_CONFIGURATIONMODULEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CConfigurationModuleWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *lineEditModuleKeyNew;
    QComboBox *comboBoxModuleType;
    QLineEdit *lineEditModuleFirmwareVariant;
    QDateEdit *dateEdit;
    QLabel *label;
    QLineEdit *lineEditModuleNumberParty;
    QLabel *label_5;
    QLineEdit *lineEditModuleNumber;
    QLineEdit *lineEditModuleKeyCurrent;
    QCheckBox *checkBoxNewKey;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CConfigurationModuleWidget)
    {
        if (CConfigurationModuleWidget->objectName().isEmpty())
            CConfigurationModuleWidget->setObjectName(QString::fromUtf8("CConfigurationModuleWidget"));
        CConfigurationModuleWidget->resize(427, 255);
        verticalLayout = new QVBoxLayout(CConfigurationModuleWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(CConfigurationModuleWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(CConfigurationModuleWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(CConfigurationModuleWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(CConfigurationModuleWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_7 = new QLabel(CConfigurationModuleWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        lineEditModuleKeyNew = new QLineEdit(CConfigurationModuleWidget);
        lineEditModuleKeyNew->setObjectName(QString::fromUtf8("lineEditModuleKeyNew"));
        lineEditModuleKeyNew->setMaxLength(4);
        lineEditModuleKeyNew->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditModuleKeyNew, 6, 1, 1, 1);

        comboBoxModuleType = new QComboBox(CConfigurationModuleWidget);
        comboBoxModuleType->addItem(QString());
        comboBoxModuleType->addItem(QString());
        comboBoxModuleType->addItem(QString());
        comboBoxModuleType->setObjectName(QString::fromUtf8("comboBoxModuleType"));

        gridLayout->addWidget(comboBoxModuleType, 0, 1, 1, 1);

        lineEditModuleFirmwareVariant = new QLineEdit(CConfigurationModuleWidget);
        lineEditModuleFirmwareVariant->setObjectName(QString::fromUtf8("lineEditModuleFirmwareVariant"));
        lineEditModuleFirmwareVariant->setMaxLength(2);
        lineEditModuleFirmwareVariant->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditModuleFirmwareVariant, 3, 1, 1, 1);

        dateEdit = new QDateEdit(CConfigurationModuleWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(dateEdit, 4, 1, 1, 1);

        label = new QLabel(CConfigurationModuleWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditModuleNumberParty = new QLineEdit(CConfigurationModuleWidget);
        lineEditModuleNumberParty->setObjectName(QString::fromUtf8("lineEditModuleNumberParty"));
        lineEditModuleNumberParty->setMaxLength(2);
        lineEditModuleNumberParty->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditModuleNumberParty, 2, 1, 1, 1);

        label_5 = new QLabel(CConfigurationModuleWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEditModuleNumber = new QLineEdit(CConfigurationModuleWidget);
        lineEditModuleNumber->setObjectName(QString::fromUtf8("lineEditModuleNumber"));
        lineEditModuleNumber->setMaxLength(4);
        lineEditModuleNumber->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditModuleNumber, 1, 1, 1, 1);

        lineEditModuleKeyCurrent = new QLineEdit(CConfigurationModuleWidget);
        lineEditModuleKeyCurrent->setObjectName(QString::fromUtf8("lineEditModuleKeyCurrent"));
        lineEditModuleKeyCurrent->setContextMenuPolicy(Qt::CustomContextMenu);
        lineEditModuleKeyCurrent->setMaxLength(4);
        lineEditModuleKeyCurrent->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditModuleKeyCurrent, 5, 1, 1, 1);

        checkBoxNewKey = new QCheckBox(CConfigurationModuleWidget);
        checkBoxNewKey->setObjectName(QString::fromUtf8("checkBoxNewKey"));

        gridLayout->addWidget(checkBoxNewKey, 6, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(CConfigurationModuleWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CConfigurationModuleWidget);
        QObject::connect(buttonBox, SIGNAL(accepted()), CConfigurationModuleWidget, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CConfigurationModuleWidget, SLOT(reject()));

        QMetaObject::connectSlotsByName(CConfigurationModuleWidget);
    } // setupUi

    void retranslateUi(QDialog *CConfigurationModuleWidget)
    {
        CConfigurationModuleWidget->setWindowTitle(QApplication::translate("CConfigurationModuleWidget", "\320\232\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\274\320\276\320\264\321\203\320\273\321\217", nullptr));
        label_6->setText(QApplication::translate("CConfigurationModuleWidget", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\272\320\273\321\216\321\207", nullptr));
        label_2->setText(QApplication::translate("CConfigurationModuleWidget", "\320\237\320\276\321\200\321\217\320\264\320\272\320\276\320\262\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        label_4->setText(QApplication::translate("CConfigurationModuleWidget", "\320\222\320\260\321\200\320\270\320\260\320\275\321\202 \320\277\321\200\320\276\321\210\320\270\320\262\320\272\320\270", nullptr));
        label_3->setText(QApplication::translate("CConfigurationModuleWidget", "\320\235\320\276\320\274\320\265\321\200 \320\262 \320\277\320\260\321\200\321\202\320\270\320\270", nullptr));
        label_7->setText(QApplication::translate("CConfigurationModuleWidget", "\320\235\320\276\320\262\321\213\320\271 \320\272\320\273\321\216\321\207", nullptr));
        lineEditModuleKeyNew->setText(QApplication::translate("CConfigurationModuleWidget", "0000", nullptr));
        comboBoxModuleType->setItemText(0, QApplication::translate("CConfigurationModuleWidget", "\320\234\320\224\320\222\320\222-01", nullptr));
        comboBoxModuleType->setItemText(1, QApplication::translate("CConfigurationModuleWidget", "\320\234\320\224\320\222\320\222-02", nullptr));
        comboBoxModuleType->setItemText(2, QApplication::translate("CConfigurationModuleWidget", "\320\234\320\230\320\232-01", nullptr));

        lineEditModuleFirmwareVariant->setText(QApplication::translate("CConfigurationModuleWidget", "00", nullptr));
        label->setText(QApplication::translate("CConfigurationModuleWidget", "\320\234\320\276\320\264\321\203\320\273\321\214", nullptr));
        lineEditModuleNumberParty->setText(QApplication::translate("CConfigurationModuleWidget", "00", nullptr));
        label_5->setText(QApplication::translate("CConfigurationModuleWidget", "\320\224\320\260\321\202\320\260", nullptr));
        lineEditModuleNumber->setText(QApplication::translate("CConfigurationModuleWidget", "0000", nullptr));
        lineEditModuleKeyCurrent->setText(QApplication::translate("CConfigurationModuleWidget", "0000", nullptr));
#ifndef QT_NO_TOOLTIP
        checkBoxNewKey->setToolTip(QApplication::translate("CConfigurationModuleWidget", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\272\320\273\321\216\321\207", nullptr));
#endif // QT_NO_TOOLTIP
        checkBoxNewKey->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CConfigurationModuleWidget: public Ui_CConfigurationModuleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONMODULEWIDGET_H
