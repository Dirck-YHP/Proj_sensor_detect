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

    void on_comboBox_currentIndexChanged(int index);

public slots:
    void slot_get_resis_and_show(QVector<double> data);

private:
    Ui::showWin_measureResis *ui;
    Resis* _resis;

    void set_visible();

    void UI_init();

signals:
    void signal_delete();

    void signal_change_resis(int index);
};

#endif // SHOWWIN_MEASURERESIS_H
