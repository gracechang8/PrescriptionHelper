#include "addnewdialog.h"
#include "ui_addnewdialog.h"
//#include <QTimeEdit>
#include <QTimeEdit>
#include <QString>
#include "mainwindow.h"


MainWindow* mainWindowAdd;


AddNewDialog::AddNewDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddNewDialog)
{
    ui->setupUi(this);
    mainWindowAdd = qobject_cast<MainWindow*>(parent);
}

AddNewDialog::~AddNewDialog()
{
    delete ui;
}

QString preName="";
int qty=0;
int dosesPerDay = 0;


void AddNewDialog::on_doseOKbutton_clicked()
{
    //maybe try to remove any existing ones in case they click it again


    dosesPerDay = ui->spinBox->value();
    // Create a single QVBoxLayout for the main widget
    //QVBoxLayout* mainLayout = new QVBoxLayout(this);

    for (int i = 0; i < dosesPerDay; i++) {
        QTimeEdit* timeEdit = new QTimeEdit();
        //mainLayout->addWidget(timeEdit);
        layout()->addWidget(timeEdit);
        timeEdits.push_back(timeEdit); // add pointer to the time edit to a vector
    }

    // Show the main widget (assuming it's not already shown)
    this->show();

}


void AddNewDialog::on_buttonBox_accepted()
{
    //when click OK
    preName = ui->lineEdit->text();
    QString poo = ui->lineEdit_2->text();
    qty = poo.toInt();



    //need to save the times
    //can put an if statement here to check if what they entered was valid
    //do we wanna store it in one struct?
    //should we have stored all their login info into one struct?
    mainWindowAdd->setTempPreName(preName);
    mainWindowAdd->setTempQty(qty);
    mainWindowAdd->setTempDoseNum(dosesPerDay);


    //could this potentially be where the issue lies?
    //i dont think so, it only sends a time over.
    for (const auto& timeEdit : timeEdits){
        mainWindowAdd->addNewTime(timeEdit->time());

    }
    //use for loop to send the times over


}

