/********************************************************************************
** Form generated from reading UI file 'showwin_proximityswitch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWWIN_PROXIMITYSWITCH_H
#define UI_SHOWWIN_PROXIMITYSWITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_showWin_proximitySwitch
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_bat;
    QProgressBar *pBar_battery;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_dis;
    QCustomPlot *plot_distance;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_supply_voltage;
    QLineEdit *lineE_supply_voltage;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_supply_current;
    QLineEdit *lineE_supply_current;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_signal_voltage;
    QLineEdit *lineE_signal_voltage;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_signal_current;
    QLineEdit *lineE_signal_current;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_sensing_dis;
    QLineEdit *lineE_sensing_dis;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_repeat_precise;
    QHBoxLayout *horizontalLayout;
    QLabel *label_dis_max;
    QLineEdit *lineE_dis_max;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_dis_min;
    QLineEdit *lineE_dis_min;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_dis_avg;
    QLineEdit *lineE_dis_avg;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btn_ok;
    QPushButton *btn_start_finish_mea;

    void setupUi(QWidget *showWin_proximitySwitch)
    {
        if (showWin_proximitySwitch->objectName().isEmpty())
            showWin_proximitySwitch->setObjectName(QString::fromUtf8("showWin_proximitySwitch"));
        showWin_proximitySwitch->resize(1154, 667);
        gridLayout = new QGridLayout(showWin_proximitySwitch);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label = new QLabel(showWin_proximitySwitch);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout_10->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_bat = new QLabel(showWin_proximitySwitch);
        label_bat->setObjectName(QString::fromUtf8("label_bat"));

        horizontalLayout_9->addWidget(label_bat);

        pBar_battery = new QProgressBar(showWin_proximitySwitch);
        pBar_battery->setObjectName(QString::fromUtf8("pBar_battery"));
        pBar_battery->setValue(0);

        horizontalLayout_9->addWidget(pBar_battery);


        horizontalLayout_10->addLayout(horizontalLayout_9);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_dis = new QLabel(showWin_proximitySwitch);
        label_dis->setObjectName(QString::fromUtf8("label_dis"));
        label_dis->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(label_dis);

        plot_distance = new QCustomPlot(showWin_proximitySwitch);
        plot_distance->setObjectName(QString::fromUtf8("plot_distance"));
        plot_distance->setMinimumSize(QSize(0, 200));

        verticalLayout_3->addWidget(plot_distance);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_supply_voltage = new QLabel(showWin_proximitySwitch);
        label_supply_voltage->setObjectName(QString::fromUtf8("label_supply_voltage"));

        horizontalLayout_4->addWidget(label_supply_voltage);

        lineE_supply_voltage = new QLineEdit(showWin_proximitySwitch);
        lineE_supply_voltage->setObjectName(QString::fromUtf8("lineE_supply_voltage"));

        horizontalLayout_4->addWidget(lineE_supply_voltage);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_supply_current = new QLabel(showWin_proximitySwitch);
        label_supply_current->setObjectName(QString::fromUtf8("label_supply_current"));

        horizontalLayout_5->addWidget(label_supply_current);

        lineE_supply_current = new QLineEdit(showWin_proximitySwitch);
        lineE_supply_current->setObjectName(QString::fromUtf8("lineE_supply_current"));

        horizontalLayout_5->addWidget(lineE_supply_current);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_signal_voltage = new QLabel(showWin_proximitySwitch);
        label_signal_voltage->setObjectName(QString::fromUtf8("label_signal_voltage"));

        horizontalLayout_6->addWidget(label_signal_voltage);

        lineE_signal_voltage = new QLineEdit(showWin_proximitySwitch);
        lineE_signal_voltage->setObjectName(QString::fromUtf8("lineE_signal_voltage"));

        horizontalLayout_6->addWidget(lineE_signal_voltage);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_signal_current = new QLabel(showWin_proximitySwitch);
        label_signal_current->setObjectName(QString::fromUtf8("label_signal_current"));

        horizontalLayout_7->addWidget(label_signal_current);

        lineE_signal_current = new QLineEdit(showWin_proximitySwitch);
        lineE_signal_current->setObjectName(QString::fromUtf8("lineE_signal_current"));

        horizontalLayout_7->addWidget(lineE_signal_current);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_sensing_dis = new QLabel(showWin_proximitySwitch);
        label_sensing_dis->setObjectName(QString::fromUtf8("label_sensing_dis"));

        horizontalLayout_8->addWidget(label_sensing_dis);

        lineE_sensing_dis = new QLineEdit(showWin_proximitySwitch);
        lineE_sensing_dis->setObjectName(QString::fromUtf8("lineE_sensing_dis"));

        horizontalLayout_8->addWidget(lineE_sensing_dis);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_11->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_repeat_precise = new QPushButton(showWin_proximitySwitch);
        btn_repeat_precise->setObjectName(QString::fromUtf8("btn_repeat_precise"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_repeat_precise->sizePolicy().hasHeightForWidth());
        btn_repeat_precise->setSizePolicy(sizePolicy);
        btn_repeat_precise->setMinimumSize(QSize(0, 40));
        btn_repeat_precise->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(btn_repeat_precise);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_dis_max = new QLabel(showWin_proximitySwitch);
        label_dis_max->setObjectName(QString::fromUtf8("label_dis_max"));

        horizontalLayout->addWidget(label_dis_max);

        lineE_dis_max = new QLineEdit(showWin_proximitySwitch);
        lineE_dis_max->setObjectName(QString::fromUtf8("lineE_dis_max"));

        horizontalLayout->addWidget(lineE_dis_max);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_dis_min = new QLabel(showWin_proximitySwitch);
        label_dis_min->setObjectName(QString::fromUtf8("label_dis_min"));

        horizontalLayout_2->addWidget(label_dis_min);

        lineE_dis_min = new QLineEdit(showWin_proximitySwitch);
        lineE_dis_min->setObjectName(QString::fromUtf8("lineE_dis_min"));

        horizontalLayout_2->addWidget(lineE_dis_min);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_dis_avg = new QLabel(showWin_proximitySwitch);
        label_dis_avg->setObjectName(QString::fromUtf8("label_dis_avg"));

        horizontalLayout_3->addWidget(label_dis_avg);

        lineE_dis_avg = new QLineEdit(showWin_proximitySwitch);
        lineE_dis_avg->setObjectName(QString::fromUtf8("lineE_dis_avg"));

        horizontalLayout_3->addWidget(lineE_dis_avg);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_11->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout_11, 2, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btn_ok = new QPushButton(showWin_proximitySwitch);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy);

        verticalLayout_4->addWidget(btn_ok);


        gridLayout->addLayout(verticalLayout_4, 2, 1, 1, 1);

        btn_start_finish_mea = new QPushButton(showWin_proximitySwitch);
        btn_start_finish_mea->setObjectName(QString::fromUtf8("btn_start_finish_mea"));
        sizePolicy.setHeightForWidth(btn_start_finish_mea->sizePolicy().hasHeightForWidth());
        btn_start_finish_mea->setSizePolicy(sizePolicy);
        btn_start_finish_mea->setMinimumSize(QSize(200, 0));
        btn_start_finish_mea->setCheckable(true);

        gridLayout->addWidget(btn_start_finish_mea, 1, 1, 1, 1);


        retranslateUi(showWin_proximitySwitch);

        QMetaObject::connectSlotsByName(showWin_proximitySwitch);
    } // setupUi

    void retranslateUi(QWidget *showWin_proximitySwitch)
    {
        showWin_proximitySwitch->setWindowTitle(QCoreApplication::translate("showWin_proximitySwitch", "\346\230\276\347\244\272_\346\216\245\350\277\221\345\274\200\345\205\263", nullptr));
        label->setText(QCoreApplication::translate("showWin_proximitySwitch", "\346\230\276\347\244\272\342\200\224\342\200\224\346\216\245\350\277\221\345\274\200\345\205\263", nullptr));
        label_bat->setText(QCoreApplication::translate("showWin_proximitySwitch", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\232", nullptr));
        label_dis->setText(QCoreApplication::translate("showWin_proximitySwitch", "\350\267\235\347\246\273\357\274\232", nullptr));
        label_supply_voltage->setText(QCoreApplication::translate("showWin_proximitySwitch", "\344\276\233\347\224\265\345\233\236\350\267\257\347\224\265\345\216\213\357\274\232", nullptr));
        label_supply_current->setText(QCoreApplication::translate("showWin_proximitySwitch", "\344\276\233\347\224\265\345\233\236\350\267\257\347\224\265\346\265\201\357\274\232", nullptr));
        label_signal_voltage->setText(QCoreApplication::translate("showWin_proximitySwitch", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\345\216\213\357\274\232", nullptr));
        label_signal_current->setText(QCoreApplication::translate("showWin_proximitySwitch", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\346\265\201\357\274\232", nullptr));
        label_sensing_dis->setText(QCoreApplication::translate("showWin_proximitySwitch", "\346\204\237\345\272\224\350\267\235\347\246\273\357\274\232", nullptr));
        btn_repeat_precise->setText(QCoreApplication::translate("showWin_proximitySwitch", "\351\207\215\345\244\215\347\262\276\345\272\246\346\265\213\351\207\217", nullptr));
        label_dis_max->setText(QCoreApplication::translate("showWin_proximitySwitch", "\346\234\200\345\244\247\345\200\274\357\274\232", nullptr));
        label_dis_min->setText(QCoreApplication::translate("showWin_proximitySwitch", "\346\234\200\345\260\217\345\200\274\357\274\232", nullptr));
        label_dis_avg->setText(QCoreApplication::translate("showWin_proximitySwitch", "\345\271\263\345\235\207\345\200\274\357\274\232", nullptr));
        btn_ok->setText(QCoreApplication::translate("showWin_proximitySwitch", "\347\241\256\345\256\232", nullptr));
        btn_start_finish_mea->setText(QCoreApplication::translate("showWin_proximitySwitch", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showWin_proximitySwitch: public Ui_showWin_proximitySwitch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWWIN_PROXIMITYSWITCH_H
