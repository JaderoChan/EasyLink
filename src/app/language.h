#pragma once

#include <qstring.h>

enum Language
{
    LANG_EN,
    LANG_ZH
};

// 如果应用程序不支持当前系统语言则返回`LANG_EN`。
Language currentSystemLang();

bool setLanguage(Language lang);
