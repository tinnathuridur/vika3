#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "models/scientist.h"
//#include "services/scientistservice.h"


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
    void on_action_addScientist_triggered();

    void on_action_deleteScientist_triggered();

    void on_table_Scientist_clicked(const QModelIndex &index);

    void on_table_Computers_clicked(const QModelIndex &index);

    void on_table_Join_clicked(const QModelIndex &index);

    void on_action_Add_computer_triggered();

    void on_action_Delete_computer_triggered();

    void on_action_Search_triggered();

private:
    Ui::MainWindow *ui;

    /*std::vector<Scientist> currentlyDisplayedScientists;

    void displayAllScientists();
    void displayScientists(std::vector<Scientist> scientists);

    ScientistService scientistService;*/

};

#endif // MAINWINDOW_H
