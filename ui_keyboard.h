/********************************************************************************
** Form generated from reading UI file 'keyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARD_H
#define UI_KEYBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qkey.h"

QT_BEGIN_NAMESPACE

class Ui_QKeyboard
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QKey *key_7;
    QKey *key_4;
    QKey *key_9;
    QSpacerItem *horizontalSpacer_4;
    QKey *key_6;
    QKey *key_1;
    QKey *key_0;
    QKey *key_esc;
    QSpacerItem *horizontalSpacer_8;
    QKey *key_point;
    QSpacerItem *horizontalSpacer_5;
    QKey *key_off;
    QKey *key_2;
    QKey *key_up;
    QKey *key_8;
    QKey *key_reset;
    QKey *key_down;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QKey *key_right;
    QKey *key_5;
    QKey *key_on;
    QSpacerItem *horizontalSpacer;
    QKey *key_3;
    QSpacerItem *horizontalSpacer_2;
    QKey *key_left;
    QSpacerItem *horizontalSpacer_3;
    QKey *key_ok;

    void setupUi(QWidget *QKeyboard)
    {
        if (QKeyboard->objectName().isEmpty())
            QKeyboard->setObjectName(QString::fromUtf8("QKeyboard"));
        QKeyboard->resize(269, 458);
        verticalLayout = new QVBoxLayout(QKeyboard);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        key_7 = new QKey(QKeyboard);
        key_7->setObjectName(QString::fromUtf8("key_7"));
        key_7->setMinimumSize(QSize(56, 56));
        key_7->setMaximumSize(QSize(56, 56));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        key_7->setFont(font);
        key_7->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_7, 0, 0, 1, 1);

        key_4 = new QKey(QKeyboard);
        key_4->setObjectName(QString::fromUtf8("key_4"));
        key_4->setMinimumSize(QSize(56, 56));
        key_4->setMaximumSize(QSize(56, 56));
        key_4->setFont(font);
        key_4->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_4, 1, 0, 1, 1);

        key_9 = new QKey(QKeyboard);
        key_9->setObjectName(QString::fromUtf8("key_9"));
        key_9->setMinimumSize(QSize(56, 56));
        key_9->setMaximumSize(QSize(56, 56));
        key_9->setFont(font);
        key_9->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_9, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 2, 1, 1);

        key_6 = new QKey(QKeyboard);
        key_6->setObjectName(QString::fromUtf8("key_6"));
        key_6->setMinimumSize(QSize(56, 56));
        key_6->setMaximumSize(QSize(56, 56));
        key_6->setFont(font);
        key_6->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_6, 1, 2, 1, 1);

        key_1 = new QKey(QKeyboard);
        key_1->setObjectName(QString::fromUtf8("key_1"));
        key_1->setMinimumSize(QSize(56, 56));
        key_1->setMaximumSize(QSize(56, 56));
        key_1->setFont(font);
        key_1->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_1, 2, 0, 1, 1);

        key_0 = new QKey(QKeyboard);
        key_0->setObjectName(QString::fromUtf8("key_0"));
        key_0->setMinimumSize(QSize(56, 56));
        key_0->setMaximumSize(QSize(56, 56));
        key_0->setFont(font);
        key_0->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_0, 3, 1, 1, 1);

        key_esc = new QKey(QKeyboard);
        key_esc->setObjectName(QString::fromUtf8("key_esc"));
        key_esc->setMinimumSize(QSize(56, 56));
        key_esc->setMaximumSize(QSize(56, 56));
        key_esc->setFont(font);
        key_esc->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_esc, 3, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 5, 3, 1, 1);

        key_point = new QKey(QKeyboard);
        key_point->setObjectName(QString::fromUtf8("key_point"));
        key_point->setMinimumSize(QSize(56, 56));
        key_point->setMaximumSize(QSize(56, 56));
        key_point->setFont(font);
        key_point->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_point, 3, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 0, 1, 1);

        key_off = new QKey(QKeyboard);
        key_off->setObjectName(QString::fromUtf8("key_off"));
        key_off->setMinimumSize(QSize(56, 56));
        key_off->setMaximumSize(QSize(56, 56));
        key_off->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/resource/images/key_off.png"), QSize(), QIcon::Normal, QIcon::Off);
        key_off->setIcon(icon);
        key_off->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_off, 4, 3, 1, 1);

        key_2 = new QKey(QKeyboard);
        key_2->setObjectName(QString::fromUtf8("key_2"));
        key_2->setMinimumSize(QSize(56, 56));
        key_2->setMaximumSize(QSize(56, 56));
        key_2->setFont(font);
        key_2->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_2, 2, 1, 1, 1);

        key_up = new QKey(QKeyboard);
        key_up->setObjectName(QString::fromUtf8("key_up"));
        key_up->setMinimumSize(QSize(56, 56));
        key_up->setMaximumSize(QSize(56, 56));
        key_up->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/resource/images/arrow_up.png"), QSize(), QIcon::Normal, QIcon::Off);
        key_up->setIcon(icon1);
        key_up->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_up, 4, 1, 1, 1);

        key_8 = new QKey(QKeyboard);
        key_8->setObjectName(QString::fromUtf8("key_8"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(48);
        sizePolicy.setVerticalStretch(48);
        sizePolicy.setHeightForWidth(key_8->sizePolicy().hasHeightForWidth());
        key_8->setSizePolicy(sizePolicy);
        key_8->setMinimumSize(QSize(56, 56));
        key_8->setMaximumSize(QSize(56, 56));
        key_8->setFont(font);
        key_8->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_8, 0, 1, 1, 1);

        key_reset = new QKey(QKeyboard);
        key_reset->setObjectName(QString::fromUtf8("key_reset"));
        key_reset->setMinimumSize(QSize(56, 56));
        key_reset->setMaximumSize(QSize(56, 56));
        key_reset->setFont(font);
        key_reset->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_reset, 6, 3, 1, 1);

        key_down = new QKey(QKeyboard);
        key_down->setObjectName(QString::fromUtf8("key_down"));
        key_down->setMinimumSize(QSize(56, 56));
        key_down->setMaximumSize(QSize(56, 56));
        key_down->setFont(font);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/resource/images/arrow_down.png"), QSize(), QIcon::Normal, QIcon::Off);
        key_down->setIcon(icon2);
        key_down->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_down, 6, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 6, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 6, 2, 1, 1);

        key_right = new QKey(QKeyboard);
        key_right->setObjectName(QString::fromUtf8("key_right"));
        key_right->setMinimumSize(QSize(56, 56));
        key_right->setMaximumSize(QSize(56, 56));
        key_right->setFont(font);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/resource/images/arrow_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        key_right->setIcon(icon3);
        key_right->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_right, 5, 2, 1, 1);

        key_5 = new QKey(QKeyboard);
        key_5->setObjectName(QString::fromUtf8("key_5"));
        key_5->setMinimumSize(QSize(56, 56));
        key_5->setMaximumSize(QSize(56, 56));
        key_5->setFont(font);
        key_5->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_5, 1, 1, 1, 1);

        key_on = new QKey(QKeyboard);
        key_on->setObjectName(QString::fromUtf8("key_on"));
        key_on->setMinimumSize(QSize(56, 56));
        key_on->setMaximumSize(QSize(56, 56));
        key_on->setFont(font);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/resource/images/key_on.png"), QSize(), QIcon::Normal, QIcon::Off);
        key_on->setIcon(icon4);
        key_on->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_on, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        key_3 = new QKey(QKeyboard);
        key_3->setObjectName(QString::fromUtf8("key_3"));
        key_3->setMinimumSize(QSize(56, 56));
        key_3->setMaximumSize(QSize(56, 56));
        key_3->setFont(font);
        key_3->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_3, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        key_left = new QKey(QKeyboard);
        key_left->setObjectName(QString::fromUtf8("key_left"));
        key_left->setMinimumSize(QSize(56, 56));
        key_left->setMaximumSize(QSize(56, 56));
        key_left->setFont(font);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/resource/images/arrow_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        key_left->setIcon(icon5);
        key_left->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_left, 5, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 3, 1, 1);

        key_ok = new QKey(QKeyboard);
        key_ok->setObjectName(QString::fromUtf8("key_ok"));
        key_ok->setMinimumSize(QSize(56, 56));
        key_ok->setMaximumSize(QSize(56, 56));
        key_ok->setFont(font);
        key_ok->setIconSize(QSize(32, 32));

        gridLayout->addWidget(key_ok, 5, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(QKeyboard);

        QMetaObject::connectSlotsByName(QKeyboard);
    } // setupUi

    void retranslateUi(QWidget *QKeyboard)
    {
        QKeyboard->setWindowTitle(QApplication::translate("QKeyboard", "Form", nullptr));
        key_7->setText(QApplication::translate("QKeyboard", "7", nullptr));
        key_4->setText(QApplication::translate("QKeyboard", "4", nullptr));
        key_9->setText(QApplication::translate("QKeyboard", "9", nullptr));
        key_6->setText(QApplication::translate("QKeyboard", "6", nullptr));
        key_1->setText(QApplication::translate("QKeyboard", "1", nullptr));
        key_0->setText(QApplication::translate("QKeyboard", "0", nullptr));
        key_esc->setText(QApplication::translate("QKeyboard", "Esc", nullptr));
        key_point->setText(QApplication::translate("QKeyboard", ".", nullptr));
        key_off->setText(QApplication::translate("QKeyboard", "0", nullptr));
        key_2->setText(QApplication::translate("QKeyboard", "2", nullptr));
        key_up->setText(QApplication::translate("QKeyboard", "0", nullptr));
        key_8->setText(QApplication::translate("QKeyboard", "8", nullptr));
        key_reset->setText(QApplication::translate("QKeyboard", "R", nullptr));
        key_down->setText(QApplication::translate("QKeyboard", "0", nullptr));
        key_right->setText(QApplication::translate("QKeyboard", "0", nullptr));
        key_5->setText(QApplication::translate("QKeyboard", "5", nullptr));
        key_on->setText(QApplication::translate("QKeyboard", "0", nullptr));
        key_3->setText(QApplication::translate("QKeyboard", "3", nullptr));
        key_left->setText(QApplication::translate("QKeyboard", "0", nullptr));
        key_ok->setText(QApplication::translate("QKeyboard", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QKeyboard: public Ui_QKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARD_H
