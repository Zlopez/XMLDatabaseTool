#include "dbtablemodel.h"
#include "xmltable.h"

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

    if(role == Qt::DisplayRole)
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
