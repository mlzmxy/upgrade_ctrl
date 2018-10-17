#include "qmsg.h"

#include <string>

#include <QDebug>
#include <QString>

QMsg::QMsg()
{

}

void QMsg::ProgressValue(int progress_value)
{
    qDebug() << QString::number(progress_value);
}

void QMsg::Cout(std::string msg)
{
    qDebug() << msg.c_str();
}
