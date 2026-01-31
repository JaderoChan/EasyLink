#pragma once

#include <qstring.h>

#include <global_hotkey/key_combination.hpp>

#include "language.h"
#include "filelink/link_config.h"

struct Settings
{
    bool autoRunOnStartUp;
    Language language;
    LinkConfig linkConfig;
    gbhk::KeyCombination symlinkHotkey;
    gbhk::KeyCombination hardlinkHotkey;
};

Settings loadSettings();

void saveSettings(const Settings& settings);
