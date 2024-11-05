/********************************************************************************
** Form generated from reading UI file 'showwin_angleencoder.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWWIN_ANGLEENCODER_H
#define UI_SHOWWIN_ANGLEENCODER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_showWin_angleEncoder
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_bat;
    QProgressBar *pBar_battery;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_21;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_ang;
    QCustomPlot *plot_angle;
    QHBoxLayout *horizontalLayout_20;
    QFrame *line_8;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_enc_angle;
    QLineEdit *lineE_encoder_angle;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_enc_A_pulse;
    QLineEdit *lineE_encoder_A_pulse;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_enc_B_pulse;
    QLineEdit *lineE_encoder_B_pulse;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_err_per;
    QLineEdit *lineE_phase_err_per;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_pul;
    QCustomPlot *plot_impulse;
    QHBoxLayout *horizontalLayout_9;
    QFrame *line_10;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_motor_angle;
    QLineEdit *lineE_motor_angle;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_motor_circle;
    QLineEdit *lineE_motor_circle;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_motor_speed;
    QLineEdit *lineE_motor_speed;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_run_stop;
    QPushButton *btn_stop_now;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_supply_voltage;
    QLineEdit *lineE_supply_voltage;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_supply_current;
    QLineEdit *lineE_supply_current;
    QFrame *line;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_signal_voltage_A;
    QLineEdit *lineE_signal_voltage_A;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_signal_current_A;
    QLineEdit *lineE_signal_current_A;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_signal_voltage_B;
    QLineEdit *lineE_signal_voltage_B;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_signal_current_B;
    QLineEdit *lineE_signal_current_B;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_period;
    QLineEdit *lineE_period;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_two_edge_sep;
    QLineEdit *lineE_two_edge_sep;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *btn_start_finish_mea;
    QPushButton *btn_ok;

    void setupUi(QWidget *showWin_angleEncoder)
    {
        if (showWin_angleEncoder->objectName().isEmpty())
            showWin_angleEncoder->setObjectName(QString::fromUtf8("showWin_angleEncoder"));
        showWin_angleEncoder->resize(1276, 794);
        showWin_angleEncoder->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(showWin_angleEncoder);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label = new QLabel(showWin_angleEncoder);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_17->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer);

        line_7 = new QFrame(showWin_angleEncoder);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_17->addWidget(line_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_bat = new QLabel(showWin_angleEncoder);
        label_bat->setObjectName(QString::fromUtf8("label_bat"));

        horizontalLayout->addWidget(label_bat);

        pBar_battery = new QProgressBar(showWin_angleEncoder);
        pBar_battery->setObjectName(QString::fromUtf8("pBar_battery"));
        pBar_battery->setMinimumSize(QSize(0, 50));
        pBar_battery->setValue(0);

        horizontalLayout->addWidget(pBar_battery);


        horizontalLayout_17->addLayout(horizontalLayout);


        verticalLayout_10->addLayout(horizontalLayout_17);

        line_3 = new QFrame(showWin_angleEncoder);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line_3->sizePolicy().hasHeightForWidth());
        line_3->setSizePolicy(sizePolicy);
        line_3->setMinimumSize(QSize(300, 0));
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_3);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_ang = new QLabel(showWin_angleEncoder);
        label_ang->setObjectName(QString::fromUtf8("label_ang"));
        label_ang->setMinimumSize(QSize(600, 0));
        label_ang->setMaximumSize(QSize(16777215, 50));

        verticalLayout_7->addWidget(label_ang);

        plot_angle = new QCustomPlot(showWin_angleEncoder);
        plot_angle->setObjectName(QString::fromUtf8("plot_angle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plot_angle->sizePolicy().hasHeightForWidth());
        plot_angle->setSizePolicy(sizePolicy1);
        plot_angle->setMinimumSize(QSize(600, 200));

        verticalLayout_7->addWidget(plot_angle);


        horizontalLayout_21->addLayout(verticalLayout_7);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        line_8 = new QFrame(showWin_angleEncoder);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_20->addWidget(line_8);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_enc_angle = new QLabel(showWin_angleEncoder);
        label_enc_angle->setObjectName(QString::fromUtf8("label_enc_angle"));
        label_enc_angle->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(label_enc_angle);

        lineE_encoder_angle = new QLineEdit(showWin_angleEncoder);
        lineE_encoder_angle->setObjectName(QString::fromUtf8("lineE_encoder_angle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineE_encoder_angle->sizePolicy().hasHeightForWidth());
        lineE_encoder_angle->setSizePolicy(sizePolicy2);
        lineE_encoder_angle->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_2->addWidget(lineE_encoder_angle);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_enc_A_pulse = new QLabel(showWin_angleEncoder);
        label_enc_A_pulse->setObjectName(QString::fromUtf8("label_enc_A_pulse"));
        label_enc_A_pulse->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(label_enc_A_pulse);

        lineE_encoder_A_pulse = new QLineEdit(showWin_angleEncoder);
        lineE_encoder_A_pulse->setObjectName(QString::fromUtf8("lineE_encoder_A_pulse"));
        sizePolicy2.setHeightForWidth(lineE_encoder_A_pulse->sizePolicy().hasHeightForWidth());
        lineE_encoder_A_pulse->setSizePolicy(sizePolicy2);
        lineE_encoder_A_pulse->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_3->addWidget(lineE_encoder_A_pulse);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_enc_B_pulse = new QLabel(showWin_angleEncoder);
        label_enc_B_pulse->setObjectName(QString::fromUtf8("label_enc_B_pulse"));
        label_enc_B_pulse->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(label_enc_B_pulse);

        lineE_encoder_B_pulse = new QLineEdit(showWin_angleEncoder);
        lineE_encoder_B_pulse->setObjectName(QString::fromUtf8("lineE_encoder_B_pulse"));
        sizePolicy2.setHeightForWidth(lineE_encoder_B_pulse->sizePolicy().hasHeightForWidth());
        lineE_encoder_B_pulse->setSizePolicy(sizePolicy2);
        lineE_encoder_B_pulse->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_4->addWidget(lineE_encoder_B_pulse);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_err_per = new QLabel(showWin_angleEncoder);
        label_err_per->setObjectName(QString::fromUtf8("label_err_per"));
        label_err_per->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_5->addWidget(label_err_per);

        lineE_phase_err_per = new QLineEdit(showWin_angleEncoder);
        lineE_phase_err_per->setObjectName(QString::fromUtf8("lineE_phase_err_per"));
        sizePolicy2.setHeightForWidth(lineE_phase_err_per->sizePolicy().hasHeightForWidth());
        lineE_phase_err_per->setSizePolicy(sizePolicy2);
        lineE_phase_err_per->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_5->addWidget(lineE_phase_err_per);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_20->addLayout(verticalLayout_3);


        horizontalLayout_21->addLayout(horizontalLayout_20);


        verticalLayout_10->addLayout(horizontalLayout_21);

        line_4 = new QFrame(showWin_angleEncoder);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_4);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_pul = new QLabel(showWin_angleEncoder);
        label_pul->setObjectName(QString::fromUtf8("label_pul"));
        label_pul->setMinimumSize(QSize(600, 0));
        label_pul->setMaximumSize(QSize(16777215, 50));

        verticalLayout_8->addWidget(label_pul);

        plot_impulse = new QCustomPlot(showWin_angleEncoder);
        plot_impulse->setObjectName(QString::fromUtf8("plot_impulse"));
        plot_impulse->setMinimumSize(QSize(600, 200));

        verticalLayout_8->addWidget(plot_impulse);


        horizontalLayout_19->addLayout(verticalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        line_10 = new QFrame(showWin_angleEncoder);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line_10);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_motor_angle = new QLabel(showWin_angleEncoder);
        label_motor_angle->setObjectName(QString::fromUtf8("label_motor_angle"));
        label_motor_angle->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_6->addWidget(label_motor_angle);

        lineE_motor_angle = new QLineEdit(showWin_angleEncoder);
        lineE_motor_angle->setObjectName(QString::fromUtf8("lineE_motor_angle"));
        sizePolicy2.setHeightForWidth(lineE_motor_angle->sizePolicy().hasHeightForWidth());
        lineE_motor_angle->setSizePolicy(sizePolicy2);
        lineE_motor_angle->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(lineE_motor_angle);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_motor_circle = new QLabel(showWin_angleEncoder);
        label_motor_circle->setObjectName(QString::fromUtf8("label_motor_circle"));
        label_motor_circle->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(label_motor_circle);

        lineE_motor_circle = new QLineEdit(showWin_angleEncoder);
        lineE_motor_circle->setObjectName(QString::fromUtf8("lineE_motor_circle"));
        sizePolicy2.setHeightForWidth(lineE_motor_circle->sizePolicy().hasHeightForWidth());
        lineE_motor_circle->setSizePolicy(sizePolicy2);
        lineE_motor_circle->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_7->addWidget(lineE_motor_circle);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_motor_speed = new QLabel(showWin_angleEncoder);
        label_motor_speed->setObjectName(QString::fromUtf8("label_motor_speed"));
        label_motor_speed->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(label_motor_speed);

        lineE_motor_speed = new QLineEdit(showWin_angleEncoder);
        lineE_motor_speed->setObjectName(QString::fromUtf8("lineE_motor_speed"));
        sizePolicy2.setHeightForWidth(lineE_motor_speed->sizePolicy().hasHeightForWidth());
        lineE_motor_speed->setSizePolicy(sizePolicy2);
        lineE_motor_speed->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_8->addWidget(lineE_motor_speed);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_9->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_run_stop = new QPushButton(showWin_angleEncoder);
        btn_run_stop->setObjectName(QString::fromUtf8("btn_run_stop"));
        sizePolicy1.setHeightForWidth(btn_run_stop->sizePolicy().hasHeightForWidth());
        btn_run_stop->setSizePolicy(sizePolicy1);
        btn_run_stop->setMinimumSize(QSize(300, 50));
        btn_run_stop->setMaximumSize(QSize(100, 16777215));
        btn_run_stop->setCheckable(true);

        verticalLayout->addWidget(btn_run_stop);

        btn_stop_now = new QPushButton(showWin_angleEncoder);
        btn_stop_now->setObjectName(QString::fromUtf8("btn_stop_now"));
        sizePolicy1.setHeightForWidth(btn_stop_now->sizePolicy().hasHeightForWidth());
        btn_stop_now->setSizePolicy(sizePolicy1);
        btn_stop_now->setMinimumSize(QSize(300, 50));
        btn_stop_now->setMaximumSize(QSize(100, 16777215));
        btn_stop_now->setCheckable(false);

        verticalLayout->addWidget(btn_stop_now);


        horizontalLayout_9->addLayout(verticalLayout);


        horizontalLayout_19->addLayout(horizontalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_19);

        line_5 = new QFrame(showWin_angleEncoder);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_5);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_supply_voltage = new QLabel(showWin_angleEncoder);
        label_supply_voltage->setObjectName(QString::fromUtf8("label_supply_voltage"));

        horizontalLayout_10->addWidget(label_supply_voltage);

        lineE_supply_voltage = new QLineEdit(showWin_angleEncoder);
        lineE_supply_voltage->setObjectName(QString::fromUtf8("lineE_supply_voltage"));
        sizePolicy2.setHeightForWidth(lineE_supply_voltage->sizePolicy().hasHeightForWidth());
        lineE_supply_voltage->setSizePolicy(sizePolicy2);
        lineE_supply_voltage->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_10->addWidget(lineE_supply_voltage);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_supply_current = new QLabel(showWin_angleEncoder);
        label_supply_current->setObjectName(QString::fromUtf8("label_supply_current"));

        horizontalLayout_11->addWidget(label_supply_current);

        lineE_supply_current = new QLineEdit(showWin_angleEncoder);
        lineE_supply_current->setObjectName(QString::fromUtf8("lineE_supply_current"));
        sizePolicy2.setHeightForWidth(lineE_supply_current->sizePolicy().hasHeightForWidth());
        lineE_supply_current->setSizePolicy(sizePolicy2);
        lineE_supply_current->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_11->addWidget(lineE_supply_current);


        verticalLayout_6->addLayout(horizontalLayout_11);


        horizontalLayout_16->addLayout(verticalLayout_6);

        line = new QFrame(showWin_angleEncoder);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_signal_voltage_A = new QLabel(showWin_angleEncoder);
        label_signal_voltage_A->setObjectName(QString::fromUtf8("label_signal_voltage_A"));

        horizontalLayout_12->addWidget(label_signal_voltage_A);

        lineE_signal_voltage_A = new QLineEdit(showWin_angleEncoder);
        lineE_signal_voltage_A->setObjectName(QString::fromUtf8("lineE_signal_voltage_A"));
        sizePolicy2.setHeightForWidth(lineE_signal_voltage_A->sizePolicy().hasHeightForWidth());
        lineE_signal_voltage_A->setSizePolicy(sizePolicy2);
        lineE_signal_voltage_A->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_12->addWidget(lineE_signal_voltage_A);


        verticalLayout_5->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_signal_current_A = new QLabel(showWin_angleEncoder);
        label_signal_current_A->setObjectName(QString::fromUtf8("label_signal_current_A"));

        horizontalLayout_13->addWidget(label_signal_current_A);

        lineE_signal_current_A = new QLineEdit(showWin_angleEncoder);
        lineE_signal_current_A->setObjectName(QString::fromUtf8("lineE_signal_current_A"));
        sizePolicy2.setHeightForWidth(lineE_signal_current_A->sizePolicy().hasHeightForWidth());
        lineE_signal_current_A->setSizePolicy(sizePolicy2);
        lineE_signal_current_A->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_13->addWidget(lineE_signal_current_A);


        verticalLayout_5->addLayout(horizontalLayout_13);


        horizontalLayout_16->addLayout(verticalLayout_5);

        line_2 = new QFrame(showWin_angleEncoder);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_signal_voltage_B = new QLabel(showWin_angleEncoder);
        label_signal_voltage_B->setObjectName(QString::fromUtf8("label_signal_voltage_B"));

        horizontalLayout_14->addWidget(label_signal_voltage_B);

        lineE_signal_voltage_B = new QLineEdit(showWin_angleEncoder);
        lineE_signal_voltage_B->setObjectName(QString::fromUtf8("lineE_signal_voltage_B"));
        sizePolicy2.setHeightForWidth(lineE_signal_voltage_B->sizePolicy().hasHeightForWidth());
        lineE_signal_voltage_B->setSizePolicy(sizePolicy2);
        lineE_signal_voltage_B->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_14->addWidget(lineE_signal_voltage_B);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_signal_current_B = new QLabel(showWin_angleEncoder);
        label_signal_current_B->setObjectName(QString::fromUtf8("label_signal_current_B"));

        horizontalLayout_15->addWidget(label_signal_current_B);

        lineE_signal_current_B = new QLineEdit(showWin_angleEncoder);
        lineE_signal_current_B->setObjectName(QString::fromUtf8("lineE_signal_current_B"));
        sizePolicy2.setHeightForWidth(lineE_signal_current_B->sizePolicy().hasHeightForWidth());
        lineE_signal_current_B->setSizePolicy(sizePolicy2);
        lineE_signal_current_B->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_15->addWidget(lineE_signal_current_B);


        verticalLayout_4->addLayout(horizontalLayout_15);


        horizontalLayout_16->addLayout(verticalLayout_4);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_period = new QLabel(showWin_angleEncoder);
        label_period->setObjectName(QString::fromUtf8("label_period"));

        horizontalLayout_22->addWidget(label_period);

        lineE_period = new QLineEdit(showWin_angleEncoder);
        lineE_period->setObjectName(QString::fromUtf8("lineE_period"));
        sizePolicy2.setHeightForWidth(lineE_period->sizePolicy().hasHeightForWidth());
        lineE_period->setSizePolicy(sizePolicy2);
        lineE_period->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_22->addWidget(lineE_period);


        verticalLayout_9->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_two_edge_sep = new QLabel(showWin_angleEncoder);
        label_two_edge_sep->setObjectName(QString::fromUtf8("label_two_edge_sep"));

        horizontalLayout_23->addWidget(label_two_edge_sep);

        lineE_two_edge_sep = new QLineEdit(showWin_angleEncoder);
        lineE_two_edge_sep->setObjectName(QString::fromUtf8("lineE_two_edge_sep"));
        sizePolicy2.setHeightForWidth(lineE_two_edge_sep->sizePolicy().hasHeightForWidth());
        lineE_two_edge_sep->setSizePolicy(sizePolicy2);
        lineE_two_edge_sep->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_23->addWidget(lineE_two_edge_sep);


        verticalLayout_9->addLayout(horizontalLayout_23);


        horizontalLayout_16->addLayout(verticalLayout_9);


        verticalLayout_10->addLayout(horizontalLayout_16);

        line_6 = new QFrame(showWin_angleEncoder);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line_6);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        btn_start_finish_mea = new QPushButton(showWin_angleEncoder);
        btn_start_finish_mea->setObjectName(QString::fromUtf8("btn_start_finish_mea"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_start_finish_mea->sizePolicy().hasHeightForWidth());
        btn_start_finish_mea->setSizePolicy(sizePolicy3);
        btn_start_finish_mea->setMinimumSize(QSize(0, 50));
        btn_start_finish_mea->setMaximumSize(QSize(16777215, 150));
        btn_start_finish_mea->setCheckable(true);

        horizontalLayout_18->addWidget(btn_start_finish_mea);

        btn_ok = new QPushButton(showWin_angleEncoder);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy3.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy3);
        btn_ok->setMinimumSize(QSize(0, 50));
        btn_ok->setMaximumSize(QSize(16777215, 150));

        horizontalLayout_18->addWidget(btn_ok);


        verticalLayout_10->addLayout(horizontalLayout_18);


        gridLayout->addLayout(verticalLayout_10, 0, 0, 1, 1);


        retranslateUi(showWin_angleEncoder);

        QMetaObject::connectSlotsByName(showWin_angleEncoder);
    } // setupUi

    void retranslateUi(QWidget *showWin_angleEncoder)
    {
        showWin_angleEncoder->setWindowTitle(QCoreApplication::translate("showWin_angleEncoder", "\346\230\276\347\244\272_\350\247\222\344\275\215\347\247\273\347\274\226\347\240\201\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("showWin_angleEncoder", "\346\230\276\347\244\272\342\200\224\342\200\224\350\247\222\344\275\215\347\247\273\347\274\226\347\240\201\345\231\250", nullptr));
        label_bat->setText(QCoreApplication::translate("showWin_angleEncoder", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\232", nullptr));
        label_ang->setText(QCoreApplication::translate("showWin_angleEncoder", "\350\247\222\345\272\246\357\274\232", nullptr));
        label_enc_angle->setText(QCoreApplication::translate("showWin_angleEncoder", "\347\274\226\347\240\201\345\231\250\350\247\222\345\272\246\357\274\232", nullptr));
        label_enc_A_pulse->setText(QCoreApplication::translate("showWin_angleEncoder", "A\347\233\270\344\270\212\345\215\207\346\262\277\350\256\241\346\225\260\357\274\232", nullptr));
        label_enc_B_pulse->setText(QCoreApplication::translate("showWin_angleEncoder", "B\347\233\270\344\270\212\345\215\207\346\262\277\350\256\241\346\225\260\357\274\232", nullptr));
        label_err_per->setText(QCoreApplication::translate("showWin_angleEncoder", "\350\257\257\345\267\256\347\231\276\345\210\206\346\257\224\357\274\232", nullptr));
        label_pul->setText(QCoreApplication::translate("showWin_angleEncoder", "\350\204\211\345\206\262\357\274\232", nullptr));
        label_motor_angle->setText(QCoreApplication::translate("showWin_angleEncoder", "\347\224\265\346\234\272\350\275\254\345\212\250\350\247\222\345\272\246\357\274\232", nullptr));
        label_motor_circle->setText(QCoreApplication::translate("showWin_angleEncoder", "\347\224\265\346\234\272\350\275\254\345\212\250\345\234\210\346\225\260\357\274\232", nullptr));
        label_motor_speed->setText(QCoreApplication::translate("showWin_angleEncoder", "\347\224\265\346\234\272\350\275\254\345\212\250\351\200\237\345\272\246\357\274\232", nullptr));
        btn_run_stop->setText(QCoreApplication::translate("showWin_angleEncoder", "\350\277\220\350\241\214", nullptr));
        btn_stop_now->setText(QCoreApplication::translate("showWin_angleEncoder", "\347\264\247\346\200\245\345\201\234\346\255\242", nullptr));
        label_supply_voltage->setText(QCoreApplication::translate("showWin_angleEncoder", "\344\276\233\347\224\265\345\233\236\350\267\257\347\224\265\345\216\213\357\274\232", nullptr));
        label_supply_current->setText(QCoreApplication::translate("showWin_angleEncoder", "\344\276\233\347\224\265\345\233\236\350\267\257\347\224\265\346\265\201\357\274\232", nullptr));
        label_signal_voltage_A->setText(QCoreApplication::translate("showWin_angleEncoder", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\345\216\213 A\357\274\232", nullptr));
        label_signal_current_A->setText(QCoreApplication::translate("showWin_angleEncoder", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\346\265\201 A\357\274\232", nullptr));
        label_signal_voltage_B->setText(QCoreApplication::translate("showWin_angleEncoder", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\345\216\213 B\357\274\232", nullptr));
        label_signal_current_B->setText(QCoreApplication::translate("showWin_angleEncoder", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\346\265\201 B\357\274\232", nullptr));
        label_period->setText(QCoreApplication::translate("showWin_angleEncoder", "period:", nullptr));
        label_two_edge_sep->setText(QCoreApplication::translate("showWin_angleEncoder", "interval", nullptr));
        btn_start_finish_mea->setText(QCoreApplication::translate("showWin_angleEncoder", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
        btn_ok->setText(QCoreApplication::translate("showWin_angleEncoder", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showWin_angleEncoder: public Ui_showWin_angleEncoder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWWIN_ANGLEENCODER_H
