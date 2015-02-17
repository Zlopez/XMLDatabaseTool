#include "columnwidget.h"
#include "ui_columnwidget.h"
#include <QListWidget>

ColumnWidget::ColumnWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::columnWidget)
{
    ui->setupUi(this);
    connect(ui->addColButton,&QPushButton::clicked,this,&ColumnWidget::onAddButtonClicked);
    connect(ui->delColButton,&QPushButton::clicked,this,&ColumnWidget::onRemoveButtonClicked);
    connect(this,&ColumnWidget::objectNameChanged,this,&ColumnWidget::onColumnNameChanged);
}

ColumnWidget::~ColumnWidget()
{
    delete ui;
}

/**
 * @brief Adds column with default name
 */
void ColumnWidget::addColumn()
{
    QListWidgetItem* item = new QListWidgetItem("column" + QString("%1").arg(ui->listWidget->count() + 1));
    item->setFlags(item->flags () | Qt::ItemIsEditable);
    ui->listWidget->addItem(item);
}

/**
 * @brief Adds column with specified name
 */
void ColumnWidget::addColumn(int index)
{
    QListWidgetItem* item = new QListWidgetItem("column" + QString("%1").arg(index + 2));
    item->setFlags(item->flags () | Qt::ItemIsEditable);
    ui->listWidget->insertItem(index + 1, item);
    emit columnAdded(index);
}

/**
 * @brief Removes column specified by index
 * @param index
 */
void ColumnWidget::removeColumn(int index)
{
    QListWidgetItem* item = ui->listWidget->item(index);
    delete item;

    emit columnRemoved(index);
}

/**
 * @brief Adds new column when button is clicked
 */
void ColumnWidget::onAddButtonClicked()
{
    addColumn(ui->listWidget->currentRow());
}

/**
 * @brief Removes new column when button is clicked
 */
void ColumnWidget::onRemoveButtonClicked()
{
    removeColumn(ui->listWidget->currentRow());
}

/**
 * @brief Get text and index of column and emits signal for column name changed
 */
void ColumnWidget::onColumnNameChanged()
{
    int index = ui->listWidget->currentRow();
    QString name = ui->listWidget->currentItem()->text();

    emit columnNameChanged(index,&name);
}


