#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "models/computer.h"
#include "models/scientist.h"
#include "services/scientistservice.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::displayScientists(std::vector<Scientist> scientists)
{
    ui->table_Scientists->clearContents();

    ui->table_Scientists->setRowCount(scientists.size());

    for (unsigned int row = 0; row < scientists.size(); row++)
    {
        Scientist currentScientist = scientists.at(row);

        QString name = QString::fromStdString(currentScientist.getName());
        QString sex = QString::number(currentScientist.getSex());
        QString yearBorn = QString::number(currentScientist.getYearBorn());
        QString yearDied = QString::number(currentScientist.getYearDied());

        ui->table_Scientists->setItem(row, 0, new QTableWidgetItem(name));
        ui->table_Scientists->setItem(row, 1, new QTableWidgetItem(sex));
        ui->table_Scientists->setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui->table_Scientists->setItem(row, 3, new QTableWidgetItem(yearDied));
    }

    currentlyDisplayedScientists = scientists;
}*/

/*void MainWindow::displayAllScientists()
{
    std::vector<Scientist> scientists = scientistService.getAllScientists();
    displayScientists(scientists);
}*/

void MainWindow::on_action_AddScientist_triggered()
{
    //tryggvi
}

void MainWindow::on_action_DeleteScientist_triggered()
{
    /*//tinna
    int currentlySelectedScientistIndex = ui->table_Scientists->currentIndex().row();

    Scientist currentlySelectedScientist = currentlyDisplayedScientists.at(currentlySelectedScientistIndex);

    bool success = scientistService.deleteScientist(currentlySelectedScientist);

    if(success)
    {
        //ui->input_filter_students->setText("");
        displayAllScientists();

        ui->action_DeleteScientist->setEnabled(false);
    }
    else
    {
        //cout << "There was an error, please try again";
    }*/
}

void MainWindow::on_table_Scientist_clicked(const QModelIndex &index)
{
    //tinna
    //ui->action_DeleteScientist->setEnabled(true);
}

void MainWindow::on_table_Computers_clicked(const QModelIndex &index)
{
    //tinna
    //ui->action_DeleteComputer->setEnabled(true);
}

void MainWindow::on_table_Join_clicked(const QModelIndex &index)
{
    //tinna
}

void MainWindow::on_action_Add_computer_triggered()
{
    //tryggvi geyma
}

void MainWindow::on_action_Delete_computer_triggered()
{
    //tinna geyma
}

void MainWindow::on_action_Search_triggered()
{
    //emil
}

