/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_AddScientist;
    QAction *action_DeleteScientist;
    QAction *action_AddComputer;
    QAction *action_DeleteComputer;
    QAction *action_Search;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_Scientists;
    QTableWidget *table_Scientists;
    QWidget *tab_Computers;
    QTableWidget *table_Computers;
    QWidget *tab_Join;
    QTableWidget *table_Join;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(651, 456);
        action_AddScientist = new QAction(MainWindow);
        action_AddScientist->setObjectName(QStringLiteral("action_AddScientist"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/addPerson.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_AddScientist->setIcon(icon);
        action_DeleteScientist = new QAction(MainWindow);
        action_DeleteScientist->setObjectName(QStringLiteral("action_DeleteScientist"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/images/deletePerson.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_DeleteScientist->setIcon(icon1);
        action_AddComputer = new QAction(MainWindow);
        action_AddComputer->setObjectName(QStringLiteral("action_AddComputer"));
        action_AddComputer->setIcon(icon1);
        action_DeleteComputer = new QAction(MainWindow);
        action_DeleteComputer->setObjectName(QStringLiteral("action_DeleteComputer"));
        action_DeleteComputer->setIcon(icon1);
        action_Search = new QAction(MainWindow);
        action_Search->setObjectName(QStringLiteral("action_Search"));
        action_Search->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_Scientists = new QWidget();
        tab_Scientists->setObjectName(QStringLiteral("tab_Scientists"));
        table_Scientists = new QTableWidget(tab_Scientists);
        if (table_Scientists->columnCount() < 4)
            table_Scientists->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_Scientists->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_Scientists->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_Scientists->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_Scientists->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_Scientists->setObjectName(QStringLiteral("table_Scientists"));
        table_Scientists->setGeometry(QRect(10, 10, 601, 351));
        table_Scientists->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_Scientists->setAlternatingRowColors(true);
        table_Scientists->setSortingEnabled(true);
        table_Scientists->horizontalHeader()->setCascadingSectionResizes(false);
        table_Scientists->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_Scientists->horizontalHeader()->setStretchLastSection(true);
        table_Scientists->verticalHeader()->setCascadingSectionResizes(false);
        table_Scientists->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        table_Scientists->verticalHeader()->setStretchLastSection(false);
        tabWidget->addTab(tab_Scientists, QString());
        tab_Computers = new QWidget();
        tab_Computers->setObjectName(QStringLiteral("tab_Computers"));
        table_Computers = new QTableWidget(tab_Computers);
        if (table_Computers->columnCount() < 4)
            table_Computers->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_Computers->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_Computers->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_Computers->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_Computers->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        table_Computers->setObjectName(QStringLiteral("table_Computers"));
        table_Computers->setGeometry(QRect(10, 10, 601, 351));
        table_Computers->setSortingEnabled(true);
        table_Computers->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_Computers->horizontalHeader()->setStretchLastSection(true);
        tabWidget->addTab(tab_Computers, QString());
        tab_Join = new QWidget();
        tab_Join->setObjectName(QStringLiteral("tab_Join"));
        table_Join = new QTableWidget(tab_Join);
        if (table_Join->columnCount() < 2)
            table_Join->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_Join->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_Join->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        table_Join->setObjectName(QStringLiteral("table_Join"));
        table_Join->setGeometry(QRect(10, 10, 601, 351));
        table_Join->setSortingEnabled(true);
        table_Join->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        table_Join->horizontalHeader()->setStretchLastSection(true);
        tabWidget->addTab(tab_Join, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 651, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(action_AddScientist);
        mainToolBar->addAction(action_DeleteScientist);
        mainToolBar->addAction(action_AddComputer);
        mainToolBar->addAction(action_DeleteComputer);
        mainToolBar->addAction(action_Search);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_AddScientist->setText(QApplication::translate("MainWindow", "add scientist", 0));
        action_DeleteScientist->setText(QApplication::translate("MainWindow", "delete scientist", 0));
        action_AddComputer->setText(QApplication::translate("MainWindow", "add computer", 0));
        action_DeleteComputer->setText(QApplication::translate("MainWindow", "delete computer", 0));
        action_Search->setText(QApplication::translate("MainWindow", "search", 0));
        QTableWidgetItem *___qtablewidgetitem = table_Scientists->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_Scientists->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "sex", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_Scientists->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "yearBorn", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_Scientists->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "yearDied", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Scientists), QApplication::translate("MainWindow", "Scientists", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_Computers->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "New Column", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_Computers->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_Computers->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem7 = table_Computers->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Was built", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Computers), QApplication::translate("MainWindow", "Computers", 0));
        QTableWidgetItem *___qtablewidgetitem8 = table_Join->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "New Column", 0));
        QTableWidgetItem *___qtablewidgetitem9 = table_Join->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Computer", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_Join), QApplication::translate("MainWindow", "Join", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
