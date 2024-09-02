/********************************************************************************
** Form generated from reading UI file 'addnewdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWDIALOG_H
#define UI_ADDNEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddNewDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QSpinBox *spinBox;
    QPushButton *doseOKbutton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddNewDialog)
    {
        if (AddNewDialog->objectName().isEmpty())
            AddNewDialog->setObjectName("AddNewDialog");
        AddNewDialog->resize(314, 417);
        verticalLayout = new QVBoxLayout(AddNewDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(AddNewDialog);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(AddNewDialog);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(AddNewDialog);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_3 = new QLabel(AddNewDialog);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(AddNewDialog);
        lineEdit_2->setObjectName("lineEdit_2");

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(AddNewDialog);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        spinBox = new QSpinBox(AddNewDialog);
        spinBox->setObjectName("spinBox");

        horizontalLayout_3->addWidget(spinBox);

        doseOKbutton = new QPushButton(AddNewDialog);
        doseOKbutton->setObjectName("doseOKbutton");

        horizontalLayout_3->addWidget(doseOKbutton);


        verticalLayout->addLayout(horizontalLayout_3);

        buttonBox = new QDialogButtonBox(AddNewDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddNewDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddNewDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddNewDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddNewDialog);
    } // setupUi

    void retranslateUi(QDialog *AddNewDialog)
    {
        AddNewDialog->setWindowTitle(QCoreApplication::translate("AddNewDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddNewDialog", "Adding New Prescription", nullptr));
        label_2->setText(QCoreApplication::translate("AddNewDialog", "Prescription Name:", nullptr));
        label_3->setText(QCoreApplication::translate("AddNewDialog", "Quantity:", nullptr));
        label_4->setText(QCoreApplication::translate("AddNewDialog", "# of Doses per Day", nullptr));
        doseOKbutton->setText(QCoreApplication::translate("AddNewDialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNewDialog: public Ui_AddNewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWDIALOG_H
