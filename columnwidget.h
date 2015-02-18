#ifndef COLUMNWIDGET_H
#define COLUMNWIDGET_H

#include <QWidget>
#include <QList>
#include <QString>
#include <QVector>

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
    void addColumn(int index, const QString name);
    void removeColumn(int index);
    void setColumns(QVector<QString> columns);

signals:
    void columnAdded(int index, const QString name);
    void columnRemoved(int index);
    void columnNameChanged(int index, const QString name);

public slots:
    void onAddButtonClicked();
    void onRemoveButtonClicked();
    void onColumnNameChanged();
    void onTableChange(QList<QString>* columns);

private:
    Ui::columnWidget *ui;
};

#endif // COLUMNWIDGET_H
