#include "columnwidget.h"
#include "ui_columnwidget.h"
#include <QListWidget>

ColumnWidget::ColumnWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::columnWidget)
{
    ui->setupUi(this);
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
    ui->listWidget->addItem("column" + QString("%1").arg(ui->listWidget->count() + 1));
}

/**
 * @brief Adds column with specified name
 */
void ColumnWidget::addColumn(int index)
{
    ui->listWidget->insertItem(index, "column" + QString("%1").arg(index + 1));
    emit columnAdded(index);
}

/**
 * @brief Removes column specified by index
 * @param index
 */
void ColumnWidget::removeColumn(int index)
{
    QListWidgetItem* item = ui->listWidget->item(index);
    ui->listWidget->removeItemWidget(item);

    emit columnRemoved(index);
}

/**
 * @brief Adds new column when button is clicked
 */
void ColumnWidget::onAddButtonClicked()
{
    addColumn(ui->listWidget->selectionModel()->selectedRows().first().row());
}

/**
 * @brief Removes new column when button is clicked
 */
void ColumnWidget::onRemoveButtonClicked()
{
    removeColumn(ui->listWidget->selectionModel()->selectedRows().first().row());
}

