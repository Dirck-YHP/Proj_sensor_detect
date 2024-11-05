/********************************************************************************
** Form generated from reading UI file 'paramwin_mea_resis.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMWIN_MEA_RESIS_H
#define UI_PARAMWIN_MEA_RESIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paramWin_mea_resis
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_channel;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout;
    QCheckBox *checkBox_ch_5;
    QCheckBox *checkBox_ch_2;
    QCheckBox *checkBox_ch_3;
    QCheckBox *checkBox_ch_4;
    QCheckBox *checkBox_ch_1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_back_mainW;
    QPushButton *btn_ok;
    QPushButton *btn_exit;
    QFrame *line;
    QFrame *line_2;

    void setupUi(QWidget *paramWin_mea_resis)
    {
        if (paramWin_mea_resis->objectName().isEmpty())
            paramWin_mea_resis->setObjectName(QString::fromUtf8("paramWin_mea_resis"));
        paramWin_mea_resis->resize(990, 598);
        gridLayout_2 = new QGridLayout(paramWin_mea_resis);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(paramWin_mea_resis);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 60));
        label->setMaximumSize(QSize(77777, 80));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_channel = new QLabel(paramWin_mea_resis);
        label_channel->setObjectName(QString::fromUtf8("label_channel"));
        label_channel->setMinimumSize(QSize(100, 30));
        label_channel->setMaximumSize(QSize(200, 7777));

        verticalLayout->addWidget(label_channel);

        gridGroupBox = new QGroupBox(paramWin_mea_resis);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridLayout = new QGridLayout(gridGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        checkBox_ch_5 = new QCheckBox(gridGroupBox);
        checkBox_ch_5->setObjectName(QString::fromUtf8("checkBox_ch_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox_ch_5->sizePolicy().hasHeightForWidth());
        checkBox_ch_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(checkBox_ch_5, 0, 4, 1, 1);

        checkBox_ch_2 = new QCheckBox(gridGroupBox);
        checkBox_ch_2->setObjectName(QString::fromUtf8("checkBox_ch_2"));
        sizePolicy.setHeightForWidth(checkBox_ch_2->sizePolicy().hasHeightForWidth());
        checkBox_ch_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(checkBox_ch_2, 0, 1, 1, 1);

        checkBox_ch_3 = new QCheckBox(gridGroupBox);
        checkBox_ch_3->setObjectName(QString::fromUtf8("checkBox_ch_3"));
        sizePolicy.setHeightForWidth(checkBox_ch_3->sizePolicy().hasHeightForWidth());
        checkBox_ch_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(checkBox_ch_3, 0, 2, 1, 1);

        checkBox_ch_4 = new QCheckBox(gridGroupBox);
        checkBox_ch_4->setObjectName(QString::fromUtf8("checkBox_ch_4"));
        sizePolicy.setHeightForWidth(checkBox_ch_4->sizePolicy().hasHeightForWidth());
        checkBox_ch_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(checkBox_ch_4, 0, 3, 1, 1);

        checkBox_ch_1 = new QCheckBox(gridGroupBox);
        checkBox_ch_1->setObjectName(QString::fromUtf8("checkBox_ch_1"));
        sizePolicy.setHeightForWidth(checkBox_ch_1->sizePolicy().hasHeightForWidth());
        checkBox_ch_1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(checkBox_ch_1, 0, 0, 1, 1);


        verticalLayout->addWidget(gridGroupBox);


        gridLayout_2->addLayout(verticalLayout, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_back_mainW = new QPushButton(paramWin_mea_resis);
        btn_back_mainW->setObjectName(QString::fromUtf8("btn_back_mainW"));
        sizePolicy.setHeightForWidth(btn_back_mainW->sizePolicy().hasHeightForWidth());
        btn_back_mainW->setSizePolicy(sizePolicy);
        btn_back_mainW->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_back_mainW);

        btn_ok = new QPushButton(paramWin_mea_resis);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy);
        btn_ok->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_ok);

        btn_exit = new QPushButton(paramWin_mea_resis);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        sizePolicy.setHeightForWidth(btn_exit->sizePolicy().hasHeightForWidth());
        btn_exit->setSizePolicy(sizePolicy);
        btn_exit->setMinimumSize(QSize(200, 100));

        horizontalLayout->addWidget(btn_exit);


        gridLayout_2->addLayout(horizontalLayout, 4, 0, 1, 1);

        line = new QFrame(paramWin_mea_resis);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 3, 0, 1, 1);

        line_2 = new QFrame(paramWin_mea_resis);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setStyleSheet(QString::fromUtf8("background-color: rgb\357\274\210255,255,255\357\274\211"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 1, 0, 1, 1);


        retranslateUi(paramWin_mea_resis);

        QMetaObject::connectSlotsByName(paramWin_mea_resis);
    } // setupUi

    void retranslateUi(QWidget *paramWin_mea_resis)
    {
        paramWin_mea_resis->setWindowTitle(QCoreApplication::translate("paramWin_mea_resis", "\345\217\202\346\225\260\350\256\276\347\275\256_\347\224\265\351\230\273", nullptr));
        label->setText(QCoreApplication::translate("paramWin_mea_resis", "\345\217\202\346\225\260\350\256\276\347\275\256\342\200\224\342\200\224\347\224\265\351\230\273", nullptr));
        label_channel->setText(QCoreApplication::translate("paramWin_mea_resis", "\351\200\232\351\201\223\351\200\211\346\213\251", nullptr));
        checkBox_ch_5->setText(QCoreApplication::translate("paramWin_mea_resis", "\351\200\232\351\201\2235", nullptr));
        checkBox_ch_2->setText(QCoreApplication::translate("paramWin_mea_resis", "\351\200\232\351\201\2232", nullptr));
        checkBox_ch_3->setText(QCoreApplication::translate("paramWin_mea_resis", "\351\200\232\351\201\2233", nullptr));
        checkBox_ch_4->setText(QCoreApplication::translate("paramWin_mea_resis", "\351\200\232\351\201\2234", nullptr));
        checkBox_ch_1->setText(QCoreApplication::translate("paramWin_mea_resis", "\351\200\232\351\201\2231", nullptr));
        btn_back_mainW->setText(QCoreApplication::translate("paramWin_mea_resis", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        btn_ok->setText(QCoreApplication::translate("paramWin_mea_resis", "\347\241\256\345\256\232", nullptr));
        btn_exit->setText(QCoreApplication::translate("paramWin_mea_resis", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paramWin_mea_resis: public Ui_paramWin_mea_resis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMWIN_MEA_RESIS_H
