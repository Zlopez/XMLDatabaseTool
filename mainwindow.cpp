#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newtabledialog.h"
#include "qmessagebox.h"
#include "dbtablemodel.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->databaseWidget->hide();
	connect(ui->actionNew_table,SIGNAL(triggered()),this,SLOT(onNewTableActionClicked()));
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
	ui->tablesTab->setTabText(ui->tablesTab->count()-1,tableName);
	ui->tableView->setModel(new DbTableModel(ui->tab,&tableName,columns));
}

MainWindow::~MainWindow()
{
	delete ui;
}
