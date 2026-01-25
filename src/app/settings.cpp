#include "settings.h"

#include <qsettings.h>

#include "config.h"

#define READ_KC(settings, key, defaultValue) \
gbhk::KeyCombination(settings.value(key, "defaultValue").toString().toStdString())

Settings readSettings()
{
    Settings settings;

    QSettings qsettings(QSettings::NativeFormat, QSettings::UserScope, APP_ORGANIZATION, APP_TITLE);
    settings.language = qsettings.value("Language", currentSystemLang()).value<Language>();
    settings.autoRunOnStartUp = qsettings.value("AutoRunOnStartUp", false).toBool();
    settings.symlinkHotkey = READ_KC(qsettings, "SymlinkHotkey", "Ctrl+S");
    settings.hardlinkHotkey = READ_KC(qsettings, "HardlinkHotkey", "Ctrl+H");

    qsettings.beginGroup("LinkConfig");
    settings.linkConfig.keepDialogWhenErrorOccurred = qsettings.value("KeepDialogWhenErrorOccurred", false).toBool();
    settings.linkConfig.removeToTrash = qsettings.value("RemoveToTrash", false).toBool();
    qsettings.endGroup();

    return settings;
}

void writeSettings(const Settings& settings)
{
    QSettings qsettings(QSettings::NativeFormat, QSettings::UserScope, APP_ORGANIZATION, APP_TITLE);
    qsettings.setValue("Language", settings.language);
    qsettings.setValue("AutoRunOnStartUp", settings.autoRunOnStartUp);
    qsettings.setValue("SymlinkHotkey", settings.symlinkHotkey.toString().c_str());
    qsettings.setValue("HardlinkHotkey", settings.hardlinkHotkey.toString().c_str());

    qsettings.beginGroup("LinkConfig");
    qsettings.setValue("KeepDialogWhenErrorOccurred", settings.linkConfig.keepDialogWhenErrorOccurred);
    qsettings.setValue("RemoveToTrash", settings.linkConfig.removeToTrash);
    qsettings.endGroup();
}
