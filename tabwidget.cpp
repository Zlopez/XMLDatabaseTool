#include "tabwidget.h"
#include "ui_tabwidget.h"
#include "dbtablemodel.h"

#include <QtDebug>

TabWidget::TabWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::TabWidget)
{
	qDebug() << "contructor";
	ui->setupUi(this);
}

void TabWidget::setModel(DbTableModel *model)
{
	ui->tableView->setModel(model);

	connect(ui->addRowButton,&QPushButton::clicked,static_cast<DbTableModel*>(ui->tableView->model()),&DbTableModel::insertRow);
	connect(ui->deleteRowButton,&QPushButton::clicked,this,&TabWidget::delRow);
	connect(this,&TabWidget::delSelectedRow,static_cast<DbTableModel*>(ui->tableView->model()),&DbTableModel::deleteRow);
    connect(this,&TabWidget::columnAdded,static_cast<DbTableModel*>(ui->tableView->model()),&DbTableModel::onColumnAdded);
    connect(this,&TabWidget::columnRemoved,static_cast<DbTableModel*>(ui->tableView->model()),&DbTableModel::onColumnRemoved);
    connect(this,&TabWidget::columnNameChanged,static_cast<DbTableModel*>(ui->tableView->model()),&DbTableModel::onColumnNameChanged);
}

void TabWidget::delRow()
{
	emit delSelectedRow(ui->tableView->selectionModel());
}

TabWidget::~TabWidget()
{
	delete ui;
}

/**
 * @brief Emits signal to model
 * @param index
 */
void TabWidget::onColumnAdded(int index, const QString name)
{
    emit columnAdded(index, name);
}

/**
 * @brief Emits signal to model
 * @param index
 */
void TabWidget::onColumnRemoved(int index)
{
    emit columnRemoved(index);
}

/**
 * @brief Emits signal to model
 * @param index
 * @param name
 */
void TabWidget::onColumnNameChanged(int index, const QString name)
{
    emit columnNameChanged(index,name);
}
