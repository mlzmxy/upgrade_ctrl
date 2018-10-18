#include <QCoreApplication>
#include <QDebug>

#include "upgradeproc.h"
#include "qmsg.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    UpgradeProc proc(new QMsg, UpgradeProc::LocalProgram, 0x800);
    if(proc.ParseHexFile("F:/Workspace/Workspace_Qt/FlashUpdate-Can-3s.hex", 0x338000, 0x8000)){
        if(proc.InitCAN()) {
            proc.WaitForUpgrade();
            if(proc.Process()) {
                qDebug() << "升级成功";
            } else {
                qDebug() << "升级失败";
            }
        }
    }


    return a.exec();
}
