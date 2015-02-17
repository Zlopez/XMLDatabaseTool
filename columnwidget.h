#ifndef COLUMNWIDGET_H
#define COLUMNWIDGET_H

#include <QWidget>
#include <QList>
#include <QString>

namespace Ui {
class columnWidget;
}

class ColumnWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ColumnWidget(QWidget *parent = 0);
    ~ColumnWidget();
    void addColumn();
    void addColumn(int index);
    void removeColumn(int index);

signals:
    void columnAdded(int index);
    void columnRemoved(int index);
    void columnNameChanged(int index, const QString *name);

public slots:
    void onAddButtonClicked();
    void onRemoveButtonClicked();
    void onColumnNameChanged();

private:
    Ui::columnWidget *ui;
};

#endif // COLUMNWIDGET_H
