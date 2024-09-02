#ifndef MANAGEDIALOG_H
#define MANAGEDIALOG_H

#include <QDialog>

namespace Ui {
class ManageDialog;
}

class ManageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageDialog(QWidget *parent = nullptr);
    ~ManageDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void addNewClicked();

private:
    Ui::ManageDialog *ui;
};

#endif // MANAGEDIALOG_H
