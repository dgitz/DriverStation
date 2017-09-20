/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDial>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *bClose;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *CalibrationSubTab;
    QWidget *tabCalibrationJoystick;
    QGroupBox *groupCalibrate;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_3;
    QLabel *lCalibrateOption;
    QLabel *lCalibrateStep;
    QCheckBox *chbCalibrateInvert;
    QDial *dCalibrateMin;
    QLabel *lCalibrateMin;
    QDial *dCalibrateNeutral;
    QPushButton *bCalibrateCancel;
    QPushButton *bCalibrateSave;
    QLabel *lCalibrateNeutral;
    QDial *dCalibrateDeadband;
    QLabel *lCalibrateDeadband;
    QDial *dCalibrateMax;
    QLabel *lCalibrateMax;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_7;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *bYAxisCal;
    QPushButton *bYAxisCalView;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *bZAxisCal;
    QPushButton *bZAxisCalView;
    QSlider *YAxis;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lXAxisValue;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lYAxisValue;
    QLabel *label_5;
    QSlider *ZAxis;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *bXAxisCal;
    QPushButton *bXAxisCalView;
    QSlider *XAxis;
    QHBoxLayout *horizontalLayout_11;
    QLabel *lZAxisValue;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *bJoyButton4;
    QPushButton *bJoyButton2;
    QPushButton *bJoyButton1;
    QPushButton *bJoyButton3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *bJoyPOVUp;
    QPushButton *bJoyPOVLeft;
    QPushButton *bJoyPOVDown;
    QPushButton *bJoyPOVRight;
    QWidget *tabCalibrationTuning;
    QComboBox *cbControlGroup;
    QPushButton *bControlGroupRead;
    QPushButton *bTuningPSmaller;
    QPushButton *bTuningPBigger;
    QPushButton *bTuningPReset;
    QFrame *line_3;
    QFrame *line_4;
    QLabel *lTuningPValue;
    QLabel *label_2;
    QPushButton *bControlGroupSave;
    QLabel *lTuningIValue;
    QPushButton *bTuningIReset;
    QDial *dTuningI;
    QLabel *label_3;
    QPushButton *bTuningISmaller;
    QPushButton *bTuningIBigger;
    QLabel *lTuningDValue;
    QPushButton *bTuningDReset;
    QDial *dTuningD;
    QLabel *label_4;
    QPushButton *bTuningDSmaller;
    QPushButton *bTuningDBigger;
    QDial *dTuningP;
    QSlider *hsTuningMaxValue;
    QSlider *hsTuningMinValue;
    QSlider *hsTuningDefaultValue;
    QLabel *label;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *lTuningMaxValue;
    QLabel *lTuningMinValue;
    QLabel *lTuningDefaultValue;
    QWidget *tab_2;
    QTextBrowser *tInfo;
    QPushButton *tEStopState;
    QLabel *iRoverSignal;
    QLabel *iRoverActive;
    QLabel *iROSSignal;
    QLabel *iRouterSignal;
    QLabel *iRouterActive;
    QLabel *iROSServerActive;
    QPushButton *bArmDisarm;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1251, 792);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bClose = new QPushButton(centralWidget);
        bClose->setObjectName(QString::fromUtf8("bClose"));
        bClose->setGeometry(QRect(730, 600, 151, 81));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 861, 581));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        CalibrationSubTab = new QTabWidget(tab);
        CalibrationSubTab->setObjectName(QString::fromUtf8("CalibrationSubTab"));
        CalibrationSubTab->setGeometry(QRect(0, 0, 851, 541));
        tabCalibrationJoystick = new QWidget();
        tabCalibrationJoystick->setObjectName(QString::fromUtf8("tabCalibrationJoystick"));
        groupCalibrate = new QGroupBox(tabCalibrationJoystick);
        groupCalibrate->setObjectName(QString::fromUtf8("groupCalibrate"));
        groupCalibrate->setEnabled(true);
        groupCalibrate->setGeometry(QRect(620, 0, 211, 571));
        groupCalibrate->setAutoFillBackground(false);
        formLayoutWidget = new QWidget(groupCalibrate);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 20, 201, 541));
        formLayout_3 = new QFormLayout(formLayoutWidget);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setLabelAlignment(Qt::AlignCenter);
        formLayout_3->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        lCalibrateOption = new QLabel(formLayoutWidget);
        lCalibrateOption->setObjectName(QString::fromUtf8("lCalibrateOption"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, lCalibrateOption);

        lCalibrateStep = new QLabel(formLayoutWidget);
        lCalibrateStep->setObjectName(QString::fromUtf8("lCalibrateStep"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lCalibrateStep);

        chbCalibrateInvert = new QCheckBox(formLayoutWidget);
        chbCalibrateInvert->setObjectName(QString::fromUtf8("chbCalibrateInvert"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, chbCalibrateInvert);

        dCalibrateMin = new QDial(formLayoutWidget);
        dCalibrateMin->setObjectName(QString::fromUtf8("dCalibrateMin"));
        dCalibrateMin->setMinimum(-32768);
        dCalibrateMin->setMaximum(0);
        dCalibrateMin->setValue(-32768);
        dCalibrateMin->setSliderPosition(-32768);
        dCalibrateMin->setOrientation(Qt::Horizontal);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, dCalibrateMin);

        lCalibrateMin = new QLabel(formLayoutWidget);
        lCalibrateMin->setObjectName(QString::fromUtf8("lCalibrateMin"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, lCalibrateMin);

        dCalibrateNeutral = new QDial(formLayoutWidget);
        dCalibrateNeutral->setObjectName(QString::fromUtf8("dCalibrateNeutral"));
        dCalibrateNeutral->setMinimum(-32768);
        dCalibrateNeutral->setMaximum(32768);
        dCalibrateNeutral->setValue(32768);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, dCalibrateNeutral);

        bCalibrateCancel = new QPushButton(formLayoutWidget);
        bCalibrateCancel->setObjectName(QString::fromUtf8("bCalibrateCancel"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, bCalibrateCancel);

        bCalibrateSave = new QPushButton(formLayoutWidget);
        bCalibrateSave->setObjectName(QString::fromUtf8("bCalibrateSave"));

        formLayout_3->setWidget(8, QFormLayout::FieldRole, bCalibrateSave);

        lCalibrateNeutral = new QLabel(formLayoutWidget);
        lCalibrateNeutral->setObjectName(QString::fromUtf8("lCalibrateNeutral"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, lCalibrateNeutral);

        dCalibrateDeadband = new QDial(formLayoutWidget);
        dCalibrateDeadband->setObjectName(QString::fromUtf8("dCalibrateDeadband"));
        dCalibrateDeadband->setMaximum(25);

        formLayout_3->setWidget(7, QFormLayout::LabelRole, dCalibrateDeadband);

        lCalibrateDeadband = new QLabel(formLayoutWidget);
        lCalibrateDeadband->setObjectName(QString::fromUtf8("lCalibrateDeadband"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, lCalibrateDeadband);

        dCalibrateMax = new QDial(formLayoutWidget);
        dCalibrateMax->setObjectName(QString::fromUtf8("dCalibrateMax"));
        dCalibrateMax->setMinimum(0);
        dCalibrateMax->setMaximum(32768);
        dCalibrateMax->setValue(32768);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, dCalibrateMax);

        lCalibrateMax = new QLabel(formLayoutWidget);
        lCalibrateMax->setObjectName(QString::fromUtf8("lCalibrateMax"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lCalibrateMax);

        gridLayoutWidget_4 = new QWidget(tabCalibrationJoystick);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(0, 0, 594, 211));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setHorizontalSpacing(6);
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(gridLayoutWidget_4);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line, 3, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        bYAxisCal = new QPushButton(gridLayoutWidget_4);
        bYAxisCal->setObjectName(QString::fromUtf8("bYAxisCal"));

        horizontalLayout_4->addWidget(bYAxisCal);

        bYAxisCalView = new QPushButton(gridLayoutWidget_4);
        bYAxisCalView->setObjectName(QString::fromUtf8("bYAxisCalView"));

        horizontalLayout_4->addWidget(bYAxisCalView);


        gridLayout_7->addLayout(horizontalLayout_4, 1, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        bZAxisCal = new QPushButton(gridLayoutWidget_4);
        bZAxisCal->setObjectName(QString::fromUtf8("bZAxisCal"));

        horizontalLayout_8->addWidget(bZAxisCal);

        bZAxisCalView = new QPushButton(gridLayoutWidget_4);
        bZAxisCalView->setObjectName(QString::fromUtf8("bZAxisCalView"));

        horizontalLayout_8->addWidget(bZAxisCalView);


        gridLayout_7->addLayout(horizontalLayout_8, 1, 4, 1, 1);

        YAxis = new QSlider(gridLayoutWidget_4);
        YAxis->setObjectName(QString::fromUtf8("YAxis"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(YAxis->sizePolicy().hasHeightForWidth());
        YAxis->setSizePolicy(sizePolicy);
        YAxis->setMinimum(-32767);
        YAxis->setMaximum(32767);
        YAxis->setSingleStep(10);
        YAxis->setOrientation(Qt::Vertical);

        gridLayout_7->addWidget(YAxis, 3, 2, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        lXAxisValue = new QLabel(gridLayoutWidget_4);
        lXAxisValue->setObjectName(QString::fromUtf8("lXAxisValue"));

        horizontalLayout_9->addWidget(lXAxisValue);


        gridLayout_7->addLayout(horizontalLayout_9, 4, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lYAxisValue = new QLabel(gridLayoutWidget_4);
        lYAxisValue->setObjectName(QString::fromUtf8("lYAxisValue"));

        horizontalLayout_10->addWidget(lYAxisValue);


        gridLayout_7->addLayout(horizontalLayout_10, 4, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_5, 0, 0, 1, 1);

        ZAxis = new QSlider(gridLayoutWidget_4);
        ZAxis->setObjectName(QString::fromUtf8("ZAxis"));
        sizePolicy.setHeightForWidth(ZAxis->sizePolicy().hasHeightForWidth());
        ZAxis->setSizePolicy(sizePolicy);
        ZAxis->setMinimum(-32767);
        ZAxis->setMaximum(32767);
        ZAxis->setOrientation(Qt::Vertical);

        gridLayout_7->addWidget(ZAxis, 3, 4, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        bXAxisCal = new QPushButton(gridLayoutWidget_4);
        bXAxisCal->setObjectName(QString::fromUtf8("bXAxisCal"));

        horizontalLayout_7->addWidget(bXAxisCal);

        bXAxisCalView = new QPushButton(gridLayoutWidget_4);
        bXAxisCalView->setObjectName(QString::fromUtf8("bXAxisCalView"));

        horizontalLayout_7->addWidget(bXAxisCalView);


        gridLayout_7->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        XAxis = new QSlider(gridLayoutWidget_4);
        XAxis->setObjectName(QString::fromUtf8("XAxis"));
        sizePolicy.setHeightForWidth(XAxis->sizePolicy().hasHeightForWidth());
        XAxis->setSizePolicy(sizePolicy);
        XAxis->setLayoutDirection(Qt::LeftToRight);
        XAxis->setMinimum(-32767);
        XAxis->setMaximum(32767);
        XAxis->setSingleStep(10);
        XAxis->setSliderPosition(0);
        XAxis->setOrientation(Qt::Vertical);

        gridLayout_7->addWidget(XAxis, 3, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        lZAxisValue = new QLabel(gridLayoutWidget_4);
        lZAxisValue->setObjectName(QString::fromUtf8("lZAxisValue"));

        horizontalLayout_11->addWidget(lZAxisValue);


        gridLayout_7->addLayout(horizontalLayout_11, 4, 4, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_6, 0, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_7, 0, 4, 1, 1);

        line_2 = new QFrame(gridLayoutWidget_4);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_2, 3, 3, 1, 1);

        gridLayoutWidget = new QWidget(tabCalibrationJoystick);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 300, 271, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bJoyButton4 = new QPushButton(gridLayoutWidget);
        bJoyButton4->setObjectName(QString::fromUtf8("bJoyButton4"));

        gridLayout->addWidget(bJoyButton4, 1, 1, 1, 1);

        bJoyButton2 = new QPushButton(gridLayoutWidget);
        bJoyButton2->setObjectName(QString::fromUtf8("bJoyButton2"));

        gridLayout->addWidget(bJoyButton2, 0, 1, 1, 1);

        bJoyButton1 = new QPushButton(gridLayoutWidget);
        bJoyButton1->setObjectName(QString::fromUtf8("bJoyButton1"));

        gridLayout->addWidget(bJoyButton1, 0, 0, 1, 1);

        bJoyButton3 = new QPushButton(gridLayoutWidget);
        bJoyButton3->setObjectName(QString::fromUtf8("bJoyButton3"));

        gridLayout->addWidget(bJoyButton3, 1, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(tabCalibrationJoystick);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(320, 280, 254, 181));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 2, 0, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_10, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 0, 2, 1, 1);

        bJoyPOVUp = new QPushButton(gridLayoutWidget_2);
        bJoyPOVUp->setObjectName(QString::fromUtf8("bJoyPOVUp"));

        gridLayout_4->addWidget(bJoyPOVUp, 0, 1, 1, 1);

        bJoyPOVLeft = new QPushButton(gridLayoutWidget_2);
        bJoyPOVLeft->setObjectName(QString::fromUtf8("bJoyPOVLeft"));

        gridLayout_4->addWidget(bJoyPOVLeft, 1, 0, 1, 1);

        bJoyPOVDown = new QPushButton(gridLayoutWidget_2);
        bJoyPOVDown->setObjectName(QString::fromUtf8("bJoyPOVDown"));

        gridLayout_4->addWidget(bJoyPOVDown, 2, 1, 1, 1);

        bJoyPOVRight = new QPushButton(gridLayoutWidget_2);
        bJoyPOVRight->setObjectName(QString::fromUtf8("bJoyPOVRight"));

        gridLayout_4->addWidget(bJoyPOVRight, 1, 2, 1, 1);

        CalibrationSubTab->addTab(tabCalibrationJoystick, QString());
        tabCalibrationTuning = new QWidget();
        tabCalibrationTuning->setObjectName(QString::fromUtf8("tabCalibrationTuning"));
        cbControlGroup = new QComboBox(tabCalibrationTuning);
        cbControlGroup->setObjectName(QString::fromUtf8("cbControlGroup"));
        cbControlGroup->setGeometry(QRect(90, 20, 231, 23));
        bControlGroupRead = new QPushButton(tabCalibrationTuning);
        bControlGroupRead->setObjectName(QString::fromUtf8("bControlGroupRead"));
        bControlGroupRead->setGeometry(QRect(10, 20, 80, 23));
        bTuningPSmaller = new QPushButton(tabCalibrationTuning);
        bTuningPSmaller->setObjectName(QString::fromUtf8("bTuningPSmaller"));
        bTuningPSmaller->setGeometry(QRect(10, 430, 51, 23));
        bTuningPBigger = new QPushButton(tabCalibrationTuning);
        bTuningPBigger->setObjectName(QString::fromUtf8("bTuningPBigger"));
        bTuningPBigger->setGeometry(QRect(200, 430, 51, 23));
        bTuningPReset = new QPushButton(tabCalibrationTuning);
        bTuningPReset->setObjectName(QString::fromUtf8("bTuningPReset"));
        bTuningPReset->setGeometry(QRect(90, 190, 80, 23));
        line_3 = new QFrame(tabCalibrationTuning);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(250, 60, 21, 521));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(tabCalibrationTuning);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(520, 110, 21, 471));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        lTuningPValue = new QLabel(tabCalibrationTuning);
        lTuningPValue->setObjectName(QString::fromUtf8("lTuningPValue"));
        lTuningPValue->setGeometry(QRect(18, 470, 221, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("FreeMono"));
        font.setPointSize(12);
        lTuningPValue->setFont(font);
        lTuningPValue->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(tabCalibrationTuning);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(8, 150, 241, 20));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_2->setAutoFillBackground(false);
        label_2->setAlignment(Qt::AlignCenter);
        bControlGroupSave = new QPushButton(tabCalibrationTuning);
        bControlGroupSave->setObjectName(QString::fromUtf8("bControlGroupSave"));
        bControlGroupSave->setGeometry(QRect(320, 20, 80, 23));
        lTuningIValue = new QLabel(tabCalibrationTuning);
        lTuningIValue->setObjectName(QString::fromUtf8("lTuningIValue"));
        lTuningIValue->setGeometry(QRect(290, 470, 221, 15));
        lTuningIValue->setFont(font);
        lTuningIValue->setAlignment(Qt::AlignCenter);
        bTuningIReset = new QPushButton(tabCalibrationTuning);
        bTuningIReset->setObjectName(QString::fromUtf8("bTuningIReset"));
        bTuningIReset->setGeometry(QRect(350, 190, 80, 23));
        dTuningI = new QDial(tabCalibrationTuning);
        dTuningI->setObjectName(QString::fromUtf8("dTuningI"));
        dTuningI->setGeometry(QRect(260, 160, 261, 341));
        dTuningI->setMinimum(-1000);
        dTuningI->setMaximum(1000);
        label_3 = new QLabel(tabCalibrationTuning);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(268, 150, 241, 20));
        label_3->setFont(font1);
        label_3->setAutoFillBackground(false);
        label_3->setAlignment(Qt::AlignCenter);
        bTuningISmaller = new QPushButton(tabCalibrationTuning);
        bTuningISmaller->setObjectName(QString::fromUtf8("bTuningISmaller"));
        bTuningISmaller->setGeometry(QRect(270, 430, 51, 23));
        bTuningIBigger = new QPushButton(tabCalibrationTuning);
        bTuningIBigger->setObjectName(QString::fromUtf8("bTuningIBigger"));
        bTuningIBigger->setGeometry(QRect(460, 430, 51, 23));
        lTuningDValue = new QLabel(tabCalibrationTuning);
        lTuningDValue->setObjectName(QString::fromUtf8("lTuningDValue"));
        lTuningDValue->setGeometry(QRect(570, 470, 221, 15));
        lTuningDValue->setFont(font);
        lTuningDValue->setAlignment(Qt::AlignCenter);
        bTuningDReset = new QPushButton(tabCalibrationTuning);
        bTuningDReset->setObjectName(QString::fromUtf8("bTuningDReset"));
        bTuningDReset->setGeometry(QRect(630, 190, 80, 23));
        dTuningD = new QDial(tabCalibrationTuning);
        dTuningD->setObjectName(QString::fromUtf8("dTuningD"));
        dTuningD->setGeometry(QRect(540, 160, 261, 341));
        dTuningD->setMinimum(-1000);
        dTuningD->setMaximum(1000);
        label_4 = new QLabel(tabCalibrationTuning);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(548, 150, 241, 20));
        label_4->setFont(font1);
        label_4->setAutoFillBackground(false);
        label_4->setAlignment(Qt::AlignCenter);
        bTuningDSmaller = new QPushButton(tabCalibrationTuning);
        bTuningDSmaller->setObjectName(QString::fromUtf8("bTuningDSmaller"));
        bTuningDSmaller->setGeometry(QRect(550, 430, 51, 23));
        bTuningDBigger = new QPushButton(tabCalibrationTuning);
        bTuningDBigger->setObjectName(QString::fromUtf8("bTuningDBigger"));
        bTuningDBigger->setGeometry(QRect(740, 430, 51, 23));
        dTuningP = new QDial(tabCalibrationTuning);
        dTuningP->setObjectName(QString::fromUtf8("dTuningP"));
        dTuningP->setGeometry(QRect(0, 160, 261, 341));
        dTuningP->setMinimum(-1000);
        dTuningP->setMaximum(1000);
        dTuningP->setInvertedAppearance(false);
        hsTuningMaxValue = new QSlider(tabCalibrationTuning);
        hsTuningMaxValue->setObjectName(QString::fromUtf8("hsTuningMaxValue"));
        hsTuningMaxValue->setGeometry(QRect(460, 20, 291, 16));
        hsTuningMaxValue->setMinimum(1000);
        hsTuningMaxValue->setMaximum(2000);
        hsTuningMaxValue->setSliderPosition(1500);
        hsTuningMaxValue->setTracking(true);
        hsTuningMaxValue->setOrientation(Qt::Horizontal);
        hsTuningMaxValue->setInvertedAppearance(false);
        hsTuningMaxValue->setInvertedControls(false);
        hsTuningMaxValue->setTickPosition(QSlider::NoTicks);
        hsTuningMinValue = new QSlider(tabCalibrationTuning);
        hsTuningMinValue->setObjectName(QString::fromUtf8("hsTuningMinValue"));
        hsTuningMinValue->setGeometry(QRect(460, 50, 291, 16));
        hsTuningMinValue->setMinimum(1000);
        hsTuningMinValue->setMaximum(2000);
        hsTuningMinValue->setSliderPosition(1500);
        hsTuningMinValue->setTracking(true);
        hsTuningMinValue->setOrientation(Qt::Horizontal);
        hsTuningMinValue->setInvertedAppearance(false);
        hsTuningMinValue->setInvertedControls(false);
        hsTuningMinValue->setTickPosition(QSlider::NoTicks);
        hsTuningDefaultValue = new QSlider(tabCalibrationTuning);
        hsTuningDefaultValue->setObjectName(QString::fromUtf8("hsTuningDefaultValue"));
        hsTuningDefaultValue->setGeometry(QRect(460, 80, 291, 16));
        hsTuningDefaultValue->setMinimum(1000);
        hsTuningDefaultValue->setMaximum(2000);
        hsTuningDefaultValue->setSliderPosition(1500);
        hsTuningDefaultValue->setTracking(true);
        hsTuningDefaultValue->setOrientation(Qt::Horizontal);
        hsTuningDefaultValue->setInvertedAppearance(false);
        hsTuningDefaultValue->setInvertedControls(false);
        hsTuningDefaultValue->setTickPosition(QSlider::NoTicks);
        label = new QLabel(tabCalibrationTuning);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(420, 20, 31, 16));
        label_12 = new QLabel(tabCalibrationTuning);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(420, 50, 31, 16));
        label_13 = new QLabel(tabCalibrationTuning);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(400, 80, 51, 16));
        lTuningMaxValue = new QLabel(tabCalibrationTuning);
        lTuningMaxValue->setObjectName(QString::fromUtf8("lTuningMaxValue"));
        lTuningMaxValue->setGeometry(QRect(760, 20, 59, 15));
        lTuningMinValue = new QLabel(tabCalibrationTuning);
        lTuningMinValue->setObjectName(QString::fromUtf8("lTuningMinValue"));
        lTuningMinValue->setGeometry(QRect(760, 50, 59, 15));
        lTuningDefaultValue = new QLabel(tabCalibrationTuning);
        lTuningDefaultValue->setObjectName(QString::fromUtf8("lTuningDefaultValue"));
        lTuningDefaultValue->setGeometry(QRect(760, 80, 59, 15));
        CalibrationSubTab->addTab(tabCalibrationTuning, QString());
        dTuningP->raise();
        dTuningD->raise();
        dTuningI->raise();
        cbControlGroup->raise();
        bControlGroupRead->raise();
        bTuningPSmaller->raise();
        bTuningPBigger->raise();
        bTuningPReset->raise();
        line_3->raise();
        line_4->raise();
        lTuningPValue->raise();
        label_2->raise();
        bControlGroupSave->raise();
        lTuningIValue->raise();
        bTuningIReset->raise();
        label_3->raise();
        bTuningISmaller->raise();
        bTuningIBigger->raise();
        lTuningDValue->raise();
        bTuningDReset->raise();
        label_4->raise();
        bTuningDSmaller->raise();
        bTuningDBigger->raise();
        hsTuningMaxValue->raise();
        hsTuningMinValue->raise();
        hsTuningDefaultValue->raise();
        label->raise();
        label_12->raise();
        label_13->raise();
        lTuningMaxValue->raise();
        lTuningMinValue->raise();
        lTuningDefaultValue->raise();
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tInfo = new QTextBrowser(tab_2);
        tInfo->setObjectName(QString::fromUtf8("tInfo"));
        tInfo->setGeometry(QRect(60, 140, 371, 311));
        tabWidget->addTab(tab_2, QString());
        tEStopState = new QPushButton(centralWidget);
        tEStopState->setObjectName(QString::fromUtf8("tEStopState"));
        tEStopState->setGeometry(QRect(20, 600, 701, 81));
        QFont font2;
        font2.setPointSize(16);
        font2.setItalic(true);
        tEStopState->setFont(font2);
        tEStopState->setAutoFillBackground(false);
        tEStopState->setStyleSheet(QString::fromUtf8(""));
        iRoverSignal = new QLabel(centralWidget);
        iRoverSignal->setObjectName(QString::fromUtf8("iRoverSignal"));
        iRoverSignal->setGeometry(QRect(1060, 440, 175, 155));
        QPalette palette;
        QBrush brush(QColor(239, 235, 231, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        iRoverSignal->setPalette(palette);
        iRoverSignal->setAutoFillBackground(true);
        iRoverActive = new QLabel(centralWidget);
        iRoverActive->setObjectName(QString::fromUtf8("iRoverActive"));
        iRoverActive->setGeometry(QRect(900, 440, 155, 155));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        iRoverActive->setPalette(palette1);
        iRoverActive->setAutoFillBackground(true);
        iROSSignal = new QLabel(centralWidget);
        iROSSignal->setObjectName(QString::fromUtf8("iROSSignal"));
        iROSSignal->setGeometry(QRect(1060, 280, 175, 155));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        iROSSignal->setPalette(palette2);
        iROSSignal->setAutoFillBackground(true);
        iRouterSignal = new QLabel(centralWidget);
        iRouterSignal->setObjectName(QString::fromUtf8("iRouterSignal"));
        iRouterSignal->setGeometry(QRect(1060, 120, 175, 155));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        iRouterSignal->setPalette(palette3);
        iRouterSignal->setAutoFillBackground(true);
        iRouterActive = new QLabel(centralWidget);
        iRouterActive->setObjectName(QString::fromUtf8("iRouterActive"));
        iRouterActive->setGeometry(QRect(900, 120, 155, 155));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        iRouterActive->setPalette(palette4);
        iRouterActive->setAutoFillBackground(true);
        iROSServerActive = new QLabel(centralWidget);
        iROSServerActive->setObjectName(QString::fromUtf8("iROSServerActive"));
        iROSServerActive->setGeometry(QRect(900, 280, 155, 155));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        iROSServerActive->setPalette(palette5);
        iROSServerActive->setAutoFillBackground(true);
        bArmDisarm = new QPushButton(centralWidget);
        bArmDisarm->setObjectName(QString::fromUtf8("bArmDisarm"));
        bArmDisarm->setGeometry(QRect(920, 40, 281, 61));
        bArmDisarm->setFont(font2);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        CalibrationSubTab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        bClose->setText(QApplication::translate("MainWindow", "CLOSE", 0, QApplication::UnicodeUTF8));
        groupCalibrate->setTitle(QString());
        lCalibrateOption->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        lCalibrateStep->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        chbCalibrateInvert->setText(QApplication::translate("MainWindow", "Invert", 0, QApplication::UnicodeUTF8));
        lCalibrateMin->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        bCalibrateCancel->setText(QApplication::translate("MainWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        bCalibrateSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        lCalibrateNeutral->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        lCalibrateDeadband->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        lCalibrateMax->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        bYAxisCal->setText(QApplication::translate("MainWindow", "Calibrate", 0, QApplication::UnicodeUTF8));
        bYAxisCalView->setText(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        bZAxisCal->setText(QApplication::translate("MainWindow", "Calibrate", 0, QApplication::UnicodeUTF8));
        bZAxisCalView->setText(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        lXAxisValue->setText(QApplication::translate("MainWindow", "X:", 0, QApplication::UnicodeUTF8));
        lYAxisValue->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "X-Axis", 0, QApplication::UnicodeUTF8));
        bXAxisCal->setText(QApplication::translate("MainWindow", "Calibrate", 0, QApplication::UnicodeUTF8));
        bXAxisCalView->setText(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        lZAxisValue->setText(QApplication::translate("MainWindow", "Z:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Y-Axis", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Z-Axis", 0, QApplication::UnicodeUTF8));
        bJoyButton4->setText(QApplication::translate("MainWindow", "Joy B4", 0, QApplication::UnicodeUTF8));
        bJoyButton2->setText(QApplication::translate("MainWindow", "Joy B2", 0, QApplication::UnicodeUTF8));
        bJoyButton1->setText(QApplication::translate("MainWindow", "Joy B1", 0, QApplication::UnicodeUTF8));
        bJoyButton3->setText(QApplication::translate("MainWindow", "Joy B3", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "POV", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        bJoyPOVUp->setText(QApplication::translate("MainWindow", "UP", 0, QApplication::UnicodeUTF8));
        bJoyPOVLeft->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        bJoyPOVDown->setText(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
        bJoyPOVRight->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        CalibrationSubTab->setTabText(CalibrationSubTab->indexOf(tabCalibrationJoystick), QApplication::translate("MainWindow", "Joystick", 0, QApplication::UnicodeUTF8));
        cbControlGroup->setCurrentText(QString());
        bControlGroupRead->setText(QApplication::translate("MainWindow", "Read", 0, QApplication::UnicodeUTF8));
        bTuningPSmaller->setText(QApplication::translate("MainWindow", "/2", 0, QApplication::UnicodeUTF8));
        bTuningPBigger->setText(QApplication::translate("MainWindow", "*2", 0, QApplication::UnicodeUTF8));
        bTuningPReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        lTuningPValue->setText(QApplication::translate("MainWindow", "0.0", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Proportional Gain", 0, QApplication::UnicodeUTF8));
        bControlGroupSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        lTuningIValue->setText(QApplication::translate("MainWindow", "0.0", 0, QApplication::UnicodeUTF8));
        bTuningIReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Integral Gain", 0, QApplication::UnicodeUTF8));
        bTuningISmaller->setText(QApplication::translate("MainWindow", "/2", 0, QApplication::UnicodeUTF8));
        bTuningIBigger->setText(QApplication::translate("MainWindow", "*2", 0, QApplication::UnicodeUTF8));
        lTuningDValue->setText(QApplication::translate("MainWindow", "0.0", 0, QApplication::UnicodeUTF8));
        bTuningDReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Derivative Gain", 0, QApplication::UnicodeUTF8));
        bTuningDSmaller->setText(QApplication::translate("MainWindow", "/2", 0, QApplication::UnicodeUTF8));
        bTuningDBigger->setText(QApplication::translate("MainWindow", "*2", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Max", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Min:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Default:", 0, QApplication::UnicodeUTF8));
        lTuningMaxValue->setText(QApplication::translate("MainWindow", "1500", 0, QApplication::UnicodeUTF8));
        lTuningMinValue->setText(QApplication::translate("MainWindow", "1500", 0, QApplication::UnicodeUTF8));
        lTuningDefaultValue->setText(QApplication::translate("MainWindow", "1500", 0, QApplication::UnicodeUTF8));
        CalibrationSubTab->setTabText(CalibrationSubTab->indexOf(tabCalibrationTuning), QApplication::translate("MainWindow", "Tuning", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Calibration", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Operation", 0, QApplication::UnicodeUTF8));
        tEStopState->setText(QApplication::translate("MainWindow", "UNDEFINED", 0, QApplication::UnicodeUTF8));
        iRoverSignal->setText(QString());
        iRoverActive->setText(QString());
        iROSSignal->setText(QString());
        iRouterSignal->setText(QString());
        iRouterActive->setText(QString());
        iROSServerActive->setText(QString());
        bArmDisarm->setText(QApplication::translate("MainWindow", "UNDEFINED", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
