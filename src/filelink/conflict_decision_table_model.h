#pragma once

#include <qabstractitemmodel.h>
#include <qfileinfo.h>
#include <qicon.h>

#include "types.h"

#define SAME_DATE_SIZE_ROLE (Qt::UserRole + 1)

class ConflictDecisionTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ConflictDecisionTableModel(LinkTasks& conflicts, QObject* parent = nullptr);

    // Non-thread-safe
    static QIcon getFileIcon(const QFileInfo& fileinfo);
    static EntryConflictStrategy getEcsByCheckState(Qt::CheckState source, Qt::CheckState target);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& idx, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& idx) const override;

    bool setData(const QModelIndex& idx, const QVariant& value, int role = Qt::DisplayRole) override;

    // 下面两个函数不会发出dataChanged信号，需要在此前后调用beginReset()和endReset()。
    bool setChecked(const QModelIndex& idx, bool checked);
    bool setEcs(int row, EntryConflictStrategy ecs);

    void beginBatchSet();
    void endBatchSet();

private:
    LinkTasks& conflicts_;
};
