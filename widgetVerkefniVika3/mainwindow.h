#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "models/scientist.h"
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include <vector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_AddScientist_triggered();

    //void on_action_DeleteScientist_triggered();

    void on_table_Scientist_clicked(const QModelIndex &index);

    void on_table_Computers_clicked(const QModelIndex &index);

    void on_table_Join_clicked(const QModelIndex &index);

    void on_action_Add_computer_triggered();

    //void on_action_Delete_computer_triggered();

    void on_action_Search_triggered();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_search_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<Scientist> currentlyDisplayedScientists;
    std::vector<Computer> currentlyDisplayedComputers;

    void displayAllScientists();
    void displayScientists(std::vector<Scientist> scientists);

    void displayAllComputers();
    void displayComputers(std::vector<Computer> computers);

    ComputerService computersService;
    ScientistService scientistService;

};

#endif // MAINWINDOW_H
