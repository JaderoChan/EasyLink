#pragma once

#include <qobject.h>

#include "about_dialog.h"
#include "hotkey_manager.h"
#include "settings.h"
#include "settings_widget.h"
#include "system_tray_icon.h"

class AppManager : public QObject
{
    Q_OBJECT

public:
    explicit AppManager(QObject* parent = nullptr);
    ~AppManager();

private:
    Settings settings_;
    AboutDialog* aboutDlg_ = nullptr;
    HotkeyManager* hotkeyMgr_ = nullptr;
    SettingsWidget* settingsWgt_ = nullptr;
    SystemTrayIcon* sti_ = nullptr;
};
