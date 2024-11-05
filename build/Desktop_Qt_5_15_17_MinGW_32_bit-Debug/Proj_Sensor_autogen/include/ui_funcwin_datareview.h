/********************************************************************************
** Form generated from reading UI file 'funcwin_datareview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCWIN_DATAREVIEW_H
#define UI_FUNCWIN_DATAREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_funcWin_DataReview
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineE_labels;
    QCustomPlot *custom_plot;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_choose_file;
    QPushButton *btn_ok;

    void setupUi(QWidget *funcWin_DataReview)
    {
        if (funcWin_DataReview->objectName().isEmpty())
            funcWin_DataReview->setObjectName(QString::fromUtf8("funcWin_DataReview"));
        funcWin_DataReview->resize(760, 630);
        gridLayout = new QGridLayout(funcWin_DataReview);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(funcWin_DataReview);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineE_labels = new QLineEdit(funcWin_DataReview);
        lineE_labels->setObjectName(QString::fromUtf8("lineE_labels"));
        lineE_labels->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(lineE_labels, 1, 0, 1, 1);

        custom_plot = new QCustomPlot(funcWin_DataReview);
        custom_plot->setObjectName(QString::fromUtf8("custom_plot"));

        gridLayout->addWidget(custom_plot, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_choose_file = new QPushButton(funcWin_DataReview);
        btn_choose_file->setObjectName(QString::fromUtf8("btn_choose_file"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_choose_file->sizePolicy().hasHeightForWidth());
        btn_choose_file->setSizePolicy(sizePolicy);
        btn_choose_file->setMaximumSize(QSize(16777215, 150));

        horizontalLayout->addWidget(btn_choose_file);

        btn_ok = new QPushButton(funcWin_DataReview);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        sizePolicy.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy);
        btn_ok->setMaximumSize(QSize(16777215, 150));

        horizontalLayout->addWidget(btn_ok);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(funcWin_DataReview);

        QMetaObject::connectSlotsByName(funcWin_DataReview);
    } // setupUi

    void retranslateUi(QWidget *funcWin_DataReview)
    {
        funcWin_DataReview->setWindowTitle(QCoreApplication::translate("funcWin_DataReview", "\346\225\260\346\215\256\345\244\215\347\216\260", nullptr));
        label_2->setText(QCoreApplication::translate("funcWin_DataReview", "\346\240\207\347\255\276\357\274\232", nullptr));
        btn_choose_file->setText(QCoreApplication::translate("funcWin_DataReview", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        btn_ok->setText(QCoreApplication::translate("funcWin_DataReview", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class funcWin_DataReview: public Ui_funcWin_DataReview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCWIN_DATAREVIEW_H
