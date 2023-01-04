
#ifndef DBUS_INTERFACE_H
#define DBUS_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>


class ComPolkitAbsurdDreamDbusInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "com.polkit.absurd.dream.dbus"; }

public:
    ComPolkitAbsurdDreamDbusInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~ComPolkitAbsurdDreamDbusInterface();

public Q_SLOTS: // METHODS    
    inline QDBusPendingReply<QString> runCmd(const QString &cmd)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(cmd);
        return asyncCallWithArgumentList(QStringLiteral("runCmd"), argumentList);
    }
    inline QDBusPendingReply<QString> runCmdDetached(const QString &cmd)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(cmd);
        return asyncCallWithArgumentList(QStringLiteral("runCmdDetached"), argumentList);
    }
Q_SIGNALS: // SIGNALS
};

namespace com {
  namespace polkit {
    namespace inspur {
      namespace assistant {
        typedef ::ComPolkitAbsurdDreamDbusInterface dbus;
      }
    }
  }
}
#endif
