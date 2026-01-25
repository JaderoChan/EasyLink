#include <qapplication.h>
#include <qlockfile.h>

#include <easy_translate.hpp>

#include "config.h"
#include "language.h"
#include "settings.h"
#include "system_tray_icon.h"

int main(int argc, char* argv[])
{
    QLockFile lock(APP_LOCK_FILENAME);
    if (lock.isLocked() || !lock.tryLock(500))
        return 0;

    QApplication a(argc, argv);
    a.setOrganizationName(APP_ORGANIZATION);
    a.setApplicationName(APP_TITLE);
    a.setQuitOnLastWindowClosed(false);

    auto settings = readSettings();
    if (!setLanguage(settings.language));
        qDebug() << "Failed set the language";

    SystemTray st;
    st.show();

    int ret = a.exec();

    easytr::updateTranslationsFiles();

    return ret;
}
