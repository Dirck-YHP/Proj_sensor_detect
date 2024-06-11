#ifndef SHOWWIN_MEASURERESIS_H
#define SHOWWIN_MEASURERESIS_H

#include <QWidget>

namespace Ui {
class showWin_measureResis;
}

class showWin_measureResis : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_measureResis(QWidget *parent = nullptr);
    ~showWin_measureResis();

private slots:
    void on_btn_ok_clicked();

private:
    Ui::showWin_measureResis *ui;
};

#endif // SHOWWIN_MEASURERESIS_H
