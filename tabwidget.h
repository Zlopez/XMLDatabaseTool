#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>
#include <QModelIndex>
#include <QItemSelectionModel>

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

private:
	Ui::TabWidget *ui;

signals:
	/**
	 * @brief Delete selected row
	 * @param index
	 */
	void delSelectedRow(QItemSelectionModel* selection);

public slots:
	/**
	 * @brief This slot is used for handling delete row button signal
	 */
	void delRow();
};

#endif // TABWIDGET_H
