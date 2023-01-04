
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>

#include "mainwindow.h"
#include "dbus_interface.h"


mainwindow::mainwindow(QWidget *parent) :
        QMainWindow(parent) {

    this->resize(500, 400);

    QLabel *label = new QLabel(this);
    label->setGeometry(10, 10, 100, 20);
    label->setText("命令获取测试:");

    qDebug() << QCoreApplication::applicationPid();
    com::polkit::inspur::assistant::dbus *dbus = new com::polkit::inspur::assistant::dbus(
            "com.polkit.absurd.dream.dbus", "/", QDBusConnection::systemBus(), this);

    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(10, 40, 400, 30);
    lineEdit->setText("dmidecode -t 17");

    QTextBrowser *textData = new QTextBrowser(this);
    textData->setGeometry(10, 80, 480, 300);

    QPushButton *button = new QPushButton("查询",this);
    button->setGeometry(430, 40, 60, 30);

    connect(button, &QPushButton::clicked, this, [ = ] {
        textData->setText(dbus->runCmd(lineEdit->text()));
    });
    
}