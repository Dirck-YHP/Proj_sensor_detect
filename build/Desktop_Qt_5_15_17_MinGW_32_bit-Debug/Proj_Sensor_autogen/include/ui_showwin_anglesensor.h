/********************************************************************************
** Form generated from reading UI file 'showwin_anglesensor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWWIN_ANGLESENSOR_H
#define UI_SHOWWIN_ANGLESENSOR_H

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

class Ui_showWin_angleSensor
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_bat;
    QProgressBar *pBar_battery;
    QFrame *line_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_ang;
    QCustomPlot *plot_angle;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_supply_voltage;
    QLineEdit *lineE_supply_voltage;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_supply_current;
    QLineEdit *lineE_supply_current;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_signal_voltage;
    QLineEdit *lineE_signal_voltage;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_signal_current;
    QLineEdit *lineE_signal_current;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_motor_angle;
    QLineEdit *lineE_motor_angle;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_motor_circle;
    QLineEdit *lineE_motor_circle;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_run_stop;
    QPushButton *btn_stop_now;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_sensor_angle;
    QLineEdit *lineE_sensor_angle;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_angle_err;
    QLineEdit *lineE_angle_err;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_angle_err_per;
    QLineEdit *lineE_angle_err_per;
    QFrame *line;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btn_angle_cali;
    QLineEdit *lineE_angle_cali;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *btn_start_finish_mea;
    QPushButton *btn_ok;

    void setupUi(QWidget *showWin_angleSensor)
    {
        if (showWin_angleSensor->objectName().isEmpty())
            showWin_angleSensor->setObjectName(QString::fromUtf8("showWin_angleSensor"));
        showWin_angleSensor->resize(1213, 880);
        gridLayout = new QGridLayout(showWin_angleSensor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label = new QLabel(showWin_angleSensor);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout_16->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_bat = new QLabel(showWin_angleSensor);
        label_bat->setObjectName(QString::fromUtf8("label_bat"));

        horizontalLayout_15->addWidget(label_bat);

        pBar_battery = new QProgressBar(showWin_angleSensor);
        pBar_battery->setObjectName(QString::fromUtf8("pBar_battery"));
        pBar_battery->setMinimumSize(QSize(0, 50));
        pBar_battery->setValue(0);

        horizontalLayout_15->addWidget(pBar_battery);


        horizontalLayout_16->addLayout(horizontalLayout_15);


        verticalLayout_7->addLayout(horizontalLayout_16);

        line_5 = new QFrame(showWin_angleSensor);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_ang = new QLabel(showWin_angleSensor);
        label_ang->setObjectName(QString::fromUtf8("label_ang"));
        label_ang->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(label_ang);

        plot_angle = new QCustomPlot(showWin_angleSensor);
        plot_angle->setObjectName(QString::fromUtf8("plot_angle"));
        plot_angle->setMinimumSize(QSize(0, 300));

        verticalLayout->addWidget(plot_angle);


        verticalLayout_7->addLayout(verticalLayout);

        line_3 = new QFrame(showWin_angleSensor);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_supply_voltage = new QLabel(showWin_angleSensor);
        label_supply_voltage->setObjectName(QString::fromUtf8("label_supply_voltage"));

        horizontalLayout->addWidget(label_supply_voltage);

        lineE_supply_voltage = new QLineEdit(showWin_angleSensor);
        lineE_supply_voltage->setObjectName(QString::fromUtf8("lineE_supply_voltage"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineE_supply_voltage->sizePolicy().hasHeightForWidth());
        lineE_supply_voltage->setSizePolicy(sizePolicy);
        lineE_supply_voltage->setMaximumSize(QSize(16777215, 50));

        horizontalLayout->addWidget(lineE_supply_voltage);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_supply_current = new QLabel(showWin_angleSensor);
        label_supply_current->setObjectName(QString::fromUtf8("label_supply_current"));

        horizontalLayout_2->addWidget(label_supply_current);

        lineE_supply_current = new QLineEdit(showWin_angleSensor);
        lineE_supply_current->setObjectName(QString::fromUtf8("lineE_supply_current"));
        sizePolicy.setHeightForWidth(lineE_supply_current->sizePolicy().hasHeightForWidth());
        lineE_supply_current->setSizePolicy(sizePolicy);
        lineE_supply_current->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_2->addWidget(lineE_supply_current);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_12->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_signal_voltage = new QLabel(showWin_angleSensor);
        label_signal_voltage->setObjectName(QString::fromUtf8("label_signal_voltage"));

        horizontalLayout_3->addWidget(label_signal_voltage);

        lineE_signal_voltage = new QLineEdit(showWin_angleSensor);
        lineE_signal_voltage->setObjectName(QString::fromUtf8("lineE_signal_voltage"));
        sizePolicy.setHeightForWidth(lineE_signal_voltage->sizePolicy().hasHeightForWidth());
        lineE_signal_voltage->setSizePolicy(sizePolicy);
        lineE_signal_voltage->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_3->addWidget(lineE_signal_voltage);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_signal_current = new QLabel(showWin_angleSensor);
        label_signal_current->setObjectName(QString::fromUtf8("label_signal_current"));

        horizontalLayout_4->addWidget(label_signal_current);

        lineE_signal_current = new QLineEdit(showWin_angleSensor);
        lineE_signal_current->setObjectName(QString::fromUtf8("lineE_signal_current"));
        sizePolicy.setHeightForWidth(lineE_signal_current->sizePolicy().hasHeightForWidth());
        lineE_signal_current->setSizePolicy(sizePolicy);
        lineE_signal_current->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_4->addWidget(lineE_signal_current);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_12->addLayout(verticalLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_motor_angle = new QLabel(showWin_angleSensor);
        label_motor_angle->setObjectName(QString::fromUtf8("label_motor_angle"));

        horizontalLayout_8->addWidget(label_motor_angle);

        lineE_motor_angle = new QLineEdit(showWin_angleSensor);
        lineE_motor_angle->setObjectName(QString::fromUtf8("lineE_motor_angle"));
        sizePolicy.setHeightForWidth(lineE_motor_angle->sizePolicy().hasHeightForWidth());
        lineE_motor_angle->setSizePolicy(sizePolicy);
        lineE_motor_angle->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_8->addWidget(lineE_motor_angle);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_motor_circle = new QLabel(showWin_angleSensor);
        label_motor_circle->setObjectName(QString::fromUtf8("label_motor_circle"));

        horizontalLayout_9->addWidget(label_motor_circle);

        lineE_motor_circle = new QLineEdit(showWin_angleSensor);
        lineE_motor_circle->setObjectName(QString::fromUtf8("lineE_motor_circle"));
        sizePolicy.setHeightForWidth(lineE_motor_circle->sizePolicy().hasHeightForWidth());
        lineE_motor_circle->setSizePolicy(sizePolicy);
        lineE_motor_circle->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_9->addWidget(lineE_motor_circle);


        verticalLayout_3->addLayout(horizontalLayout_9);


        horizontalLayout_11->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btn_run_stop = new QPushButton(showWin_angleSensor);
        btn_run_stop->setObjectName(QString::fromUtf8("btn_run_stop"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_run_stop->sizePolicy().hasHeightForWidth());
        btn_run_stop->setSizePolicy(sizePolicy1);
        btn_run_stop->setMinimumSize(QSize(200, 0));
        btn_run_stop->setCheckable(true);

        verticalLayout_2->addWidget(btn_run_stop);

        btn_stop_now = new QPushButton(showWin_angleSensor);
        btn_stop_now->setObjectName(QString::fromUtf8("btn_stop_now"));
        sizePolicy1.setHeightForWidth(btn_stop_now->sizePolicy().hasHeightForWidth());
        btn_stop_now->setSizePolicy(sizePolicy1);
        btn_stop_now->setMinimumSize(QSize(200, 0));
        btn_stop_now->setCheckable(false);

        verticalLayout_2->addWidget(btn_stop_now);


        horizontalLayout_11->addLayout(verticalLayout_2);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_7->addLayout(horizontalLayout_12);

        line_2 = new QFrame(showWin_angleSensor);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_sensor_angle = new QLabel(showWin_angleSensor);
        label_sensor_angle->setObjectName(QString::fromUtf8("label_sensor_angle"));

        horizontalLayout_5->addWidget(label_sensor_angle);

        lineE_sensor_angle = new QLineEdit(showWin_angleSensor);
        lineE_sensor_angle->setObjectName(QString::fromUtf8("lineE_sensor_angle"));
        sizePolicy.setHeightForWidth(lineE_sensor_angle->sizePolicy().hasHeightForWidth());
        lineE_sensor_angle->setSizePolicy(sizePolicy);
        lineE_sensor_angle->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_5->addWidget(lineE_sensor_angle);


        horizontalLayout_13->addLayout(horizontalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_angle_err = new QLabel(showWin_angleSensor);
        label_angle_err->setObjectName(QString::fromUtf8("label_angle_err"));

        horizontalLayout_6->addWidget(label_angle_err);

        lineE_angle_err = new QLineEdit(showWin_angleSensor);
        lineE_angle_err->setObjectName(QString::fromUtf8("lineE_angle_err"));
        sizePolicy.setHeightForWidth(lineE_angle_err->sizePolicy().hasHeightForWidth());
        lineE_angle_err->setSizePolicy(sizePolicy);
        lineE_angle_err->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_6->addWidget(lineE_angle_err);


        verticalLayout_6->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_angle_err_per = new QLabel(showWin_angleSensor);
        label_angle_err_per->setObjectName(QString::fromUtf8("label_angle_err_per"));

        horizontalLayout_7->addWidget(label_angle_err_per);

        lineE_angle_err_per = new QLineEdit(showWin_angleSensor);
        lineE_angle_err_per->setObjectName(QString::fromUtf8("lineE_angle_err_per"));
        sizePolicy.setHeightForWidth(lineE_angle_err_per->sizePolicy().hasHeightForWidth());
        lineE_angle_err_per->setSizePolicy(sizePolicy);
        lineE_angle_err_per->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_7->addWidget(lineE_angle_err_per);


        verticalLayout_6->addLayout(horizontalLayout_7);


        horizontalLayout_13->addLayout(verticalLayout_6);

        line = new QFrame(showWin_angleSensor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_13->addWidget(line);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        btn_angle_cali = new QPushButton(showWin_angleSensor);
        btn_angle_cali->setObjectName(QString::fromUtf8("btn_angle_cali"));
        sizePolicy1.setHeightForWidth(btn_angle_cali->sizePolicy().hasHeightForWidth());
        btn_angle_cali->setSizePolicy(sizePolicy1);
        btn_angle_cali->setMinimumSize(QSize(200, 0));

        horizontalLayout_10->addWidget(btn_angle_cali);

        lineE_angle_cali = new QLineEdit(showWin_angleSensor);
        lineE_angle_cali->setObjectName(QString::fromUtf8("lineE_angle_cali"));
        sizePolicy.setHeightForWidth(lineE_angle_cali->sizePolicy().hasHeightForWidth());
        lineE_angle_cali->setSizePolicy(sizePolicy);
        lineE_angle_cali->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_10->addWidget(lineE_angle_cali);


        horizontalLayout_13->addLayout(horizontalLayout_10);


        verticalLayout_7->addLayout(horizontalLayout_13);

        line_4 = new QFrame(showWin_angleSensor);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_4);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        btn_start_finish_mea = new QPushButton(showWin_angleSensor);
        btn_start_finish_mea->setObjectName(QString::fromUtf8("btn_start_finish_mea"));
        sizePolicy1.setHeightForWidth(btn_start_finish_mea->sizePolicy().hasHeightForWidth());
        btn_start_finish_mea->setSizePolicy(sizePolicy1);
        btn_start_finish_mea->setMaximumSize(QSize(16777215, 150));
        btn_start_finish_mea->setCheckable(true);

        horizontalLayout_14->addWidget(btn_start_finish_mea);

        btn_ok = new QPushButton(showWin_angleSensor);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy1.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy1);
        btn_ok->setMaximumSize(QSize(16777215, 150));

        horizontalLayout_14->addWidget(btn_ok);


        verticalLayout_7->addLayout(horizontalLayout_14);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);


        retranslateUi(showWin_angleSensor);

        QMetaObject::connectSlotsByName(showWin_angleSensor);
    } // setupUi

    void retranslateUi(QWidget *showWin_angleSensor)
    {
        showWin_angleSensor->setWindowTitle(QCoreApplication::translate("showWin_angleSensor", "\346\230\276\347\244\272_\350\247\222\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("showWin_angleSensor", "\346\230\276\347\244\272\342\200\224\342\200\224\350\247\222\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", nullptr));
        label_bat->setText(QCoreApplication::translate("showWin_angleSensor", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\232", nullptr));
        label_ang->setText(QCoreApplication::translate("showWin_angleSensor", "\350\247\222\345\272\246\357\274\232", nullptr));
        label_supply_voltage->setText(QCoreApplication::translate("showWin_angleSensor", "\344\276\233\347\224\265\345\233\236\350\267\257\347\224\265\345\216\213\357\274\232", nullptr));
        label_supply_current->setText(QCoreApplication::translate("showWin_angleSensor", "\344\276\233\347\224\265\345\233\236\350\267\257\347\224\265\346\265\201\357\274\232", nullptr));
        label_signal_voltage->setText(QCoreApplication::translate("showWin_angleSensor", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\345\216\213\357\274\232", nullptr));
        label_signal_current->setText(QCoreApplication::translate("showWin_angleSensor", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\346\265\201\357\274\232", nullptr));
        label_motor_angle->setText(QCoreApplication::translate("showWin_angleSensor", "\347\224\265\346\234\272\350\275\254\345\212\250\350\247\222\345\272\246\357\274\232", nullptr));
        label_motor_circle->setText(QCoreApplication::translate("showWin_angleSensor", "\347\224\265\346\234\272\350\275\254\345\212\250\345\234\210\346\225\260\357\274\232", nullptr));
        btn_run_stop->setText(QCoreApplication::translate("showWin_angleSensor", "\350\277\220\350\241\214", nullptr));
        btn_stop_now->setText(QCoreApplication::translate("showWin_angleSensor", "\347\264\247\346\200\245\345\201\234\346\255\242", nullptr));
        label_sensor_angle->setText(QCoreApplication::translate("showWin_angleSensor", "\344\274\240\346\204\237\345\231\250\350\247\222\345\272\246\357\274\232", nullptr));
        label_angle_err->setText(QCoreApplication::translate("showWin_angleSensor", "\350\247\222\345\272\246\350\257\257\345\267\256\357\274\232", nullptr));
        label_angle_err_per->setText(QCoreApplication::translate("showWin_angleSensor", "\350\247\222\345\272\246\350\257\257\345\267\256\347\231\276\345\210\206\346\257\224\357\274\232", nullptr));
        btn_angle_cali->setText(QCoreApplication::translate("showWin_angleSensor", "\350\247\222\345\272\246\346\240\241\345\207\206", nullptr));
        lineE_angle_cali->setText(QString());
        btn_start_finish_mea->setText(QCoreApplication::translate("showWin_angleSensor", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
        btn_ok->setText(QCoreApplication::translate("showWin_angleSensor", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showWin_angleSensor: public Ui_showWin_angleSensor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWWIN_ANGLESENSOR_H
