#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newtabledialog.h"
#include "qmessagebox.h"
#include "dbtablemodel.h"
#include "tabwidget.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->databaseWidget->hide();
	connect(ui->actionNew_table,SIGNAL(triggered()),this,SLOT(onNewTableActionClicked()));
	ui->tablesTab->clear();
}

/**
 * @brief Open dialog for new table.
 */
void MainWindow::onNewTableActionClicked()
{
	NewTableDialog *dialog = new NewTableDialog(this);
	dialog->show();
}

/**
 * @brief Initialiase ui for new table.
 * @param tableName Name of table.
 * @param columns Number of columns.
 */
void MainWindow::createNewTable(QString tableName,int columns)
{
	ui->databaseWidget->show();

	int i = ui->tablesTab->addTab(new TabWidget(this),tableName);

	ui->tablesTab->setCurrentIndex(i);
    ui->tablesTab->setMinimumWidth(300);

	TabWidget* widget=static_cast<TabWidget*>(ui->tablesTab->currentWidget());
	DbTableModel* table=new DbTableModel(this,&tableName,columns);
	widget->setModel(table);

}

MainWindow::~MainWindow()
{
	delete ui;
}
