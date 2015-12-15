#include "editdatabase.h"
#include "ui_editdatabase.h"

editDatabase::editDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editDatabase)
{
    ui->setupUi(this);
}

editDatabase::~editDatabase()
{
    delete ui;
}

void editDatabase::on_radioButton_editScientist_clicked()
{
    //Kveikir á öllum scientist textaboxunum
    ui->lineEdit_editScientistId->setEnabled(true);
    ui->lineEdit_editScientistName->setEnabled(true);
    ui->comboBox_editScientistSex->setEnabled(true);
    ui->lineEdit_editScientistBorn->setEnabled(true);
    ui->lineEdit_editScientistDied->setEnabled(true);

    //Slekkur á öllum computer og join textaboxunum
    ui->lineEdit_editComputerId->setEnabled(false);
    ui->lineEdit_editComputerName->setEnabled(false);
    ui->comboBox_editComputerType->setEnabled(false);
    ui->lineEdit_editComputerBuilt->setEnabled(false);
    ui->checkBox_editWasBuilt->setEnabled(false);
    ui->lineEdit_editJoinId->setEnabled(false);
    ui->lineEdit_editJoinScientistId->setEnabled(false);
    ui->lineEdit_editJoinComputerId->setEnabled(false);
}

void editDatabase::on_radioButton_editComputer_clicked()
{
    //Kveikir á öllum computer textaboxunum
    ui->lineEdit_editComputerId->setEnabled(true);
    ui->lineEdit_editComputerName->setEnabled(true);
    ui->comboBox_editComputerType->setEnabled(true);
    ui->checkBox_editWasBuilt->setEnabled(true);

    //Slekkur á öllum scientist og join textaboxunum
    ui->lineEdit_editScientistId->setEnabled(false);
    ui->lineEdit_editScientistName->setEnabled(false);
    ui->comboBox_editScientistSex->setEnabled(false);
    ui->lineEdit_editScientistBorn->setEnabled(false);
    ui->lineEdit_editScientistDied->setEnabled(false);
    ui->lineEdit_editJoinId->setEnabled(false);
    ui->lineEdit_editJoinScientistId->setEnabled(false);
    ui->lineEdit_editJoinComputerId->setEnabled(false);
}

void editDatabase::on_radioButton_editJoin_clicked()
{
    //Kveikir á öllum join textaboxunum
    ui->lineEdit_editJoinId->setEnabled(true);
    ui->lineEdit_editJoinScientistId->setEnabled(true);
    ui->lineEdit_editJoinComputerId->setEnabled(true);

    //Slekkur á öllum scientist og computer textaboxunum
    ui->lineEdit_editScientistId->setEnabled(false);
    ui->lineEdit_editScientistName->setEnabled(false);
    ui->comboBox_editScientistSex->setEnabled(false);
    ui->lineEdit_editScientistBorn->setEnabled(false);
    ui->lineEdit_editScientistDied->setEnabled(false);
    ui->lineEdit_editComputerId->setEnabled(false);
    ui->lineEdit_editComputerName->setEnabled(false);
    ui->comboBox_editComputerType->setEnabled(false);
    ui->lineEdit_editComputerBuilt->setEnabled(false);
    ui->checkBox_editWasBuilt->setEnabled(false);
}

void editDatabase::on_checkBox_editWasBuilt_clicked()
{
    bool isButtonChecked = ui->checkBox_editWasBuilt->isChecked();
    if(isButtonChecked)
    {
        ui->lineEdit_editComputerBuilt->setEnabled(true);
    }
    else
    {
        ui->lineEdit_editComputerBuilt->setEnabled(false);
        ui->lineEdit_editComputerBuilt->setText("");
    }
}
