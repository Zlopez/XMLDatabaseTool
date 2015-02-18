#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newtabledialog.h"
#include "qmessagebox.h"
#include "dbtablemodel.h"
#include "tabwidget.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    ui(new Ui::MainWindow),
    columnWidget(nullptr)
{
	ui->setupUi(this);
	ui->databaseWidget->hide();
	connect(ui->actionNew_table,SIGNAL(triggered()),this,SLOT(onNewTableActionClicked()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(onExitActionClicked()));
    connect(ui->actionOpen_database,SIGNAL(triggered()),this,SLOT(onLoadDatabaseActionClicked()));
    connect(ui->actionSave_database,SIGNAL(triggered()),this,SLOT(onSaveDatabaseActionClicked()));
    connect(ui->tablesTab,SIGNAL(currentChanged(int)),this,SLOT(onTableChanged()));
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

    if(ui->colNavigator->layout()->isEmpty())
    {
        columnWidget = new ColumnWidget(this);

        for(int i = 0;i < columns;i++)
        {
            columnWidget->addColumn();
        }

        ui->colNavigator->layout()->addWidget(columnWidget);
    }

	int i = ui->tablesTab->addTab(new TabWidget(this),tableName);

    TabWidget* tabWidget=static_cast<TabWidget*>(ui->tablesTab->currentWidget());
    DbTableModel* table=new DbTableModel(this,&tableName,columns);
    tabWidget->setModel(table);

	ui->tablesTab->setCurrentIndex(i);
    ui->tablesTab->setMinimumWidth(300);


    ui->databaseWidget->show();


}

/**
 * @brief Remaps signals and slots on table change
 */
void MainWindow::onTableChanged()
{

    if(columnWidget != nullptr)
    {
        columnWidget->disconnect();
        TabWidget* tabWidget = (TabWidget*)ui->tablesTab->currentWidget();
        if(tabWidget->model() != nullptr)
        {
            columnWidget->setColumns(tabWidget->columns());
        }

        connect(columnWidget,&ColumnWidget::columnAdded,tabWidget,&TabWidget::onColumnAdded,Qt::UniqueConnection);
        connect(columnWidget,&ColumnWidget::columnRemoved,tabWidget,&TabWidget::onColumnRemoved,Qt::UniqueConnection);
        connect(columnWidget,&ColumnWidget::columnNameChanged,tabWidget,&TabWidget::onColumnNameChanged,Qt::UniqueConnection);
    }
}

MainWindow::~MainWindow()
{
	delete ui;
}
