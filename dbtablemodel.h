#ifndef DBTABLEMODEL_H
#define DBTABLEMODEL_H

#include <QAbstractTableModel>
#include <QScopedPointer>

class DbTableModelPrivate;

/**
 * @brief Model class for database table.
 */
class DbTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	explicit DbTableModel(QObject *parent = 0, QString *name = new QString("default"), int size = 1);
    virtual ~DbTableModel();

	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	Qt::ItemFlags flags(const QModelIndex &index);
	bool setData(const QModelIndex &index, const QVariant &value, int role);

private:
    QScopedPointer<DbTableModelPrivate> d_ptr;
    Q_DECLARE_PRIVATE(DbTableModel)

signals:

public slots:

};

#endif // DBTABLEMODEL_H
