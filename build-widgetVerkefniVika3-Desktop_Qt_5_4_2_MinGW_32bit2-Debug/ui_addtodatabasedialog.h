/********************************************************************************
** Form generated from reading UI file 'addtodatabasedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTODATABASEDIALOG_H
#define UI_ADDTODATABASEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_AddToDatabaseDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_9;
    QPushButton *pushButton_AddToDatabase;
    QRadioButton *radioButton_Scientist;
    QRadioButton *radioButton_Computer;
    QRadioButton *radioButton_Join;
    QLineEdit *lineEdit_Scientist_Name;
    QLineEdit *lineEdit_Scientist_YearBorn;
    QLineEdit *lineEdit_Scientist_YearDied;
    QLineEdit *lineEdit_Computer_Name;
    QLineEdit *lineEdit_Computer_YearBuilt;
    QLineEdit *lineEdit_Join_Scientist;
    QLineEdit *lineEdit_Join_Computer;
    QLabel *label_6;
    QComboBox *comboBox_Scientist_Sex;
    QComboBox *comboBox_Computer_BuiltOrNot;
    QLabel *errorLabel_Scientist;
    QLabel *errorLabel_Computer;
    QLabel *errorLabel_Join;
    QComboBox *comboBox_Computer_Type;

    void setupUi(QDialog *AddToDatabaseDialog)
    {
        if (AddToDatabaseDialog->objectName().isEmpty())
            AddToDatabaseDialog->setObjectName(QStringLiteral("AddToDatabaseDialog"));
        AddToDatabaseDialog->resize(644, 502);
        label = new QLabel(AddToDatabaseDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 190, 55, 16));
        label_2 = new QLabel(AddToDatabaseDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 220, 55, 16));
        label_3 = new QLabel(AddToDatabaseDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 250, 55, 16));
        label_4 = new QLabel(AddToDatabaseDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 280, 55, 16));
        label_5 = new QLabel(AddToDatabaseDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(230, 280, 71, 16));
        label_7 = new QLabel(AddToDatabaseDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(230, 190, 55, 16));
        label_8 = new QLabel(AddToDatabaseDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 250, 71, 16));
        label_11 = new QLabel(AddToDatabaseDialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(440, 190, 55, 16));
        label_12 = new QLabel(AddToDatabaseDialog);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(440, 220, 71, 16));
        label_9 = new QLabel(AddToDatabaseDialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 80, 291, 31));
        pushButton_AddToDatabase = new QPushButton(AddToDatabaseDialog);
        pushButton_AddToDatabase->setObjectName(QStringLiteral("pushButton_AddToDatabase"));
        pushButton_AddToDatabase->setGeometry(QRect(140, 370, 291, 51));
        radioButton_Scientist = new QRadioButton(AddToDatabaseDialog);
        radioButton_Scientist->setObjectName(QStringLiteral("radioButton_Scientist"));
        radioButton_Scientist->setGeometry(QRect(60, 140, 95, 20));
        radioButton_Computer = new QRadioButton(AddToDatabaseDialog);
        radioButton_Computer->setObjectName(QStringLiteral("radioButton_Computer"));
        radioButton_Computer->setGeometry(QRect(260, 140, 95, 20));
        radioButton_Join = new QRadioButton(AddToDatabaseDialog);
        radioButton_Join->setObjectName(QStringLiteral("radioButton_Join"));
        radioButton_Join->setGeometry(QRect(470, 140, 95, 20));
        lineEdit_Scientist_Name = new QLineEdit(AddToDatabaseDialog);
        lineEdit_Scientist_Name->setObjectName(QStringLiteral("lineEdit_Scientist_Name"));
        lineEdit_Scientist_Name->setEnabled(false);
        lineEdit_Scientist_Name->setGeometry(QRect(90, 190, 113, 22));
        lineEdit_Scientist_YearBorn = new QLineEdit(AddToDatabaseDialog);
        lineEdit_Scientist_YearBorn->setObjectName(QStringLiteral("lineEdit_Scientist_YearBorn"));
        lineEdit_Scientist_YearBorn->setEnabled(false);
        lineEdit_Scientist_YearBorn->setGeometry(QRect(90, 250, 113, 22));
        lineEdit_Scientist_YearDied = new QLineEdit(AddToDatabaseDialog);
        lineEdit_Scientist_YearDied->setObjectName(QStringLiteral("lineEdit_Scientist_YearDied"));
        lineEdit_Scientist_YearDied->setEnabled(false);
        lineEdit_Scientist_YearDied->setGeometry(QRect(90, 280, 113, 22));
        lineEdit_Computer_Name = new QLineEdit(AddToDatabaseDialog);
        lineEdit_Computer_Name->setObjectName(QStringLiteral("lineEdit_Computer_Name"));
        lineEdit_Computer_Name->setEnabled(false);
        lineEdit_Computer_Name->setGeometry(QRect(300, 190, 113, 22));
        lineEdit_Computer_YearBuilt = new QLineEdit(AddToDatabaseDialog);
        lineEdit_Computer_YearBuilt->setObjectName(QStringLiteral("lineEdit_Computer_YearBuilt"));
        lineEdit_Computer_YearBuilt->setEnabled(false);
        lineEdit_Computer_YearBuilt->setGeometry(QRect(300, 250, 113, 22));
        lineEdit_Join_Scientist = new QLineEdit(AddToDatabaseDialog);
        lineEdit_Join_Scientist->setObjectName(QStringLiteral("lineEdit_Join_Scientist"));
        lineEdit_Join_Scientist->setEnabled(false);
        lineEdit_Join_Scientist->setGeometry(QRect(510, 190, 113, 22));
        lineEdit_Join_Computer = new QLineEdit(AddToDatabaseDialog);
        lineEdit_Join_Computer->setObjectName(QStringLiteral("lineEdit_Join_Computer"));
        lineEdit_Join_Computer->setEnabled(false);
        lineEdit_Join_Computer->setGeometry(QRect(510, 220, 113, 22));
        label_6 = new QLabel(AddToDatabaseDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 220, 55, 16));
        comboBox_Scientist_Sex = new QComboBox(AddToDatabaseDialog);
        comboBox_Scientist_Sex->setObjectName(QStringLiteral("comboBox_Scientist_Sex"));
        comboBox_Scientist_Sex->setEnabled(false);
        comboBox_Scientist_Sex->setGeometry(QRect(90, 220, 111, 22));
        comboBox_Scientist_Sex->setEditable(false);
        comboBox_Computer_BuiltOrNot = new QComboBox(AddToDatabaseDialog);
        comboBox_Computer_BuiltOrNot->setObjectName(QStringLiteral("comboBox_Computer_BuiltOrNot"));
        comboBox_Computer_BuiltOrNot->setEnabled(false);
        comboBox_Computer_BuiltOrNot->setGeometry(QRect(300, 280, 111, 22));
        comboBox_Computer_BuiltOrNot->setEditable(false);
        errorLabel_Scientist = new QLabel(AddToDatabaseDialog);
        errorLabel_Scientist->setObjectName(QStringLiteral("errorLabel_Scientist"));
        errorLabel_Scientist->setGeometry(QRect(70, 330, 101, 21));
        errorLabel_Computer = new QLabel(AddToDatabaseDialog);
        errorLabel_Computer->setObjectName(QStringLiteral("errorLabel_Computer"));
        errorLabel_Computer->setGeometry(QRect(280, 330, 101, 21));
        errorLabel_Join = new QLabel(AddToDatabaseDialog);
        errorLabel_Join->setObjectName(QStringLiteral("errorLabel_Join"));
        errorLabel_Join->setGeometry(QRect(490, 330, 101, 21));
        comboBox_Computer_Type = new QComboBox(AddToDatabaseDialog);
        comboBox_Computer_Type->setObjectName(QStringLiteral("comboBox_Computer_Type"));
        comboBox_Computer_Type->setEnabled(false);
        comboBox_Computer_Type->setGeometry(QRect(300, 220, 111, 22));
        comboBox_Computer_Type->setEditable(false);

        retranslateUi(AddToDatabaseDialog);

        QMetaObject::connectSlotsByName(AddToDatabaseDialog);
    } // setupUi

    void retranslateUi(QDialog *AddToDatabaseDialog)
    {
        AddToDatabaseDialog->setWindowTitle(QApplication::translate("AddToDatabaseDialog", "Dialog", 0));
        label->setText(QApplication::translate("AddToDatabaseDialog", "Name:", 0));
        label_2->setText(QApplication::translate("AddToDatabaseDialog", "Sex:", 0));
        label_3->setText(QApplication::translate("AddToDatabaseDialog", "Year born:", 0));
        label_4->setText(QApplication::translate("AddToDatabaseDialog", "Year died:", 0));
        label_5->setText(QApplication::translate("AddToDatabaseDialog", "Built or not:", 0));
        label_7->setText(QApplication::translate("AddToDatabaseDialog", "Name:", 0));
        label_8->setText(QApplication::translate("AddToDatabaseDialog", "Year built:", 0));
        label_11->setText(QApplication::translate("AddToDatabaseDialog", "Scientist:", 0));
        label_12->setText(QApplication::translate("AddToDatabaseDialog", "Computer:", 0));
        label_9->setText(QApplication::translate("AddToDatabaseDialog", "Choose what to add to the Database", 0));
        pushButton_AddToDatabase->setText(QApplication::translate("AddToDatabaseDialog", "Add to database", 0));
        radioButton_Scientist->setText(QApplication::translate("AddToDatabaseDialog", "Scientist", 0));
        radioButton_Computer->setText(QApplication::translate("AddToDatabaseDialog", "Computer", 0));
        radioButton_Join->setText(QApplication::translate("AddToDatabaseDialog", "Join", 0));
        label_6->setText(QApplication::translate("AddToDatabaseDialog", "Type:", 0));
        comboBox_Scientist_Sex->clear();
        comboBox_Scientist_Sex->insertItems(0, QStringList()
         << QApplication::translate("AddToDatabaseDialog", "Male", 0)
         << QApplication::translate("AddToDatabaseDialog", "Female", 0)
        );
        comboBox_Computer_BuiltOrNot->clear();
        comboBox_Computer_BuiltOrNot->insertItems(0, QStringList()
         << QApplication::translate("AddToDatabaseDialog", "Built", 0)
         << QApplication::translate("AddToDatabaseDialog", "Not Built", 0)
        );
        errorLabel_Scientist->setText(QApplication::translate("AddToDatabaseDialog", "Error Scientist", 0));
        errorLabel_Computer->setText(QApplication::translate("AddToDatabaseDialog", "Error Computer", 0));
        errorLabel_Join->setText(QApplication::translate("AddToDatabaseDialog", "Error Join", 0));
        comboBox_Computer_Type->clear();
        comboBox_Computer_Type->insertItems(0, QStringList()
         << QApplication::translate("AddToDatabaseDialog", "Electronic", 0)
         << QApplication::translate("AddToDatabaseDialog", "Mechatronic", 0)
         << QApplication::translate("AddToDatabaseDialog", "Transistor", 0)
         << QApplication::translate("AddToDatabaseDialog", "Other", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class AddToDatabaseDialog: public Ui_AddToDatabaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTODATABASEDIALOG_H
