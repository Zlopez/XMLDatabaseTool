#ifndef XMLTABLE_H
#define XMLTABLE_H

#include <QVector2D>
#include <QVector>
#include <QString>

/**
 * @brief Class that represents one xml database file.
 */
class XMLTable
{
public:
	explicit XMLTable(QString &name);
	QString getColumnName(int index);
	QString getData(int row,int col);
	void setColumnName(int index, QString &name);
	void setData(int row,int col, QString &data);
	void addColumn();
	void addColumn(QString &name);
	void setTableName(QString &name);
	QString getTableName();
	~XMLTable();
	int getRowCount();
	int getColCount();

private:
	QVector<QString> columns;
	QVector<QVector<QString> > data;
	QString name;
};

#endif // XMLTABLE_H
