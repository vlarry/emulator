/********************************************************************************
** Form generated from reading UI file 'command.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMAND_H
#define UI_COMMAND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QCommand
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *lwCmd;

    void setupUi(QWidget *QCommand)
    {
        if (QCommand->objectName().isEmpty())
            QCommand->setObjectName(QString::fromUtf8("QCommand"));
        QCommand->resize(277, 487);
        verticalLayout = new QVBoxLayout(QCommand);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lwCmd = new QListWidget(QCommand);
        lwCmd->setObjectName(QString::fromUtf8("lwCmd"));

        verticalLayout->addWidget(lwCmd);


        retranslateUi(QCommand);

        QMetaObject::connectSlotsByName(QCommand);
    } // setupUi

    void retranslateUi(QWidget *QCommand)
    {
        QCommand->setWindowTitle(QApplication::translate("QCommand", "\320\232\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QCommand: public Ui_QCommand {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMAND_H
