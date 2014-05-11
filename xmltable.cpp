#include "xmltable.h"


/**
 * @brief Creates table with specified name.
 * @param name Name of new table
 */
XMLTable::XMLTable(QString &name)
{
	this->name=name;
}

/**
 * @brief Returns name of column.
 * @param index Index of column
 * @return Name of column
 */
QString XMLTable::getColumnName(int index)
{
	return columns[index];
}

/**
 * @brief Returns data at specified index.
 * @param row Index of row.
 * @param col Index of column.
 * @return Data at specified index.
 */
QString XMLTable::getData(int row, int col)
{
	return data[row][col];
}

/**
 * @brief Sets name of column.
 * @param index Index of column
 * @param name New name of column
 */
void XMLTable::setColumnName(int index, QString &name)
{
	columns[index]=name;
}

/**
 * @brief Sets data to specified index.
 * @param row Index of row
 * @param col Index of column
 * @param data New data to add
 */
void XMLTable::setData(int row, int col, QString &data)
{
	this->data[row][col]=data;
}

/**
 * @brief Adds new column with default name.
 */
void XMLTable::addColumn()
{
	columns.append("column" + QString(columns.count() + 1));
}

/**
 * @brief Adds new column with specified name.
 * @param name Name of column
 */
void XMLTable::addColumn(QString &name)
{
	columns.append(name);
}

/**
 * @brief Sets new table name.
 * @param name New name of table
 */
void XMLTable::setTableName(QString &name)
{
	this->name=name;
}

/**
 * @brief Returns table name.
 * @return Name of table
 */
QString XMLTable::getTableName()
{
	return this->name;
}

/**
 * @brief Returns number of columns.
 * @return Columns count
 */
int XMLTable::getColCount()
{
	return columns.size();
}

/**
 * @brief Returns number of rows.
 * @return Rows count
 */
int XMLTable::getRowCount()
{
	return data.size();
}

/**
 * @brief Adds new row to table
 */
void XMLTable::addRow()
{
	QVector<QString> row(columns.size());
	this->data.append(row);
}
