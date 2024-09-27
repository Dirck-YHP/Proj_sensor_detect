#include "errorprompt.h"

ErrorPrompt::ErrorPrompt(QWidget *parent)
    : m_parent(parent)
{

}

void ErrorPrompt::showError(ErrorType type)
{
    QString message;
    switch (type) {
        case ErrorType::NetworkError:
            message = "网络连接不正确，请检查您的网络设置。";
            break;
        case ErrorType::InputError:
            message = "输入不正确，请重新输入。";
            break;
        case ErrorType::LowBattery:
            message = "电量低，请及时充电。";
            break;
        // 可以添加更多错误类型的处理
        default:
            message = "发生未知错误。";
            break;
    }

    QMessageBox::warning(m_parent, "操作失误", message);
}
