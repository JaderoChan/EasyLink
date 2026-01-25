#pragma once

#include <qstring.h>

#include <global_hotkey/key_combination.hpp>

#include "language.h"
#include "filelink/link_config.h"

struct Settings
{
    bool autoRunOnStartUp = false;
    Language language;
    gbhk::KeyCombination symlinkHotkey  = "Ctrl+S";
    gbhk::KeyCombination hardlinkHotkey = "Ctrl+H";
    LinkConfig linkConfig;
};

Settings readSettings();

void writeSettings(const Settings& settings);
