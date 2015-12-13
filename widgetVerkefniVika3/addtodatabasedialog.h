#ifndef ADDTODATABASEDIALOG_H
#define ADDTODATABASEDIALOG_H

#include <QDialog>

#include "scientistservice.h"
#include "computerservice.h"

namespace Ui {
class AddToDatabaseDialog;
}

class AddToDatabaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddToDatabaseDialog(QWidget *parent = 0);
    ~AddToDatabaseDialog();

private slots:
    void on_radioButton_Scientist_clicked();

    void on_radioButton_Computer_clicked();

    void on_radioButton_Join_clicked();

    void on_pushButton_AddToDatabase_clicked();

private:
    Ui::AddToDatabaseDialog *ui;

    ScientistService scientistService;
    ComputerService computerService;
};

#endif // ADDTODATABASEDIALOG_H
