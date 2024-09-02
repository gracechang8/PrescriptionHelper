#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include "registerdialog.h"
#include <QTime>
#include <vector>
#include <utility>
#include <QCheckBox>


struct Prescription{
    QString prescName;
    int quantity;
    int dosesPerDay;
    //std::vector<QTime> times = {};
    //std::vector<std::pair<QTime, bool>> times = {};
    std::vector<std::pair<QTime, QCheckBox*>> times = {};
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;

}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    void setName(QString name);

    void setEmail(QString email);

    void setPass(QString password);

    QString getName();

    QString getEmail();

    QString getPass();

    //std::vector <Prescription*>* getPtrToPre();

    //std::vector getPtrToPre();

    std::vector<Prescription*>* getPtrToPre();

    int getNumPres();

    void setTempPreName(QString preName);

    void setTempQty(int quantity);

    void setTempDoseNum(int numDose);

    void addNewTime(QTime newTime);



private slots:
    void on_actionSettings_triggered();

    void on_actionProfile_triggered();

    void on_actionHelp_triggered();

    void on_actionNotifications_triggered();

    void on_sussyBaka_clicked();

    void onAddNewClicked();

    void saveFileTings();

    void updateFunction();

private:
    Ui::MainWindow *ui;



    //this is where tutorial created the other dialogs

    LoginDialog *loginDialog;
    RegisterDialog *registerDialog;




    //loginDialog.setModal(true);
    // loginDialog.exec();
    //Login
};
#endif // MAINWINDOW_H
