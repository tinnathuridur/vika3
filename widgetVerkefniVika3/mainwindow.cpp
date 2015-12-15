#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "models/computer.h"
#include "models/scientist.h"
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "addtodatabasedialog.h"
#include <vector>
#include "repositories/scientistrepository.h"
#include "repositories/computerrepository.h"
#include <QMessageBox>
#include "editdatabase.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Search->hide();

    displayAllScientists();
    displayAllComputers();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayScientists(std::vector<Scientist> scientists)
{
    ui->table_Scientists->clearContents();

    ui->table_Scientists->setRowCount(scientists.size());

    ui->table_Scientists->verticalHeader()->setVisible(false);

    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists.at(row);

        QString sexDisplay;

        QString Id = QString::number(currentScientist.getId());
        QString name = QString::fromStdString(currentScientist.getName());
        QString sex = QString::number(currentScientist.getSex());
        QString yearBorn = QString::number(currentScientist.getYearBorn());
        QString yearDied = QString::number(currentScientist.getYearDied());
            if(sex == "1")
            {
                sexDisplay = "Male";
            }
            else
            {
                sexDisplay = "Female";
            }

        ui->table_Scientists->setItem(row, 0, new QTableWidgetItem(Id));
        ui->table_Scientists->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_Scientists->setItem(row, 2, new QTableWidgetItem(sexDisplay));
        ui->table_Scientists->setItem(row, 3, new QTableWidgetItem(yearBorn));
        ui->table_Scientists->setItem(row, 4, new QTableWidgetItem(yearDied));
    }

    currentlyDisplayedScientists = scientists;
}

void MainWindow::displayAllComputers()
{
    std::vector<Computer> computers = computersService.getAllComputers("id", true);
    displayComputers(computers);
}

void MainWindow::displayComputers(std::vector<Computer> computers)
{
    ui->table_Computers->clearContents();

    ui->table_Computers->setRowCount(computers.size());

    ui->table_Computers->verticalHeader()->setVisible(false);

    for (unsigned int row = 0; row < computers.size(); row++)
    {
        Computer currentComputers = computers.at(row);
        QString wasItBuilt;

        QString id = QString::number(currentComputers.getId());
        QString name = QString::fromStdString(currentComputers.getName());
        QString type = QString::fromStdString(currentComputers.getTypeName());
        QString yearBuilt = QString::number(currentComputers.getYearBuilt());
        QString wasBuilt = QString::number(currentComputers.wasBuilt());

        if(wasBuilt == "1")
        {
            wasItBuilt = "Yes";
        }
        else
        {
            wasItBuilt = "No";
        }

        ui->table_Computers->setItem(row, 0, new QTableWidgetItem(id));
        ui->table_Computers->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_Computers->setItem(row, 2, new QTableWidgetItem(type));
        ui->table_Computers->setItem(row, 3, new QTableWidgetItem(yearBuilt));
        ui->table_Computers->setItem(row, 4, new QTableWidgetItem(wasItBuilt));
    }

    currentlyDisplayedComputers = computers;
}

void MainWindow::displayAllScientists()
{
    std::vector<Scientist> scientists = scientistService.getAllScientists("id", true);
    displayScientists(scientists);
}

void MainWindow::on_action_AddScientist_triggered()
{
    //tryggvi
    AddToDatabaseDialog addToDatabaseDialog;
    int addToDatabaseReturnValue = addToDatabaseDialog.exec();
}

void MainWindow::on_table_Scientist_clicked(const QModelIndex &index)
{
    //tinna
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_edit->setEnabled(true);
}

void MainWindow::on_table_Computers_clicked(const QModelIndex &index)
{
    //tinna
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_edit->setEnabled(true);
}

void MainWindow::on_table_Join_clicked(const QModelIndex &index)
{
    //tinna
    ui->pushButton_delete->setEnabled(true);
    ui->pushButton_edit->setEnabled(true);
}

void MainWindow::on_action_Add_computer_triggered()
{
    //tryggvi geyma
}

void MainWindow::on_action_Search_triggered()
{
    //emil
}

void MainWindow::on_pushButton_add_clicked()
{
    AddToDatabaseDialog addToDatabaseDialog;
    int addToDatabaseReturnValue = addToDatabaseDialog.exec();
    displayAllScientists();
    displayAllComputers();
}

void MainWindow::on_pushButton_edit_clicked()
{
    editDatabase editDatabase;
    int editDatabaseReturnValue = editDatabase.exec();
    displayAllScientists();
    displayAllComputers();
}

void MainWindow::on_pushButton_search_clicked()
{

}

void MainWindow::on_pushButton_search_toggled(bool checked)
{
    if(checked == true)
    {
        ui->lineEdit_Search->show();
    }
    else
    {
        ui->lineEdit_Search->hide();
    }
}

void MainWindow::on_lineEdit_Search_textChanged(const QString &arg1)
{
    std::string userInput = ui->lineEdit_Search->text().toStdString();

    vector<Scientist>scientists = scientistService.searchForScientists(userInput);
    displayScientists(scientists);
    vector<Computer>computer = computersService.searchForComputers(userInput);
    displayComputers(computer);
}

void MainWindow::on_pushButton_delete_toggled(bool checked)
{
    if (checked == true)
    {
        ui->pushButton_delete->setEnabled(true);

        if (ui->tabWidget->currentIndex() == 0)
        {
            int currentlySelectedScientistIndex = ui->table_Scientists->currentIndex().row();

            Scientist currentlySelectedScientist = currentlyDisplayedScientists.at(currentlySelectedScientistIndex);

            bool success = scientistService.deleteScientist(currentlySelectedScientist);

            if(success)
            {
                displayAllScientists();

                ui->pushButton_delete->setEnabled(false);
            }
            else
            {
                QMessageBox::warning(this, "Error", "Scientist was not deleted. Please try again");
                ui->pushButton_delete->setEnabled(false);
            }
        }

        else //if(ui->tabWidget->currentIndex() == 1 /*&& ui->tabWidget->currentWidget() == pointer á computer tab*/)
        {
            int currentlySelectedComputerIndex = ui->table_Computers->currentIndex().row();

            Computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);

            bool success = computersService.deleteComputer(currentlySelectedComputer);

            if(success)
            {
                displayAllComputers();

                ui->pushButton_delete->setEnabled(false);
            }
            else
            {
                QMessageBox::warning(this, "Error", "Computer not deleted. Please try again");
                ui->pushButton_delete->setEnabled(false);
            }
        }

       /* else
        {
         //eyða úr join
        }*/
    }
    else
    {
        ui->pushButton_delete->setEnabled(false);
    }
}
