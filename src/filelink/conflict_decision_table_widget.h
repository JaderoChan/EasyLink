#pragma once

#include <qevent.h>
#include <qtableview.h>
#include <qsortfilterproxymodel.h>
#include <qwidget.h>

#include "conflict_decision_table_model.h"
#include "conflict_decision_table_header.h"
#include "types.h"

class ConflictDecisionTableWidget : public QWidget
{
public:
    explicit ConflictDecisionTableWidget(LinkTasks& conflicts, QWidget* parent = nullptr);

    int sameDateSizeEntries() const;

    void setSkipSameDateSize(bool skip);
    void setAllSourcesChecked(bool checked);
    void setAllTargetsChecked(bool checked);

protected:
    virtual void updateText();
    void changeEvent(QEvent* event) override;

    void onModelDataChanged();
    void onSourceHeaderClicked();
    void onTargetHeaderClicked();

private:
    void setupUi();

    LinkTasks& conflicts_;

    ConflictDecisionTableHeader sourceHeader_;
    ConflictDecisionTableHeader targetHeader_;
    QTableView view_;
    ConflictDecisionTableModel model_;
    QSortFilterProxyModel proxyModel_;

    int checkedSources_ = 0;
    int checkedTargets_ = 0;
};
