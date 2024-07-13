#ifndef SHOWWIN_MEASURERESIS_H
#define SHOWWIN_MEASURERESIS_H

#include <QWidget>
#include "sensors/resis.h"
#include "assist_func/assist.h"

namespace Ui {
class showWin_measureResis;
}

class showWin_measureResis : public QWidget
{
    Q_OBJECT

public:
    explicit showWin_measureResis(Resis *mea_resis, QWidget *parent = nullptr);
    ~showWin_measureResis();

private slots:
    void on_btn_ok_clicked();
    void on_btn_start_finish_mea_toggled(bool checked);

public slots:
    void slot_get_resis_and_show(QVector<double> resis);

private:
    Ui::showWin_measureResis *ui;
    Resis* _resis;

    void set_visible();
};

#endif // SHOWWIN_MEASURERESIS_H
