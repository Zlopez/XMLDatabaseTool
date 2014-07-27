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
}

void TabWidget::delRow()
{
	emit delSelectedRow(ui->tableView->selectionModel());
}

TabWidget::~TabWidget()
{
	delete ui;
}
