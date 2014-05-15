#include "xmltable.h"
#include <QVector2D>
#include <QVector>
#include <QString>

class XMLTablePrivate
{
public:
    QVector<QString> columns;
    QVector<QVector<QString> > data;
    QString name;
};

/**
 * @brief Creates table with specified name.
 * @param name Name of new table
 */
XMLTable::XMLTable(QString &name) :
    d_ptr(new XMLTablePrivate())
{
    Q_D(XMLTable);

    d->name=name;
}

XMLTable::~XMLTable()
{

}

/**
 * @brief Returns name of column.
 * @param index Index of column
 * @return Name of column
 */
QString XMLTable::getColumnName(int index)
{
    Q_D(XMLTable);

    return d->columns[index];
}

/**
 * @brief Returns data at specified index.
 * @param row Index of row.
 * @param col Index of column.
 * @return Data at specified index.
 */
QString XMLTable::getData(int row, int col)
{
    Q_D(XMLTable);

    return d->data[row][col];
}

/**
 * @brief Sets name of column.
 * @param index Index of column
 * @param name New name of column
 */
void XMLTable::setColumnName(int index, QString &name)
{
    Q_D(XMLTable);

    d->columns[index]=name;
}

/**
 * @brief Sets data to specified index.
 * @param row Index of row
 * @param col Index of column
 * @param data New data to add
 */
void XMLTable::setData(int row, int col, QString &data)
{
    Q_D(XMLTable);

    d->data[row][col]=data;
}

/**
 * @brief Adds new column with default name.
 */
void XMLTable::addColumn()
{
    Q_D(XMLTable);

    d->columns.append("column" + QString("%1").arg(d->columns.count() + 1));
}

/**
 * @brief Adds new column with specified name.
 * @param name Name of column
 */
void XMLTable::addColumn(QString &name)
{
    Q_D(XMLTable);

    d->columns.append(name);
}

/**
 * @brief Sets new table name.
 * @param name New name of table
 */
void XMLTable::setTableName(QString &name)
{
    Q_D(XMLTable);

    d->name=name;
}

/**
 * @brief Returns table name.
 * @return Name of table
 */
QString XMLTable::getTableName()
{
    Q_D(XMLTable);

    return d->name;
}

/**
 * @brief Returns number of columns.
 * @return Columns count
 */
int XMLTable::getColCount()
{
    Q_D(XMLTable);

    return d->columns.size();
}

/**
 * @brief Returns number of rows.
 * @return Rows count
 */
int XMLTable::getRowCount()
{
    Q_D(XMLTable);

    return d->data.size();
}

/**
 * @brief Adds new row to table
 */
void XMLTable::addRow()
{
    Q_D(XMLTable);

    QVector<QString> row(d->columns.size());
    d->data.append(row);
}
