#ifndef XMLTABLE_H
#define XMLTABLE_H

#include <QScopedPointer>

class XMLTablePrivate;
/**
 * @brief Class that represents one xml database file.
 */
class XMLTable
{
public:
	explicit XMLTable(QString &name);
    virtual ~XMLTable();

	QString getColumnName(int index);
	QString getData(int row,int col);
	void setColumnName(int index, QString &name);
	void setData(int row, int col, const QString &data);
	void addColumn();
	void addColumn(QString &name);
	void setTableName(QString &name);
	QString getTableName();
	int getRowCount();
	int getColCount();
	void addRow();
	/**
	 * @brief Deletes row by row index
	 * @param row
	 */
	void deleteRow(int row);

private:
    QScopedPointer<XMLTablePrivate> d_ptr;
    Q_DECLARE_PRIVATE(XMLTable)
};

#endif // XMLTABLE_H
