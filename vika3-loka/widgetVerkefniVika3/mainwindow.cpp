#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "models/computer.h"
#include "models/scientist.h"
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "services/linkservice.h"
#include "addtodatabasedialog.h"
#include <vector>
#include "repositories/scientistrepository.h"
#include "repositories/computerrepository.h"
#include <QMessageBox>
#include <iostream>
#include "utilities/utils.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->lineEdit_Search->hide();

    displayAllScientists();
    displayAllComputers();
    displayAllLinks();

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

        if(yearDied == "13337")
        {
            yearDied = "Still Alive!";
        }


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

        if(yearBuilt == "13337")
        {
            yearBuilt = "Not Built";
        }


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

void MainWindow::displayLinks(std::vector<Computer> computers)
{
    ui->table_Join->clearContents();
    ui->table_Join->verticalHeader()->setVisible(false);

    //Stilla línufjöldann
    int rowCount = 0;
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        std::vector<Scientist> scientistAll = computers.at(i).getScientists();
        rowCount = rowCount + scientistAll.size();
    }

    ui->table_Join->setRowCount(rowCount);

    int row = 0;//Heldur utan um í hvaða röð forritið er komið
    //Skrifa út eftirfarandi tengingar
    for(unsigned int i = 0; i < computers.size(); i++)
    {

        std::vector<Scientist> scientists = computers.at(i).getScientists();

        for(unsigned int j = 0; j < scientists.size(); j++)
        {
            Computer currentComputer = computers.at(i);
            Scientist currentScientist = scientists.at(j);

            QString scientistName = QString::fromStdString(currentScientist.getName());
            QString computerName = QString::fromStdString(currentComputer.getName());

            ui->table_Join->setItem(row, 0, new QTableWidgetItem(scientistName));
            ui->table_Join->setItem(row, 1, new QTableWidgetItem(computerName));

            row++;
        }
    }
}

void MainWindow::displayAllScientists()
{
    std::vector<Scientist> scientists = scientistService.getAllScientists("id", true);
    displayScientists(scientists);
}

void MainWindow::displayAllLinks()
{
    //Breytur
    int row = 0;
    int rowCounter = 0;
    std::vector<Computer> computersAll = computersService.getAllComputers("id", true);

    //Teljari til að finna út fjölda lína í table'inu
    for(unsigned int i = 0; i < computersAll.size(); i++)
    {
        std::vector<Scientist> scientistAll = computersAll.at(i).getScientists();
        rowCounter = rowCounter + scientistAll.size();
    }

    //Setur inn fjölda lína
    ui->table_Join->setRowCount(rowCounter);

    //Skrifar út gögnin í línurnar
    for(unsigned int i = 0; i < computersAll.size(); i++)
    {

        std::vector<Scientist> scientistAll = computersAll.at(i).getScientists();

        for(unsigned int j = 0; j < scientistAll.size(); j++)
        {


        Computer currentComputers = computersAll.at(i);
        Scientist currentScientist = scientistAll.at(j);


        QString scientistName = QString::fromStdString(currentScientist.getName());
        QString computerName = QString::fromStdString(currentComputers.getName());

        ui->table_Join->setItem(row, 0, new QTableWidgetItem(scientistName));
        ui->table_Join->setItem(row, 1, new QTableWidgetItem(computerName));

        row++;
        }
    }
}

void MainWindow::on_table_Scientist_clicked(const QModelIndex &index)
{
    //tinna
    ui->pushButton_deleteScientist->setEnabled(true);
}

void MainWindow::on_table_Computers_clicked(const QModelIndex &index)
{
    //tinna
    ui->pushButton_deleteComputer->setEnabled(true);
}

void MainWindow::on_table_Join_clicked(const QModelIndex &index)
{
    //tinna
    ui->pushButton_deleteJoin->setEnabled(true);
}

void MainWindow::on_pushButton_add_clicked()
{
    AddToDatabaseDialog addToDatabaseDialog;
    int addToDatabaseReturnValue = addToDatabaseDialog.exec();
    displayAllScientists();
    displayAllComputers();
    displayAllLinks();
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
    vector<Computer>computera = computersService.searchForComputers(userInput);
    displayLinks(computera);

}

void MainWindow::on_pushButton_deleteScientist_clicked()
{
    if (ui->tabWidget->currentIndex() == 0)
    {
        int currentlySelectedScientistIndex = ui->table_Scientists->currentIndex().row();

        Scientist currentlySelectedScientist = currentlyDisplayedScientists.at(currentlySelectedScientistIndex);

        bool success = scientistService.deleteScientist(currentlySelectedScientist);

        if(success)
        {
            displayAllScientists();
        }
        else
        {
            QMessageBox::warning(this, "Error", "Scientist was not deleted. Please try again");
        }
    }
}

void MainWindow::on_pushButton_deleteJoin_clicked()
{
    //Heldur utan um í hvaða röð forlykkjurnar eru komnar
    int row = 0;
    //Finnur röðina sem er valin
    int currentSelectedJoinIndex = ui->table_Join->currentIndex().row();

    //Ef join tabinn er valinn
    if (ui->tabWidget->currentIndex() == 2){

        //Nær í allar tölvur og raðar þeim í id röð í vector
        std::vector<Computer> computersAll = computersService.getAllComputers("id", true);

        //Rúllar í gegnum alla join töfluna, til að finna sömu röð og er valin
        for(unsigned int i = 0; i < computersAll.size(); i++)
        {
            //Nær í allar vísindamenn sem eru tengdir tölvunni í sæti i í vectornum
            std::vector<Scientist> scientistAll = computersAll.at(i).getScientists();

            //Rúllar í gegnum Vísindamennina tengdir þeirri tölvu
            for(unsigned int j = 0; j < scientistAll.size(); j++)
            {
            //Setur alltaf tölvuna og vísindamanninn sem er valinn í vector
            Computer currentComputer = computersAll.at(i);
            Scientist currentScientist = scientistAll.at(j);

            //Þegar röðin sem er valin og röðin sem er verið að rúlla uppí er sú sama
            if(row == currentSelectedJoinIndex)
            {
                //Náum í Id'in útúr objectunum
                int scientistId = currentScientist.getId();
                int computerId = currentComputer.getId();

                //Hendum þeim yfir í string
                string scientistIdString = utils::intToString(scientistId);
                string computerIdString = utils::intToString(computerId);

                //Og sendum inní delete fallið
                linkService.deleteLink(scientistIdString, computerIdString);
            }
            //Hækka um röð ef þetta var ekki röðin sem var valin
            row++;
            }
        displayAllLinks();
        }


    }
}

void MainWindow::on_pushButton_deleteComputer_clicked()
{
    int currentlySelectedComputerIndex = ui->table_Computers->currentIndex().row();

    Computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);

    bool success = computersService.deleteComputer(currentlySelectedComputer);

    if(success)
    {
        displayAllComputers();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Computer not deleted. Please try again");
    }
}
