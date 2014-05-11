#ifndef DBTABLEMODEL_H
#define DBTABLEMODEL_H

#include <QAbstractTableModel>
#include "xmltable.h"

/**
 * @brief Model class for database table.
 */
class DbTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit DbTableModel(QObject *parent = 0, QString *name = new QString("default"), int size = 1);
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
	XMLTable *table;

signals:

public slots:

};

#endif // DBTABLEMODEL_H
