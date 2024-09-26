#ifndef FUNCWIN_ERRORPROMPT_H
#define FUNCWIN_ERRORPROMPT_H

#include <QWidget>

namespace Ui {
class funcwin_errorprompt;
}

class funcwin_errorprompt : public QWidget
{
    Q_OBJECT

public:
    explicit funcwin_errorprompt(QWidget *parent = nullptr);
    ~funcwin_errorprompt();

private:
    Ui::funcwin_errorprompt *ui;
};

#endif // FUNCWIN_ERRORPROMPT_H
