#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settingsdialog.h"
#include "profiledialog.h"
#include "managedialog.h"
#include "logindialog.h"
#include "registerdialog.h"
#include <QMessageBox>
#include "addnewdialog.h"
#include <vector>
#include <QTime>
#include <QPixmap>
#include <QTimer>
#include <QDateTime>
#include <QCheckBox>
#include <QWidget>
#include <QVBoxLayout>
#include <utility>

#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDir>


QString userName = "ASPIDNOAISDNOIASDH*H)(#J";
QString userEmail = "io3rh1t0hfaisndpiN";
QString userPassword = "0th20nfisdnk";

/*i feel like the countdown on the checkboxes is not priority.
 *aug 25:
 *ok so before I start coding, i need to think abt stuff and write it out
 *last time, i figured out how to write to txt files, now i think i need to learn how to read from them, and filter out stuff
 *my end goal here is to have the program write to save file when you exit, with all your info and times and stuff, then when you boot up
 *the program again it loads in all that info so the user can log in and have all their times and prescriptions
 *
 *how we can do this is:
 *-when you exit the app, it can call a function that is in the mainWindow:: called save() or something, and this will save all of the info in the
 *thing to the txt file in this format:
 *user
 *password
 *email
 *info
 *info
 *info
 *END   <-- this is so the thing will know how to divide the info amongst different users?
 *
 *then when you boot up the application, and asks the user for their info, it'll check if there is a user with whatever was inputted
 *then if it is a registered user, it will check if the passwords match, and let them in if yes
 *if no to any of this, it'll give a critical thing and go back to the login thing
 *
 *then when they log in, the log in window should send over which user they are to the mainwindow,
 *which will then read all their info from the txt file, and add all their info and stuff to the mainwindow (it shall proliferate their tings)
 *then it should be good? i think?
 *
 *
 *!! note !!
 *one thing we have to do is when you register wrong or log in wrong it should take you back to the log in screen,
 *rn it just exits the application
 *can do this using: switch statement , do while? idk try shit out
 *
 *testing making changes
 *test
 *hello
 *
 */




//are these redeclaring and overriding the setters?
//does it have something to do with pointers?
QString tempPreName = "asass";
int tempQty = 0;
int tempDoseNum = 0;
std::vector <std::pair<QTime, QCheckBox*>> tempTimes = {};
int numOfPres = 0;


/*
struct Prescription{
    QString prescName;
    int quantity;
    int dosesPerDay;
    std::vector<QTime> times = {};
};*/

std::vector<Prescription*> prescriptions = {};
std::vector<Prescription*>* MainWindow::getPtrToPre(){
    return &prescriptions;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //theWindow = this;


    loginDialog = new LoginDialog(this);
    loginDialog->setModal(true);
    loginDialog->show();

    //probably delete this later?
    //it didnt make the file
    this->saveFileTings();

    //register window
    int hasLoginBeenAccepted = loginDialog->exec();
    if (hasLoginBeenAccepted == QDialog::Accepted){

         ui->setupUi(this);
         qDebug("Login successful");


    } else if (hasLoginBeenAccepted == 5){
        // this is if they chose the register thing

        qDebug("They chose register button");

        //OPEN THE REGISTER DIALOG
        //registerDialog = new RegisterDialog(this);
        RegisterDialog* registerDialog = new RegisterDialog(this);
        registerDialog->setModal(true);
        registerDialog->show();

        int hasRegisterBeenAccepted = registerDialog->exec();
        if (hasRegisterBeenAccepted == 4){

            //instead of doing ui->setupUi, it should take them back to the login screen where they have to reenter their info
            QMessageBox::information(this, "Register", "Account successfully created");
            ui->setupUi(this);

            QPixmap pix2(":/rec/img/pills.png");
            int wpix2 = ui->label_4->width();
            int hpix2 = ui->label_4->height();
            ui->label_4->setPixmap(pix2.scaled(wpix2,hpix2,Qt::KeepAspectRatio));

            //this will create the timer in the thing, runs the update function every second
            QTimer* timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()),this,SLOT(updateFunction()));
            timer->start(1000);


            for (int i = 0; i < prescriptions.size(); i++){
                for (int j = 0; j < prescriptions[i]->times.size();j++){
                    //THIS IS WHERE YOU WOULD ADD THE CHECKBOX STUFF WHEN YOU HAVE SAVE FILES
                    ui->checkBoxLayout->addWidget(prescriptions[i]->times[j].second);
                }
            }

        } // if it is unsuccessful it should reprompt

         else {
            QMessageBox::warning(this, "Register", "Registration failed");
            //go back to og screen
            //MAYBE SHOULD USE A DO WHILE, OR A SWITCH STATEMENT FOR THIS?

        }



    } else {
        //delete ui;
        qDebug("Login failed");
    }



//idk if i should be using a modal or modalless approach
}

MainWindow::~MainWindow()
{
    //theWindow = nullptr;
    delete ui;
}

// static get(){
//     return theWindow;
// }


void MainWindow::updateFunction(){ //updates every second
    QTime timeForClock = QTime::currentTime();
    QString timeText = timeForClock.toString("hh : mm : ss");
    ui->timeLabel->setText(timeText);
    //qDebug() << "Current Time:" << timeForClock;

    //in here, we need to check if the currentTime is the same as any of our prescription alarm times

    //So we can access each presciption and their time, but need to figure out how we want to actually present it. Like, what
    //do you actually want to code here? cuz u know how to do it, just need to have an idea of like the format or design of
    //the alarms before you code it

    //when it updates every second, we need it to check if theres any alarms that should go off. do i use a for loop?
    //THIS ISNT WORKING!!!!


    //Either its this not working, or has something to do with comparing the times? Diff formats, HH:MM vs HH:MM:SS
    //I'm thinking that since this is a loop, its hard for it to check every second if the times match

    //So right now this code is updating every seccond, and every second it has to do a double for loop to check through each prescription
    //and each of each prescriptions times
    //how can we optimize this?
    //let me just check and see if its actually a problem with the loop
    //okay i just checked and its just not working
    //NEEDS TO BE >=
    /*
    if (timeForClock>=QTime(20,53)){
        //Alarm activate!!
        qDebug("ALARM!!!");

    }*/

    //okay so the alarm thing works but not the loop thing


    //YES THIS SHIT WORKS LETS FUCKING GO OMG HOLY FUCK
    //ok nice so thats like the main functionality of the project done
    //what i need to add to this part now is to figure out how to make it actually alarm, instead of just on the terminal
    //idk how to really interact with ios yet, but the alarm is now working!
    //i would also need to make it just look better with the ui, but my next step at the moment is to make the account creation actually work,
    //and carry over between log ins, like save to a separate file and pull from that file to check
    //i would also need the users info to carry over, as well as their alarms.
    //ive done that before though, just in java, so tbh shouldn't be that hard
    //checkbox system too


    //CHECKBOX
    //ok, so for this checkbox system, I need to take whatever is in the prescription thing and generate checkboxes in the mainwindow
    //each checkbox should use the name, and should also haev a time to take? maybe there should be a "take in x time" thing, where
    //it subtracts the current time from the target time? the program should also organize the checkboxes by whichever med you need to take next

    //SAVE FILES
    //need to learn how to read and write to external files
    //
    //


    //REFILL SYSTEM
    //the thing should do a calculation, quantity/thingsperday = # of days till you are out. then when you are at like a week or 2 before running
    //out, it should show up as a reminder in the refill system
    //you can also change when it wants to remind you in the settings?

    //LOGIN SYSTEM
    //learn how to actually send emails?
    //make it work with the save file system

    //SCHEDULE
    //today: finish the checkbox system, start the save files
    //tomorrow:


    for (int i = 0; i < prescriptions.size();i++){
        for (int j = 0; j<(prescriptions[i]->times).size();j++){
            //qDebug()<<"I be checking";
            if (timeForClock>= prescriptions[i]->times[j].first){
                //Alarm activate!!
                qDebug() <<"ALARM!!!";

            }
        }

    }


}

//trying to learn save file stuff



// im thinking to save the necessary info, I can pass all the needed info into this function as paramaters, then write them to the file with
// keywords in front for easier readability, then at the start I can use a different function to reinitialize the values
//potential idea: have all the stuff we need to save as a data structure, so we dont need to pass a million things into it?
void MainWindow::saveFileTings(){
    qDebug()<<"This shit is writing";

    //might need to change this?
    QFile file("/Users/gracechang/Library/Mobile Documents/com~apple~CloudDocs/SUMMER CODING/prehelp/test.txt");
    //qDebug() << "Absolute file path:" << QFileInfo(file).absoluteFilePath();
    qDebug() << "Current working directory:" << QDir::currentPath();
    if(!file.open(QIODevice::ReadWrite)){
        qCritical()<<"Could not open file!";
        qCritical()<<file.errorString();
        return;

    }
    qInfo()<<"Writing file...";
    file.write(QByteArray("Hello World"));
    file.flush(); //pushes the data to the disk

    qInfo()<<"Reading file...";
    //0 means very beginning of file
    file.seek(0);
    qInfo()<<file.readAll();
    file.close();

}


void MainWindow::on_actionSettings_triggered()
{
    qDebug("Settings clicked");

    //open settings window
    SettingsDialog settingsDialog;
    settingsDialog.setModal(true);
    settingsDialog.exec();
    //settingsDialog.show();
}


void MainWindow::on_actionProfile_triggered()
{
    qDebug("Profile clicked");
    ProfileDialog* profileDialog = new ProfileDialog(this);
    profileDialog->setModal(true);
    //profileDialog->exec();
    profileDialog->show();


}


void MainWindow::on_actionHelp_triggered()
{
    qDebug("Help clicked");

}


void MainWindow::on_actionNotifications_triggered()
{
    qDebug("Notifs clicked");

}


void MainWindow::on_sussyBaka_clicked()
{
    qDebug("Manage clicked");
    ManageDialog* manageDialog = new ManageDialog(this);
    connect(manageDialog, &ManageDialog::addNewClicked, this, &MainWindow::onAddNewClicked);

    manageDialog->setModal(true);
    manageDialog->exec();

    qDebug()<<"manage closed";

    //okay so the issue here is its creating duplicates, how do we prevent that?
    //we can just clear out the old thing? how do we clear a layout?
    //that might not be good, because then they lose all the previous info and what was checked off
    //maybe have an if statement? that checks if idk i think i need to better understand what im making here
    //also, for the checkboxes, they need to reset at certain times. if the medication is meant to be taken daily, then the thing needs to reset
    //daily
    //maybe we could have another
    //we also need to have more checkboxes based on how many times per day they need to take, and i think the thing on the mainwindow
    //needs more information to it, like the time and countdown and stuff
    //im thinking one solution to this issue is to add some more things to the prescription data structure,
    //idk
    //overall we need to just present more data here. maybe use a form layout? on the left you can have the checkbox, and on the right you
    //can have the timer for when it needs to be taken
    //form layout has one side label, other side widget, so it could be the timer as the label, and the checkbox as the widget
    //so i know how to do the timer thing, what is the problem here that i need to figure out? I think the problem is that its creating
    //duplicate things every time, so we need to know which prescriptions are already being shown, IN ADDITION, we need some way of storing the
    //data if a checkbox is already checked off, so that we can spawn it in and check it off
    //as a last step, can order them by doing some kind of comparison thing with the timers, idk how that would work with the layouts but...
    //maybe i could clear it, and then have it spawn in the whole thing again, and then i just have "checked" as a data item in the array

    //okay, so this is working properly, just when I try to add the widgets to the layout it gets funky?
    for (int i=0;i<prescriptions.size();i++){
        for (int j=0;j<prescriptions[i]->times.size();j++){
            qDebug()<<"Times:"<<prescriptions[i]->times[j].first;
            qDebug()<<"Checkbox title:"<<prescriptions[i]->times[j].second->text();
            ui->checkBoxLayout->addWidget(prescriptions[i]->times[j].second);
        }
    }

}

void MainWindow::setName(QString name){
    userName = name;
}

void MainWindow::setEmail(QString email){
    userEmail = email;
}

void MainWindow::setPass(QString password){
    userPassword = password;
}

QString MainWindow::getName(){
    return userName;
}

QString MainWindow::getEmail(){
    return userEmail;
}

QString MainWindow::getPass(){
    return userPassword;
}

void MainWindow::setTempPreName(QString preName){
    tempPreName = preName;
}

void MainWindow::setTempQty(int quantity){
    tempQty = quantity;
}

void MainWindow::setTempDoseNum(int numDose){
    tempDoseNum = numDose;
}

void MainWindow::addNewTime(QTime newTime){
    //QCheckBox *checkBox = new QCheckBox(prescriptions[i]->prescName + " - " + prescriptions[i]->times[j].first.toString(),this);
    //so, temptimes will have a bunch of times beside a bunch of null pointers.
    //tempTimes.push_back(std::make_pair(newTime, nullptr));
    tempTimes.push_back(std::make_pair(newTime, nullptr));
}

int MainWindow::getNumPres(){
    return numOfPres;
}





void MainWindow::onAddNewClicked()
{
    // Close the current dialog
    ManageDialog *currentDialog = qobject_cast<ManageDialog *>(sender());
    if (currentDialog)
        currentDialog->close();

    // Open a new dialog

    AddNewDialog *addNewDialog = new AddNewDialog(this);
    addNewDialog->show();

    int addNewComplete = addNewDialog->exec();
    if (addNewComplete==QDialog::Accepted){

        //Once they add the thing, save it into a struct
        Prescription* prescription = new Prescription;
        //saves pointers to the prescriptions objects
        prescriptions.push_back(prescription);
        numOfPres = prescriptions.size();
        //numOfPres++;
        //prescription = {tempPreName,tempQty,tempDoseNum};
        prescription->prescName=tempPreName;
        prescription->quantity=tempQty;
        prescription->dosesPerDay=tempDoseNum;
        //Need to get the times into mainWindow then use a loop to add them all to this structure
        prescription->times = tempTimes;
        //so this creates a prescription object then copies whatever was sent in temptimes to this, so in this prescription's time,
        //it'll have a bunch of times and null pointers

        //add the checkbox with it
        for (int i = 0; i < prescription->times.size();i++){

            QCheckBox *checkBox = new QCheckBox(prescription->prescName + " - " + prescription->times[i].first.toString(),this);
            //maybe I need to be using pushback??
            prescription->times[i].second = checkBox;
            //ok so we know its properly adding it to the prescription?
            qDebug()<<"TESTING SHIT:"<<prescription->times[i].second->text();


        }


        //the issue here is tempTimes is a vector not a pair
        //prescriptions.push_back(std::make_pair(tempTimes,false));
        //need to clear tempTimes for next use.

        tempTimes.clear();


        //need to also save the times
        //maybe have an array or vector in the struct? vector is an array w dynamic size

        //WHEN YOU EXIT THE ADD NEW WINDOW IT SHOULD GO BACK TO MANAgE NOT MAINWINDOW



    }


}
