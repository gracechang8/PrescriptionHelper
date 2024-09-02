#include "managedialog.h"
#include "ui_managedialog.h"
#include "mainwindow.h"
#include <QTime>
#include <QString>

//int numOfPres = 0;

MainWindow* mainWindowMan;

//Take the data from mainwindow and add it to the table
//When we have save files, we are gonna need to add that data to mainwindow

ManageDialog::ManageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManageDialog)
{
    ui->setupUi(this);
    mainWindowMan = qobject_cast<MainWindow*>(parent);


    //when we create this dialog, we need to populate the table w the data for mainwindow

    for (int i = 0; i < mainWindowMan->getNumPres();i++){
        ui->tableWidget->insertRow(i);
        //ui->tableWidget->editItem()
        //should i even use a table widget? i can just use a bunch of labels?
        QTableWidgetItem* nameItem = new QTableWidgetItem((*mainWindowMan->getPtrToPre())[i]->prescName);
        ui->tableWidget->setItem(i,0,nameItem);
        QTableWidgetItem* qtyItem = new QTableWidgetItem(QString::number(((*mainWindowMan->getPtrToPre())[i]->quantity)));
        ui->tableWidget->setItem(i,1,qtyItem);
        QTableWidgetItem* dosesItem = new QTableWidgetItem(QString::number((*mainWindowMan->getPtrToPre())[i]->dosesPerDay));
        ui->tableWidget->setItem(i,2,dosesItem);

        //NEED TO ADD THE TIMES
        QString thing = "";


        //the problem is that its reading from the same times?

        /*
         * The problem is, its all using the same times array.
         * Need to sort them into separate arrays based on their owner
         *
         */
        for (int j = 0; j<((*mainWindowMan->getPtrToPre())[i]->times).size();j++){

            thing += ((*mainWindowMan->getPtrToPre())[i]->times[j]).first.toString("hh:mm");

            //only add the comma if its not the last
            if (!(j+1==((*mainWindowMan->getPtrToPre())[i]->times).size())){
                thing += ", ";
            }
        }

        QTableWidgetItem* timeItem = new QTableWidgetItem(thing);
        ui->tableWidget->setItem(i,3,timeItem);


    }
    //ERROR: if u click add new again, it draws from previous data for doses/day and time


}

ManageDialog::~ManageDialog()
{
    delete ui;
}

void ManageDialog::on_pushButton_clicked()
{
    this->done(1);
}



//When they click add new
void ManageDialog::on_pushButton_2_clicked()
{


    qDebug("clicked");
    emit addNewClicked();
    this->done(9);

}


