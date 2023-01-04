
#include "dbus.h"
#include "PolicyKitHelper.h"
#include <QDebug>
#include <QtCore/QFile>
#include <QProcess>

dbus::dbus(QObject *parent) :
    QObject(parent){

}

QString dbus::runCmd(QString cmd) {
    if(PolicyKitHelper::instance()->checkAuthorization("com.polkit.absurd.dream.runCmd", getpid())){
        qDebug() << "请求运行命令:" + cmd;
        QProcess p;
        p.start("bash", QStringList() <<"-c" << cmd);
        p.waitForFinished(-1);
        QString strResult = p.readAllStandardOutput();
        return strResult;
    }else{
        qDebug() << "无权运行命令:" + cmd;

        return "无权运行命令" + cmd;
    }
}

QString dbus::runCmdDetached(QString cmd) {
    if(PolicyKitHelper::instance()->checkAuthorization("com.polkit.absurd.dream.runCmdDetached", getpid())){
        qDebug() << "请求运行命令:" + cmd;
        // QProcess p;
        // p.start("bash", QStringList() <<"-c" << cmd);
        // p.waitForFinished(-1);
        // QString strResult = p.readAllStandardOutput();
        // return strResult;
        bool flag = QProcess::startDetached(cmd,QStringList());
        qDebug() << flag;
        if(flag) {
            return "true";
        } else {
            return "false";
        }
    }else{
        qDebug() << "无权运行命令:" + cmd;

        return "无权运行命令" + cmd;
    }
}
