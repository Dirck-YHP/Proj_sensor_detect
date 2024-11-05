/********************************************************************************
** Form generated from reading UI file 'paramwin_angleencoder.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMWIN_ANGLEENCODER_H
#define UI_PARAMWIN_ANGLEENCODER_H

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

class Ui_paramWin_angleEncoder
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_sensor_type;
    QComboBox *cBox_angle_sensor_type;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_pul_per_cir;
    QLineEdit *lineE_pulse_per_cir;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_3;
    QPushButton *btn_load_data;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *cBox_file_save;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_file_name;
    QLineEdit *lineE_file_name;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_no_need_device;
    QSpacerItem *horizontalSpacer;
    QLabel *label_motor;
    QLineEdit *lineE_target_angle;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_motor_spd;
    QLineEdit *lineE_motor_spd;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_back_mainW;
    QPushButton *btn_ok;
    QPushButton *btn_exit;

    void setupUi(QWidget *paramWin_angleEncoder)
    {
        if (paramWin_angleEncoder->objectName().isEmpty())
            paramWin_angleEncoder->setObjectName(QString::fromUtf8("paramWin_angleEncoder"));
        paramWin_angleEncoder->resize(943, 498);
        gridLayout = new QGridLayout(paramWin_angleEncoder);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label = new QLabel(paramWin_angleEncoder);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(8989888, 300));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label);

        line_5 = new QFrame(paramWin_angleEncoder);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_sensor_type = new QLabel(paramWin_angleEncoder);
        label_sensor_type->setObjectName(QString::fromUtf8("label_sensor_type"));
        label_sensor_type->setMinimumSize(QSize(0, 40));
        label_sensor_type->setMaximumSize(QSize(16777215, 7777));

        verticalLayout->addWidget(label_sensor_type);

        cBox_angle_sensor_type = new QComboBox(paramWin_angleEncoder);
        cBox_angle_sensor_type->addItem(QString());
        cBox_angle_sensor_type->addItem(QString());
        cBox_angle_sensor_type->setObjectName(QString::fromUtf8("cBox_angle_sensor_type"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cBox_angle_sensor_type->sizePolicy().hasHeightForWidth());
        cBox_angle_sensor_type->setSizePolicy(sizePolicy);
        cBox_angle_sensor_type->setMinimumSize(QSize(300, 50));
        cBox_angle_sensor_type->setMaximumSize(QSize(7777, 80));
        QFont font1;
        font1.setPointSize(12);
        cBox_angle_sensor_type->setFont(font1);

        verticalLayout->addWidget(cBox_angle_sensor_type);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_pul_per_cir = new QLabel(paramWin_angleEncoder);
        label_pul_per_cir->setObjectName(QString::fromUtf8("label_pul_per_cir"));
        label_pul_per_cir->setMinimumSize(QSize(300, 40));
        label_pul_per_cir->setMaximumSize(QSize(400, 7777));

        verticalLayout_2->addWidget(label_pul_per_cir);

        lineE_pulse_per_cir = new QLineEdit(paramWin_angleEncoder);
        lineE_pulse_per_cir->setObjectName(QString::fromUtf8("lineE_pulse_per_cir"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineE_pulse_per_cir->sizePolicy().hasHeightForWidth());
        lineE_pulse_per_cir->setSizePolicy(sizePolicy1);
        lineE_pulse_per_cir->setMinimumSize(QSize(200, 50));
        lineE_pulse_per_cir->setMaximumSize(QSize(7777, 80));

        verticalLayout_2->addWidget(lineE_pulse_per_cir);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        line_3 = new QFrame(paramWin_angleEncoder);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        btn_load_data = new QPushButton(paramWin_angleEncoder);
        btn_load_data->setObjectName(QString::fromUtf8("btn_load_data"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_load_data->sizePolicy().hasHeightForWidth());
        btn_load_data->setSizePolicy(sizePolicy2);
        btn_load_data->setMinimumSize(QSize(200, 60));
        btn_load_data->setMaximumSize(QSize(77777, 16777215));

        horizontalLayout_3->addWidget(btn_load_data);


        verticalLayout_4->addLayout(horizontalLayout_3);

        line_2 = new QFrame(paramWin_angleEncoder);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        cBox_file_save = new QCheckBox(paramWin_angleEncoder);
        cBox_file_save->setObjectName(QString::fromUtf8("cBox_file_save"));
        sizePolicy2.setHeightForWidth(cBox_file_save->sizePolicy().hasHeightForWidth());
        cBox_file_save->setSizePolicy(sizePolicy2);
        cBox_file_save->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        cBox_file_save->setFont(font2);

        verticalLayout_5->addWidget(cBox_file_save);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_file_name = new QLabel(paramWin_angleEncoder);
        label_file_name->setObjectName(QString::fromUtf8("label_file_name"));

        horizontalLayout_6->addWidget(label_file_name);

        lineE_file_name = new QLineEdit(paramWin_angleEncoder);
        lineE_file_name->setObjectName(QString::fromUtf8("lineE_file_name"));
        sizePolicy1.setHeightForWidth(lineE_file_name->sizePolicy().hasHeightForWidth());
        lineE_file_name->setSizePolicy(sizePolicy1);
        lineE_file_name->setMinimumSize(QSize(200, 0));
        lineE_file_name->setMaximumSize(QSize(16777215, 80));

        horizontalLayout_6->addWidget(lineE_file_name);


        horizontalLayout_4->addLayout(horizontalLayout_6);

        line = new QFrame(paramWin_angleEncoder);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBox_no_need_device = new QCheckBox(paramWin_angleEncoder);
        checkBox_no_need_device->setObjectName(QString::fromUtf8("checkBox_no_need_device"));
        sizePolicy.setHeightForWidth(checkBox_no_need_device->sizePolicy().hasHeightForWidth());
        checkBox_no_need_device->setSizePolicy(sizePolicy);
        checkBox_no_need_device->setMinimumSize(QSize(0, 50));
        checkBox_no_need_device->setFont(font1);

        horizontalLayout_2->addWidget(checkBox_no_need_device);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_motor = new QLabel(paramWin_angleEncoder);
        label_motor->setObjectName(QString::fromUtf8("label_motor"));
        label_motor->setMinimumSize(QSize(0, 40));

        horizontalLayout_2->addWidget(label_motor);

        lineE_target_angle = new QLineEdit(paramWin_angleEncoder);
        lineE_target_angle->setObjectName(QString::fromUtf8("lineE_target_angle"));
        sizePolicy1.setHeightForWidth(lineE_target_angle->sizePolicy().hasHeightForWidth());
        lineE_target_angle->setSizePolicy(sizePolicy1);
        lineE_target_angle->setMinimumSize(QSize(150, 50));
        lineE_target_angle->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_2->addWidget(lineE_target_angle);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        label_motor_spd = new QLabel(paramWin_angleEncoder);
        label_motor_spd->setObjectName(QString::fromUtf8("label_motor_spd"));
        label_motor_spd->setMinimumSize(QSize(0, 40));

        horizontalLayout_5->addWidget(label_motor_spd);

        lineE_motor_spd = new QLineEdit(paramWin_angleEncoder);
        lineE_motor_spd->setObjectName(QString::fromUtf8("lineE_motor_spd"));
        sizePolicy1.setHeightForWidth(lineE_motor_spd->sizePolicy().hasHeightForWidth());
        lineE_motor_spd->setSizePolicy(sizePolicy1);
        lineE_motor_spd->setMinimumSize(QSize(150, 50));
        lineE_motor_spd->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(lineE_motor_spd);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_4);

        line_4 = new QFrame(paramWin_angleEncoder);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_back_mainW = new QPushButton(paramWin_angleEncoder);
        btn_back_mainW->setObjectName(QString::fromUtf8("btn_back_mainW"));
        sizePolicy2.setHeightForWidth(btn_back_mainW->sizePolicy().hasHeightForWidth());
        btn_back_mainW->setSizePolicy(sizePolicy2);
        btn_back_mainW->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_back_mainW);

        btn_ok = new QPushButton(paramWin_angleEncoder);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy2.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy2);
        btn_ok->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_ok);

        btn_exit = new QPushButton(paramWin_angleEncoder);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        sizePolicy2.setHeightForWidth(btn_exit->sizePolicy().hasHeightForWidth());
        btn_exit->setSizePolicy(sizePolicy2);
        btn_exit->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_exit);


        verticalLayout_4->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(paramWin_angleEncoder);

        QMetaObject::connectSlotsByName(paramWin_angleEncoder);
    } // setupUi

    void retranslateUi(QWidget *paramWin_angleEncoder)
    {
        paramWin_angleEncoder->setWindowTitle(QCoreApplication::translate("paramWin_angleEncoder", "\345\217\202\346\225\260\350\256\276\347\275\256_\350\247\222\344\275\215\347\247\273\347\274\226\347\240\201\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("paramWin_angleEncoder", "\345\217\202\346\225\260\350\256\276\347\275\256\342\200\224\342\200\224\350\247\222\344\275\215\347\247\273\347\274\226\347\240\201\345\231\250", nullptr));
        label_sensor_type->setText(QCoreApplication::translate("paramWin_angleEncoder", "\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213", nullptr));
        cBox_angle_sensor_type->setItemText(0, QCoreApplication::translate("paramWin_angleEncoder", "test1", nullptr));
        cBox_angle_sensor_type->setItemText(1, QCoreApplication::translate("paramWin_angleEncoder", "test2", nullptr));

        label_pul_per_cir->setText(QCoreApplication::translate("paramWin_angleEncoder", "\347\274\226\347\240\201\345\231\250\346\257\217\345\234\210\350\204\211\345\206\262\346\225\260\357\274\232", nullptr));
        lineE_pulse_per_cir->setText(QCoreApplication::translate("paramWin_angleEncoder", "500", nullptr));
        btn_load_data->setText(QCoreApplication::translate("paramWin_angleEncoder", "\345\257\274\345\205\245\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        cBox_file_save->setText(QCoreApplication::translate("paramWin_angleEncoder", "\346\226\207\344\273\266\344\277\235\345\255\230", nullptr));
        label_file_name->setText(QCoreApplication::translate("paramWin_angleEncoder", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        checkBox_no_need_device->setText(QCoreApplication::translate("paramWin_angleEncoder", "\344\270\215\351\234\200\350\246\201\345\267\245\350\243\205\350\256\276\345\244\207", nullptr));
        label_motor->setText(QCoreApplication::translate("paramWin_angleEncoder", "\347\224\265\346\234\272\347\233\256\346\240\207\350\275\254\345\212\250\345\234\210\346\225\260\357\274\232", nullptr));
        lineE_target_angle->setText(QCoreApplication::translate("paramWin_angleEncoder", "3", nullptr));
        label_motor_spd->setText(QCoreApplication::translate("paramWin_angleEncoder", "\347\224\265\346\234\272\350\275\254\345\212\250\351\200\237\345\272\246\357\274\210\350\204\211\345\206\262\357\274\211\357\274\232", nullptr));
        lineE_motor_spd->setText(QCoreApplication::translate("paramWin_angleEncoder", "19200", nullptr));
        btn_back_mainW->setText(QCoreApplication::translate("paramWin_angleEncoder", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        btn_ok->setText(QCoreApplication::translate("paramWin_angleEncoder", "\347\241\256\345\256\232", nullptr));
        btn_exit->setText(QCoreApplication::translate("paramWin_angleEncoder", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paramWin_angleEncoder: public Ui_paramWin_angleEncoder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWIN_ANGLEENCODER_H
