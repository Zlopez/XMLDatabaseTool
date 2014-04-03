#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionNew_table,SIGNAL(triggered()),SLOT(open()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
