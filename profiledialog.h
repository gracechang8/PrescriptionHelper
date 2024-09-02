#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class ProfileDialog;
}

class ProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileDialog(QWidget *parent = nullptr);
    ~ProfileDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ProfileDialog *ui;
};

#endif // PROFILEDIALOG_H
