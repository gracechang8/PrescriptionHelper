#include "profiledialog.h"
#include "ui_profiledialog.h"
#include "mainwindow.h"

MainWindow* mainWindowProf;


ProfileDialog::ProfileDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ProfileDialog)
{
    ui->setupUi(this);
    //setAttribute(Qt::WA_DeleteOnClose);

    mainWindowProf = qobject_cast<MainWindow*>(parent);

    ui->nameLabel->setText(mainWindowProf->getName());
    ui->emailLabel->setText(mainWindowProf->getEmail());
    ui->passLabel->setText(mainWindowProf->getPass());



}

ProfileDialog::~ProfileDialog()
{
    delete ui;
}

void ProfileDialog::on_pushButton_clicked()
{
    this->done(1);

}

