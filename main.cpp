#include <QCoreApplication>
#include <QDebug>

#include "upgradeproc.h"
#include "qmsg.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    UpgradeProc proc(new QMsg, 0x800);
    proc.SetHexParseSettings("F:/Workspace/Workspace_Qt/TestOfFlashUpdateA.hex", 0x318000, 0x18000);
    if(proc.Process()) {
        qDebug() << "升级成功";
    } else {
        qDebug() << "升级失败";
    }

    return a.exec();
}
