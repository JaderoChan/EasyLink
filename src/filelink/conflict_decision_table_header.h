#pragma once

#include <qcheckbox.h>
#include <qevent.h>
#include <qlabel.h>
#include <qstring.h>
#include <qwidget.h>

class ConflictDecisionTableHeader : public QWidget
{
    Q_OBJECT

public:
    explicit ConflictDecisionTableHeader(QWidget* parent = nullptr);
    explicit ConflictDecisionTableHeader(const QString& text, QWidget* parent = nullptr);

    const QLabel& label() const { return label_; };
    QLabel& label() { return label_; };

    const QCheckBox& checkBox() const { return cb_; };
    QCheckBox& checkBox() { return cb_; };

    QString text() const { return label_.text(); };
    void setText(const QString& text) { label_.setText(text); };

    Qt::CheckState checkState() const { return cb_.checkState(); };
    void setCheckState(Qt::CheckState cs) { cb_.setCheckState(cs); };

    int spacing() const;
    void setSpacing(int px);

signals:
    void clicked();

protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
    bool event(QEvent* event) override;

private:
    void setupUi();

    QLabel label_;
    QCheckBox cb_;
    bool pressed_ = false;
};
