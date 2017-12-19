/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *simulateButton;
    QGroupBox *userGroup;
    QSpinBox *constantUsers;
    QLabel *fromUsersLabel;
    QSpinBox *fromUsers;
    QLabel *toUsersLabel;
    QSpinBox *toUsers;
    QCheckBox *randomUsers;
    QGroupBox *jobsGroup;
    QSpinBox *constantJobs;
    QLabel *fromJobsLabel;
    QSpinBox *fromJobs;
    QLabel *toJobsLabel;
    QSpinBox *toJobs;
    QCheckBox *randomJobs;
    QGroupBox *researcherGroup;
    QDoubleSpinBox *constantResearcher;
    QLabel *fromResearcherLabel;
    QDoubleSpinBox *fromResearcher;
    QLabel *toResearcherLabel;
    QDoubleSpinBox *toResearcher;
    QCheckBox *randomResearcher;
    QGroupBox *studentGroup;
    QDoubleSpinBox *constantStudentBudget;
    QLabel *fromStudentLabel;
    QDoubleSpinBox *fromStudent;
    QLabel *toStudentLabel;
    QDoubleSpinBox *toStudent;
    QCheckBox *randomStudent;
    QGroupBox *dateGroup;
    QCheckBox *nowDate;
    QDateTimeEdit *startDateTimeEdit;
    QGroupBox *requestsEndDate;
    QSpinBox *requestsSpinBox;
    QGroupBox *nodesGroup;
    QSpinBox *nodesSpinBox;
    QGroupBox *coresGroup;
    QSpinBox *coresSpinBox;
    QGroupBox *usagePriceGroup;
    QDoubleSpinBox *usagePriceSpinBox;
    QGroupBox *operationalCostGroup;
    QDoubleSpinBox *operationalCostSpinBox;
    QTextBrowser *outputBox;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuSupercomputer_Simulation;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(863, 472);
        MainWindow->setMinimumSize(QSize(863, 472));
        MainWindow->setMaximumSize(QSize(863, 472));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        simulateButton = new QPushButton(centralWidget);
        simulateButton->setObjectName(QStringLiteral("simulateButton"));
        simulateButton->setGeometry(QRect(280, 380, 101, 51));
        simulateButton->setCursor(QCursor(Qt::PointingHandCursor));
        userGroup = new QGroupBox(centralWidget);
        userGroup->setObjectName(QStringLiteral("userGroup"));
        userGroup->setGeometry(QRect(20, 20, 171, 71));
        userGroup->setCheckable(false);
        constantUsers = new QSpinBox(userGroup);
        constantUsers->setObjectName(QStringLiteral("constantUsers"));
        constantUsers->setGeometry(QRect(50, 30, 71, 23));
        constantUsers->setProperty("showGroupSeparator", QVariant(true));
        constantUsers->setMaximum(1000);
        fromUsersLabel = new QLabel(userGroup);
        fromUsersLabel->setObjectName(QStringLiteral("fromUsersLabel"));
        fromUsersLabel->setGeometry(QRect(20, 20, 28, 14));
        fromUsers = new QSpinBox(userGroup);
        fromUsers->setObjectName(QStringLiteral("fromUsers"));
        fromUsers->setGeometry(QRect(10, 40, 71, 23));
        toUsersLabel = new QLabel(userGroup);
        toUsersLabel->setObjectName(QStringLiteral("toUsersLabel"));
        toUsersLabel->setGeometry(QRect(100, 20, 13, 14));
        toUsers = new QSpinBox(userGroup);
        toUsers->setObjectName(QStringLiteral("toUsers"));
        toUsers->setGeometry(QRect(90, 40, 71, 23));
        toUsers->setMinimum(1);
        toUsers->setMaximum(1000);
        randomUsers = new QCheckBox(userGroup);
        randomUsers->setObjectName(QStringLiteral("randomUsers"));
        randomUsers->setGeometry(QRect(100, 0, 71, 16));
        randomUsers->setCursor(QCursor(Qt::PointingHandCursor));
        toUsers->raise();
        fromUsersLabel->raise();
        fromUsers->raise();
        constantUsers->raise();
        toUsersLabel->raise();
        randomUsers->raise();
        jobsGroup = new QGroupBox(centralWidget);
        jobsGroup->setObjectName(QStringLiteral("jobsGroup"));
        jobsGroup->setGeometry(QRect(210, 20, 171, 71));
        jobsGroup->setCheckable(false);
        constantJobs = new QSpinBox(jobsGroup);
        constantJobs->setObjectName(QStringLiteral("constantJobs"));
        constantJobs->setGeometry(QRect(50, 30, 71, 23));
        constantJobs->setProperty("showGroupSeparator", QVariant(true));
        constantJobs->setMaximum(1000);
        fromJobsLabel = new QLabel(jobsGroup);
        fromJobsLabel->setObjectName(QStringLiteral("fromJobsLabel"));
        fromJobsLabel->setGeometry(QRect(20, 20, 28, 14));
        fromJobs = new QSpinBox(jobsGroup);
        fromJobs->setObjectName(QStringLiteral("fromJobs"));
        fromJobs->setGeometry(QRect(10, 40, 71, 23));
        fromJobs->setMaximum(1000);
        toJobsLabel = new QLabel(jobsGroup);
        toJobsLabel->setObjectName(QStringLiteral("toJobsLabel"));
        toJobsLabel->setGeometry(QRect(100, 20, 13, 14));
        toJobs = new QSpinBox(jobsGroup);
        toJobs->setObjectName(QStringLiteral("toJobs"));
        toJobs->setGeometry(QRect(90, 40, 71, 23));
        toJobs->setMaximum(1000);
        randomJobs = new QCheckBox(jobsGroup);
        randomJobs->setObjectName(QStringLiteral("randomJobs"));
        randomJobs->setGeometry(QRect(100, 0, 71, 16));
        randomJobs->setCursor(QCursor(Qt::PointingHandCursor));
        fromJobsLabel->raise();
        fromJobs->raise();
        toJobsLabel->raise();
        toJobs->raise();
        randomJobs->raise();
        constantJobs->raise();
        researcherGroup = new QGroupBox(centralWidget);
        researcherGroup->setObjectName(QStringLiteral("researcherGroup"));
        researcherGroup->setGeometry(QRect(210, 110, 171, 71));
        researcherGroup->setCheckable(false);
        constantResearcher = new QDoubleSpinBox(researcherGroup);
        constantResearcher->setObjectName(QStringLiteral("constantResearcher"));
        constantResearcher->setGeometry(QRect(50, 30, 71, 23));
        constantResearcher->setProperty("showGroupSeparator", QVariant(true));
        constantResearcher->setMinimum(1);
        constantResearcher->setMaximum(1000);
        constantResearcher->setSingleStep(0.01);
        fromResearcherLabel = new QLabel(researcherGroup);
        fromResearcherLabel->setObjectName(QStringLiteral("fromResearcherLabel"));
        fromResearcherLabel->setGeometry(QRect(20, 20, 28, 14));
        fromResearcher = new QDoubleSpinBox(researcherGroup);
        fromResearcher->setObjectName(QStringLiteral("fromResearcher"));
        fromResearcher->setGeometry(QRect(20, 40, 61, 23));
        fromResearcher->setMinimum(1);
        fromResearcher->setMaximum(1000.99);
        fromResearcher->setSingleStep(0.01);
        toResearcherLabel = new QLabel(researcherGroup);
        toResearcherLabel->setObjectName(QStringLiteral("toResearcherLabel"));
        toResearcherLabel->setGeometry(QRect(100, 20, 13, 14));
        toResearcher = new QDoubleSpinBox(researcherGroup);
        toResearcher->setObjectName(QStringLiteral("toResearcher"));
        toResearcher->setGeometry(QRect(100, 40, 61, 23));
        toResearcher->setMinimum(1);
        toResearcher->setMaximum(1000);
        toResearcher->setSingleStep(0.01);
        randomResearcher = new QCheckBox(researcherGroup);
        randomResearcher->setObjectName(QStringLiteral("randomResearcher"));
        randomResearcher->setGeometry(QRect(100, 0, 71, 16));
        randomResearcher->setCursor(QCursor(Qt::PointingHandCursor));
        fromResearcherLabel->raise();
        fromResearcher->raise();
        toResearcherLabel->raise();
        toResearcher->raise();
        randomResearcher->raise();
        constantResearcher->raise();
        studentGroup = new QGroupBox(centralWidget);
        studentGroup->setObjectName(QStringLiteral("studentGroup"));
        studentGroup->setGeometry(QRect(20, 110, 171, 71));
        studentGroup->setCheckable(false);
        constantStudentBudget = new QDoubleSpinBox(studentGroup);
        constantStudentBudget->setObjectName(QStringLiteral("constantStudentBudget"));
        constantStudentBudget->setGeometry(QRect(50, 30, 71, 23));
        constantStudentBudget->setProperty("showGroupSeparator", QVariant(true));
        constantStudentBudget->setMinimum(1);
        constantStudentBudget->setMaximum(1000);
        constantStudentBudget->setSingleStep(0.01);
        fromStudentLabel = new QLabel(studentGroup);
        fromStudentLabel->setObjectName(QStringLiteral("fromStudentLabel"));
        fromStudentLabel->setGeometry(QRect(20, 20, 28, 14));
        fromStudent = new QDoubleSpinBox(studentGroup);
        fromStudent->setObjectName(QStringLiteral("fromStudent"));
        fromStudent->setGeometry(QRect(20, 40, 61, 23));
        fromStudent->setMinimum(1);
        fromStudent->setMaximum(1000);
        fromStudent->setSingleStep(0.01);
        toStudentLabel = new QLabel(studentGroup);
        toStudentLabel->setObjectName(QStringLiteral("toStudentLabel"));
        toStudentLabel->setGeometry(QRect(100, 20, 13, 14));
        toStudent = new QDoubleSpinBox(studentGroup);
        toStudent->setObjectName(QStringLiteral("toStudent"));
        toStudent->setGeometry(QRect(100, 40, 61, 23));
        toStudent->setMinimum(1);
        toStudent->setMaximum(1000);
        toStudent->setSingleStep(0.01);
        randomStudent = new QCheckBox(studentGroup);
        randomStudent->setObjectName(QStringLiteral("randomStudent"));
        randomStudent->setGeometry(QRect(100, 0, 71, 16));
        randomStudent->setCursor(QCursor(Qt::PointingHandCursor));
        fromStudentLabel->raise();
        fromStudent->raise();
        toStudentLabel->raise();
        toStudent->raise();
        randomStudent->raise();
        constantStudentBudget->raise();
        dateGroup = new QGroupBox(centralWidget);
        dateGroup->setObjectName(QStringLiteral("dateGroup"));
        dateGroup->setGeometry(QRect(20, 200, 171, 71));
        dateGroup->setCheckable(false);
        nowDate = new QCheckBox(dateGroup);
        nowDate->setObjectName(QStringLiteral("nowDate"));
        nowDate->setGeometry(QRect(110, 0, 61, 16));
        nowDate->setCursor(QCursor(Qt::PointingHandCursor));
        nowDate->setChecked(true);
        startDateTimeEdit = new QDateTimeEdit(dateGroup);
        startDateTimeEdit->setObjectName(QStringLiteral("startDateTimeEdit"));
        startDateTimeEdit->setEnabled(false);
        startDateTimeEdit->setGeometry(QRect(20, 30, 141, 23));
        requestsEndDate = new QGroupBox(centralWidget);
        requestsEndDate->setObjectName(QStringLiteral("requestsEndDate"));
        requestsEndDate->setGeometry(QRect(210, 200, 171, 71));
        requestsSpinBox = new QSpinBox(requestsEndDate);
        requestsSpinBox->setObjectName(QStringLiteral("requestsSpinBox"));
        requestsSpinBox->setGeometry(QRect(40, 30, 81, 23));
        requestsSpinBox->setMinimum(1);
        requestsSpinBox->setMaximum(604800);
        requestsSpinBox->setValue(10);
        nodesGroup = new QGroupBox(centralWidget);
        nodesGroup->setObjectName(QStringLiteral("nodesGroup"));
        nodesGroup->setGeometry(QRect(20, 360, 111, 71));
        nodesSpinBox = new QSpinBox(nodesGroup);
        nodesSpinBox->setObjectName(QStringLiteral("nodesSpinBox"));
        nodesSpinBox->setGeometry(QRect(20, 30, 61, 23));
        nodesSpinBox->setMinimum(128);
        nodesSpinBox->setMaximum(512);
        coresGroup = new QGroupBox(centralWidget);
        coresGroup->setObjectName(QStringLiteral("coresGroup"));
        coresGroup->setGeometry(QRect(150, 360, 111, 71));
        coresSpinBox = new QSpinBox(coresGroup);
        coresSpinBox->setObjectName(QStringLiteral("coresSpinBox"));
        coresSpinBox->setGeometry(QRect(20, 30, 61, 23));
        coresSpinBox->setMinimum(16);
        coresSpinBox->setMaximum(64);
        usagePriceGroup = new QGroupBox(centralWidget);
        usagePriceGroup->setObjectName(QStringLiteral("usagePriceGroup"));
        usagePriceGroup->setGeometry(QRect(20, 280, 171, 71));
        usagePriceSpinBox = new QDoubleSpinBox(usagePriceGroup);
        usagePriceSpinBox->setObjectName(QStringLiteral("usagePriceSpinBox"));
        usagePriceSpinBox->setGeometry(QRect(40, 30, 101, 23));
        usagePriceSpinBox->setDecimals(6);
        usagePriceSpinBox->setMinimum(1e-06);
        usagePriceSpinBox->setMaximum(5);
        usagePriceSpinBox->setSingleStep(1e-06);
        operationalCostGroup = new QGroupBox(centralWidget);
        operationalCostGroup->setObjectName(QStringLiteral("operationalCostGroup"));
        operationalCostGroup->setGeometry(QRect(210, 280, 171, 71));
        operationalCostSpinBox = new QDoubleSpinBox(operationalCostGroup);
        operationalCostSpinBox->setObjectName(QStringLiteral("operationalCostSpinBox"));
        operationalCostSpinBox->setGeometry(QRect(40, 30, 101, 23));
        operationalCostSpinBox->setDecimals(6);
        operationalCostSpinBox->setMinimum(1e-06);
        operationalCostSpinBox->setMaximum(5);
        operationalCostSpinBox->setSingleStep(1e-06);
        outputBox = new QTextBrowser(centralWidget);
        outputBox->setObjectName(QStringLiteral("outputBox"));
        outputBox->setGeometry(QRect(410, 40, 431, 381));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(600, 10, 41, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 863, 19));
        menuSupercomputer_Simulation = new QMenu(menuBar);
        menuSupercomputer_Simulation->setObjectName(QStringLiteral("menuSupercomputer_Simulation"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSupercomputer_Simulation->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Supercomputer", 0));
        simulateButton->setText(QApplication::translate("MainWindow", "Run simulation", 0));
        userGroup->setTitle(QApplication::translate("MainWindow", "Number of users", 0));
        fromUsersLabel->setText(QApplication::translate("MainWindow", "From", 0));
        toUsersLabel->setText(QApplication::translate("MainWindow", "To", 0));
        randomUsers->setText(QApplication::translate("MainWindow", "random", 0));
        jobsGroup->setTitle(QApplication::translate("MainWindow", "Number of jobs", 0));
        fromJobsLabel->setText(QApplication::translate("MainWindow", "From", 0));
        toJobsLabel->setText(QApplication::translate("MainWindow", "To", 0));
        randomJobs->setText(QApplication::translate("MainWindow", "random", 0));
        researcherGroup->setTitle(QApplication::translate("MainWindow", "Researcher Budget", 0));
        fromResearcherLabel->setText(QApplication::translate("MainWindow", "From", 0));
        toResearcherLabel->setText(QApplication::translate("MainWindow", "To", 0));
        randomResearcher->setText(QApplication::translate("MainWindow", "random", 0));
        studentGroup->setTitle(QApplication::translate("MainWindow", "Student Budget", 0));
        fromStudentLabel->setText(QApplication::translate("MainWindow", "From", 0));
        toStudentLabel->setText(QApplication::translate("MainWindow", "To", 0));
        randomStudent->setText(QApplication::translate("MainWindow", "random", 0));
        dateGroup->setTitle(QApplication::translate("MainWindow", "Starting Date", 0));
        nowDate->setText(QApplication::translate("MainWindow", "now", 0));
        startDateTimeEdit->setDisplayFormat(QApplication::translate("MainWindow", "dd/MM/yyyy HH:mm:ss", 0));
        requestsEndDate->setTitle(QApplication::translate("MainWindow", "Requests Span (seconds)", 0));
        nodesGroup->setTitle(QApplication::translate("MainWindow", "Number of nodes", 0));
        coresGroup->setTitle(QApplication::translate("MainWindow", "Cores per node", 0));
        usagePriceGroup->setTitle(QApplication::translate("MainWindow", "Usage Price \302\243 (per core)", 0));
#ifndef QT_NO_TOOLTIP
        operationalCostGroup->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        operationalCostGroup->setTitle(QApplication::translate("MainWindow", "Operational Cost \302\243", 0));
        label->setText(QApplication::translate("MainWindow", "Output", 0));
        menuSupercomputer_Simulation->setTitle(QApplication::translate("MainWindow", "Supercomputer Simulation", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
