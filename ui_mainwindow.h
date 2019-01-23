/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ciodevice.h"
#include "qcmd.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_34;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_11;
    QGroupBox *grboxComPort;
    QGridLayout *gridLayout;
    QPushButton *pbCtrlPort;
    QLabel *lblNameBaudrate;
    QLabel *lblNamePort;
    QToolButton *tbPortRefresh;
    QComboBox *cbPortNames;
    QComboBox *cbBaudrate;
    QSpacerItem *horizontalSpacer_16;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *cboxTerminal;
    QCheckBox *cbKeyboard;
    QCheckBox *cbCommand;
    QCheckBox *checkBoxSerialConfig;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupDevices;
    QVBoxLayout *verticalLayout_33;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_34;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QCmd *cbCmdList;
    QLabel *lblCommand;
    QLabel *lblDeviceAddress;
    QSpinBox *sbDeviceAddress;
    QPushButton *pbCmdSend;
    QLabel *lblCmdDescription;
    QSpacerItem *horizontalSpacer;
    QGroupBox *gboxAutorepeat;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_20;
    QCheckBox *cboxRepeatInputs;
    QSpinBox *sbRepeatInputs;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *cboxRepeatAIN;
    QSpinBox *sbRepeatAIN;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_33;
    QLabel *lblStateDSIDIN;
    QLineEdit *leStateDSDIN;
    QSpacerItem *horizontalSpacer_44;
    QLabel *lblTimeDSDIN;
    QLineEdit *leTimeDSDIN;
    QGroupBox *gboxInputSettings;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *gboxInputSettingsFilter;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *lblPeriods;
    QSpinBox *sbPeriods;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_13;
    QLabel *lblDiscret;
    QSpacerItem *horizontalSpacer_8;
    QSpinBox *sbDiscret;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lblSignal;
    QSpacerItem *horizontalSpacer_9;
    QSpinBox *sbSignal;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *gboxInput;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonInputSingle;
    QRadioButton *radioButtonInputGroup;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButtonInputSet;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_9;
    QLineEdit *lineEditMessageQueue;
    QFrame *line;
    QTabWidget *twPeriphery;
    QWidget *tabIO;
    QVBoxLayout *verticalLayout_32;
    QHBoxLayout *horizontalLayout_85;
    QSpacerItem *horizontalSpacer_97;
    QGroupBox *gboxInputs;
    QHBoxLayout *horizontalLayout_43;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_10;
    CIODevice *IN1;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_17;
    CIODevice *IN2;
    QSpacerItem *horizontalSpacer_18;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_20;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_21;
    CIODevice *IN3;
    QSpacerItem *horizontalSpacer_23;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_23;
    QSpacerItem *horizontalSpacer_24;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_25;
    QHBoxLayout *horizontalLayout_24;
    QSpacerItem *horizontalSpacer_26;
    CIODevice *IN4;
    QSpacerItem *horizontalSpacer_27;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_25;
    QSpacerItem *horizontalSpacer_28;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_29;
    QHBoxLayout *horizontalLayout_26;
    QSpacerItem *horizontalSpacer_30;
    CIODevice *IN5;
    QSpacerItem *horizontalSpacer_31;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_27;
    QSpacerItem *horizontalSpacer_32;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_33;
    QHBoxLayout *horizontalLayout_28;
    QSpacerItem *horizontalSpacer_34;
    CIODevice *IN6;
    QSpacerItem *horizontalSpacer_35;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *horizontalLayout_29;
    QSpacerItem *horizontalSpacer_36;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_37;
    QHBoxLayout *horizontalLayout_30;
    QSpacerItem *horizontalSpacer_38;
    CIODevice *IN7;
    QSpacerItem *horizontalSpacer_39;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_31;
    QSpacerItem *horizontalSpacer_40;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_41;
    QHBoxLayout *horizontalLayout_32;
    QSpacerItem *horizontalSpacer_42;
    CIODevice *IN8;
    QSpacerItem *horizontalSpacer_43;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_35;
    QSpacerItem *horizontalSpacer_48;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_49;
    QHBoxLayout *horizontalLayout_36;
    QSpacerItem *horizontalSpacer_50;
    CIODevice *IN9;
    QSpacerItem *horizontalSpacer_51;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_37;
    QSpacerItem *horizontalSpacer_52;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_53;
    QHBoxLayout *horizontalLayout_38;
    QSpacerItem *horizontalSpacer_54;
    CIODevice *IN10;
    QSpacerItem *horizontalSpacer_55;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_39;
    QSpacerItem *horizontalSpacer_56;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_57;
    QHBoxLayout *horizontalLayout_40;
    QSpacerItem *horizontalSpacer_58;
    CIODevice *IN11;
    QSpacerItem *horizontalSpacer_59;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_41;
    QSpacerItem *horizontalSpacer_60;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_61;
    QHBoxLayout *horizontalLayout_42;
    QSpacerItem *horizontalSpacer_62;
    CIODevice *IN12;
    QSpacerItem *horizontalSpacer_63;
    QSpacerItem *horizontalSpacer_96;
    QHBoxLayout *horizontalLayout_70;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_44;
    QSpacerItem *horizontalSpacer_64;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_65;
    QHBoxLayout *horizontalLayout_45;
    QSpacerItem *horizontalSpacer_66;
    CIODevice *OUT1;
    QSpacerItem *horizontalSpacer_67;
    QVBoxLayout *verticalLayout_21;
    QHBoxLayout *horizontalLayout_46;
    QSpacerItem *horizontalSpacer_68;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_69;
    QHBoxLayout *horizontalLayout_47;
    QSpacerItem *horizontalSpacer_70;
    CIODevice *OUT2;
    QSpacerItem *horizontalSpacer_71;
    QVBoxLayout *verticalLayout_22;
    QHBoxLayout *horizontalLayout_48;
    QSpacerItem *horizontalSpacer_72;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_73;
    QHBoxLayout *horizontalLayout_49;
    QSpacerItem *horizontalSpacer_74;
    CIODevice *OUT3;
    QSpacerItem *horizontalSpacer_75;
    QVBoxLayout *verticalLayout_23;
    QHBoxLayout *horizontalLayout_50;
    QSpacerItem *horizontalSpacer_76;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_77;
    QHBoxLayout *horizontalLayout_51;
    QSpacerItem *horizontalSpacer_78;
    CIODevice *OUT4;
    QSpacerItem *horizontalSpacer_79;
    QVBoxLayout *verticalLayout_24;
    QHBoxLayout *horizontalLayout_52;
    QSpacerItem *horizontalSpacer_80;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_81;
    QHBoxLayout *horizontalLayout_53;
    QSpacerItem *horizontalSpacer_82;
    CIODevice *OUT5;
    QSpacerItem *horizontalSpacer_83;
    QVBoxLayout *verticalLayout_25;
    QHBoxLayout *horizontalLayout_54;
    QSpacerItem *horizontalSpacer_84;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_85;
    QHBoxLayout *horizontalLayout_55;
    QSpacerItem *horizontalSpacer_86;
    CIODevice *OUT6;
    QSpacerItem *horizontalSpacer_87;
    QVBoxLayout *verticalLayout_26;
    QHBoxLayout *horizontalLayout_56;
    QSpacerItem *horizontalSpacer_88;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_89;
    QHBoxLayout *horizontalLayout_57;
    QSpacerItem *horizontalSpacer_90;
    CIODevice *OUT7;
    QSpacerItem *horizontalSpacer_91;
    QVBoxLayout *verticalLayout_27;
    QHBoxLayout *horizontalLayout_58;
    QSpacerItem *horizontalSpacer_92;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer_93;
    QHBoxLayout *horizontalLayout_59;
    QSpacerItem *horizontalSpacer_94;
    CIODevice *OUT8;
    QSpacerItem *horizontalSpacer_95;
    QVBoxLayout *verticalLayout_28;
    QHBoxLayout *horizontalLayout_62;
    QSpacerItem *horizontalSpacer_98;
    QLabel *label_22;
    QSpacerItem *horizontalSpacer_99;
    QHBoxLayout *horizontalLayout_63;
    QSpacerItem *horizontalSpacer_100;
    CIODevice *OUT9;
    QSpacerItem *horizontalSpacer_101;
    QVBoxLayout *verticalLayout_29;
    QHBoxLayout *horizontalLayout_64;
    QSpacerItem *horizontalSpacer_102;
    QLabel *label_23;
    QSpacerItem *horizontalSpacer_103;
    QHBoxLayout *horizontalLayout_65;
    QSpacerItem *horizontalSpacer_104;
    CIODevice *OUT10;
    QSpacerItem *horizontalSpacer_105;
    QVBoxLayout *verticalLayout_30;
    QHBoxLayout *horizontalLayout_66;
    QSpacerItem *horizontalSpacer_106;
    QLabel *label_24;
    QSpacerItem *horizontalSpacer_107;
    QHBoxLayout *horizontalLayout_67;
    QSpacerItem *horizontalSpacer_108;
    CIODevice *OUT11;
    QSpacerItem *horizontalSpacer_109;
    QVBoxLayout *verticalLayout_31;
    QHBoxLayout *horizontalLayout_68;
    QSpacerItem *horizontalSpacer_110;
    QLabel *label_25;
    QSpacerItem *horizontalSpacer_111;
    QHBoxLayout *horizontalLayout_69;
    QSpacerItem *horizontalSpacer_112;
    CIODevice *OUT12;
    QSpacerItem *horizontalSpacer_113;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_87;
    QSpacerItem *horizontalSpacer_147;
    QGroupBox *groupAIN;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_40;
    QLabel *lblAIN1;
    QLineEdit *leAIN1;
    QVBoxLayout *verticalLayout_41;
    QLabel *lblAIN2;
    QLineEdit *leAIN2;
    QVBoxLayout *verticalLayout_42;
    QLabel *lblAIN3;
    QLineEdit *leAIN3;
    QVBoxLayout *verticalLayout_43;
    QLabel *lblAIN4;
    QLineEdit *leAIN4;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_148;
    QWidget *tabInfo;
    QHBoxLayout *horizontalLayout_72;
    QVBoxLayout *verticalLayout_39;
    QGroupBox *groupError;
    QHBoxLayout *horizontalLayout_71;
    QVBoxLayout *verticalLayout_36;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QVBoxLayout *verticalLayout_35;
    QLineEdit *leErrorAddr;
    QLineEdit *leErrorCmd;
    QLineEdit *leErrorChecksum;
    QGroupBox *groupDeviceInfo;
    QHBoxLayout *horizontalLayout_73;
    QVBoxLayout *verticalLayout_38;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QVBoxLayout *verticalLayout_37;
    QLineEdit *leDeviceID;
    QLineEdit *leDeviceNumber;
    QLineEdit *leDeviceLotNum;
    QLineEdit *leDeviceFirmwareVar;
    QLineEdit *leDeviceFirmwareDate;
    QSpacerItem *horizontalSpacer_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dwTerminal;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_15;
    QPlainTextEdit *pteConsole;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1284, 858);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_34 = new QVBoxLayout(centralWidget);
        verticalLayout_34->setSpacing(6);
        verticalLayout_34->setContentsMargins(11, 11, 11, 11);
        verticalLayout_34->setObjectName(QString::fromUtf8("verticalLayout_34"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        grboxComPort = new QGroupBox(centralWidget);
        grboxComPort->setObjectName(QString::fromUtf8("grboxComPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grboxComPort->sizePolicy().hasHeightForWidth());
        grboxComPort->setSizePolicy(sizePolicy);
        grboxComPort->setAlignment(Qt::AlignCenter);
        grboxComPort->setFlat(false);
        gridLayout = new QGridLayout(grboxComPort);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 5, -1, 5);
        pbCtrlPort = new QPushButton(grboxComPort);
        pbCtrlPort->setObjectName(QString::fromUtf8("pbCtrlPort"));
        pbCtrlPort->setCheckable(true);
        pbCtrlPort->setChecked(false);
        pbCtrlPort->setAutoDefault(false);
        pbCtrlPort->setFlat(false);

        gridLayout->addWidget(pbCtrlPort, 0, 6, 1, 1);

        lblNameBaudrate = new QLabel(grboxComPort);
        lblNameBaudrate->setObjectName(QString::fromUtf8("lblNameBaudrate"));

        gridLayout->addWidget(lblNameBaudrate, 2, 0, 1, 2);

        lblNamePort = new QLabel(grboxComPort);
        lblNamePort->setObjectName(QString::fromUtf8("lblNamePort"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblNamePort->sizePolicy().hasHeightForWidth());
        lblNamePort->setSizePolicy(sizePolicy1);
        lblNamePort->setContextMenuPolicy(Qt::NoContextMenu);
        lblNamePort->setTextFormat(Qt::AutoText);
        lblNamePort->setScaledContents(false);
        lblNamePort->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblNamePort->setWordWrap(false);

        gridLayout->addWidget(lblNamePort, 0, 0, 1, 1);

        tbPortRefresh = new QToolButton(grboxComPort);
        tbPortRefresh->setObjectName(QString::fromUtf8("tbPortRefresh"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/resource/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbPortRefresh->setIcon(icon);

        gridLayout->addWidget(tbPortRefresh, 0, 4, 1, 2);

        cbPortNames = new QComboBox(grboxComPort);
        cbPortNames->setObjectName(QString::fromUtf8("cbPortNames"));

        gridLayout->addWidget(cbPortNames, 0, 3, 1, 1);

        cbBaudrate = new QComboBox(grboxComPort);
        cbBaudrate->setObjectName(QString::fromUtf8("cbBaudrate"));

        gridLayout->addWidget(cbBaudrate, 2, 3, 1, 1);


        horizontalLayout_11->addWidget(grboxComPort);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_16);


        horizontalLayout_18->addLayout(horizontalLayout_11);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        cboxTerminal = new QCheckBox(centralWidget);
        cboxTerminal->setObjectName(QString::fromUtf8("cboxTerminal"));

        verticalLayout_5->addWidget(cboxTerminal);

        cbKeyboard = new QCheckBox(centralWidget);
        cbKeyboard->setObjectName(QString::fromUtf8("cbKeyboard"));
        cbKeyboard->setChecked(true);

        verticalLayout_5->addWidget(cbKeyboard);

        cbCommand = new QCheckBox(centralWidget);
        cbCommand->setObjectName(QString::fromUtf8("cbCommand"));

        verticalLayout_5->addWidget(cbCommand);

        checkBoxSerialConfig = new QCheckBox(centralWidget);
        checkBoxSerialConfig->setObjectName(QString::fromUtf8("checkBoxSerialConfig"));

        verticalLayout_5->addWidget(checkBoxSerialConfig);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_18->addLayout(verticalLayout_5);


        verticalLayout_34->addLayout(horizontalLayout_18);

        groupDevices = new QGroupBox(centralWidget);
        groupDevices->setObjectName(QString::fromUtf8("groupDevices"));
        groupDevices->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupDevices->sizePolicy().hasHeightForWidth());
        groupDevices->setSizePolicy(sizePolicy2);
        verticalLayout_33 = new QVBoxLayout(groupDevices);
        verticalLayout_33->setSpacing(6);
        verticalLayout_33->setContentsMargins(11, 11, 11, 11);
        verticalLayout_33->setObjectName(QString::fromUtf8("verticalLayout_33"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setVerticalSpacing(6);
        cbCmdList = new QCmd(groupDevices);
        cbCmdList->setObjectName(QString::fromUtf8("cbCmdList"));

        gridLayout_2->addWidget(cbCmdList, 1, 1, 1, 1);

        lblCommand = new QLabel(groupDevices);
        lblCommand->setObjectName(QString::fromUtf8("lblCommand"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblCommand->sizePolicy().hasHeightForWidth());
        lblCommand->setSizePolicy(sizePolicy3);
        lblCommand->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblCommand, 1, 0, 1, 1);

        lblDeviceAddress = new QLabel(groupDevices);
        lblDeviceAddress->setObjectName(QString::fromUtf8("lblDeviceAddress"));
        sizePolicy3.setHeightForWidth(lblDeviceAddress->sizePolicy().hasHeightForWidth());
        lblDeviceAddress->setSizePolicy(sizePolicy3);
        lblDeviceAddress->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lblDeviceAddress, 0, 0, 1, 1);

        sbDeviceAddress = new QSpinBox(groupDevices);
        sbDeviceAddress->setObjectName(QString::fromUtf8("sbDeviceAddress"));
        sbDeviceAddress->setAlignment(Qt::AlignCenter);
        sbDeviceAddress->setMaximum(3);

        gridLayout_2->addWidget(sbDeviceAddress, 0, 1, 1, 1);

        pbCmdSend = new QPushButton(groupDevices);
        pbCmdSend->setObjectName(QString::fromUtf8("pbCmdSend"));

        gridLayout_2->addWidget(pbCmdSend, 2, 1, 1, 1);

        lblCmdDescription = new QLabel(groupDevices);
        lblCmdDescription->setObjectName(QString::fromUtf8("lblCmdDescription"));
        lblCmdDescription->setScaledContents(true);

        gridLayout_2->addWidget(lblCmdDescription, 1, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        horizontalLayout_34->addLayout(horizontalLayout);

        gboxAutorepeat = new QGroupBox(groupDevices);
        gboxAutorepeat->setObjectName(QString::fromUtf8("gboxAutorepeat"));
        gboxAutorepeat->setEnabled(false);
        gboxAutorepeat->setAlignment(Qt::AlignCenter);
        verticalLayout_6 = new QVBoxLayout(gboxAutorepeat);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 5, -1, 5);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        cboxRepeatInputs = new QCheckBox(gboxAutorepeat);
        cboxRepeatInputs->setObjectName(QString::fromUtf8("cboxRepeatInputs"));

        horizontalLayout_20->addWidget(cboxRepeatInputs);

        sbRepeatInputs = new QSpinBox(gboxAutorepeat);
        sbRepeatInputs->setObjectName(QString::fromUtf8("sbRepeatInputs"));
        sbRepeatInputs->setAlignment(Qt::AlignCenter);
        sbRepeatInputs->setMinimum(10);
        sbRepeatInputs->setMaximum(1000);
        sbRepeatInputs->setSingleStep(10);
        sbRepeatInputs->setValue(20);

        horizontalLayout_20->addWidget(sbRepeatInputs);


        verticalLayout_6->addLayout(horizontalLayout_20);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        cboxRepeatAIN = new QCheckBox(gboxAutorepeat);
        cboxRepeatAIN->setObjectName(QString::fromUtf8("cboxRepeatAIN"));

        horizontalLayout_19->addWidget(cboxRepeatAIN);

        sbRepeatAIN = new QSpinBox(gboxAutorepeat);
        sbRepeatAIN->setObjectName(QString::fromUtf8("sbRepeatAIN"));
        sbRepeatAIN->setAlignment(Qt::AlignCenter);
        sbRepeatAIN->setMinimum(10);
        sbRepeatAIN->setMaximum(10000);
        sbRepeatAIN->setSingleStep(10);
        sbRepeatAIN->setValue(20);

        horizontalLayout_19->addWidget(sbRepeatAIN);


        verticalLayout_6->addLayout(horizontalLayout_19);


        horizontalLayout_34->addWidget(gboxAutorepeat);


        verticalLayout_7->addLayout(horizontalLayout_34);

        groupBox_2 = new QGroupBox(groupDevices);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        horizontalLayout_33 = new QHBoxLayout(groupBox_2);
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        lblStateDSIDIN = new QLabel(groupBox_2);
        lblStateDSIDIN->setObjectName(QString::fromUtf8("lblStateDSIDIN"));

        horizontalLayout_33->addWidget(lblStateDSIDIN);

        leStateDSDIN = new QLineEdit(groupBox_2);
        leStateDSDIN->setObjectName(QString::fromUtf8("leStateDSDIN"));
        leStateDSDIN->setMinimumSize(QSize(200, 0));
        leStateDSDIN->setMaxLength(100);
        leStateDSDIN->setAlignment(Qt::AlignCenter);
        leStateDSDIN->setReadOnly(true);

        horizontalLayout_33->addWidget(leStateDSDIN);

        horizontalSpacer_44 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_44);

        lblTimeDSDIN = new QLabel(groupBox_2);
        lblTimeDSDIN->setObjectName(QString::fromUtf8("lblTimeDSDIN"));

        horizontalLayout_33->addWidget(lblTimeDSDIN);

        leTimeDSDIN = new QLineEdit(groupBox_2);
        leTimeDSDIN->setObjectName(QString::fromUtf8("leTimeDSDIN"));
        leTimeDSDIN->setMaxLength(8);
        leTimeDSDIN->setAlignment(Qt::AlignCenter);
        leTimeDSDIN->setReadOnly(true);

        horizontalLayout_33->addWidget(leTimeDSDIN);


        verticalLayout_7->addWidget(groupBox_2);


        horizontalLayout_14->addLayout(verticalLayout_7);

        gboxInputSettings = new QGroupBox(groupDevices);
        gboxInputSettings->setObjectName(QString::fromUtf8("gboxInputSettings"));
        gboxInputSettings->setAlignment(Qt::AlignCenter);
        horizontalLayout_9 = new QHBoxLayout(gboxInputSettings);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gboxInputSettingsFilter = new QGroupBox(gboxInputSettings);
        gboxInputSettingsFilter->setObjectName(QString::fromUtf8("gboxInputSettingsFilter"));
        gboxInputSettingsFilter->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(gboxInputSettingsFilter);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        lblPeriods = new QLabel(gboxInputSettingsFilter);
        lblPeriods->setObjectName(QString::fromUtf8("lblPeriods"));

        horizontalLayout_12->addWidget(lblPeriods);

        sbPeriods = new QSpinBox(gboxInputSettingsFilter);
        sbPeriods->setObjectName(QString::fromUtf8("sbPeriods"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sbPeriods->sizePolicy().hasHeightForWidth());
        sbPeriods->setSizePolicy(sizePolicy4);
        sbPeriods->setAccelerated(true);
        sbPeriods->setMinimum(1);
        sbPeriods->setMaximum(100);
        sbPeriods->setValue(3);

        horizontalLayout_12->addWidget(sbPeriods);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lblDiscret = new QLabel(gboxInputSettingsFilter);
        lblDiscret->setObjectName(QString::fromUtf8("lblDiscret"));

        horizontalLayout_13->addWidget(lblDiscret);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_8);

        sbDiscret = new QSpinBox(gboxInputSettingsFilter);
        sbDiscret->setObjectName(QString::fromUtf8("sbDiscret"));
        sbDiscret->setAccelerated(true);
        sbDiscret->setMinimum(10);
        sbDiscret->setMaximum(40);
        sbDiscret->setSingleStep(10);

        horizontalLayout_13->addWidget(sbDiscret);


        horizontalLayout_10->addLayout(horizontalLayout_13);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lblSignal = new QLabel(gboxInputSettingsFilter);
        lblSignal->setObjectName(QString::fromUtf8("lblSignal"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lblSignal->sizePolicy().hasHeightForWidth());
        lblSignal->setSizePolicy(sizePolicy5);
        lblSignal->setScaledContents(true);

        horizontalLayout_8->addWidget(lblSignal);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        sbSignal = new QSpinBox(gboxInputSettingsFilter);
        sbSignal->setObjectName(QString::fromUtf8("sbSignal"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(sbSignal->sizePolicy().hasHeightForWidth());
        sbSignal->setSizePolicy(sizePolicy6);
        sbSignal->setMinimum(1);
        sbSignal->setMaximum(100);
        sbSignal->setValue(5);

        horizontalLayout_8->addWidget(sbSignal);


        horizontalLayout_15->addLayout(horizontalLayout_8);


        verticalLayout_2->addLayout(horizontalLayout_15);


        verticalLayout_4->addWidget(gboxInputSettingsFilter);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_9->addLayout(verticalLayout_4);

        gboxInput = new QGroupBox(gboxInputSettings);
        gboxInput->setObjectName(QString::fromUtf8("gboxInput"));
        gboxInput->setAlignment(Qt::AlignCenter);
        verticalLayout_3 = new QVBoxLayout(gboxInput);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButtonInputSingle = new QRadioButton(gboxInput);
        radioButtonInputSingle->setObjectName(QString::fromUtf8("radioButtonInputSingle"));

        verticalLayout_3->addWidget(radioButtonInputSingle);

        radioButtonInputGroup = new QRadioButton(gboxInput);
        radioButtonInputGroup->setObjectName(QString::fromUtf8("radioButtonInputGroup"));
        radioButtonInputGroup->setChecked(true);

        verticalLayout_3->addWidget(radioButtonInputGroup);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        pushButtonInputSet = new QPushButton(gboxInput);
        pushButtonInputSet->setObjectName(QString::fromUtf8("pushButtonInputSet"));

        verticalLayout_3->addWidget(pushButtonInputSet);


        horizontalLayout_9->addWidget(gboxInput);


        horizontalLayout_14->addWidget(gboxInputSettings);


        verticalLayout_33->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_7);

        label_9 = new QLabel(groupDevices);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_16->addWidget(label_9);

        lineEditMessageQueue = new QLineEdit(groupDevices);
        lineEditMessageQueue->setObjectName(QString::fromUtf8("lineEditMessageQueue"));
        sizePolicy.setHeightForWidth(lineEditMessageQueue->sizePolicy().hasHeightForWidth());
        lineEditMessageQueue->setSizePolicy(sizePolicy);
        lineEditMessageQueue->setAlignment(Qt::AlignCenter);
        lineEditMessageQueue->setReadOnly(true);

        horizontalLayout_16->addWidget(lineEditMessageQueue);


        verticalLayout_33->addLayout(horizontalLayout_16);

        line = new QFrame(groupDevices);
        line->setObjectName(QString::fromUtf8("line"));
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_33->addWidget(line);

        twPeriphery = new QTabWidget(groupDevices);
        twPeriphery->setObjectName(QString::fromUtf8("twPeriphery"));
        tabIO = new QWidget();
        tabIO->setObjectName(QString::fromUtf8("tabIO"));
        verticalLayout_32 = new QVBoxLayout(tabIO);
        verticalLayout_32->setSpacing(6);
        verticalLayout_32->setContentsMargins(11, 11, 11, 11);
        verticalLayout_32->setObjectName(QString::fromUtf8("verticalLayout_32"));
        horizontalLayout_85 = new QHBoxLayout();
        horizontalLayout_85->setSpacing(0);
        horizontalLayout_85->setObjectName(QString::fromUtf8("horizontalLayout_85"));
        horizontalSpacer_97 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_85->addItem(horizontalSpacer_97);

        gboxInputs = new QGroupBox(tabIO);
        gboxInputs->setObjectName(QString::fromUtf8("gboxInputs"));
        gboxInputs->setAlignment(Qt::AlignCenter);
        horizontalLayout_43 = new QHBoxLayout(gboxInputs);
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        horizontalLayout_43->setContentsMargins(5, 0, 5, -1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(gboxInputs);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_10 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        IN1 = new CIODevice(gboxInputs);
        IN1->setObjectName(QString::fromUtf8("IN1"));
        IN1->setMinimumSize(QSize(32, 32));
        IN1->setMaximumSize(QSize(32, 32));
        IN1->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(IN1);

        horizontalSpacer_11 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_43->addLayout(verticalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_14 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_14);

        label_2 = new QLabel(gboxInputs);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_2);

        horizontalSpacer_15 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_15);


        verticalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_17 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_17);

        IN2 = new CIODevice(gboxInputs);
        IN2->setObjectName(QString::fromUtf8("IN2"));
        IN2->setMinimumSize(QSize(32, 32));
        IN2->setMaximumSize(QSize(32, 32));
        IN2->setIconSize(QSize(24, 24));

        horizontalLayout_7->addWidget(IN2);

        horizontalSpacer_18 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_18);


        verticalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout_43->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        horizontalSpacer_19 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_19);

        label_3 = new QLabel(gboxInputs);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_21->addWidget(label_3);

        horizontalSpacer_20 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_20);


        verticalLayout_9->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalSpacer_21 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_21);

        IN3 = new CIODevice(gboxInputs);
        IN3->setObjectName(QString::fromUtf8("IN3"));
        IN3->setMinimumSize(QSize(32, 32));
        IN3->setMaximumSize(QSize(32, 32));
        IN3->setIconSize(QSize(24, 24));

        horizontalLayout_22->addWidget(IN3);

        horizontalSpacer_23 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_23);


        verticalLayout_9->addLayout(horizontalLayout_22);


        horizontalLayout_43->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setSpacing(0);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalSpacer_24 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_24);

        label_4 = new QLabel(gboxInputs);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_23->addWidget(label_4);

        horizontalSpacer_25 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_25);


        verticalLayout_10->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(0);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalSpacer_26 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_26);

        IN4 = new CIODevice(gboxInputs);
        IN4->setObjectName(QString::fromUtf8("IN4"));
        IN4->setMinimumSize(QSize(32, 32));
        IN4->setMaximumSize(QSize(32, 32));
        IN4->setIconSize(QSize(24, 24));

        horizontalLayout_24->addWidget(IN4);

        horizontalSpacer_27 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_27);


        verticalLayout_10->addLayout(horizontalLayout_24);


        horizontalLayout_43->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        horizontalSpacer_28 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_28);

        label_5 = new QLabel(gboxInputs);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_25->addWidget(label_5);

        horizontalSpacer_29 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_29);


        verticalLayout_11->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(0);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        horizontalSpacer_30 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_30);

        IN5 = new CIODevice(gboxInputs);
        IN5->setObjectName(QString::fromUtf8("IN5"));
        IN5->setMinimumSize(QSize(32, 32));
        IN5->setMaximumSize(QSize(32, 32));
        IN5->setIconSize(QSize(24, 24));

        horizontalLayout_26->addWidget(IN5);

        horizontalSpacer_31 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_31);


        verticalLayout_11->addLayout(horizontalLayout_26);


        horizontalLayout_43->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(0);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalSpacer_32 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_32);

        label_6 = new QLabel(gboxInputs);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_27->addWidget(label_6);

        horizontalSpacer_33 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_27->addItem(horizontalSpacer_33);


        verticalLayout_12->addLayout(horizontalLayout_27);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(0);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        horizontalSpacer_34 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_34);

        IN6 = new CIODevice(gboxInputs);
        IN6->setObjectName(QString::fromUtf8("IN6"));
        IN6->setMinimumSize(QSize(32, 32));
        IN6->setMaximumSize(QSize(32, 32));
        IN6->setIconSize(QSize(24, 24));

        horizontalLayout_28->addWidget(IN6);

        horizontalSpacer_35 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer_35);


        verticalLayout_12->addLayout(horizontalLayout_28);


        horizontalLayout_43->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(0);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        horizontalSpacer_36 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_36);

        label_7 = new QLabel(gboxInputs);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_29->addWidget(label_7);

        horizontalSpacer_37 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_29->addItem(horizontalSpacer_37);


        verticalLayout_13->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(0);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        horizontalSpacer_38 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_38);

        IN7 = new CIODevice(gboxInputs);
        IN7->setObjectName(QString::fromUtf8("IN7"));
        IN7->setMinimumSize(QSize(32, 32));
        IN7->setMaximumSize(QSize(32, 32));
        IN7->setIconSize(QSize(24, 24));

        horizontalLayout_30->addWidget(IN7);

        horizontalSpacer_39 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_39);


        verticalLayout_13->addLayout(horizontalLayout_30);


        horizontalLayout_43->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(0);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalSpacer_40 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_40);

        label_8 = new QLabel(gboxInputs);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_31->addWidget(label_8);

        horizontalSpacer_41 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_31->addItem(horizontalSpacer_41);


        verticalLayout_14->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(0);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        horizontalSpacer_42 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_42);

        IN8 = new CIODevice(gboxInputs);
        IN8->setObjectName(QString::fromUtf8("IN8"));
        IN8->setMinimumSize(QSize(32, 32));
        IN8->setMaximumSize(QSize(32, 32));
        IN8->setIconSize(QSize(24, 24));

        horizontalLayout_32->addWidget(IN8);

        horizontalSpacer_43 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_32->addItem(horizontalSpacer_43);


        verticalLayout_14->addLayout(horizontalLayout_32);


        horizontalLayout_43->addLayout(verticalLayout_14);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(0);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        horizontalSpacer_48 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_48);

        label_10 = new QLabel(gboxInputs);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_35->addWidget(label_10);

        horizontalSpacer_49 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_35->addItem(horizontalSpacer_49);


        verticalLayout_16->addLayout(horizontalLayout_35);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(0);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        horizontalSpacer_50 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_50);

        IN9 = new CIODevice(gboxInputs);
        IN9->setObjectName(QString::fromUtf8("IN9"));
        IN9->setMinimumSize(QSize(32, 32));
        IN9->setMaximumSize(QSize(32, 32));
        IN9->setIconSize(QSize(24, 24));

        horizontalLayout_36->addWidget(IN9);

        horizontalSpacer_51 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_36->addItem(horizontalSpacer_51);


        verticalLayout_16->addLayout(horizontalLayout_36);


        horizontalLayout_43->addLayout(verticalLayout_16);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(0);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        horizontalSpacer_52 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_37->addItem(horizontalSpacer_52);

        label_11 = new QLabel(gboxInputs);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_37->addWidget(label_11);

        horizontalSpacer_53 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_37->addItem(horizontalSpacer_53);


        verticalLayout_17->addLayout(horizontalLayout_37);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(0);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        horizontalSpacer_54 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_54);

        IN10 = new CIODevice(gboxInputs);
        IN10->setObjectName(QString::fromUtf8("IN10"));
        IN10->setMinimumSize(QSize(32, 32));
        IN10->setMaximumSize(QSize(32, 32));
        IN10->setIconSize(QSize(24, 24));

        horizontalLayout_38->addWidget(IN10);

        horizontalSpacer_55 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_55);


        verticalLayout_17->addLayout(horizontalLayout_38);


        horizontalLayout_43->addLayout(verticalLayout_17);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(0);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        horizontalSpacer_56 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_56);

        label_12 = new QLabel(gboxInputs);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_39->addWidget(label_12);

        horizontalSpacer_57 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_39->addItem(horizontalSpacer_57);


        verticalLayout_18->addLayout(horizontalLayout_39);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(0);
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        horizontalSpacer_58 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_40->addItem(horizontalSpacer_58);

        IN11 = new CIODevice(gboxInputs);
        IN11->setObjectName(QString::fromUtf8("IN11"));
        IN11->setMinimumSize(QSize(32, 32));
        IN11->setMaximumSize(QSize(32, 32));
        IN11->setIconSize(QSize(24, 24));

        horizontalLayout_40->addWidget(IN11);

        horizontalSpacer_59 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_40->addItem(horizontalSpacer_59);


        verticalLayout_18->addLayout(horizontalLayout_40);


        horizontalLayout_43->addLayout(verticalLayout_18);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(0);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_19->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(0);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        horizontalSpacer_60 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_60);

        label_13 = new QLabel(gboxInputs);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_41->addWidget(label_13);

        horizontalSpacer_61 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_41->addItem(horizontalSpacer_61);


        verticalLayout_19->addLayout(horizontalLayout_41);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(0);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        horizontalSpacer_62 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_42->addItem(horizontalSpacer_62);

        IN12 = new CIODevice(gboxInputs);
        IN12->setObjectName(QString::fromUtf8("IN12"));
        IN12->setMinimumSize(QSize(32, 32));
        IN12->setMaximumSize(QSize(32, 32));
        IN12->setIconSize(QSize(24, 24));

        horizontalLayout_42->addWidget(IN12);

        horizontalSpacer_63 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_42->addItem(horizontalSpacer_63);


        verticalLayout_19->addLayout(horizontalLayout_42);


        horizontalLayout_43->addLayout(verticalLayout_19);


        horizontalLayout_85->addWidget(gboxInputs);

        horizontalSpacer_96 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_85->addItem(horizontalSpacer_96);


        verticalLayout_32->addLayout(horizontalLayout_85);

        horizontalLayout_70 = new QHBoxLayout();
        horizontalLayout_70->setSpacing(6);
        horizontalLayout_70->setObjectName(QString::fromUtf8("horizontalLayout_70"));
        horizontalSpacer_5 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_70->addItem(horizontalSpacer_5);

        groupBox = new QGroupBox(tabIO);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, 0, 5, -1);
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        verticalLayout_20->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setSpacing(0);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        horizontalSpacer_64 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_64);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_44->addWidget(label_14);

        horizontalSpacer_65 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_44->addItem(horizontalSpacer_65);


        verticalLayout_20->addLayout(horizontalLayout_44);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setSpacing(0);
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        horizontalSpacer_66 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_45->addItem(horizontalSpacer_66);

        OUT1 = new CIODevice(groupBox);
        OUT1->setObjectName(QString::fromUtf8("OUT1"));
        OUT1->setMinimumSize(QSize(32, 32));
        OUT1->setMaximumSize(QSize(32, 32));
        OUT1->setIconSize(QSize(24, 24));
        OUT1->setCheckable(true);

        horizontalLayout_45->addWidget(OUT1);

        horizontalSpacer_67 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_45->addItem(horizontalSpacer_67);


        verticalLayout_20->addLayout(horizontalLayout_45);


        horizontalLayout_4->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        verticalLayout_21->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setSpacing(0);
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        horizontalSpacer_68 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_68);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_46->addWidget(label_15);

        horizontalSpacer_69 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_46->addItem(horizontalSpacer_69);


        verticalLayout_21->addLayout(horizontalLayout_46);

        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setSpacing(0);
        horizontalLayout_47->setObjectName(QString::fromUtf8("horizontalLayout_47"));
        horizontalSpacer_70 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_47->addItem(horizontalSpacer_70);

        OUT2 = new CIODevice(groupBox);
        OUT2->setObjectName(QString::fromUtf8("OUT2"));
        OUT2->setMinimumSize(QSize(32, 32));
        OUT2->setMaximumSize(QSize(32, 32));
        OUT2->setIconSize(QSize(24, 24));
        OUT2->setCheckable(true);

        horizontalLayout_47->addWidget(OUT2);

        horizontalSpacer_71 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_47->addItem(horizontalSpacer_71);


        verticalLayout_21->addLayout(horizontalLayout_47);


        horizontalLayout_4->addLayout(verticalLayout_21);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(0);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        verticalLayout_22->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setSpacing(0);
        horizontalLayout_48->setObjectName(QString::fromUtf8("horizontalLayout_48"));
        horizontalSpacer_72 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_48->addItem(horizontalSpacer_72);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_48->addWidget(label_16);

        horizontalSpacer_73 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_48->addItem(horizontalSpacer_73);


        verticalLayout_22->addLayout(horizontalLayout_48);

        horizontalLayout_49 = new QHBoxLayout();
        horizontalLayout_49->setSpacing(0);
        horizontalLayout_49->setObjectName(QString::fromUtf8("horizontalLayout_49"));
        horizontalSpacer_74 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_49->addItem(horizontalSpacer_74);

        OUT3 = new CIODevice(groupBox);
        OUT3->setObjectName(QString::fromUtf8("OUT3"));
        OUT3->setMinimumSize(QSize(32, 32));
        OUT3->setMaximumSize(QSize(32, 32));
        OUT3->setIconSize(QSize(24, 24));
        OUT3->setCheckable(true);

        horizontalLayout_49->addWidget(OUT3);

        horizontalSpacer_75 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_49->addItem(horizontalSpacer_75);


        verticalLayout_22->addLayout(horizontalLayout_49);


        horizontalLayout_4->addLayout(verticalLayout_22);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(0);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        verticalLayout_23->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setSpacing(0);
        horizontalLayout_50->setObjectName(QString::fromUtf8("horizontalLayout_50"));
        horizontalSpacer_76 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_50->addItem(horizontalSpacer_76);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_50->addWidget(label_17);

        horizontalSpacer_77 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_50->addItem(horizontalSpacer_77);


        verticalLayout_23->addLayout(horizontalLayout_50);

        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setSpacing(0);
        horizontalLayout_51->setObjectName(QString::fromUtf8("horizontalLayout_51"));
        horizontalSpacer_78 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_51->addItem(horizontalSpacer_78);

        OUT4 = new CIODevice(groupBox);
        OUT4->setObjectName(QString::fromUtf8("OUT4"));
        OUT4->setMinimumSize(QSize(32, 32));
        OUT4->setMaximumSize(QSize(32, 32));
        OUT4->setIconSize(QSize(24, 24));
        OUT4->setCheckable(true);

        horizontalLayout_51->addWidget(OUT4);

        horizontalSpacer_79 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_51->addItem(horizontalSpacer_79);


        verticalLayout_23->addLayout(horizontalLayout_51);


        horizontalLayout_4->addLayout(verticalLayout_23);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(0);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        verticalLayout_24->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setSpacing(0);
        horizontalLayout_52->setObjectName(QString::fromUtf8("horizontalLayout_52"));
        horizontalSpacer_80 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_52->addItem(horizontalSpacer_80);

        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_52->addWidget(label_18);

        horizontalSpacer_81 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_52->addItem(horizontalSpacer_81);


        verticalLayout_24->addLayout(horizontalLayout_52);

        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setSpacing(0);
        horizontalLayout_53->setObjectName(QString::fromUtf8("horizontalLayout_53"));
        horizontalSpacer_82 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_53->addItem(horizontalSpacer_82);

        OUT5 = new CIODevice(groupBox);
        OUT5->setObjectName(QString::fromUtf8("OUT5"));
        OUT5->setMinimumSize(QSize(32, 32));
        OUT5->setMaximumSize(QSize(32, 32));
        OUT5->setIconSize(QSize(24, 24));
        OUT5->setCheckable(true);

        horizontalLayout_53->addWidget(OUT5);

        horizontalSpacer_83 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_53->addItem(horizontalSpacer_83);


        verticalLayout_24->addLayout(horizontalLayout_53);


        horizontalLayout_4->addLayout(verticalLayout_24);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setSpacing(0);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        verticalLayout_25->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_54 = new QHBoxLayout();
        horizontalLayout_54->setSpacing(0);
        horizontalLayout_54->setObjectName(QString::fromUtf8("horizontalLayout_54"));
        horizontalSpacer_84 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_54->addItem(horizontalSpacer_84);

        label_19 = new QLabel(groupBox);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_54->addWidget(label_19);

        horizontalSpacer_85 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_54->addItem(horizontalSpacer_85);


        verticalLayout_25->addLayout(horizontalLayout_54);

        horizontalLayout_55 = new QHBoxLayout();
        horizontalLayout_55->setSpacing(0);
        horizontalLayout_55->setObjectName(QString::fromUtf8("horizontalLayout_55"));
        horizontalSpacer_86 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_55->addItem(horizontalSpacer_86);

        OUT6 = new CIODevice(groupBox);
        OUT6->setObjectName(QString::fromUtf8("OUT6"));
        OUT6->setMinimumSize(QSize(32, 32));
        OUT6->setMaximumSize(QSize(32, 32));
        OUT6->setIconSize(QSize(24, 24));
        OUT6->setCheckable(true);

        horizontalLayout_55->addWidget(OUT6);

        horizontalSpacer_87 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_55->addItem(horizontalSpacer_87);


        verticalLayout_25->addLayout(horizontalLayout_55);


        horizontalLayout_4->addLayout(verticalLayout_25);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setSpacing(0);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));
        verticalLayout_26->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_56 = new QHBoxLayout();
        horizontalLayout_56->setSpacing(0);
        horizontalLayout_56->setObjectName(QString::fromUtf8("horizontalLayout_56"));
        horizontalSpacer_88 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_56->addItem(horizontalSpacer_88);

        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_56->addWidget(label_20);

        horizontalSpacer_89 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_56->addItem(horizontalSpacer_89);


        verticalLayout_26->addLayout(horizontalLayout_56);

        horizontalLayout_57 = new QHBoxLayout();
        horizontalLayout_57->setSpacing(0);
        horizontalLayout_57->setObjectName(QString::fromUtf8("horizontalLayout_57"));
        horizontalSpacer_90 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_57->addItem(horizontalSpacer_90);

        OUT7 = new CIODevice(groupBox);
        OUT7->setObjectName(QString::fromUtf8("OUT7"));
        OUT7->setMinimumSize(QSize(32, 32));
        OUT7->setMaximumSize(QSize(32, 32));
        OUT7->setIconSize(QSize(24, 24));
        OUT7->setCheckable(true);

        horizontalLayout_57->addWidget(OUT7);

        horizontalSpacer_91 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_57->addItem(horizontalSpacer_91);


        verticalLayout_26->addLayout(horizontalLayout_57);


        horizontalLayout_4->addLayout(verticalLayout_26);

        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setSpacing(0);
        verticalLayout_27->setObjectName(QString::fromUtf8("verticalLayout_27"));
        verticalLayout_27->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setSpacing(0);
        horizontalLayout_58->setObjectName(QString::fromUtf8("horizontalLayout_58"));
        horizontalSpacer_92 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_58->addItem(horizontalSpacer_92);

        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_58->addWidget(label_21);

        horizontalSpacer_93 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_58->addItem(horizontalSpacer_93);


        verticalLayout_27->addLayout(horizontalLayout_58);

        horizontalLayout_59 = new QHBoxLayout();
        horizontalLayout_59->setSpacing(0);
        horizontalLayout_59->setObjectName(QString::fromUtf8("horizontalLayout_59"));
        horizontalSpacer_94 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_59->addItem(horizontalSpacer_94);

        OUT8 = new CIODevice(groupBox);
        OUT8->setObjectName(QString::fromUtf8("OUT8"));
        OUT8->setMinimumSize(QSize(32, 32));
        OUT8->setMaximumSize(QSize(32, 32));
        OUT8->setIconSize(QSize(24, 24));
        OUT8->setCheckable(true);

        horizontalLayout_59->addWidget(OUT8);

        horizontalSpacer_95 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_59->addItem(horizontalSpacer_95);


        verticalLayout_27->addLayout(horizontalLayout_59);


        horizontalLayout_4->addLayout(verticalLayout_27);

        verticalLayout_28 = new QVBoxLayout();
        verticalLayout_28->setSpacing(0);
        verticalLayout_28->setObjectName(QString::fromUtf8("verticalLayout_28"));
        verticalLayout_28->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_62 = new QHBoxLayout();
        horizontalLayout_62->setSpacing(0);
        horizontalLayout_62->setObjectName(QString::fromUtf8("horizontalLayout_62"));
        horizontalSpacer_98 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_62->addItem(horizontalSpacer_98);

        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_62->addWidget(label_22);

        horizontalSpacer_99 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_62->addItem(horizontalSpacer_99);


        verticalLayout_28->addLayout(horizontalLayout_62);

        horizontalLayout_63 = new QHBoxLayout();
        horizontalLayout_63->setSpacing(0);
        horizontalLayout_63->setObjectName(QString::fromUtf8("horizontalLayout_63"));
        horizontalSpacer_100 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_63->addItem(horizontalSpacer_100);

        OUT9 = new CIODevice(groupBox);
        OUT9->setObjectName(QString::fromUtf8("OUT9"));
        OUT9->setMinimumSize(QSize(32, 32));
        OUT9->setMaximumSize(QSize(32, 32));
        OUT9->setIconSize(QSize(24, 24));
        OUT9->setCheckable(true);

        horizontalLayout_63->addWidget(OUT9);

        horizontalSpacer_101 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_63->addItem(horizontalSpacer_101);


        verticalLayout_28->addLayout(horizontalLayout_63);


        horizontalLayout_4->addLayout(verticalLayout_28);

        verticalLayout_29 = new QVBoxLayout();
        verticalLayout_29->setSpacing(0);
        verticalLayout_29->setObjectName(QString::fromUtf8("verticalLayout_29"));
        verticalLayout_29->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_64 = new QHBoxLayout();
        horizontalLayout_64->setSpacing(0);
        horizontalLayout_64->setObjectName(QString::fromUtf8("horizontalLayout_64"));
        horizontalSpacer_102 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_64->addItem(horizontalSpacer_102);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_64->addWidget(label_23);

        horizontalSpacer_103 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_64->addItem(horizontalSpacer_103);


        verticalLayout_29->addLayout(horizontalLayout_64);

        horizontalLayout_65 = new QHBoxLayout();
        horizontalLayout_65->setSpacing(0);
        horizontalLayout_65->setObjectName(QString::fromUtf8("horizontalLayout_65"));
        horizontalSpacer_104 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_65->addItem(horizontalSpacer_104);

        OUT10 = new CIODevice(groupBox);
        OUT10->setObjectName(QString::fromUtf8("OUT10"));
        OUT10->setMinimumSize(QSize(32, 32));
        OUT10->setMaximumSize(QSize(32, 32));
        OUT10->setIconSize(QSize(24, 24));
        OUT10->setCheckable(true);

        horizontalLayout_65->addWidget(OUT10);

        horizontalSpacer_105 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_65->addItem(horizontalSpacer_105);


        verticalLayout_29->addLayout(horizontalLayout_65);


        horizontalLayout_4->addLayout(verticalLayout_29);

        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setSpacing(0);
        verticalLayout_30->setObjectName(QString::fromUtf8("verticalLayout_30"));
        verticalLayout_30->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_66 = new QHBoxLayout();
        horizontalLayout_66->setSpacing(0);
        horizontalLayout_66->setObjectName(QString::fromUtf8("horizontalLayout_66"));
        horizontalSpacer_106 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_66->addItem(horizontalSpacer_106);

        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_66->addWidget(label_24);

        horizontalSpacer_107 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_66->addItem(horizontalSpacer_107);


        verticalLayout_30->addLayout(horizontalLayout_66);

        horizontalLayout_67 = new QHBoxLayout();
        horizontalLayout_67->setSpacing(0);
        horizontalLayout_67->setObjectName(QString::fromUtf8("horizontalLayout_67"));
        horizontalSpacer_108 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_67->addItem(horizontalSpacer_108);

        OUT11 = new CIODevice(groupBox);
        OUT11->setObjectName(QString::fromUtf8("OUT11"));
        OUT11->setMinimumSize(QSize(32, 32));
        OUT11->setMaximumSize(QSize(32, 32));
        OUT11->setIconSize(QSize(24, 24));
        OUT11->setCheckable(true);

        horizontalLayout_67->addWidget(OUT11);

        horizontalSpacer_109 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_67->addItem(horizontalSpacer_109);


        verticalLayout_30->addLayout(horizontalLayout_67);


        horizontalLayout_4->addLayout(verticalLayout_30);

        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setSpacing(0);
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));
        verticalLayout_31->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_68 = new QHBoxLayout();
        horizontalLayout_68->setSpacing(0);
        horizontalLayout_68->setObjectName(QString::fromUtf8("horizontalLayout_68"));
        horizontalSpacer_110 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_68->addItem(horizontalSpacer_110);

        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_68->addWidget(label_25);

        horizontalSpacer_111 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_68->addItem(horizontalSpacer_111);


        verticalLayout_31->addLayout(horizontalLayout_68);

        horizontalLayout_69 = new QHBoxLayout();
        horizontalLayout_69->setSpacing(0);
        horizontalLayout_69->setObjectName(QString::fromUtf8("horizontalLayout_69"));
        horizontalSpacer_112 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_69->addItem(horizontalSpacer_112);

        OUT12 = new CIODevice(groupBox);
        OUT12->setObjectName(QString::fromUtf8("OUT12"));
        OUT12->setMinimumSize(QSize(32, 32));
        OUT12->setMaximumSize(QSize(32, 32));
        OUT12->setIconSize(QSize(24, 24));
        OUT12->setCheckable(true);

        horizontalLayout_69->addWidget(OUT12);

        horizontalSpacer_113 = new QSpacerItem(5, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_69->addItem(horizontalSpacer_113);


        verticalLayout_31->addLayout(horizontalLayout_69);


        horizontalLayout_4->addLayout(verticalLayout_31);


        horizontalLayout_70->addWidget(groupBox);

        horizontalSpacer_4 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_70->addItem(horizontalSpacer_4);


        verticalLayout_32->addLayout(horizontalLayout_70);

        horizontalLayout_87 = new QHBoxLayout();
        horizontalLayout_87->setSpacing(6);
        horizontalLayout_87->setObjectName(QString::fromUtf8("horizontalLayout_87"));
        horizontalSpacer_147 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_87->addItem(horizontalSpacer_147);

        groupAIN = new QGroupBox(tabIO);
        groupAIN->setObjectName(QString::fromUtf8("groupAIN"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupAIN->sizePolicy().hasHeightForWidth());
        groupAIN->setSizePolicy(sizePolicy7);
        groupAIN->setAlignment(Qt::AlignCenter);
        horizontalLayout_6 = new QHBoxLayout(groupAIN);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(5, 0, 5, -1);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        verticalLayout_40 = new QVBoxLayout();
        verticalLayout_40->setSpacing(6);
        verticalLayout_40->setObjectName(QString::fromUtf8("verticalLayout_40"));
        lblAIN1 = new QLabel(groupAIN);
        lblAIN1->setObjectName(QString::fromUtf8("lblAIN1"));
        lblAIN1->setScaledContents(true);
        lblAIN1->setAlignment(Qt::AlignCenter);

        verticalLayout_40->addWidget(lblAIN1);

        leAIN1 = new QLineEdit(groupAIN);
        leAIN1->setObjectName(QString::fromUtf8("leAIN1"));
        leAIN1->setMinimumSize(QSize(50, 0));
        leAIN1->setMaximumSize(QSize(75, 16777215));
        leAIN1->setMaxLength(10);
        leAIN1->setAlignment(Qt::AlignCenter);
        leAIN1->setReadOnly(true);
        leAIN1->setCursorMoveStyle(Qt::LogicalMoveStyle);

        verticalLayout_40->addWidget(leAIN1);


        horizontalLayout_6->addLayout(verticalLayout_40);

        verticalLayout_41 = new QVBoxLayout();
        verticalLayout_41->setSpacing(6);
        verticalLayout_41->setObjectName(QString::fromUtf8("verticalLayout_41"));
        lblAIN2 = new QLabel(groupAIN);
        lblAIN2->setObjectName(QString::fromUtf8("lblAIN2"));
        lblAIN2->setScaledContents(true);
        lblAIN2->setAlignment(Qt::AlignCenter);

        verticalLayout_41->addWidget(lblAIN2);

        leAIN2 = new QLineEdit(groupAIN);
        leAIN2->setObjectName(QString::fromUtf8("leAIN2"));
        leAIN2->setMaximumSize(QSize(75, 16777215));
        leAIN2->setMaxLength(10);
        leAIN2->setFrame(true);
        leAIN2->setAlignment(Qt::AlignCenter);
        leAIN2->setReadOnly(true);

        verticalLayout_41->addWidget(leAIN2);


        horizontalLayout_6->addLayout(verticalLayout_41);

        verticalLayout_42 = new QVBoxLayout();
        verticalLayout_42->setSpacing(6);
        verticalLayout_42->setObjectName(QString::fromUtf8("verticalLayout_42"));
        lblAIN3 = new QLabel(groupAIN);
        lblAIN3->setObjectName(QString::fromUtf8("lblAIN3"));
        lblAIN3->setScaledContents(true);
        lblAIN3->setAlignment(Qt::AlignCenter);

        verticalLayout_42->addWidget(lblAIN3);

        leAIN3 = new QLineEdit(groupAIN);
        leAIN3->setObjectName(QString::fromUtf8("leAIN3"));
        leAIN3->setMaximumSize(QSize(75, 16777215));
        leAIN3->setMaxLength(10);
        leAIN3->setFrame(true);
        leAIN3->setAlignment(Qt::AlignCenter);
        leAIN3->setReadOnly(true);

        verticalLayout_42->addWidget(leAIN3);


        horizontalLayout_6->addLayout(verticalLayout_42);

        verticalLayout_43 = new QVBoxLayout();
        verticalLayout_43->setSpacing(6);
        verticalLayout_43->setObjectName(QString::fromUtf8("verticalLayout_43"));
        lblAIN4 = new QLabel(groupAIN);
        lblAIN4->setObjectName(QString::fromUtf8("lblAIN4"));
        lblAIN4->setScaledContents(true);
        lblAIN4->setAlignment(Qt::AlignCenter);

        verticalLayout_43->addWidget(lblAIN4);

        leAIN4 = new QLineEdit(groupAIN);
        leAIN4->setObjectName(QString::fromUtf8("leAIN4"));
        leAIN4->setMaximumSize(QSize(75, 16777215));
        leAIN4->setMaxLength(10);
        leAIN4->setFrame(true);
        leAIN4->setAlignment(Qt::AlignCenter);
        leAIN4->setReadOnly(true);

        verticalLayout_43->addWidget(leAIN4);


        horizontalLayout_6->addLayout(verticalLayout_43);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_22);


        horizontalLayout_87->addWidget(groupAIN);

        horizontalSpacer_148 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_87->addItem(horizontalSpacer_148);


        verticalLayout_32->addLayout(horizontalLayout_87);

        twPeriphery->addTab(tabIO, QString());
        tabInfo = new QWidget();
        tabInfo->setObjectName(QString::fromUtf8("tabInfo"));
        horizontalLayout_72 = new QHBoxLayout(tabInfo);
        horizontalLayout_72->setSpacing(6);
        horizontalLayout_72->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_72->setObjectName(QString::fromUtf8("horizontalLayout_72"));
        verticalLayout_39 = new QVBoxLayout();
        verticalLayout_39->setSpacing(6);
        verticalLayout_39->setObjectName(QString::fromUtf8("verticalLayout_39"));
        groupError = new QGroupBox(tabInfo);
        groupError->setObjectName(QString::fromUtf8("groupError"));
        groupError->setAlignment(Qt::AlignCenter);
        horizontalLayout_71 = new QHBoxLayout(groupError);
        horizontalLayout_71->setSpacing(6);
        horizontalLayout_71->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_71->setObjectName(QString::fromUtf8("horizontalLayout_71"));
        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setSpacing(6);
        verticalLayout_36->setObjectName(QString::fromUtf8("verticalLayout_36"));
        label_26 = new QLabel(groupError);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setScaledContents(true);

        verticalLayout_36->addWidget(label_26);

        label_27 = new QLabel(groupError);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setScaledContents(true);

        verticalLayout_36->addWidget(label_27);

        label_28 = new QLabel(groupError);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setScaledContents(true);

        verticalLayout_36->addWidget(label_28);


        horizontalLayout_71->addLayout(verticalLayout_36);

        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setSpacing(6);
        verticalLayout_35->setObjectName(QString::fromUtf8("verticalLayout_35"));
        leErrorAddr = new QLineEdit(groupError);
        leErrorAddr->setObjectName(QString::fromUtf8("leErrorAddr"));
        sizePolicy6.setHeightForWidth(leErrorAddr->sizePolicy().hasHeightForWidth());
        leErrorAddr->setSizePolicy(sizePolicy6);
        leErrorAddr->setMaxLength(5);
        leErrorAddr->setAlignment(Qt::AlignCenter);
        leErrorAddr->setReadOnly(true);

        verticalLayout_35->addWidget(leErrorAddr);

        leErrorCmd = new QLineEdit(groupError);
        leErrorCmd->setObjectName(QString::fromUtf8("leErrorCmd"));
        sizePolicy6.setHeightForWidth(leErrorCmd->sizePolicy().hasHeightForWidth());
        leErrorCmd->setSizePolicy(sizePolicy6);
        leErrorCmd->setMaxLength(5);
        leErrorCmd->setAlignment(Qt::AlignCenter);
        leErrorCmd->setReadOnly(true);

        verticalLayout_35->addWidget(leErrorCmd);

        leErrorChecksum = new QLineEdit(groupError);
        leErrorChecksum->setObjectName(QString::fromUtf8("leErrorChecksum"));
        sizePolicy6.setHeightForWidth(leErrorChecksum->sizePolicy().hasHeightForWidth());
        leErrorChecksum->setSizePolicy(sizePolicy6);
        leErrorChecksum->setMaxLength(5);
        leErrorChecksum->setAlignment(Qt::AlignCenter);
        leErrorChecksum->setReadOnly(true);

        verticalLayout_35->addWidget(leErrorChecksum);


        horizontalLayout_71->addLayout(verticalLayout_35);


        verticalLayout_39->addWidget(groupError);

        groupDeviceInfo = new QGroupBox(tabInfo);
        groupDeviceInfo->setObjectName(QString::fromUtf8("groupDeviceInfo"));
        groupDeviceInfo->setAlignment(Qt::AlignCenter);
        horizontalLayout_73 = new QHBoxLayout(groupDeviceInfo);
        horizontalLayout_73->setSpacing(6);
        horizontalLayout_73->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_73->setObjectName(QString::fromUtf8("horizontalLayout_73"));
        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setSpacing(6);
        verticalLayout_38->setObjectName(QString::fromUtf8("verticalLayout_38"));
        label_29 = new QLabel(groupDeviceInfo);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setScaledContents(true);

        verticalLayout_38->addWidget(label_29);

        label_30 = new QLabel(groupDeviceInfo);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setScaledContents(true);

        verticalLayout_38->addWidget(label_30);

        label_31 = new QLabel(groupDeviceInfo);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setScaledContents(true);

        verticalLayout_38->addWidget(label_31);

        label_32 = new QLabel(groupDeviceInfo);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setScaledContents(true);

        verticalLayout_38->addWidget(label_32);

        label_33 = new QLabel(groupDeviceInfo);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setScaledContents(true);

        verticalLayout_38->addWidget(label_33);


        horizontalLayout_73->addLayout(verticalLayout_38);

        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setSpacing(6);
        verticalLayout_37->setObjectName(QString::fromUtf8("verticalLayout_37"));
        leDeviceID = new QLineEdit(groupDeviceInfo);
        leDeviceID->setObjectName(QString::fromUtf8("leDeviceID"));
        leDeviceID->setEnabled(false);
        leDeviceID->setAlignment(Qt::AlignCenter);
        leDeviceID->setReadOnly(true);

        verticalLayout_37->addWidget(leDeviceID);

        leDeviceNumber = new QLineEdit(groupDeviceInfo);
        leDeviceNumber->setObjectName(QString::fromUtf8("leDeviceNumber"));
        leDeviceNumber->setEnabled(false);
        leDeviceNumber->setAlignment(Qt::AlignCenter);
        leDeviceNumber->setReadOnly(true);

        verticalLayout_37->addWidget(leDeviceNumber);

        leDeviceLotNum = new QLineEdit(groupDeviceInfo);
        leDeviceLotNum->setObjectName(QString::fromUtf8("leDeviceLotNum"));
        leDeviceLotNum->setEnabled(false);
        leDeviceLotNum->setAlignment(Qt::AlignCenter);
        leDeviceLotNum->setReadOnly(true);

        verticalLayout_37->addWidget(leDeviceLotNum);

        leDeviceFirmwareVar = new QLineEdit(groupDeviceInfo);
        leDeviceFirmwareVar->setObjectName(QString::fromUtf8("leDeviceFirmwareVar"));
        leDeviceFirmwareVar->setEnabled(false);
        leDeviceFirmwareVar->setAlignment(Qt::AlignCenter);
        leDeviceFirmwareVar->setReadOnly(true);

        verticalLayout_37->addWidget(leDeviceFirmwareVar);

        leDeviceFirmwareDate = new QLineEdit(groupDeviceInfo);
        leDeviceFirmwareDate->setObjectName(QString::fromUtf8("leDeviceFirmwareDate"));
        leDeviceFirmwareDate->setEnabled(false);
        leDeviceFirmwareDate->setAlignment(Qt::AlignCenter);
        leDeviceFirmwareDate->setReadOnly(true);

        verticalLayout_37->addWidget(leDeviceFirmwareDate);


        horizontalLayout_73->addLayout(verticalLayout_37);


        verticalLayout_39->addWidget(groupDeviceInfo);


        horizontalLayout_72->addLayout(verticalLayout_39);

        horizontalSpacer_12 = new QSpacerItem(370, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_72->addItem(horizontalSpacer_12);

        twPeriphery->addTab(tabInfo, QString());

        verticalLayout_33->addWidget(twPeriphery);

        line->raise();
        twPeriphery->raise();
        lineEditMessageQueue->raise();
        label_9->raise();

        verticalLayout_34->addWidget(groupDevices);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1284, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dwTerminal = new QDockWidget(MainWindow);
        dwTerminal->setObjectName(QString::fromUtf8("dwTerminal"));
        dwTerminal->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_15 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        pteConsole = new QPlainTextEdit(dockWidgetContents_2);
        pteConsole->setObjectName(QString::fromUtf8("pteConsole"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(pteConsole->sizePolicy().hasHeightForWidth());
        pteConsole->setSizePolicy(sizePolicy8);
        pteConsole->setReadOnly(true);

        verticalLayout_15->addWidget(pteConsole);

        dwTerminal->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dwTerminal);

        retranslateUi(MainWindow);

        twPeriphery->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FS9 Emulator", nullptr));
#ifndef QT_NO_TOOLTIP
        MainWindow->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        grboxComPort->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\320\263\320\276 \320\277\320\276\321\200\321\202\320\260", nullptr));
#ifndef QT_NO_TOOLTIP
        pbCtrlPort->setToolTip(QApplication::translate("MainWindow", "CTRL port", nullptr));
#endif // QT_NO_TOOLTIP
        pbCtrlPort->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        lblNameBaudrate->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214", nullptr));
        lblNamePort->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202", nullptr));
#ifndef QT_NO_TOOLTIP
        tbPortRefresh->setToolTip(QApplication::translate("MainWindow", "Refresh", nullptr));
#endif // QT_NO_TOOLTIP
        tbPortRefresh->setText(QString());
#ifndef QT_NO_TOOLTIP
        cbPortNames->setToolTip(QApplication::translate("MainWindow", "List ports", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        cbBaudrate->setToolTip(QApplication::translate("MainWindow", "Baudrate", nullptr));
#endif // QT_NO_TOOLTIP
        cboxTerminal->setText(QApplication::translate("MainWindow", "\320\242\320\265\321\200\320\274\320\270\320\275\320\260\320\273", nullptr));
        cbKeyboard->setText(QApplication::translate("MainWindow", "\320\232\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\320\260", nullptr));
        cbCommand->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
        checkBoxSerialConfig->setText(QApplication::translate("MainWindow", "\320\241\320\265\321\200\320\270\320\271\320\275\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        groupDevices->setTitle(QApplication::translate("MainWindow", "\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
#ifndef QT_NO_TOOLTIP
        cbCmdList->setToolTip(QApplication::translate("MainWindow", "Command list", nullptr));
#endif // QT_NO_TOOLTIP
        lblCommand->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", nullptr));
        lblDeviceAddress->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
#ifndef QT_NO_TOOLTIP
        sbDeviceAddress->setToolTip(QApplication::translate("MainWindow", "Device address", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pbCmdSend->setToolTip(QApplication::translate("MainWindow", "Command send", nullptr));
#endif // QT_NO_TOOLTIP
        pbCmdSend->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        lblCmdDescription->setText(QString());
        gboxAutorepeat->setTitle(QApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\320\277\320\276\320\262\321\202\320\276\321\200", nullptr));
        cboxRepeatInputs->setText(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\321\213", nullptr));
        cboxRepeatAIN->setText(QApplication::translate("MainWindow", "AIN", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "DSDIN", nullptr));
        lblStateDSIDIN->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
        lblTimeDSDIN->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217", nullptr));
        gboxInputSettings->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\262\321\205\320\276\320\264\320\276\320\262", nullptr));
        gboxInputSettingsFilter->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\211\320\270\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\204\320\270\320\273\321\214\321\202\321\200\320\260", nullptr));
        lblPeriods->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\265\321\200\320\270\320\276\320\264\320\276\320\262", nullptr));
        lblDiscret->setText(QApplication::translate("MainWindow", "\320\224\320\270\321\201\320\272\321\200\320\265\321\202\320\275\320\276\321\201\321\202\321\214", nullptr));
        lblSignal->setText(QApplication::translate("MainWindow", "\320\241\320\270\320\263\320\275\320\260\320\273", nullptr));
        gboxInput->setTitle(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
        radioButtonInputSingle->setText(QApplication::translate("MainWindow", "\320\236\320\264\320\270\320\275\320\276\321\207\320\275\321\213\320\271", nullptr));
        radioButtonInputGroup->setText(QApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
        pushButtonInputSet->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\265\321\200\320\265\320\264\321\214 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271", nullptr));
        gboxInputs->setTitle(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\321\213", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 1", nullptr));
        IN1->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 2", nullptr));
        IN2->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 3", nullptr));
        IN3->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 4", nullptr));
        IN4->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 5", nullptr));
        IN5->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 6", nullptr));
        IN6->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 7", nullptr));
        IN7->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 8", nullptr));
        IN8->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 9", nullptr));
        IN9->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 10", nullptr));
        IN10->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 11", nullptr));
        IN11->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 12", nullptr));
        IN12->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264\321\213", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 1", nullptr));
        OUT1->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 2", nullptr));
        OUT2->setText(QString());
        label_16->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 3", nullptr));
        OUT3->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 4", nullptr));
        OUT4->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 5", nullptr));
        OUT5->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 6", nullptr));
        OUT6->setText(QString());
        label_20->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 7", nullptr));
        OUT7->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 8", nullptr));
        OUT8->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 9", nullptr));
        OUT9->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 10", nullptr));
        OUT10->setText(QString());
        label_24->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 11", nullptr));
        OUT11->setText(QString());
        label_25->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\260\320\273 12", nullptr));
        OUT12->setText(QString());
        groupAIN->setTitle(QApplication::translate("MainWindow", "AIN", nullptr));
        lblAIN1->setText(QApplication::translate("MainWindow", "AIN1", nullptr));
        lblAIN2->setText(QApplication::translate("MainWindow", "AIN2", nullptr));
        lblAIN3->setText(QApplication::translate("MainWindow", "AIN3", nullptr));
        lblAIN4->setText(QApplication::translate("MainWindow", "AIN4", nullptr));
        twPeriphery->setTabText(twPeriphery->indexOf(tabIO), QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\321\213/\320\262\321\213\321\205\320\276\320\264\321\213", nullptr));
        groupError->setTitle(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\270", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\260 \320\260\320\264\321\200\320\265\321\201\320\260\321\206\320\270\320\270:", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\260 \320\272\320\276\320\274\320\260\320\275\320\264\321\213:", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "\320\236\321\210\320\270\320\261\320\272\320\260 \320\272\320\276\320\275\321\202\321\200\320\276\320\273\321\214\320\275\320\276\320\271 \321\201\321\203\320\274\320\274\321\213:", nullptr));
        groupDeviceInfo->setTitle(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "ID \320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\217\320\264\320\272\320\276\320\262\321\213\320\271 \320\275\320\276\320\274\320\265\321\200", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\262 \320\277\320\260\321\200\321\202\320\270\320\270", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\200\320\270\320\260\320\275\321\202 \320\277\321\200\320\276\321\210\320\270\320\262\320\272\320\270", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\276\321\210\320\270\320\262\320\272\320\270", nullptr));
        twPeriphery->setTabText(twPeriphery->indexOf(tabInfo), QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        dwTerminal->setWindowTitle(QApplication::translate("MainWindow", "\320\242\320\265\321\200\320\274\320\270\320\275\320\260\320\273", nullptr));
#ifndef QT_NO_TOOLTIP
        pteConsole->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>\320\242\320\265\321\200\320\274\320\270\320\275\320\260\320\273</p><p>\320\236\321\207\320\270\321\201\321\202\320\272\320\260 ALT+C</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
