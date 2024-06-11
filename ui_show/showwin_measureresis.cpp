#include "showwin_measureresis.h"
#include "ui_showwin_measureresis.h"

showWin_measureResis::showWin_measureResis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showWin_measureResis)
{
    ui->setupUi(this);
}

showWin_measureResis::~showWin_measureResis()
{
    delete ui;
}

void showWin_measureResis::on_btn_ok_clicked()
{
    this->close();
}
