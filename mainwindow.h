#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

signals:
    void saveCurrentDatabase();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
