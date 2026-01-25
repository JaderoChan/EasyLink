#pragma once

#include <qdialog.h>

#include "ui_settings_dialog.h"

class SettingsDialog : public QDialog
{
public:
    explicit SettingsDialog(QWidget* parent = nullptr);

private:
    Ui::SettingsDialog ui;
};
