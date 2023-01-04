
#include "dbus_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class DbusAdaptor
 */

DbusAdaptor::DbusAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

DbusAdaptor::~DbusAdaptor()
{
    // destructor
}

QString DbusAdaptor::runCmd(const QString &cmd)
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "runCmd", Q_RETURN_ARG(QString, out0), Q_ARG(QString, cmd));
    return out0;
}

QString DbusAdaptor::runCmdDetached(const QString &cmd)
{
    QString out0;
    QMetaObject::invokeMethod(parent(), "runCmdDetached", Q_RETURN_ARG(QString, out0), Q_ARG(QString, cmd));
    return out0;
}