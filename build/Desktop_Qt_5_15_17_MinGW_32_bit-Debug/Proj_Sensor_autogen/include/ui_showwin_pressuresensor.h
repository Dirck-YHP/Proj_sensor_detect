/********************************************************************************
** Form generated from reading UI file 'showwin_pressuresensor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWWIN_PRESSURESENSOR_H
#define UI_SHOWWIN_PRESSURESENSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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

class Ui_showWin_pressureSensor
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_bat;
    QProgressBar *pBar_battery;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_pre;
    QCustomPlot *plot_pressure;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_err;
    QCustomPlot *plot_error;
    QLabel *label_ch1;
    QLabel *label_ch2;
    QLabel *label_ch3;
    QLabel *label_ch4;
    QLabel *label_ch5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_pre_;
    QLabel *label_sup_vol;
    QLabel *label_sup_cur;
    QLabel *label_sig_vol;
    QLabel *label_sig_cur;
    QLabel *label_err_;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineE_signal_voltage_1;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineE_error_percentage_5;
    QLineEdit *lineE_error_value_5;
    QLineEdit *lineE_supply_current_4;
    QLineEdit *lineE_pres_val_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineE_error_percentage_2;
    QLineEdit *lineE_error_value_2;
    QLineEdit *lineE_supply_voltage_4;
    QLineEdit *lineE_signal_voltage_4;
    QLineEdit *lineE_signal_current_5;
    QLineEdit *lineE_supply_voltage_5;
    QLineEdit *lineE_supply_voltage_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineE_error_percentage_3;
    QLineEdit *lineE_error_value_3;
    QLineEdit *lineE_signal_current_1;
    QLineEdit *lineE_signal_current_2;
    QLineEdit *lineE_signal_voltage_5;
    QLineEdit *lineE_pres_val_1;
    QLineEdit *lineE_supply_current_3;
    QLineEdit *lineE_signal_current_4;
    QLineEdit *lineE_supply_voltage_2;
    QLineEdit *lineE_signal_voltage_2;
    QLineEdit *lineE_supply_current_5;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineE_error_percentage_4;
    QLineEdit *lineE_error_value_4;
    QLineEdit *lineE_pres_val_2;
    QLineEdit *lineE_pres_val_3;
    QLineEdit *lineE_signal_current_3;
    QLineEdit *lineE_supply_current_1;
    QLineEdit *lineE_signal_voltage_3;
    QLineEdit *lineE_supply_voltage_1;
    QLineEdit *lineE_supply_current_2;
    QLineEdit *lineE_pres_val_5;
    QFrame *line;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_start_finish_mea;
    QPushButton *btn_ok;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_hydra_pre;
    QLineEdit *lineE_hydra_val;

    void setupUi(QWidget *showWin_pressureSensor)
    {
        if (showWin_pressureSensor->objectName().isEmpty())
            showWin_pressureSensor->setObjectName(QString::fromUtf8("showWin_pressureSensor"));
        showWin_pressureSensor->resize(1243, 987);
        gridLayout_2 = new QGridLayout(showWin_pressureSensor);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(showWin_pressureSensor);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout_6->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_bat = new QLabel(showWin_pressureSensor);
        label_bat->setObjectName(QString::fromUtf8("label_bat"));

        horizontalLayout_5->addWidget(label_bat);

        pBar_battery = new QProgressBar(showWin_pressureSensor);
        pBar_battery->setObjectName(QString::fromUtf8("pBar_battery"));
        pBar_battery->setValue(0);

        horizontalLayout_5->addWidget(pBar_battery);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_pre = new QLabel(showWin_pressureSensor);
        label_pre->setObjectName(QString::fromUtf8("label_pre"));
        label_pre->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(label_pre);

        plot_pressure = new QCustomPlot(showWin_pressureSensor);
        plot_pressure->setObjectName(QString::fromUtf8("plot_pressure"));
        plot_pressure->setMinimumSize(QSize(0, 200));

        verticalLayout_2->addWidget(plot_pressure);


        gridLayout_2->addLayout(verticalLayout_2, 1, 0, 1, 6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_err = new QLabel(showWin_pressureSensor);
        label_err->setObjectName(QString::fromUtf8("label_err"));
        label_err->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(label_err);

        plot_error = new QCustomPlot(showWin_pressureSensor);
        plot_error->setObjectName(QString::fromUtf8("plot_error"));
        plot_error->setMinimumSize(QSize(0, 200));

        verticalLayout_3->addWidget(plot_error);


        gridLayout_2->addLayout(verticalLayout_3, 2, 0, 1, 6);

        label_ch1 = new QLabel(showWin_pressureSensor);
        label_ch1->setObjectName(QString::fromUtf8("label_ch1"));

        gridLayout_2->addWidget(label_ch1, 3, 1, 1, 1);

        label_ch2 = new QLabel(showWin_pressureSensor);
        label_ch2->setObjectName(QString::fromUtf8("label_ch2"));

        gridLayout_2->addWidget(label_ch2, 3, 2, 1, 1);

        label_ch3 = new QLabel(showWin_pressureSensor);
        label_ch3->setObjectName(QString::fromUtf8("label_ch3"));

        gridLayout_2->addWidget(label_ch3, 3, 3, 1, 1);

        label_ch4 = new QLabel(showWin_pressureSensor);
        label_ch4->setObjectName(QString::fromUtf8("label_ch4"));

        gridLayout_2->addWidget(label_ch4, 3, 4, 1, 1);

        label_ch5 = new QLabel(showWin_pressureSensor);
        label_ch5->setObjectName(QString::fromUtf8("label_ch5"));

        gridLayout_2->addWidget(label_ch5, 3, 5, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_pre_ = new QLabel(showWin_pressureSensor);
        label_pre_->setObjectName(QString::fromUtf8("label_pre_"));

        verticalLayout_4->addWidget(label_pre_);

        label_sup_vol = new QLabel(showWin_pressureSensor);
        label_sup_vol->setObjectName(QString::fromUtf8("label_sup_vol"));

        verticalLayout_4->addWidget(label_sup_vol);

        label_sup_cur = new QLabel(showWin_pressureSensor);
        label_sup_cur->setObjectName(QString::fromUtf8("label_sup_cur"));

        verticalLayout_4->addWidget(label_sup_cur);

        label_sig_vol = new QLabel(showWin_pressureSensor);
        label_sig_vol->setObjectName(QString::fromUtf8("label_sig_vol"));

        verticalLayout_4->addWidget(label_sig_vol);

        label_sig_cur = new QLabel(showWin_pressureSensor);
        label_sig_cur->setObjectName(QString::fromUtf8("label_sig_cur"));

        verticalLayout_4->addWidget(label_sig_cur);

        label_err_ = new QLabel(showWin_pressureSensor);
        label_err_->setObjectName(QString::fromUtf8("label_err_"));

        verticalLayout_4->addWidget(label_err_);


        gridLayout_2->addLayout(verticalLayout_4, 4, 0, 2, 1);

        gridGroupBox = new QGroupBox(showWin_pressureSensor);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineE_signal_voltage_1 = new QLineEdit(gridGroupBox);
        lineE_signal_voltage_1->setObjectName(QString::fromUtf8("lineE_signal_voltage_1"));
        lineE_signal_voltage_1->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(lineE_signal_voltage_1, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineE_error_percentage_5 = new QLineEdit(gridGroupBox);
        lineE_error_percentage_5->setObjectName(QString::fromUtf8("lineE_error_percentage_5"));

        horizontalLayout_4->addWidget(lineE_error_percentage_5);

        lineE_error_value_5 = new QLineEdit(gridGroupBox);
        lineE_error_value_5->setObjectName(QString::fromUtf8("lineE_error_value_5"));

        horizontalLayout_4->addWidget(lineE_error_value_5);


        gridLayout->addLayout(horizontalLayout_4, 5, 5, 1, 1);

        lineE_supply_current_4 = new QLineEdit(gridGroupBox);
        lineE_supply_current_4->setObjectName(QString::fromUtf8("lineE_supply_current_4"));

        gridLayout->addWidget(lineE_supply_current_4, 2, 4, 1, 1);

        lineE_pres_val_4 = new QLineEdit(gridGroupBox);
        lineE_pres_val_4->setObjectName(QString::fromUtf8("lineE_pres_val_4"));

        gridLayout->addWidget(lineE_pres_val_4, 0, 4, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineE_error_percentage_2 = new QLineEdit(gridGroupBox);
        lineE_error_percentage_2->setObjectName(QString::fromUtf8("lineE_error_percentage_2"));

        horizontalLayout->addWidget(lineE_error_percentage_2);

        lineE_error_value_2 = new QLineEdit(gridGroupBox);
        lineE_error_value_2->setObjectName(QString::fromUtf8("lineE_error_value_2"));

        horizontalLayout->addWidget(lineE_error_value_2);


        gridLayout->addLayout(horizontalLayout, 5, 2, 1, 1);

        lineE_supply_voltage_4 = new QLineEdit(gridGroupBox);
        lineE_supply_voltage_4->setObjectName(QString::fromUtf8("lineE_supply_voltage_4"));

        gridLayout->addWidget(lineE_supply_voltage_4, 1, 4, 1, 1);

        lineE_signal_voltage_4 = new QLineEdit(gridGroupBox);
        lineE_signal_voltage_4->setObjectName(QString::fromUtf8("lineE_signal_voltage_4"));

        gridLayout->addWidget(lineE_signal_voltage_4, 3, 4, 1, 1);

        lineE_signal_current_5 = new QLineEdit(gridGroupBox);
        lineE_signal_current_5->setObjectName(QString::fromUtf8("lineE_signal_current_5"));

        gridLayout->addWidget(lineE_signal_current_5, 4, 5, 1, 1);

        lineE_supply_voltage_5 = new QLineEdit(gridGroupBox);
        lineE_supply_voltage_5->setObjectName(QString::fromUtf8("lineE_supply_voltage_5"));

        gridLayout->addWidget(lineE_supply_voltage_5, 1, 5, 1, 1);

        lineE_supply_voltage_3 = new QLineEdit(gridGroupBox);
        lineE_supply_voltage_3->setObjectName(QString::fromUtf8("lineE_supply_voltage_3"));

        gridLayout->addWidget(lineE_supply_voltage_3, 1, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineE_error_percentage_3 = new QLineEdit(gridGroupBox);
        lineE_error_percentage_3->setObjectName(QString::fromUtf8("lineE_error_percentage_3"));

        horizontalLayout_2->addWidget(lineE_error_percentage_3);

        lineE_error_value_3 = new QLineEdit(gridGroupBox);
        lineE_error_value_3->setObjectName(QString::fromUtf8("lineE_error_value_3"));

        horizontalLayout_2->addWidget(lineE_error_value_3);


        gridLayout->addLayout(horizontalLayout_2, 5, 3, 1, 1);

        lineE_signal_current_1 = new QLineEdit(gridGroupBox);
        lineE_signal_current_1->setObjectName(QString::fromUtf8("lineE_signal_current_1"));
        lineE_signal_current_1->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(lineE_signal_current_1, 4, 0, 1, 1);

        lineE_signal_current_2 = new QLineEdit(gridGroupBox);
        lineE_signal_current_2->setObjectName(QString::fromUtf8("lineE_signal_current_2"));

        gridLayout->addWidget(lineE_signal_current_2, 4, 2, 1, 1);

        lineE_signal_voltage_5 = new QLineEdit(gridGroupBox);
        lineE_signal_voltage_5->setObjectName(QString::fromUtf8("lineE_signal_voltage_5"));

        gridLayout->addWidget(lineE_signal_voltage_5, 3, 5, 1, 1);

        lineE_pres_val_1 = new QLineEdit(gridGroupBox);
        lineE_pres_val_1->setObjectName(QString::fromUtf8("lineE_pres_val_1"));
        lineE_pres_val_1->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(lineE_pres_val_1, 0, 0, 1, 1);

        lineE_supply_current_3 = new QLineEdit(gridGroupBox);
        lineE_supply_current_3->setObjectName(QString::fromUtf8("lineE_supply_current_3"));

        gridLayout->addWidget(lineE_supply_current_3, 2, 3, 1, 1);

        lineE_signal_current_4 = new QLineEdit(gridGroupBox);
        lineE_signal_current_4->setObjectName(QString::fromUtf8("lineE_signal_current_4"));

        gridLayout->addWidget(lineE_signal_current_4, 4, 4, 1, 1);

        lineE_supply_voltage_2 = new QLineEdit(gridGroupBox);
        lineE_supply_voltage_2->setObjectName(QString::fromUtf8("lineE_supply_voltage_2"));

        gridLayout->addWidget(lineE_supply_voltage_2, 1, 2, 1, 1);

        lineE_signal_voltage_2 = new QLineEdit(gridGroupBox);
        lineE_signal_voltage_2->setObjectName(QString::fromUtf8("lineE_signal_voltage_2"));

        gridLayout->addWidget(lineE_signal_voltage_2, 3, 2, 1, 1);

        lineE_supply_current_5 = new QLineEdit(gridGroupBox);
        lineE_supply_current_5->setObjectName(QString::fromUtf8("lineE_supply_current_5"));

        gridLayout->addWidget(lineE_supply_current_5, 2, 5, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineE_error_percentage_4 = new QLineEdit(gridGroupBox);
        lineE_error_percentage_4->setObjectName(QString::fromUtf8("lineE_error_percentage_4"));

        horizontalLayout_3->addWidget(lineE_error_percentage_4);

        lineE_error_value_4 = new QLineEdit(gridGroupBox);
        lineE_error_value_4->setObjectName(QString::fromUtf8("lineE_error_value_4"));

        horizontalLayout_3->addWidget(lineE_error_value_4);


        gridLayout->addLayout(horizontalLayout_3, 5, 4, 1, 1);

        lineE_pres_val_2 = new QLineEdit(gridGroupBox);
        lineE_pres_val_2->setObjectName(QString::fromUtf8("lineE_pres_val_2"));

        gridLayout->addWidget(lineE_pres_val_2, 0, 2, 1, 1);

        lineE_pres_val_3 = new QLineEdit(gridGroupBox);
        lineE_pres_val_3->setObjectName(QString::fromUtf8("lineE_pres_val_3"));

        gridLayout->addWidget(lineE_pres_val_3, 0, 3, 1, 1);

        lineE_signal_current_3 = new QLineEdit(gridGroupBox);
        lineE_signal_current_3->setObjectName(QString::fromUtf8("lineE_signal_current_3"));

        gridLayout->addWidget(lineE_signal_current_3, 4, 3, 1, 1);

        lineE_supply_current_1 = new QLineEdit(gridGroupBox);
        lineE_supply_current_1->setObjectName(QString::fromUtf8("lineE_supply_current_1"));
        lineE_supply_current_1->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(lineE_supply_current_1, 2, 0, 1, 1);

        lineE_signal_voltage_3 = new QLineEdit(gridGroupBox);
        lineE_signal_voltage_3->setObjectName(QString::fromUtf8("lineE_signal_voltage_3"));

        gridLayout->addWidget(lineE_signal_voltage_3, 3, 3, 1, 1);

        lineE_supply_voltage_1 = new QLineEdit(gridGroupBox);
        lineE_supply_voltage_1->setObjectName(QString::fromUtf8("lineE_supply_voltage_1"));
        lineE_supply_voltage_1->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(lineE_supply_voltage_1, 1, 0, 1, 1);

        lineE_supply_current_2 = new QLineEdit(gridGroupBox);
        lineE_supply_current_2->setObjectName(QString::fromUtf8("lineE_supply_current_2"));

        gridLayout->addWidget(lineE_supply_current_2, 2, 2, 1, 1);

        lineE_pres_val_5 = new QLineEdit(gridGroupBox);
        lineE_pres_val_5->setObjectName(QString::fromUtf8("lineE_pres_val_5"));

        gridLayout->addWidget(lineE_pres_val_5, 0, 5, 1, 1);

        line = new QFrame(gridGroupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 5, 1);


        gridLayout_2->addWidget(gridGroupBox, 4, 1, 2, 5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_start_finish_mea = new QPushButton(showWin_pressureSensor);
        btn_start_finish_mea->setObjectName(QString::fromUtf8("btn_start_finish_mea"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_start_finish_mea->sizePolicy().hasHeightForWidth());
        btn_start_finish_mea->setSizePolicy(sizePolicy);
        btn_start_finish_mea->setCheckable(true);

        verticalLayout->addWidget(btn_start_finish_mea);

        btn_ok = new QPushButton(showWin_pressureSensor);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(btn_ok);


        gridLayout_2->addLayout(verticalLayout, 5, 6, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_hydra_pre = new QLabel(showWin_pressureSensor);
        label_hydra_pre->setObjectName(QString::fromUtf8("label_hydra_pre"));
        label_hydra_pre->setMaximumSize(QSize(16777215, 50));

        verticalLayout_5->addWidget(label_hydra_pre);

        lineE_hydra_val = new QLineEdit(showWin_pressureSensor);
        lineE_hydra_val->setObjectName(QString::fromUtf8("lineE_hydra_val"));
        lineE_hydra_val->setMinimumSize(QSize(50, 100));

        verticalLayout_5->addWidget(lineE_hydra_val);


        gridLayout_2->addLayout(verticalLayout_5, 1, 6, 1, 1);


        retranslateUi(showWin_pressureSensor);

        QMetaObject::connectSlotsByName(showWin_pressureSensor);
    } // setupUi

    void retranslateUi(QWidget *showWin_pressureSensor)
    {
        showWin_pressureSensor->setWindowTitle(QCoreApplication::translate("showWin_pressureSensor", "\346\230\276\347\244\272_\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("showWin_pressureSensor", "\346\230\276\347\244\272\342\200\224\342\200\224\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250", nullptr));
        label_bat->setText(QCoreApplication::translate("showWin_pressureSensor", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\232", nullptr));
        label_pre->setText(QCoreApplication::translate("showWin_pressureSensor", "\345\216\213\345\212\233\357\274\232", nullptr));
        label_err->setText(QCoreApplication::translate("showWin_pressureSensor", "\350\257\257\345\267\256\357\274\232", nullptr));
        label_ch1->setText(QCoreApplication::translate("showWin_pressureSensor", "\351\200\232\351\201\2231(\346\240\207\345\207\206\344\274\240\346\204\237\345\231\250)", nullptr));
        label_ch2->setText(QCoreApplication::translate("showWin_pressureSensor", "\351\200\232\351\201\2232", nullptr));
        label_ch3->setText(QCoreApplication::translate("showWin_pressureSensor", "\351\200\232\351\201\2233", nullptr));
        label_ch4->setText(QCoreApplication::translate("showWin_pressureSensor", "\351\200\232\351\201\2234", nullptr));
        label_ch5->setText(QCoreApplication::translate("showWin_pressureSensor", "\351\200\232\351\201\2235", nullptr));
        label_pre_->setText(QCoreApplication::translate("showWin_pressureSensor", "\345\216\213\345\212\233\345\200\274\357\274\232", nullptr));
        label_sup_vol->setText(QCoreApplication::translate("showWin_pressureSensor", "\344\276\233\347\224\265\345\233\236\350\267\257\347\224\265\345\216\213\357\274\232", nullptr));
        label_sup_cur->setText(QCoreApplication::translate("showWin_pressureSensor", "\344\276\233\347\224\265\345\233\236\350\267\257\347\224\265\346\265\201\357\274\232", nullptr));
        label_sig_vol->setText(QCoreApplication::translate("showWin_pressureSensor", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\345\216\213\357\274\232", nullptr));
        label_sig_cur->setText(QCoreApplication::translate("showWin_pressureSensor", "\344\277\241\345\217\267\345\233\236\350\267\257\347\224\265\346\265\201\357\274\232", nullptr));
        label_err_->setText(QCoreApplication::translate("showWin_pressureSensor", "\350\257\257\345\267\256\357\274\232", nullptr));
        lineE_pres_val_4->setText(QCoreApplication::translate("showWin_pressureSensor", "50", nullptr));
        lineE_pres_val_1->setText(QCoreApplication::translate("showWin_pressureSensor", "20", nullptr));
        lineE_pres_val_2->setText(QCoreApplication::translate("showWin_pressureSensor", "30", nullptr));
        lineE_pres_val_3->setText(QCoreApplication::translate("showWin_pressureSensor", "40", nullptr));
        lineE_pres_val_5->setText(QCoreApplication::translate("showWin_pressureSensor", "60", nullptr));
        btn_start_finish_mea->setText(QCoreApplication::translate("showWin_pressureSensor", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
        btn_ok->setText(QCoreApplication::translate("showWin_pressureSensor", "\347\241\256\345\256\232", nullptr));
        label_hydra_pre->setText(QCoreApplication::translate("showWin_pressureSensor", "\346\266\262\345\216\213\347\253\231\345\216\213\345\212\233\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showWin_pressureSensor: public Ui_showWin_pressureSensor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWWIN_PRESSURESENSOR_H
