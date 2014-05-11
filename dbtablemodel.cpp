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
	table->addRow();
}

/**
 * @brief Returns count of rows.
 * @param parent Parent object
 * @return Rows count
 */
int DbTableModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return table->getRowCount();
}

/**
 * @brief Returns count of columns.
 * @param parent Parent object
 * @return Columns count
 */
int DbTableModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return table->getColCount();
}

/**
 * @brief Returns data on specified index.
 * @param index index of data
 * @param role display role
 * @return data on index
 */
QVariant DbTableModel::data(const QModelIndex &index, int role) const
{
	Q_UNUSED(role);
	return table->getData(index.row(),index.column());
}

/**
 * @brief Returns header name
 * @param section Section of table
 * @param orientation Orientation of table
 * @param role Display role
 * @return name
 */
QVariant DbTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	Q_UNUSED(role);
	if(orientation==Qt::Horizontal)
	{
		return table->getColumnName(section);
	}
	else
	{
		return QString(section);
	}
}
