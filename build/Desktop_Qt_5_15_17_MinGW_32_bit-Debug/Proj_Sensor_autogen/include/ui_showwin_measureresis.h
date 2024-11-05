/********************************************************************************
** Form generated from reading UI file 'showwin_measureresis.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWWIN_MEASURERESIS_H
#define UI_SHOWWIN_MEASURERESIS_H

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

QT_BEGIN_NAMESPACE

class Ui_showWin_measureResis
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_bat;
    QProgressBar *pBar_battery;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_resis;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_ch1;
    QLineEdit *lineE_show_resis_1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_ch2;
    QLineEdit *lineE_show_resis_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_ch3;
    QLineEdit *lineE_show_resis_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_ch4;
    QLineEdit *lineE_show_resis_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_ch5;
    QLineEdit *lineE_show_resis_5;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_start_finish_mea;
    QPushButton *btn_ok;

    void setupUi(QWidget *showWin_measureResis)
    {
        if (showWin_measureResis->objectName().isEmpty())
            showWin_measureResis->setObjectName(QString::fromUtf8("showWin_measureResis"));
        showWin_measureResis->resize(886, 570);
        gridLayout = new QGridLayout(showWin_measureResis);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(showWin_measureResis);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_bat = new QLabel(showWin_measureResis);
        label_bat->setObjectName(QString::fromUtf8("label_bat"));

        horizontalLayout_2->addWidget(label_bat);

        pBar_battery = new QProgressBar(showWin_measureResis);
        pBar_battery->setObjectName(QString::fromUtf8("pBar_battery"));
        pBar_battery->setValue(0);

        horizontalLayout_2->addWidget(pBar_battery);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(horizontalLayout_3);

        line_2 = new QFrame(showWin_measureResis);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_resis = new QLabel(showWin_measureResis);
        label_resis->setObjectName(QString::fromUtf8("label_resis"));

        horizontalLayout_4->addWidget(label_resis);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_ch1 = new QLabel(showWin_measureResis);
        label_ch1->setObjectName(QString::fromUtf8("label_ch1"));
        label_ch1->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(label_ch1);

        lineE_show_resis_1 = new QLineEdit(showWin_measureResis);
        lineE_show_resis_1->setObjectName(QString::fromUtf8("lineE_show_resis_1"));
        lineE_show_resis_1->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(lineE_show_resis_1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_ch2 = new QLabel(showWin_measureResis);
        label_ch2->setObjectName(QString::fromUtf8("label_ch2"));
        label_ch2->setMaximumSize(QSize(16777215, 50));

        verticalLayout_2->addWidget(label_ch2);

        lineE_show_resis_2 = new QLineEdit(showWin_measureResis);
        lineE_show_resis_2->setObjectName(QString::fromUtf8("lineE_show_resis_2"));
        lineE_show_resis_2->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(lineE_show_resis_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_ch3 = new QLabel(showWin_measureResis);
        label_ch3->setObjectName(QString::fromUtf8("label_ch3"));
        label_ch3->setMaximumSize(QSize(16777215, 50));

        verticalLayout_3->addWidget(label_ch3);

        lineE_show_resis_3 = new QLineEdit(showWin_measureResis);
        lineE_show_resis_3->setObjectName(QString::fromUtf8("lineE_show_resis_3"));
        lineE_show_resis_3->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(lineE_show_resis_3);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_ch4 = new QLabel(showWin_measureResis);
        label_ch4->setObjectName(QString::fromUtf8("label_ch4"));
        label_ch4->setMaximumSize(QSize(16777215, 50));

        verticalLayout_4->addWidget(label_ch4);

        lineE_show_resis_4 = new QLineEdit(showWin_measureResis);
        lineE_show_resis_4->setObjectName(QString::fromUtf8("lineE_show_resis_4"));
        lineE_show_resis_4->setMinimumSize(QSize(0, 50));

        verticalLayout_4->addWidget(lineE_show_resis_4);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_ch5 = new QLabel(showWin_measureResis);
        label_ch5->setObjectName(QString::fromUtf8("label_ch5"));
        label_ch5->setMaximumSize(QSize(16777215, 50));

        verticalLayout_5->addWidget(label_ch5);

        lineE_show_resis_5 = new QLineEdit(showWin_measureResis);
        lineE_show_resis_5->setObjectName(QString::fromUtf8("lineE_show_resis_5"));
        lineE_show_resis_5->setMinimumSize(QSize(0, 50));

        verticalLayout_5->addWidget(lineE_show_resis_5);


        horizontalLayout->addLayout(verticalLayout_5);


        horizontalLayout_4->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(horizontalLayout_4);

        line = new QFrame(showWin_measureResis);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btn_start_finish_mea = new QPushButton(showWin_measureResis);
        btn_start_finish_mea->setObjectName(QString::fromUtf8("btn_start_finish_mea"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_start_finish_mea->sizePolicy().hasHeightForWidth());
        btn_start_finish_mea->setSizePolicy(sizePolicy);
        btn_start_finish_mea->setMaximumSize(QSize(16777215, 150));
        btn_start_finish_mea->setCheckable(true);

        horizontalLayout_5->addWidget(btn_start_finish_mea);

        btn_ok = new QPushButton(showWin_measureResis);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy);
        btn_ok->setMaximumSize(QSize(16777215, 150));

        horizontalLayout_5->addWidget(btn_ok);


        verticalLayout_6->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_6, 0, 0, 1, 1);


        retranslateUi(showWin_measureResis);

        QMetaObject::connectSlotsByName(showWin_measureResis);
    } // setupUi

    void retranslateUi(QWidget *showWin_measureResis)
    {
        showWin_measureResis->setWindowTitle(QCoreApplication::translate("showWin_measureResis", "\346\230\276\347\244\272_\347\224\265\351\230\273", nullptr));
        label->setText(QCoreApplication::translate("showWin_measureResis", "\346\230\276\347\244\272\342\200\224\342\200\224\347\224\265\351\230\273", nullptr));
        label_bat->setText(QCoreApplication::translate("showWin_measureResis", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\232", nullptr));
        label_resis->setText(QCoreApplication::translate("showWin_measureResis", " \347\224\265\351\230\273\345\200\274\357\274\232", nullptr));
        label_ch1->setText(QCoreApplication::translate("showWin_measureResis", "\351\200\232\351\201\2231", nullptr));
        label_ch2->setText(QCoreApplication::translate("showWin_measureResis", "\351\200\232\351\201\2232", nullptr));
        label_ch3->setText(QCoreApplication::translate("showWin_measureResis", "\351\200\232\351\201\2233", nullptr));
        label_ch4->setText(QCoreApplication::translate("showWin_measureResis", "\351\200\232\351\201\2234", nullptr));
        label_ch5->setText(QCoreApplication::translate("showWin_measureResis", "\351\200\232\351\201\2235", nullptr));
        btn_start_finish_mea->setText(QCoreApplication::translate("showWin_measureResis", "\345\274\200\345\247\213\346\265\213\351\207\217", nullptr));
        btn_ok->setText(QCoreApplication::translate("showWin_measureResis", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class showWin_measureResis: public Ui_showWin_measureResis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWWIN_MEASURERESIS_H
