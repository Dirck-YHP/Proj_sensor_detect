#ifndef SHOWWIN_ANGLEENCODER_H
#define SHOWWIN_ANGLEENCODER_H

#include <QWidget>

namespace Ui {
class showWin_angleEncoder;
}

class showWin_angleEncoder : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_angleEncoder(QWidget *parent = nullptr);
    ~showWin_angleEncoder();

private:
    Ui::showWin_angleEncoder *ui;
};

#endif // SHOWWIN_ANGLEENCODER_H
