#ifndef DBUS_ADAPTOR_H
#define DBUS_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface com.polkit.absurd.dream.dbus
 */
class DbusAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.polkit.absurd.dream.dbus")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"com.polkit.absurd.dream.dbus\">\n"
"    <method name=\"runCmd\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"cmd\"/>\n"
"    </method>\n"
"    <method name=\"runCmdDetached\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"cmd\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    DbusAdaptor(QObject *parent);
    virtual ~DbusAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    QString runCmd(const QString &cmd);
    QString runCmdDetached(const QString &cmd);
Q_SIGNALS: // SIGNALS
};

#endif
