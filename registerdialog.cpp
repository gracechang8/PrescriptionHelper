#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "mainwindow.h"


//This is supposed to be private
MainWindow* mainWindow;


RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)

{
    ui->setupUi(this);
    //setAttribute(Qt::WA_DeleteOnClose);

    //get mainWindow as a pointer, so can access it
    mainWindow = qobject_cast<MainWindow*>(parent);
}


RegisterDialog::~RegisterDialog()
{
    delete ui;
}


// I don't really know about the scope stuff?
QString registerName;
QString registerEmail;
QString registerPass;


void RegisterDialog::on_buttonBox_accepted()
{
    //basically when ok is clicked
    //if the boxes are not filled out it needs to pop up a thingy saying to fill them out
    //if the passwords aren't the same don't let it work
    registerName = ui->lineEdit->text();
    registerEmail = ui->lineEdit_2->text();
    registerPass = ui->lineEdit_3->text();
    QString registerPass2 = ui->lineEdit_4->text();

    // Should adjust these later to check if email is valid
    if (registerName.length()!=0 && registerEmail.length()!=0 && registerPass.length()!=0 && (registerPass == registerPass2)){
        qDebug("Register Successful");
        //i want to use setters to the mainwindow here
        //emit sendInfoToMainWindow();
        mainWindow->setName(registerName);
        mainWindow->setEmail(registerEmail);
        mainWindow->setPass(registerPass);

        //after setting all these, go back to the main window and close the register thing
        this->done(4);


    } else {
        qDebug("Register Unsuccessful");
        //add a pop up?
    }

}


//getters to get the values inputted by the user
//these are public in the .h file
QString getName(){
    return registerName;
}

QString getEmail(){
    return registerEmail;
}

QString getPass(){
    return registerPass;
}
