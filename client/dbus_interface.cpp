
#include "dbus_interface.h"


ComPolkitAbsurdDreamDbusInterface::ComPolkitAbsurdDreamDbusInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

ComPolkitAbsurdDreamDbusInterface::~ComPolkitAbsurdDreamDbusInterface()
{
}

