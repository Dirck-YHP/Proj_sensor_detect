#include "funcwin_errorprompt.h"
#include "ui_funcwin_errorprompt.h"

funcwin_errorprompt::funcwin_errorprompt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::funcwin_errorprompt)
{
    ui->setupUi(this);
}

funcwin_errorprompt::~funcwin_errorprompt()
{
    delete ui;
}
