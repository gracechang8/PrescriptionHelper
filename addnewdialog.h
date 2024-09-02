#ifndef ADDNEWDIALOG_H
#define ADDNEWDIALOG_H
#include <QTimeEdit>
#include <QDialog>
#include <vector>

namespace Ui {
class AddNewDialog;
}

class AddNewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewDialog(QWidget *parent = nullptr);
    ~AddNewDialog();

private slots:


    void on_doseOKbutton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::AddNewDialog *ui;

    std::vector<QTimeEdit*> timeEdits; // Vector to store pointers
};

#endif // ADDNEWDIALOG_H
