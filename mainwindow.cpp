#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newtabledialog.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionNew_table,SIGNAL(triggered()),this,SLOT(onNewTableActionClicked()));
}

void MainWindow::onNewTableActionClicked()
{
    NewTableDialog *dialog = new NewTableDialog(this);
    dialog->show();
}

void MainWindow::createNewTable(QString tableName,int columns)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
