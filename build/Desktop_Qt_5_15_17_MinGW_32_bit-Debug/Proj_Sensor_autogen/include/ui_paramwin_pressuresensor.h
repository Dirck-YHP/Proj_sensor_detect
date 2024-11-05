/********************************************************************************
** Form generated from reading UI file 'paramwin_pressuresensor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMWIN_PRESSURESENSOR_H
#define UI_PARAMWIN_PRESSURESENSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paramWin_pressureSensor
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_sensor_type;
    QComboBox *cBox_pressure_sensor_type;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_load_data;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_range;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_20mA;
    QLineEdit *lineE_20mA;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *cBox_file_save;
    QLabel *label_file_name;
    QLineEdit *lineE_file_name;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_channel;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_ch_4;
    QCheckBox *checkBox_ch_2;
    QCheckBox *checkBox_ch_5;
    QCheckBox *checkBox_ch_3;
    QCheckBox *checkBox_ch_1;
    QFrame *line_6;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_back_mainW;
    QPushButton *btn_ok;
    QPushButton *btn_exit;

    void setupUi(QWidget *paramWin_pressureSensor)
    {
        if (paramWin_pressureSensor->objectName().isEmpty())
            paramWin_pressureSensor->setObjectName(QString::fromUtf8("paramWin_pressureSensor"));
        paramWin_pressureSensor->resize(946, 686);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(paramWin_pressureSensor->sizePolicy().hasHeightForWidth());
        paramWin_pressureSensor->setSizePolicy(sizePolicy);
        paramWin_pressureSensor->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(paramWin_pressureSensor);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(paramWin_pressureSensor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(2000, 50));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        line_5 = new QFrame(paramWin_pressureSensor);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_sensor_type = new QLabel(paramWin_pressureSensor);
        label_sensor_type->setObjectName(QString::fromUtf8("label_sensor_type"));

        verticalLayout_2->addWidget(label_sensor_type);

        cBox_pressure_sensor_type = new QComboBox(paramWin_pressureSensor);
        cBox_pressure_sensor_type->addItem(QString());
        cBox_pressure_sensor_type->addItem(QString());
        cBox_pressure_sensor_type->setObjectName(QString::fromUtf8("cBox_pressure_sensor_type"));
        sizePolicy.setHeightForWidth(cBox_pressure_sensor_type->sizePolicy().hasHeightForWidth());
        cBox_pressure_sensor_type->setSizePolicy(sizePolicy);
        cBox_pressure_sensor_type->setMinimumSize(QSize(150, 50));

        verticalLayout_2->addWidget(cBox_pressure_sensor_type);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_load_data = new QPushButton(paramWin_pressureSensor);
        btn_load_data->setObjectName(QString::fromUtf8("btn_load_data"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_load_data->sizePolicy().hasHeightForWidth());
        btn_load_data->setSizePolicy(sizePolicy1);
        btn_load_data->setMinimumSize(QSize(170, 60));

        horizontalLayout_2->addWidget(btn_load_data);


        verticalLayout_3->addLayout(horizontalLayout_2);

        line_4 = new QFrame(paramWin_pressureSensor);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_range = new QLabel(paramWin_pressureSensor);
        label_range->setObjectName(QString::fromUtf8("label_range"));
        label_range->setMinimumSize(QSize(0, 40));
        label_range->setMaximumSize(QSize(16777215, 7777));

        verticalLayout_5->addWidget(label_range);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_20mA = new QLabel(paramWin_pressureSensor);
        label_20mA->setObjectName(QString::fromUtf8("label_20mA"));
        label_20mA->setFont(font);

        horizontalLayout_3->addWidget(label_20mA);

        lineE_20mA = new QLineEdit(paramWin_pressureSensor);
        lineE_20mA->setObjectName(QString::fromUtf8("lineE_20mA"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineE_20mA->sizePolicy().hasHeightForWidth());
        lineE_20mA->setSizePolicy(sizePolicy2);
        lineE_20mA->setMinimumSize(QSize(149, 50));
        lineE_20mA->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_3->addWidget(lineE_20mA);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_5);

        line_3 = new QFrame(paramWin_pressureSensor);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        cBox_file_save = new QCheckBox(paramWin_pressureSensor);
        cBox_file_save->setObjectName(QString::fromUtf8("cBox_file_save"));
        sizePolicy1.setHeightForWidth(cBox_file_save->sizePolicy().hasHeightForWidth());
        cBox_file_save->setSizePolicy(sizePolicy1);
        cBox_file_save->setMinimumSize(QSize(0, 60));

        horizontalLayout_4->addWidget(cBox_file_save);

        label_file_name = new QLabel(paramWin_pressureSensor);
        label_file_name->setObjectName(QString::fromUtf8("label_file_name"));

        horizontalLayout_4->addWidget(label_file_name);

        lineE_file_name = new QLineEdit(paramWin_pressureSensor);
        lineE_file_name->setObjectName(QString::fromUtf8("lineE_file_name"));
        sizePolicy2.setHeightForWidth(lineE_file_name->sizePolicy().hasHeightForWidth());
        lineE_file_name->setSizePolicy(sizePolicy2);
        lineE_file_name->setMaximumSize(QSize(16777215, 7777));

        horizontalLayout_4->addWidget(lineE_file_name);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        line_2 = new QFrame(paramWin_pressureSensor);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_channel = new QLabel(paramWin_pressureSensor);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));
        label_channel->setMinimumSize(QSize(100, 30));
        label_channel->setMaximumSize(QSize(200, 7777));

        verticalLayout->addWidget(label_channel);

        gridGroupBox = new QGroupBox(paramWin_pressureSensor);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridGroupBox->setMinimumSize(QSize(0, 70));
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox_ch_4 = new QCheckBox(gridGroupBox);
        checkBox_ch_4->setObjectName(QString::fromUtf8("checkBox_ch_4"));
        sizePolicy1.setHeightForWidth(checkBox_ch_4->sizePolicy().hasHeightForWidth());
        checkBox_ch_4->setSizePolicy(sizePolicy1);
        checkBox_ch_4->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(checkBox_ch_4, 0, 4, 1, 1);

        checkBox_ch_2 = new QCheckBox(gridGroupBox);
        checkBox_ch_2->setObjectName(QString::fromUtf8("checkBox_ch_2"));
        sizePolicy1.setHeightForWidth(checkBox_ch_2->sizePolicy().hasHeightForWidth());
        checkBox_ch_2->setSizePolicy(sizePolicy1);
        checkBox_ch_2->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(checkBox_ch_2, 0, 2, 1, 1);

        checkBox_ch_5 = new QCheckBox(gridGroupBox);
        checkBox_ch_5->setObjectName(QString::fromUtf8("checkBox_ch_5"));
        sizePolicy1.setHeightForWidth(checkBox_ch_5->sizePolicy().hasHeightForWidth());
        checkBox_ch_5->setSizePolicy(sizePolicy1);
        checkBox_ch_5->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(checkBox_ch_5, 0, 5, 1, 1);

        checkBox_ch_3 = new QCheckBox(gridGroupBox);
        checkBox_ch_3->setObjectName(QString::fromUtf8("checkBox_ch_3"));
        sizePolicy1.setHeightForWidth(checkBox_ch_3->sizePolicy().hasHeightForWidth());
        checkBox_ch_3->setSizePolicy(sizePolicy1);
        checkBox_ch_3->setMinimumSize(QSize(80, 0));

        gridLayout->addWidget(checkBox_ch_3, 0, 3, 1, 1);

        checkBox_ch_1 = new QCheckBox(gridGroupBox);
        checkBox_ch_1->setObjectName(QString::fromUtf8("checkBox_ch_1"));
        sizePolicy1.setHeightForWidth(checkBox_ch_1->sizePolicy().hasHeightForWidth());
        checkBox_ch_1->setSizePolicy(sizePolicy1);
        checkBox_ch_1->setMinimumSize(QSize(100, 0));
        checkBox_ch_1->setChecked(true);
        checkBox_ch_1->setTristate(false);

        gridLayout->addWidget(checkBox_ch_1, 0, 0, 1, 1);

        line_6 = new QFrame(gridGroupBox);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 0, 1, 1, 1);


        verticalLayout->addWidget(gridGroupBox);


        verticalLayout_3->addLayout(verticalLayout);

        line = new QFrame(paramWin_pressureSensor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_back_mainW = new QPushButton(paramWin_pressureSensor);
        btn_back_mainW->setObjectName(QString::fromUtf8("btn_back_mainW"));
        sizePolicy1.setHeightForWidth(btn_back_mainW->sizePolicy().hasHeightForWidth());
        btn_back_mainW->setSizePolicy(sizePolicy1);
        btn_back_mainW->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_back_mainW);

        btn_ok = new QPushButton(paramWin_pressureSensor);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy1.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy1);
        btn_ok->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_ok);

        btn_exit = new QPushButton(paramWin_pressureSensor);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        sizePolicy1.setHeightForWidth(btn_exit->sizePolicy().hasHeightForWidth());
        btn_exit->setSizePolicy(sizePolicy1);
        btn_exit->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_exit);


        verticalLayout_3->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);


        retranslateUi(paramWin_pressureSensor);

        QMetaObject::connectSlotsByName(paramWin_pressureSensor);
    } // setupUi

    void retranslateUi(QWidget *paramWin_pressureSensor)
    {
        paramWin_pressureSensor->setWindowTitle(QCoreApplication::translate("paramWin_pressureSensor", "\345\217\202\346\225\260\350\256\276\347\275\256_\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("paramWin_pressureSensor", "\345\217\202\346\225\260\350\256\276\347\275\256\342\200\224\342\200\224\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250", nullptr));
        label_sensor_type->setText(QCoreApplication::translate("paramWin_pressureSensor", "\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213", nullptr));
        cBox_pressure_sensor_type->setItemText(0, QCoreApplication::translate("paramWin_pressureSensor", "test1", nullptr));
        cBox_pressure_sensor_type->setItemText(1, QCoreApplication::translate("paramWin_pressureSensor", "test2", nullptr));

        btn_load_data->setText(QCoreApplication::translate("paramWin_pressureSensor", "\345\257\274\345\205\245\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        label_range->setText(QCoreApplication::translate("paramWin_pressureSensor", "\344\274\240\346\204\237\345\231\250\351\207\217\347\250\213\357\274\21020mA\345\257\271\345\272\224\347\232\204\345\216\213\345\212\233\345\200\274\357\274\211", nullptr));
        label_20mA->setText(QCoreApplication::translate("paramWin_pressureSensor", "\351\207\217\347\250\213(Bar)\357\274\232", nullptr));
        cBox_file_save->setText(QCoreApplication::translate("paramWin_pressureSensor", "\346\226\207\344\273\266\344\277\235\345\255\230", nullptr));
        label_file_name->setText(QCoreApplication::translate("paramWin_pressureSensor", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label_channel->setText(QCoreApplication::translate("paramWin_pressureSensor", "\350\267\257\346\225\260\351\200\211\346\213\251", nullptr));
        checkBox_ch_4->setText(QCoreApplication::translate("paramWin_pressureSensor", "4", nullptr));
        checkBox_ch_2->setText(QCoreApplication::translate("paramWin_pressureSensor", "2", nullptr));
        checkBox_ch_5->setText(QCoreApplication::translate("paramWin_pressureSensor", "5", nullptr));
        checkBox_ch_3->setText(QCoreApplication::translate("paramWin_pressureSensor", "3", nullptr));
        checkBox_ch_1->setText(QCoreApplication::translate("paramWin_pressureSensor", "1", nullptr));
        btn_back_mainW->setText(QCoreApplication::translate("paramWin_pressureSensor", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        btn_ok->setText(QCoreApplication::translate("paramWin_pressureSensor", "\347\241\256\345\256\232", nullptr));
        btn_exit->setText(QCoreApplication::translate("paramWin_pressureSensor", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paramWin_pressureSensor: public Ui_paramWin_pressureSensor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWIN_PRESSURESENSOR_H
