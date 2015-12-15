#ifndef EDITDATABASE_H
#define EDITDATABASE_H

#include <QDialog>

namespace Ui {
class editDatabase;
}

class editDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit editDatabase(QWidget *parent = 0);
    ~editDatabase();

private slots:
    void on_radioButton_editScientist_clicked();

    void on_radioButton_editComputer_clicked();

    void on_radioButton_editJoin_clicked();

    void on_checkBox_editWasBuilt_clicked();

private:
    Ui::editDatabase *ui;
};

#endif // EDITDATABASE_H
