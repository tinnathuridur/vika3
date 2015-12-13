#include "addtodatabasedialog.h"
#include "ui_addtodatabasedialog.h"

#include <QMessageBox>

AddToDatabaseDialog::AddToDatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDatabaseDialog)
{
    ui->setupUi(this);
}

AddToDatabaseDialog::~AddToDatabaseDialog()
{
    delete ui;
}

void AddToDatabaseDialog::on_radioButton_Scientist_clicked()
{
    //Kveikir á öllum scientist textaboxunum
    ui->lineEdit_Scientist_Name->setEnabled(true);
    ui->lineEdit_Scientist_Sex->setEnabled(true);
    ui->lineEdit_Scientist_YearBorn->setEnabled(true);
    ui->lineEdit_Scientist_YearDied->setEnabled(true);
    //Slekkur á öllum computer og join textaboxunum
    ui->lineEdit_Computer_Name->setEnabled(false);
    ui->lineEdit_Computer_Type->setEnabled(false);
    ui->lineEdit_Computer_YearBuilt->setEnabled(false);
    ui->lineEdit_Computer_BuiltOrNot->setEnabled(false);
    ui->lineEdit_Join_Scientist->setEnabled(false);
    ui->lineEdit_Join_Computer->setEnabled(false);
}

void AddToDatabaseDialog::on_radioButton_Computer_clicked()
{
    //Kveikir á öllum computer textaboxunum
    ui->lineEdit_Computer_Name->setEnabled(true);
    ui->lineEdit_Computer_Type->setEnabled(true);
    ui->lineEdit_Computer_YearBuilt->setEnabled(true);
    ui->lineEdit_Computer_BuiltOrNot->setEnabled(true);

    //Slekkur á öllum scientist og join textaboxunum
    ui->lineEdit_Scientist_Name->setEnabled(false);
    ui->lineEdit_Scientist_Sex->setEnabled(false);
    ui->lineEdit_Scientist_YearBorn->setEnabled(false);
    ui->lineEdit_Scientist_YearDied->setEnabled(false);
    ui->lineEdit_Join_Scientist->setEnabled(false);
    ui->lineEdit_Join_Computer->setEnabled(false);
}

void AddToDatabaseDialog::on_radioButton_Join_clicked()
{
    //Kveikir á öllum join textaboxunum
    ui->lineEdit_Join_Scientist->setEnabled(true);
    ui->lineEdit_Join_Computer->setEnabled(true);
    //Slekkur á öllum scientist og computer textaboxunum
    ui->lineEdit_Scientist_Name->setEnabled(false);
    ui->lineEdit_Scientist_Sex->setEnabled(false);
    ui->lineEdit_Scientist_YearBorn->setEnabled(false);
    ui->lineEdit_Scientist_YearDied->setEnabled(false);
    ui->lineEdit_Computer_Name->setEnabled(false);
    ui->lineEdit_Computer_Type->setEnabled(false);
    ui->lineEdit_Computer_YearBuilt->setEnabled(false);
    ui->lineEdit_Computer_BuiltOrNot->setEnabled(false);
}

void AddToDatabaseDialog::on_pushButton_AddToDatabase_clicked()
{
    if(ui->radioButton_Scientist->isChecked()){
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");

        /*QString name = ui->lineEdit_Scientist_Name->text();
        QString sex = ui->lineEdit_Scientist_Sex->text();
        QString yearBorn = ui->lineEdit_Scientist_Sex->text();
        QString yearDied = ui->lineEdit_Scientist_Sex->text();

        bool success = ScientistService.addScientist(Student(name.toStdString(), yearBorn.toInt(), yearDied.toInt()));/*
        //Klára að geta sett innslegin gögn í gagnagrunninn*/

    }
    else if(ui->radioButton_Computer->isChecked()){
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");

    }
    else if(ui->radioButton_Join->isChecked()){
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");

    }
}
