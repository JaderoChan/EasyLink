#pragma once

#include <qsystemtrayicon.h>

class SystemTray : public QSystemTrayIcon
{
public:
    explicit SystemTray(QObject* parent = nullptr);

private:
};
