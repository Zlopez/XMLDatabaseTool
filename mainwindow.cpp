#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newtabledialog.h"
#include "qmessagebox.h"
#include "dbtablemodel.h"
#include "tabwidget.h"
#include "columnwidget.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	ui->databaseWidget->hide();
	connect(ui->actionNew_table,SIGNAL(triggered()),this,SLOT(onNewTableActionClicked()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(onExitActionClicked()));
    connect(ui->actionOpen_database,SIGNAL(triggered()),this,SLOT(onLoadDatabaseActionClicked()));
    connect(ui->actionSave_database,SIGNAL(triggered()),this,SLOT(onSaveDatabaseActionClicked()));
	ui->tablesTab->clear();
}

/**
 * @brief Shows dialog for new table.
 */
void MainWindow::onNewTableActionClicked()
{
	NewTableDialog *dialog = new NewTableDialog(this);
	dialog->show();
}

/**
 * @brief Exit application.
 */
void MainWindow::onExitActionClicked()
{
    exit(0);
}

/**
 * @brief Shows dialog for loading database.
 */
void MainWindow::onLoadDatabaseActionClicked()
{

}

/**
 * @brief Saves currently opened database.
 */
void MainWindow::onSaveDatabaseActionClicked()
{

}

/**
 * @brief Initialiase ui for new table.
 * @param tableName Name of table.
 * @param columns Number of columns.
 */
void MainWindow::createNewTable(QString tableName,int columns)
{
	int i = ui->tablesTab->addTab(new TabWidget(this),tableName);

	ui->tablesTab->setCurrentIndex(i);
    ui->tablesTab->setMinimumWidth(300);

	TabWidget* widget=static_cast<TabWidget*>(ui->tablesTab->currentWidget());
	DbTableModel* table=new DbTableModel(this,&tableName,columns);
	widget->setModel(table);

    ColumnWidget* columnWidget = new ColumnWidget(this);

    ui->colNavigator->layout()->addWidget(columnWidget);

    ui->databaseWidget->show();


}

MainWindow::~MainWindow()
{
	delete ui;
}
