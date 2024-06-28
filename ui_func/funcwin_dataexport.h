#ifndef FUNCWIN_DATAEXPORT_H
#define FUNCWIN_DATAEXPORT_H

#include <QWidget>

#include "functionality/dataexport.h"

namespace Ui {
class funcWin_DataExport;
}

class funcWin_DataExport : public QWidget
{
    Q_OBJECT

public:
    explicit funcWin_DataExport(QWidget *parent = nullptr);
    ~funcWin_DataExport();

private slots:
    void on_btn_ok_clicked();

    void on_btn_back_mainW_clicked();

signals:
    void subWindowClosed();

private:
    Ui::funcWin_DataExport *ui;
    DataExport *_data_export;

    QString _ip_addr;
    QString _port;
};

#endif // FUNCWIN_DATAEXPORT_H
