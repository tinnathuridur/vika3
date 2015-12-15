#include "addtodatabasedialog.h"
#include "ui_addtodatabasedialog.h"

#include <QMessageBox>

#include "scientistservice.h"
#include "computerservice.h"
#include "linkservice.h"

#include "mainwindow.h"

AddToDatabaseDialog::AddToDatabaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDatabaseDialog)
{
    ui->setupUi(this);
    ui->radioButton_Scientist->setChecked(true);
}

AddToDatabaseDialog::~AddToDatabaseDialog()
{
    delete ui;
}

void AddToDatabaseDialog::on_radioButton_Scientist_clicked()
{
    //Kveikir á öllum scientist textaboxunum
    ui->lineEdit_Scientist_Name->setEnabled(true);
    ui->comboBox_Scientist_Sex->setEnabled(true);
    ui->lineEdit_Scientist_YearBorn->setEnabled(true);
    ui->lineEdit_Scientist_YearDied->setEnabled(true);
    //Slekkur á öllum computer og join textaboxunum
    ui->lineEdit_Computer_Name->setEnabled(false);
    ui->comboBox_Computer_Type->setEnabled(false);
    ui->lineEdit_Computer_YearBuilt->setEnabled(false);
    ui->checkBox_Computer_builtOrNot->setEnabled(false);
    ui->lineEdit_Join_Scientist->setEnabled(false);
    ui->lineEdit_Join_Computer->setEnabled(false);
}

void AddToDatabaseDialog::on_radioButton_Computer_clicked()
{
    //Kveikir á öllum computer textaboxunum
    ui->lineEdit_Computer_Name->setEnabled(true);
    ui->comboBox_Computer_Type->setEnabled(true);
    ui->checkBox_Computer_builtOrNot->setEnabled(true);

    //Slekkur á öllum scientist og join textaboxunum
    ui->lineEdit_Scientist_Name->setEnabled(false);
    ui->comboBox_Scientist_Sex->setEnabled(false);
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
    ui->comboBox_Scientist_Sex->setEnabled(false);
    ui->lineEdit_Scientist_YearBorn->setEnabled(false);
    ui->lineEdit_Scientist_YearDied->setEnabled(false);
    ui->lineEdit_Computer_Name->setEnabled(false);
    ui->comboBox_Computer_Type->setEnabled(false);
    ui->lineEdit_Computer_YearBuilt->setEnabled(false);
    ui->checkBox_Computer_builtOrNot->setEnabled(false);
}

void AddToDatabaseDialog::on_checkBox_Computer_builtOrNot_clicked()
{
    bool isButtonChecked = ui->checkBox_Computer_builtOrNot->isChecked();
    if(isButtonChecked)
    {
        ui->lineEdit_Computer_YearBuilt->setEnabled(true);
    }
    else
    {
        ui->lineEdit_Computer_YearBuilt->setEnabled(false);
        ui->lineEdit_Computer_YearBuilt->setText("");
    }
}

void AddToDatabaseDialog::on_pushButton_AddToDatabase_clicked()
{
    if(ui->radioButton_Scientist->isChecked())
    {
        enum sexType sex;
        bool yearDiedisEmpty = false; //qt var að kvarta, frumstillti hana sem false (tinna)
        bool success = false;

        QString name = ui->lineEdit_Scientist_Name->text();
        QString sexQstring = ui->comboBox_Scientist_Sex->currentText();
        QString yearBorn = ui->lineEdit_Scientist_YearBorn->text();
        QString yearDied = ui->lineEdit_Scientist_YearDied->text();

        //Athugar hvort eitthvað hafi verið skilið eftir autt
        bool thereWasAnError = false;
        if(name.isEmpty())
        {
            QMessageBox::information(NULL, "Error!", "Must have a name!");
            thereWasAnError = true;
        }

        if(yearBorn.isEmpty())
        {
            QMessageBox::information(NULL, "Error!", "Must be born!");
            thereWasAnError = true;
        }
        //Athugar hvort yearBorn og yearDied séu int tölur
        QRegExp re("[0-9]*"); //Regular Expression skoðar hvort tölurnar séu milli 0 og 9
        if (!re.exactMatch(yearBorn))
        {
            QMessageBox::information(NULL, "Error!", "Year born must be a number!");
            thereWasAnError = true;
        }
        if (!re.exactMatch(yearDied))
        {
            QMessageBox::information(NULL, "Error!", "Year died must be a number!");
            thereWasAnError = true;
        }
        //Error skilaboð ef yearDied er áður en yearBorn
        if(yearBorn.toInt() > yearDied.toInt())
        {
            QMessageBox::information(NULL, "Error!", "Must be born before you die!");
            thereWasAnError = true;
        }

        if(thereWasAnError == true)
        {
            return;
        }

        //Error skilaboð ef yearDied er áður en yearBorn
        if(yearBorn.toInt() > yearDied.toInt())
        {
            QMessageBox::information(NULL, "Error!", "Must be born before you die!");
        }


        //Spyr hvort þú sért viss
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
        if(answer == QMessageBox::No)
        {
            return;
        }
        else
        {
            ui->lineEdit_Scientist_Name->setText("");
            ui->lineEdit_Scientist_YearBorn->setText("");
            ui->lineEdit_Scientist_YearDied->setText("");
        }

        //Setur sex'ið sem enum sexType
        if(sexQstring == "Male")
        {
            sex = sexType::male;
        }
        else
        {
            sex = sexType::female;
        }




        //Útaf því að fólk má ennþá vera lifandi þá athugar hann það hér, og notar mismunandi addScientist eftir því
        if(yearDied.isEmpty())
        {
            yearDiedisEmpty = true;
        }

        if(yearDiedisEmpty == true)
        {
            success = scientistService.addScientist(Scientist(name.toStdString(), sex, yearBorn.toInt()));
        }
        else
        {
            success = scientistService.addScientist(Scientist(name.toStdString(), sex, yearBorn.toInt(), yearDied.toInt()));
        }

        //Skilar villuskilaboðum ef ekki tókst að skrifa í database
        if(success == false)
        {
            ui->errorLabel_Scientist->setText("UnSuccsess");
        }
        else
        {
            ui->errorLabel_Scientist->setText("Succsess");
        }


    }
    else if(ui->radioButton_Computer->isChecked()){
        enum computerType type;
        bool success = false;
        bool yearBuiltEmpty = false;

        QString name = ui->lineEdit_Computer_Name->text();
        QString typeQString = ui->comboBox_Computer_Type->currentText();
        QString yearBuilt = ui->lineEdit_Computer_YearBuilt->text();

        //Athugar hvort eitthvað hafi verið skilið eftir autt
        bool thereWasAnError = false;
        if(name.isEmpty())
        {
            QMessageBox::information(NULL, "Error!", "Must have a name!");;
            thereWasAnError = true;
        }

        //Athugar hvort yearBuilt sé int tala
        QRegExp re("[0-9]*"); //Regular Expression skoðar hvort tölurnar séu milli 0 og 9
        if (!re.exactMatch(yearBuilt))
        {
            QMessageBox::information(NULL, "Error!", "Year built must be a number!");
            thereWasAnError = true;
        }

        if(thereWasAnError == true)
        {
            return;
        }
        if(yearBuilt.isEmpty()){
            yearBuiltEmpty = true;
        }



        //Spyr hvort þú sért viss að þú viljir skrifa í database
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
        if(answer == QMessageBox::No)
        {
            return;
        }
        else
        {
            ui->lineEdit_Computer_Name->setText("");
            ui->lineEdit_Computer_YearBuilt->setText("");
        }

        //Setur type'ið sem enum computerType
        if(typeQString == "Electronic")
        {
            type = computerType::electronic;
        }
        else if(typeQString == "Mechatronic")
        {
            type = computerType::mechatronic;
        }
        else if(typeQString == "Transistor")
        {
            type = computerType::transistor;
        }
        else
        {
            type = computerType::other;
        }

        //Vantar að laga þetta fall í repositories/computerrepository.h og .cpp þannig að það geti tekið á móti builtOrNot

        if(yearBuiltEmpty)
        {
            success = computerService.addComputer(Computer(name.toStdString(), type));
        }
        else
        {
            success = computerService.addComputer(Computer(name.toStdString(), type, yearBuilt.toInt()));
        }


        //Skilar villuskilaboðum ef ekki tókst að skrifa í database
        if(success == false)
        {
            ui->errorLabel_Computer->setText("UnSuccsess");
        }
        else
        {
            ui->errorLabel_Computer->setText("Succsess");
        }


    }
    else if(ui->radioButton_Join->isChecked()){
        bool success = false;

        QString scientistID = ui->lineEdit_Join_Scientist->text();
        QString computerID = ui->lineEdit_Join_Computer->text();

        //Athugar hvort eitthvað hafi verið skilið eftir autt
        bool thereWasAnError = false;
        if(scientistID.isEmpty())
        {
            QMessageBox::QMessageBox::information(NULL, "Error!", "Must input a scientist ID!");
            thereWasAnError = true;
        }

        if(computerID.isEmpty())
        {
            QMessageBox::QMessageBox::information(NULL, "Error!", "Must input a Computer ID!");
            thereWasAnError = true;
        }

        //Athugar hvort yearBuilt sé int tala
        QRegExp re("[0-9]*"); //Regular Expression skoðar hvort tölurnar séu milli 0 og 9
        if (!re.exactMatch(scientistID))
        {
            QMessageBox::information(NULL, "Error!", "Must input number for Scientist ID!");
            thereWasAnError = true;
        }
        if (!re.exactMatch(computerID))
        {
            QMessageBox::information(NULL, "Error!", "Must input number for Computer ID!");
            thereWasAnError = true;
        }

        if(thereWasAnError == true)
        {
            return;
        }

        //Spyr hvort þú sért viss að þú viljir skrifa í database
        int answer = QMessageBox::question(this, "Confirm", "Are you sure?");
        if(answer == QMessageBox::No)
        {
            return;
        }
        else
        {
            ui->lineEdit_Join_Scientist->setText("");
            ui->lineEdit_Join_Computer->setText("");
        }

        //Vantar að laga þetta fall í repositories/computerrepository.h og .cpp þannig að það geti tekið á móti builtOrNot
        success = linkService.addLink(scientistID.toStdString(), computerID.toStdString());


        //Skilar villuskilaboðum ef ekki tókst að skrifa í database
        if(success == false)
        {
            ui->errorLabel_Join->setText("UnSuccsess");
        }
        else
        {
            ui->errorLabel_Join->setText("Succsess");
        }



    }
}


void AddToDatabaseDialog::on_pushButton_Close_clicked()
{
    close();
}
