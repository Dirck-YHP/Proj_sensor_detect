/********************************************************************************
** Form generated from reading UI file 'paramwin_proximityswitch.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMWIN_PROXIMITYSWITCH_H
#define UI_PARAMWIN_PROXIMITYSWITCH_H

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

class Ui_paramWin_proximitySwitch
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_sensor_type;
    QComboBox *cBox_prox_switch_type;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_using_time;
    QComboBox *cBox_use_time;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_sensing_dis;
    QComboBox *cBox_distance;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_matirial;
    QComboBox *cBox_material;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_load_data;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *cBox_file_save;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_file_name;
    QLineEdit *lineE_file_name;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_channel;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_ch_1;
    QCheckBox *checkBox_ch_4;
    QCheckBox *checkBox_ch_2;
    QCheckBox *checkBox_ch_3;
    QCheckBox *checkBox_ch_5;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_back_mainW;
    QPushButton *btn_ok;
    QPushButton *btn_exit;

    void setupUi(QWidget *paramWin_proximitySwitch)
    {
        if (paramWin_proximitySwitch->objectName().isEmpty())
            paramWin_proximitySwitch->setObjectName(QString::fromUtf8("paramWin_proximitySwitch"));
        paramWin_proximitySwitch->resize(678, 549);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(paramWin_proximitySwitch->sizePolicy().hasHeightForWidth());
        paramWin_proximitySwitch->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(paramWin_proximitySwitch);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label = new QLabel(paramWin_proximitySwitch);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(2000, 50));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label);

        line_3 = new QFrame(paramWin_proximitySwitch);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_sensor_type = new QLabel(paramWin_proximitySwitch);
        label_sensor_type->setObjectName(QString::fromUtf8("label_sensor_type"));

        verticalLayout_2->addWidget(label_sensor_type);

        cBox_prox_switch_type = new QComboBox(paramWin_proximitySwitch);
        cBox_prox_switch_type->addItem(QString());
        cBox_prox_switch_type->addItem(QString());
        cBox_prox_switch_type->setObjectName(QString::fromUtf8("cBox_prox_switch_type"));
        cBox_prox_switch_type->setMinimumSize(QSize(150, 50));

        verticalLayout_2->addWidget(cBox_prox_switch_type);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_using_time = new QLabel(paramWin_proximitySwitch);
        label_using_time->setObjectName(QString::fromUtf8("label_using_time"));

        verticalLayout_5->addWidget(label_using_time);

        cBox_use_time = new QComboBox(paramWin_proximitySwitch);
        cBox_use_time->addItem(QString());
        cBox_use_time->addItem(QString());
        cBox_use_time->setObjectName(QString::fromUtf8("cBox_use_time"));
        cBox_use_time->setMinimumSize(QSize(150, 50));

        verticalLayout_5->addWidget(cBox_use_time);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_sensing_dis = new QLabel(paramWin_proximitySwitch);
        label_sensing_dis->setObjectName(QString::fromUtf8("label_sensing_dis"));

        verticalLayout_3->addWidget(label_sensing_dis);

        cBox_distance = new QComboBox(paramWin_proximitySwitch);
        cBox_distance->addItem(QString());
        cBox_distance->addItem(QString());
        cBox_distance->setObjectName(QString::fromUtf8("cBox_distance"));
        cBox_distance->setMinimumSize(QSize(150, 50));

        verticalLayout_3->addWidget(cBox_distance);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_matirial = new QLabel(paramWin_proximitySwitch);
        label_matirial->setObjectName(QString::fromUtf8("label_matirial"));

        verticalLayout_4->addWidget(label_matirial);

        cBox_material = new QComboBox(paramWin_proximitySwitch);
        cBox_material->addItem(QString());
        cBox_material->addItem(QString());
        cBox_material->setObjectName(QString::fromUtf8("cBox_material"));
        cBox_material->setMinimumSize(QSize(150, 50));

        verticalLayout_4->addWidget(cBox_material);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_6);

        line = new QFrame(paramWin_proximitySwitch);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btn_load_data = new QPushButton(paramWin_proximitySwitch);
        btn_load_data->setObjectName(QString::fromUtf8("btn_load_data"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_load_data->sizePolicy().hasHeightForWidth());
        btn_load_data->setSizePolicy(sizePolicy1);
        btn_load_data->setMinimumSize(QSize(170, 60));

        horizontalLayout_4->addWidget(btn_load_data);


        verticalLayout_7->addLayout(horizontalLayout_4);

        line_4 = new QFrame(paramWin_proximitySwitch);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        cBox_file_save = new QCheckBox(paramWin_proximitySwitch);
        cBox_file_save->setObjectName(QString::fromUtf8("cBox_file_save"));
        sizePolicy1.setHeightForWidth(cBox_file_save->sizePolicy().hasHeightForWidth());
        cBox_file_save->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(cBox_file_save);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_file_name = new QLabel(paramWin_proximitySwitch);
        label_file_name->setObjectName(QString::fromUtf8("label_file_name"));

        horizontalLayout_5->addWidget(label_file_name);

        lineE_file_name = new QLineEdit(paramWin_proximitySwitch);
        lineE_file_name->setObjectName(QString::fromUtf8("lineE_file_name"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineE_file_name->sizePolicy().hasHeightForWidth());
        lineE_file_name->setSizePolicy(sizePolicy2);
        lineE_file_name->setMaximumSize(QSize(16777215, 77777));

        horizontalLayout_5->addWidget(lineE_file_name);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_6);

        line_5 = new QFrame(paramWin_proximitySwitch);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_channel = new QLabel(paramWin_proximitySwitch);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));
        label_channel->setMinimumSize(QSize(100, 30));
        label_channel->setMaximumSize(QSize(200, 77777));

        verticalLayout->addWidget(label_channel);

        gridGroupBox = new QGroupBox(paramWin_proximitySwitch);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        checkBox_ch_1 = new QCheckBox(gridGroupBox);
        checkBox_ch_1->setObjectName(QString::fromUtf8("checkBox_ch_1"));
        sizePolicy1.setHeightForWidth(checkBox_ch_1->sizePolicy().hasHeightForWidth());
        checkBox_ch_1->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(checkBox_ch_1, 0, 0, 1, 1);

        checkBox_ch_4 = new QCheckBox(gridGroupBox);
        checkBox_ch_4->setObjectName(QString::fromUtf8("checkBox_ch_4"));
        sizePolicy1.setHeightForWidth(checkBox_ch_4->sizePolicy().hasHeightForWidth());
        checkBox_ch_4->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(checkBox_ch_4, 0, 3, 1, 1);

        checkBox_ch_2 = new QCheckBox(gridGroupBox);
        checkBox_ch_2->setObjectName(QString::fromUtf8("checkBox_ch_2"));
        sizePolicy1.setHeightForWidth(checkBox_ch_2->sizePolicy().hasHeightForWidth());
        checkBox_ch_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(checkBox_ch_2, 0, 1, 1, 1);

        checkBox_ch_3 = new QCheckBox(gridGroupBox);
        checkBox_ch_3->setObjectName(QString::fromUtf8("checkBox_ch_3"));
        sizePolicy1.setHeightForWidth(checkBox_ch_3->sizePolicy().hasHeightForWidth());
        checkBox_ch_3->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(checkBox_ch_3, 0, 2, 1, 1);

        checkBox_ch_5 = new QCheckBox(gridGroupBox);
        checkBox_ch_5->setObjectName(QString::fromUtf8("checkBox_ch_5"));
        sizePolicy1.setHeightForWidth(checkBox_ch_5->sizePolicy().hasHeightForWidth());
        checkBox_ch_5->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(checkBox_ch_5, 0, 4, 1, 1);


        verticalLayout->addWidget(gridGroupBox);


        verticalLayout_7->addLayout(verticalLayout);

        line_2 = new QFrame(paramWin_proximitySwitch);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        sizePolicy1.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy1);
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_back_mainW = new QPushButton(paramWin_proximitySwitch);
        btn_back_mainW->setObjectName(QString::fromUtf8("btn_back_mainW"));
        sizePolicy1.setHeightForWidth(btn_back_mainW->sizePolicy().hasHeightForWidth());
        btn_back_mainW->setSizePolicy(sizePolicy1);
        btn_back_mainW->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_back_mainW);

        btn_ok = new QPushButton(paramWin_proximitySwitch);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy1.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy1);
        btn_ok->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_ok);

        btn_exit = new QPushButton(paramWin_proximitySwitch);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        sizePolicy1.setHeightForWidth(btn_exit->sizePolicy().hasHeightForWidth());
        btn_exit->setSizePolicy(sizePolicy1);
        btn_exit->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_exit);


        verticalLayout_7->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);


        retranslateUi(paramWin_proximitySwitch);

        QMetaObject::connectSlotsByName(paramWin_proximitySwitch);
    } // setupUi

    void retranslateUi(QWidget *paramWin_proximitySwitch)
    {
        paramWin_proximitySwitch->setWindowTitle(QCoreApplication::translate("paramWin_proximitySwitch", "\345\217\202\346\225\260\350\256\276\347\275\256_\346\216\245\350\277\221\345\274\200\345\205\263", nullptr));
        label->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\345\217\202\346\225\260\350\256\276\347\275\256\342\200\224\342\200\224\346\216\245\350\277\221\345\274\200\345\205\263", nullptr));
        label_sensor_type->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213", nullptr));
        cBox_prox_switch_type->setItemText(0, QCoreApplication::translate("paramWin_proximitySwitch", "test1", nullptr));
        cBox_prox_switch_type->setItemText(1, QCoreApplication::translate("paramWin_proximitySwitch", "test2", nullptr));

        label_using_time->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\350\243\205\346\234\272\346\227\266\351\227\264", nullptr));
        cBox_use_time->setItemText(0, QCoreApplication::translate("paramWin_proximitySwitch", "test1", nullptr));
        cBox_use_time->setItemText(1, QCoreApplication::translate("paramWin_proximitySwitch", "test2", nullptr));

        label_sensing_dis->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\346\204\237\345\272\224\350\267\235\347\246\273", nullptr));
        cBox_distance->setItemText(0, QCoreApplication::translate("paramWin_proximitySwitch", "test1", nullptr));
        cBox_distance->setItemText(1, QCoreApplication::translate("paramWin_proximitySwitch", "test2", nullptr));

        label_matirial->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\346\204\237\345\272\224\346\235\220\346\226\231", nullptr));
        cBox_material->setItemText(0, QCoreApplication::translate("paramWin_proximitySwitch", "test1", nullptr));
        cBox_material->setItemText(1, QCoreApplication::translate("paramWin_proximitySwitch", "test2", nullptr));

        btn_load_data->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\345\257\274\345\205\245\345\216\206\345\217\262\346\225\260\346\215\256", nullptr));
        cBox_file_save->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\346\226\207\344\273\266\344\277\235\345\255\230", nullptr));
        label_file_name->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label_channel->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\351\200\232\351\201\223\351\200\211\346\213\251", nullptr));
        checkBox_ch_1->setText(QCoreApplication::translate("paramWin_proximitySwitch", "1", nullptr));
        checkBox_ch_4->setText(QCoreApplication::translate("paramWin_proximitySwitch", "4", nullptr));
        checkBox_ch_2->setText(QCoreApplication::translate("paramWin_proximitySwitch", "2", nullptr));
        checkBox_ch_3->setText(QCoreApplication::translate("paramWin_proximitySwitch", "3", nullptr));
        checkBox_ch_5->setText(QCoreApplication::translate("paramWin_proximitySwitch", "5", nullptr));
        btn_back_mainW->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        btn_ok->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\347\241\256\345\256\232", nullptr));
        btn_exit->setText(QCoreApplication::translate("paramWin_proximitySwitch", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paramWin_proximitySwitch: public Ui_paramWin_proximitySwitch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWIN_PROXIMITYSWITCH_H
