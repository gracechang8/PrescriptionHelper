#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

//newly added
//class MainWindow;


namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

    //public functions so u can access anywhere
    QString getName();
    QString getEmail();
    QString getPass();

    //void sendInfoToMainWindow();



private slots:
    void on_buttonBox_accepted();

private:
    Ui::RegisterDialog *ui;

    //newly added
    //MainWindow* m_mainWindow;
};

#endif // REGISTERDIALOG_H
