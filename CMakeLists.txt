cmake_minimum_required(VERSION 3.8)
project(polkit_qt_example)

set(CMAKE_CXX_STANDARD 11)

#qt
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets)
find_package(Qt5DBus)
find_package(PolkitQt5-1)

set(SOURCE_DAEMON_FILES
        service/main.cpp
        service/main.h
        service/dbus.cpp
        service/dbus.h
        service/dbus_adaptor.cpp
        service/dbus_adaptor.h 
        service/PolicyKitHelper.cpp 
        service/PolicyKitHelper.h)

add_executable(polkit-absurd-dream-server ${SOURCE_DAEMON_FILES})
target_link_libraries(polkit-absurd-dream-server Qt5::Widgets Qt5::DBus PolkitQt5-1::Agent)

set(SOURCE_FILES
        client/main.cpp
        client/mainwindow.cpp
        client/mainwindow.h
        client/dbus_interface.cpp
        client/dbus_interface.h)
add_executable(polkit-absurd-dream-client ${SOURCE_FILES})
target_link_libraries(polkit-absurd-dream-client Qt5::Widgets Qt5::DBus)