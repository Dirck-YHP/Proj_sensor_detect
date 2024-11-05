/********************************************************************************
** Form generated from reading UI file 'funcwin_dataexport.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCWIN_DATAEXPORT_H
#define UI_FUNCWIN_DATAEXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_funcWin_DataExport
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textE;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_choose;
    QPushButton *btn_send;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_back_mainW;
    QPushButton *btn_ok;

    void setupUi(QWidget *funcWin_DataExport)
    {
        if (funcWin_DataExport->objectName().isEmpty())
            funcWin_DataExport->setObjectName(QString::fromUtf8("funcWin_DataExport"));
        funcWin_DataExport->resize(569, 470);
        gridLayout = new QGridLayout(funcWin_DataExport);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(funcWin_DataExport);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(200, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        textE = new QTextEdit(funcWin_DataExport);
        textE->setObjectName(QString::fromUtf8("textE"));
        textE->setMinimumSize(QSize(0, 100));

        verticalLayout->addWidget(textE);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_choose = new QPushButton(funcWin_DataExport);
        btn_choose->setObjectName(QString::fromUtf8("btn_choose"));
        btn_choose->setMinimumSize(QSize(200, 100));
        QFont font1;
        font1.setPointSize(14);
        btn_choose->setFont(font1);

        horizontalLayout->addWidget(btn_choose);

        btn_send = new QPushButton(funcWin_DataExport);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        btn_send->setMinimumSize(QSize(200, 100));
        btn_send->setFont(font1);

        horizontalLayout->addWidget(btn_send);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_back_mainW = new QPushButton(funcWin_DataExport);
        btn_back_mainW->setObjectName(QString::fromUtf8("btn_back_mainW"));
        btn_back_mainW->setMinimumSize(QSize(200, 100));
        btn_back_mainW->setFont(font1);

        horizontalLayout_2->addWidget(btn_back_mainW);

        btn_ok = new QPushButton(funcWin_DataExport);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setMinimumSize(QSize(200, 100));
        btn_ok->setFont(font1);

        horizontalLayout_2->addWidget(btn_ok);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(funcWin_DataExport);

        QMetaObject::connectSlotsByName(funcWin_DataExport);
    } // setupUi

    void retranslateUi(QWidget *funcWin_DataExport)
    {
        funcWin_DataExport->setWindowTitle(QCoreApplication::translate("funcWin_DataExport", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("funcWin_DataExport", "\346\234\215\345\212\241\345\231\250", nullptr));
        btn_choose->setText(QCoreApplication::translate("funcWin_DataExport", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        btn_send->setText(QCoreApplication::translate("funcWin_DataExport", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        btn_back_mainW->setText(QCoreApplication::translate("funcWin_DataExport", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        btn_ok->setText(QCoreApplication::translate("funcWin_DataExport", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class funcWin_DataExport: public Ui_funcWin_DataExport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCWIN_DATAEXPORT_H
