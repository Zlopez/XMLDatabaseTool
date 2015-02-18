#ifndef DBTABLEMODEL_H
#define DBTABLEMODEL_H

#include <QAbstractTableModel>
#include <QScopedPointer>
#include <QItemSelectionModel>
#include <QVector>

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

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;
    QVector<QString> columns();

	/**
	 * @brief Overriden method for removing rows.
	 * @param row Begin row for removing
	 * @param count Count of rows to be removed
	 * @param parent
	 * @return boolean
	 */
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    QScopedPointer<DbTableModelPrivate> d_ptr;
    Q_DECLARE_PRIVATE(DbTableModel)

signals:

public slots:
	/**
	 * @brief Delete selected row
	 * @param index
	 */
	void deleteRow(QItemSelectionModel* selectionModel);

	/**
	 * @brief Inserts new row
	 */
	void insertRow();
    void onColumnAdded(int index, const QString name);
    void onColumnRemoved(int index);
    void onColumnNameChanged(int index, const QString name);

};

#endif // DBTABLEMODEL_H
