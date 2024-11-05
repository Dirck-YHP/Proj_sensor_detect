/********************************************************************************
** Form generated from reading UI file 'paramwin_anglesensor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMWIN_ANGLESENSOR_H
#define UI_PARAMWIN_ANGLESENSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paramWin_angleSensor
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_sensor_type;
    QComboBox *cBox_angle_sensor_type;
    QFrame *line_7;
    QVBoxLayout *verticalLayout;
    QLabel *label_range;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4mA;
    QLineEdit *lineE_4mA;
    QLabel *label_20mA;
    QLineEdit *lineE_20mA;
    QFrame *line_5;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_6;
    QPushButton *btn_load_data;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *cBox_file_save;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_file_name;
    QLineEdit *lineE_file_name;
    QSpacerItem *horizontalSpacer;
    QFrame *line_4;
    QCheckBox *checkBox_no_need_device;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_motor;
    QLineEdit *lineE_target_angle;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_motor_spd;
    QLineEdit *lineE_motor_spd;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_back_mainW;
    QPushButton *btn_ok;
    QPushButton *btn_exit;

    void setupUi(QWidget *paramWin_angleSensor)
    {
        if (paramWin_angleSensor->objectName().isEmpty())
            paramWin_angleSensor->setObjectName(QString::fromUtf8("paramWin_angleSensor"));
        paramWin_angleSensor->resize(965, 642);
        gridLayout = new QGridLayout(paramWin_angleSensor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(paramWin_angleSensor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(777777, 300));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);

        line_3 = new QFrame(paramWin_angleSensor);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_sensor_type = new QLabel(paramWin_angleSensor);
        label_sensor_type->setObjectName(QString::fromUtf8("label_sensor_type"));
        label_sensor_type->setMinimumSize(QSize(0, 40));
        label_sensor_type->setMaximumSize(QSize(16777215, 80));

        verticalLayout_2->addWidget(label_sensor_type);

        cBox_angle_sensor_type = new QComboBox(paramWin_angleSensor);
        cBox_angle_sensor_type->addItem(QString());
        cBox_angle_sensor_type->addItem(QString());
        cBox_angle_sensor_type->setObjectName(QString::fromUtf8("cBox_angle_sensor_type"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cBox_angle_sensor_type->sizePolicy().hasHeightForWidth());
        cBox_angle_sensor_type->setSizePolicy(sizePolicy);
        cBox_angle_sensor_type->setMinimumSize(QSize(200, 50));

        verticalLayout_2->addWidget(cBox_angle_sensor_type);


        horizontalLayout_6->addLayout(verticalLayout_2);

        line_7 = new QFrame(paramWin_angleSensor);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_range = new QLabel(paramWin_angleSensor);
        label_range->setObjectName(QString::fromUtf8("label_range"));
        label_range->setMinimumSize(QSize(0, 40));
        label_range->setMaximumSize(QSize(16777215, 80));

        verticalLayout->addWidget(label_range);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4mA = new QLabel(paramWin_angleSensor);
        label_4mA->setObjectName(QString::fromUtf8("label_4mA"));
        label_4mA->setFont(font);

        horizontalLayout_4->addWidget(label_4mA);

        lineE_4mA = new QLineEdit(paramWin_angleSensor);
        lineE_4mA->setObjectName(QString::fromUtf8("lineE_4mA"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineE_4mA->sizePolicy().hasHeightForWidth());
        lineE_4mA->setSizePolicy(sizePolicy1);
        lineE_4mA->setMinimumSize(QSize(150, 50));
        lineE_4mA->setMaximumSize(QSize(77777, 16777215));

        horizontalLayout_4->addWidget(lineE_4mA);

        label_20mA = new QLabel(paramWin_angleSensor);
        label_20mA->setObjectName(QString::fromUtf8("label_20mA"));
        label_20mA->setFont(font);

        horizontalLayout_4->addWidget(label_20mA);

        lineE_20mA = new QLineEdit(paramWin_angleSensor);
        lineE_20mA->setObjectName(QString::fromUtf8("lineE_20mA"));
        sizePolicy1.setHeightForWidth(lineE_20mA->sizePolicy().hasHeightForWidth());
        lineE_20mA->setSizePolicy(sizePolicy1);
        lineE_20mA->setMinimumSize(QSize(150, 50));
        lineE_20mA->setMaximumSize(QSize(77777, 16777215));

        horizontalLayout_4->addWidget(lineE_20mA);

        line_5 = new QFrame(paramWin_angleSensor);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_5);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_6->addLayout(verticalLayout);

        line_6 = new QFrame(paramWin_angleSensor);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_6);

        btn_load_data = new QPushButton(paramWin_angleSensor);
        btn_load_data->setObjectName(QString::fromUtf8("btn_load_data"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_load_data->sizePolicy().hasHeightForWidth());
        btn_load_data->setSizePolicy(sizePolicy2);
        btn_load_data->setMinimumSize(QSize(170, 60));
        btn_load_data->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_6->addWidget(btn_load_data);


        verticalLayout_5->addLayout(horizontalLayout_6);

        line_2 = new QFrame(paramWin_angleSensor);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cBox_file_save = new QCheckBox(paramWin_angleSensor);
        cBox_file_save->setObjectName(QString::fromUtf8("cBox_file_save"));
        sizePolicy2.setHeightForWidth(cBox_file_save->sizePolicy().hasHeightForWidth());
        cBox_file_save->setSizePolicy(sizePolicy2);
        cBox_file_save->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(cBox_file_save);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_file_name = new QLabel(paramWin_angleSensor);
        label_file_name->setObjectName(QString::fromUtf8("label_file_name"));

        horizontalLayout_7->addWidget(label_file_name);

        lineE_file_name = new QLineEdit(paramWin_angleSensor);
        lineE_file_name->setObjectName(QString::fromUtf8("lineE_file_name"));
        sizePolicy1.setHeightForWidth(lineE_file_name->sizePolicy().hasHeightForWidth());
        lineE_file_name->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineE_file_name);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        line_4 = new QFrame(paramWin_angleSensor);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        checkBox_no_need_device = new QCheckBox(paramWin_angleSensor);
        checkBox_no_need_device->setObjectName(QString::fromUtf8("checkBox_no_need_device"));
        sizePolicy2.setHeightForWidth(checkBox_no_need_device->sizePolicy().hasHeightForWidth());
        checkBox_no_need_device->setSizePolicy(sizePolicy2);
        checkBox_no_need_device->setMinimumSize(QSize(0, 50));

        horizontalLayout_3->addWidget(checkBox_no_need_device);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_motor = new QLabel(paramWin_angleSensor);
        label_motor->setObjectName(QString::fromUtf8("label_motor"));

        horizontalLayout_9->addWidget(label_motor);

        lineE_target_angle = new QLineEdit(paramWin_angleSensor);
        lineE_target_angle->setObjectName(QString::fromUtf8("lineE_target_angle"));
        sizePolicy1.setHeightForWidth(lineE_target_angle->sizePolicy().hasHeightForWidth());
        lineE_target_angle->setSizePolicy(sizePolicy1);
        lineE_target_angle->setMinimumSize(QSize(150, 50));

        horizontalLayout_9->addWidget(lineE_target_angle);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_motor_spd = new QLabel(paramWin_angleSensor);
        label_motor_spd->setObjectName(QString::fromUtf8("label_motor_spd"));
        label_motor_spd->setMinimumSize(QSize(0, 40));

        horizontalLayout_8->addWidget(label_motor_spd);

        lineE_motor_spd = new QLineEdit(paramWin_angleSensor);
        lineE_motor_spd->setObjectName(QString::fromUtf8("lineE_motor_spd"));
        sizePolicy1.setHeightForWidth(lineE_motor_spd->sizePolicy().hasHeightForWidth());
        lineE_motor_spd->setSizePolicy(sizePolicy1);
        lineE_motor_spd->setMinimumSize(QSize(150, 50));
        lineE_motor_spd->setMaximumSize(QSize(7777, 16777215));

        horizontalLayout_8->addWidget(lineE_motor_spd);


        verticalLayout_4->addLayout(horizontalLayout_8);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        line = new QFrame(paramWin_angleSensor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_back_mainW = new QPushButton(paramWin_angleSensor);
        btn_back_mainW->setObjectName(QString::fromUtf8("btn_back_mainW"));
        sizePolicy2.setHeightForWidth(btn_back_mainW->sizePolicy().hasHeightForWidth());
        btn_back_mainW->setSizePolicy(sizePolicy2);
        btn_back_mainW->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_back_mainW);

        btn_ok = new QPushButton(paramWin_angleSensor);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy2.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy2);
        btn_ok->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_ok);

        btn_exit = new QPushButton(paramWin_angleSensor);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        sizePolicy2.setHeightForWidth(btn_exit->sizePolicy().hasHeightForWidth());
        btn_exit->setSizePolicy(sizePolicy2);
        btn_exit->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_exit);


        verticalLayout_5->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);


        retranslateUi(paramWin_angleSensor);

        QMetaObject::connectSlotsByName(paramWin_angleSensor);
    } // setupUi

    void retranslateUi(QWidget *paramWin_angleSensor)
    {
        paramWin_angleSensor->setWindowTitle(QCoreApplication::translate("paramWin_angleSensor", "\345\217\202\346\225\260\350\256\276\347\275\256_\350\247\222\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("paramWin_angleSensor", "\345\217\202\346\225\260\350\256\276\347\275\256\342\200\224\342\200\224\350\247\222\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", nullptr));
        label_sensor_type->setText(QCoreApplication::translate("paramWin_angleSensor", "\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213", nullptr));
        cBox_angle_sensor_type->setItemText(0, QCoreApplication::translate("paramWin_angleSensor", "test1", nullptr));
        cBox_angle_sensor_type->setItemText(1, QCoreApplication::translate("paramWin_angleSensor", "test2", nullptr));

        label_range->setText(QCoreApplication::translate("paramWin_angleSensor", "\344\274\240\346\204\237\345\231\250\351\207\217\347\250\213\357\274\2104mA\345\222\21420mA\345\257\271\345\272\224\347\232\204\350\247\222\345\272\246\357\274\211", nullptr));
        label_4mA->setText(QCoreApplication::translate("paramWin_angleSensor", "4mA\357\274\232", nullptr));
        label_20mA->setText(QCoreApplication::translate("paramWin_angleSensor", "20mA\357\274\232", nullptr));
        btn_load_data->setText(QCoreApplication::translate("paramWin_angleSensor", "\345\257\274\345\205\245\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        cBox_file_save->setText(QCoreApplication::translate("paramWin_angleSensor", "\346\226\207\344\273\266\344\277\235\345\255\230", nullptr));
        label_file_name->setText(QCoreApplication::translate("paramWin_angleSensor", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        checkBox_no_need_device->setText(QCoreApplication::translate("paramWin_angleSensor", "\344\270\215\351\234\200\350\246\201\345\267\245\350\243\205\350\256\276\345\244\207", nullptr));
        label_motor->setText(QCoreApplication::translate("paramWin_angleSensor", "\347\224\265\346\234\272\347\233\256\346\240\207\350\247\222\345\272\246\357\274\232", nullptr));
        lineE_target_angle->setText(QCoreApplication::translate("paramWin_angleSensor", "3", nullptr));
        label_motor_spd->setText(QCoreApplication::translate("paramWin_angleSensor", "\347\224\265\346\234\272\350\275\254\345\212\250\351\200\237\345\272\246\357\274\232", nullptr));
        lineE_motor_spd->setText(QCoreApplication::translate("paramWin_angleSensor", "19200", nullptr));
        btn_back_mainW->setText(QCoreApplication::translate("paramWin_angleSensor", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        btn_ok->setText(QCoreApplication::translate("paramWin_angleSensor", "\347\241\256\345\256\232", nullptr));
        btn_exit->setText(QCoreApplication::translate("paramWin_angleSensor", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paramWin_angleSensor: public Ui_paramWin_angleSensor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWIN_ANGLESENSOR_H
