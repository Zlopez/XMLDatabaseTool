#include "dbtablemodel.h"

/**
 * @brief Creates new table model with name and size.
 * @param parent Parent object
 * @param name Name of table
 * @param size Size of table (columns)
 */
DbTableModel::DbTableModel(QObject *parent, QString *name,int size) :
	QAbstractTableModel(parent)
{
	table = new XMLTable(*name);
	for(int i=0;i<size;i++)
	{
		table->addColumn();
	}
}

/**
 * @brief Returns count of rows.
 * @param parent Parent object
 * @return Rows count
 */
int DbTableModel::rowCount(const QModelIndex &parent) const
{
	return table->getRowCount();
}

/**
 * @brief Returns count of columns.
 * @param parent Parent object
 * @return Columns count
 */
int DbTableModel::columnCount(const QModelIndex &parent) const
{
	return table->getColCount();
}

QVariant DbTableModel::data(const QModelIndex &index, int role) const
{
	return table->getData(index.row(),index.column());
}
