#ifndef PARAMWIN_ANGLEENCODER_H
#define PARAMWIN_ANGLEENCODER_H

#include <QWidget>

namespace Ui {
class paramWin_angleEncoder;
}

class paramWin_angleEncoder : public QWidget
{
    Q_OBJECT

public:
    explicit paramWin_angleEncoder(QWidget *parent = nullptr);
    ~paramWin_angleEncoder();

private:
    Ui::paramWin_angleEncoder *ui;

signals:
    void subWindowClosed();
private slots:
    void on_btn_back_mainW_clicked();
    void on_btn_exit_clicked();
    void on_btn_ok_clicked();
};

#endif // PARAMWIN_ANGLEENCODER_H
