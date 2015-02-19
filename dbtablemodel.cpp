#include "dbtablemodel.h"
#include "xmltable.h"
#include <QDebug>

class DbTableModelPrivate {
public:
	XMLTable *table;

	virtual ~DbTableModelPrivate()
	{
			if(table)
                delete table;
	}
};

/**
 * @brief Creates new table model with name and size.
 * @param parent Parent object
 * @param name Name of table
 * @param size Size of table (columns)
 */
DbTableModel::DbTableModel(QObject *parent, QString *name,int size) :
    QAbstractTableModel(parent),
    d_ptr(new DbTableModelPrivate())
{
	Q_D(DbTableModel);

	d->table = new XMLTable(*name);
	for(int i=0;i<size;i++)
	{
        d->table->addColumn();
	}
	d->table->addRow();

}

DbTableModel::~DbTableModel()
{

}

/**
 * @brief Returns count of rows.
 * @param parent Parent object
 * @return Rows count
 */
int DbTableModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	Q_D(const DbTableModel);

	return d->table->getRowCount();
}

/**
 * @brief Returns count of columns.
 * @param parent Parent object
 * @return Columns count
 */
int DbTableModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	Q_D(const DbTableModel);

	return d->table->getColCount();
}

/**
 * @brief Returns data on specified index.
 * @param index index of data
 * @param role display role
 * @return data on index
 */
QVariant DbTableModel::data(const QModelIndex &index, int role) const
{
	Q_D(const DbTableModel);

	if(role == Qt::DisplayRole)
			return d->table->getData(index.row(),index.column());
	if(role == Qt::EditRole)
			return d->table->getData(index.row(),index.column());

	return QVariant();
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
	Q_D(const DbTableModel);

	if(role == Qt::DisplayRole || role == Qt::EditRole)
	{
			if(orientation == Qt::Horizontal)
			{
					return d->table->getColumnName(section);
			}
			else
			{
					return section;
			}
	}

	return QVariant();
}

/**
 * @brief Sets new name to column
 * @param section
 * @param orientation
 * @param value
 * @param role
 * @return
 */
bool DbTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    Q_D(DbTableModel);

    if(role == Qt::EditRole)
    {
        if(orientation == Qt::Horizontal)
        {
            d->table->setColumnName(section,value.toString());
            return true;
        }
    }

    return false;
}

/**
 * @brief Return flag for index
 * @param index index of cell
 * @return flag
 */
Qt::ItemFlags DbTableModel::flags(const QModelIndex &index) const
{
	Qt::ItemFlags flags = QAbstractTableModel::flags(index);
	if(index.isValid())
        return Qt::ItemIsEditable | flags;
	return flags;
}

/**
 * @brief Sets data to specified value
 * @param index index of cell
 * @param value value to set
 * @param role Display role
 * @return true if edited
 */
bool DbTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	Q_D(DbTableModel);
	if(index.isValid() && role == Qt::EditRole)
	{
		d->table->setData(index.row(),index.column(),value.toString());
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Delete selected row
 * @param index
 */
void DbTableModel::deleteRow(QItemSelectionModel* selectionModel)
{
	if(!selectionModel->selection().isEmpty())
	{
        if(!selectionModel->selectedRows().isEmpty())
        {
            QModelIndexList selection = selectionModel->selectedRows();
            removeRows(selection.first().row(), selection.last().row() - selection.first().row());
        }
    }
}

/**
 * @brief Inserts new row
 */
void DbTableModel::insertRow()
{
	QAbstractItemModel::insertRow(rowCount()-1);
}

/**
 * @brief Inserts multiple rows
 * @param row
 * @param count
 * @param parent
 * @return
 */
bool DbTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
	Q_D(DbTableModel);

	beginInsertRows(parent,row,row+count-1);
	d->table->addRow();
	endInsertRows();

	return true;
}

/**
 * @brief Overriden method for removing rows.
 * @param row Begin row for removing
 * @param count Count of rows to be removed
 * @param parent
 * @return boolean
 */
bool DbTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
	Q_D(DbTableModel);

	beginRemoveRows(parent,row,row+count);
    for(int i = row;i<row+count+1;i++)
	{
        d->table->deleteRow(i);
	}
	endRemoveRows();

	return true;
}

/**
 * @brief Overriden method for inserting new column.
 * @param column
 * @param parent
 * @return boolean
 */
bool DbTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    Q_D(DbTableModel);

    beginInsertColumns(parent,column,column+count);
    for(int i = column;i <= column + count;i++)
    {
        d->table->insertColumn(i, "");
    }
    endInsertColumns();

    return true;
}

/**
 * @brief Overriden method for removing column
 * @param column
 * @param parent
 * @return
 */
bool DbTableModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    Q_D(DbTableModel);

    beginRemoveColumns(parent,column,column+count);
    for(int i = column;i <= column + count;i++)
    {
        d->table->removeColumn(i);
    }
    endRemoveColumns();

    return true;
}

/**
 * @brief Adds new column
 * @param index
 */
void DbTableModel::onColumnAdded(int index, const QString name)
{
    Q_D(DbTableModel);

    if(index >= 0 && index < columnCount())
    {
        insertColumns(index+1,0);
        QString temp;

        for(int i = index+1;i<columnCount() - 1;i++)
        {
            temp = d->table->getColumnName(i);
            setHeaderData(i+1,Qt::Horizontal,name);
        }
        setHeaderData(index+1,Qt::Horizontal,name);
    }
}

/**
 * @brief Removes column
 * @param index
 */
void DbTableModel::onColumnRemoved(int index)
{
    if(index >= 0 && index < columnCount())
    {
        if(columnCount() > 1)
        {
            removeColumns(index,0);
        }
    }
}

/**
 * @brief Changes name of column
 * @param index
 * @param name
 */
void DbTableModel::onColumnNameChanged(int index, const QString name)
{

    if(index >= 0 && index < columnCount())
    {
        setHeaderData(index,Qt::Horizontal,name);
    }
}

/**
 * @brief Returns all columns in table
 * @return
 */
QVector<QString> DbTableModel::columns()
{
    Q_D(DbTableModel);

    QVector<QString> columns;

    for(int i = 0; i < d->table->getColCount();i++)
    {
        columns.push_back(d->table->getColumnName(i));
    }

    return columns;
}
