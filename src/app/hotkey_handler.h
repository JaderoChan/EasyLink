#pragma once

#include <qobject.h>

class HotkeyHandler : public QObject
{
public:
    explicit HotkeyHandler(QObject* parent = nullptr);
    ~HotkeyHandler();

private:

};
