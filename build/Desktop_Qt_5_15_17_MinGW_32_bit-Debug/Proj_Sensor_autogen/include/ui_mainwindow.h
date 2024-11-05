/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *cbox_choose_sensor;
    QPushButton *btn_data_export;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_start;
    QPushButton *btn_exit;

    void setupUi(QWidget *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(886, 502);
        gridLayout = new QGridLayout(mainWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(mainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 100));
        label->setMaximumSize(QSize(16777215, 300));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbox_choose_sensor = new QComboBox(mainWindow);
        cbox_choose_sensor->addItem(QString());
        cbox_choose_sensor->addItem(QString());
        cbox_choose_sensor->addItem(QString());
        cbox_choose_sensor->addItem(QString());
        cbox_choose_sensor->addItem(QString());
        cbox_choose_sensor->setObjectName(QString::fromUtf8("cbox_choose_sensor"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbox_choose_sensor->sizePolicy().hasHeightForWidth());
        cbox_choose_sensor->setSizePolicy(sizePolicy);
        cbox_choose_sensor->setMinimumSize(QSize(200, 100));
        cbox_choose_sensor->setFont(font);
        cbox_choose_sensor->setEditable(false);

        horizontalLayout->addWidget(cbox_choose_sensor);

        btn_data_export = new QPushButton(mainWindow);
        btn_data_export->setObjectName(QString::fromUtf8("btn_data_export"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_data_export->sizePolicy().hasHeightForWidth());
        btn_data_export->setSizePolicy(sizePolicy1);
        btn_data_export->setMinimumSize(QSize(200, 100));
        btn_data_export->setFont(font);

        horizontalLayout->addWidget(btn_data_export);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_start = new QPushButton(mainWindow);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        sizePolicy1.setHeightForWidth(btn_start->sizePolicy().hasHeightForWidth());
        btn_start->setSizePolicy(sizePolicy1);
        btn_start->setMinimumSize(QSize(200, 100));
        btn_start->setFont(font);

        horizontalLayout_2->addWidget(btn_start);

        btn_exit = new QPushButton(mainWindow);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        sizePolicy1.setHeightForWidth(btn_exit->sizePolicy().hasHeightForWidth());
        btn_exit->setSizePolicy(sizePolicy1);
        btn_exit->setMinimumSize(QSize(200, 100));
        btn_exit->setFont(font);

        horizontalLayout_2->addWidget(btn_exit);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QWidget *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "\344\270\273\347\225\214\351\235\242", nullptr));
        label->setText(QCoreApplication::translate("mainWindow", "\344\276\277\346\220\272\345\274\217\346\240\241\351\252\214\347\263\273\347\273\237", nullptr));
        cbox_choose_sensor->setItemText(0, QCoreApplication::translate("mainWindow", "\350\247\222\344\275\215\347\247\273\347\274\226\347\240\201\345\231\250", nullptr));
        cbox_choose_sensor->setItemText(1, QCoreApplication::translate("mainWindow", "\350\247\222\344\275\215\347\247\273\344\274\240\346\204\237\345\231\250", nullptr));
        cbox_choose_sensor->setItemText(2, QCoreApplication::translate("mainWindow", "\346\216\245\350\277\221\345\274\200\345\205\263", nullptr));
        cbox_choose_sensor->setItemText(3, QCoreApplication::translate("mainWindow", "\345\216\213\345\212\233\344\274\240\346\204\237\345\231\250", nullptr));
        cbox_choose_sensor->setItemText(4, QCoreApplication::translate("mainWindow", "\347\224\265\351\230\273", nullptr));

        btn_data_export->setText(QCoreApplication::translate("mainWindow", "\346\225\260\346\215\256\345\257\274\345\207\272", nullptr));
        btn_start->setText(QCoreApplication::translate("mainWindow", "\345\274\200\345\247\213", nullptr));
        btn_exit->setText(QCoreApplication::translate("mainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
