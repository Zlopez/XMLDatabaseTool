#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QModelIndex>
#include <QItemSelectionModel>
#include <QVector>
#include <QString>

class DbTableModel;

namespace Ui {
class TabWidget;
}

class TabWidget : public QWidget
{
	Q_OBJECT

public:
	explicit TabWidget(QWidget *parent = 0);
	~TabWidget();

	/**
	 * @brief Sets model for table view on widget
	 * @param model model to set
	 */
	void setModel(DbTableModel *model);
    DbTableModel *model();
    QVector<QString> columns();

private:
	Ui::TabWidget *ui;

signals:
	/**
	 * @brief Delete selected row
	 * @param index
	 */
	void delSelectedRow(QItemSelectionModel* selection);
    void columnAdded(int index, const QString name);
    void columnRemoved(int index);
    void columnNameChanged(int index, const QString name);

public slots:
	/**
	 * @brief This slot is used for handling delete row button signal
	 */
	void delRow();
    void onColumnAdded(int index, const QString name);
    void onColumnRemoved(int index);
    void onColumnNameChanged(int index, const QString name);
};

#endif // TABWIDGET_H
