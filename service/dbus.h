
#ifndef POLKIT_ABSURDDREAM_DBUS_H
#define POLKIT_ABSURDDREAM_DBUS_H


#include <QtCore/QObject>

class dbus : public QObject{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface","com.polkit.absurd.dream.dbus")

public:
    dbus(QObject* parent=0);


public Q_SLOTS:
    QString runCmd(QString cmd);
    QString runCmdDetached(QString cmd);

};


#endif //POLKIT_ABSURDDREAM_DBUS_H
