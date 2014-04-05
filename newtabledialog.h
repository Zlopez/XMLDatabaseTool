#ifndef NEWTABLEDIALOG_H
#define NEWTABLEDIALOG_H

#include <QDialog>

namespace Ui {
class NewTableDialog;
}

class NewTableDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTableDialog(QWidget *parent = 0);
    ~NewTableDialog();

signals:
    void sendNewTableData(QString,int);

public slots:
    void onAccept();

private:
    Ui::NewTableDialog *ui;
};

#endif // NEWTABLEDIALOG_H
