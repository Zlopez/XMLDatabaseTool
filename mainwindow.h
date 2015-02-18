#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "columnwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onNewTableActionClicked();
    void createNewTable(QString,int);
    void onExitActionClicked();
    void onLoadDatabaseActionClicked();
    void onSaveDatabaseActionClicked();
    void onTableChanged();

signals:
    void saveCurrentDatabase();

private:
    Ui::MainWindow *ui;
    ColumnWidget* columnWidget;
};

#endif // MAINWINDOW_H
