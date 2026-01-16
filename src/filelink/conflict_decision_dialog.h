#pragma once

#include <qdialog.h>
#include <qevent.h>

#include "ui_conflict_decision_dialog.h"
#include "conflict_decision_table_widget.h"
#include "types.h"

class ConflictDecisionDialog : public QDialog
{
public:
    explicit ConflictDecisionDialog(LinkTasks& conflicts, QWidget* parent = nullptr);

protected:
    virtual void updateText();
    void changeEvent(QEvent* event) override;

    void onSkipSameDateSizeCbToggled(bool skip);

private:
    Ui::ConflictDecisionDialog ui;
    ConflictDecisionTableWidget tableWgt_;
    int conflicts_ = 0;
    int sameDateSizeEntries_ = 0;
};
