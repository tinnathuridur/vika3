#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "models/scientist.h"
#include "services/scientistservice.h"
#include "services/computerservice.h"
#include "services/linkservice.h"
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

    void on_table_Scientist_clicked(const QModelIndex &index);

    void on_table_Computers_clicked(const QModelIndex &index);

    void on_table_Join_clicked(const QModelIndex &index);

    //void on_action_Delete_computer_triggered();

    void on_pushButton_add_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_search_toggled(bool checked);

    void on_lineEdit_Search_textChanged(const QString &arg1);

    void displayAllLinks();

    void on_pushButton_deleteScientist_clicked();

    void on_pushButton_deleteJoin_clicked();

    void on_pushButton_deleteComputer_clicked();

    void displayLinks(std::vector<Computer> computers);

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
    LinkService linkService;
};

#endif // MAINWINDOW_H
