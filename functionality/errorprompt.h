#ifndef ERRORPROMPT_H
#define ERRORPROMPT_H

#include <QWidget>
#include <QMessageBox>
#include <QEventLoop>

enum class ErrorType {
    NetworkError,
    InputError,
    LowBattery,
};

class ErrorPrompt : public QWidget
{
    Q_OBJECT
public:
    explicit ErrorPrompt(QWidget *parent = nullptr);

    void showError(ErrorType type);

private:
    QWidget *m_parent;

signals:

};

#endif // ERRORPROMPT_H
