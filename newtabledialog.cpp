#include "newtabledialog.h"
#include "ui_newtabledialog.h"
#include "mainwindow.h"
#include "QMessageBox"

NewTableDialog::NewTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTableDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(onAccept()));
    connect(this,SIGNAL(sendNewTableData(QString,int)),parent,SLOT(createNewTable(QString,int)));
}

/**
 * @brief Slot for clicking on OK button.
 */
void NewTableDialog::onAccept()
{
    emit sendNewTableData(ui->tableNameEdit->displayText(),ui->numberOfColsBox->value());
}

NewTableDialog::~NewTableDialog()
{
    delete ui;
}
