#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config = new Configuration();

    set_initial_values();
    show_random_users(false);
    show_random_jobs(false);
    show_random_student_budget(false);
    show_random_researcher_budget(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show_random_users(bool show) {
    if (show) {
        ui->fromUsersLabel->show();
        ui->toUsersLabel->show();
        ui->fromUsers->show();
        ui->toUsers->show();
    } else {
        ui->fromUsersLabel->hide();
        ui->toUsersLabel->hide();
        ui->fromUsers->hide();
        ui->toUsers->hide();
    }
}

void MainWindow::show_random_jobs(bool show) {
    if (show) {
        ui->fromJobsLabel->show();
        ui->toJobsLabel->show();
        ui->fromJobs->show();
        ui->toJobs->show();
    } else {
        ui->fromJobsLabel->hide();
        ui->toJobsLabel->hide();
        ui->fromJobs->hide();
        ui->toJobs->hide();
    }
}

void MainWindow::show_random_student_budget(bool show) {
    if (show) {
        ui->fromStudentLabel->show();
        ui->toStudentLabel->show();
        ui->fromStudent->show();
        ui->toStudent->show();
    } else {
        ui->fromStudentLabel->hide();
        ui->toStudentLabel->hide();
        ui->fromStudent->hide();
        ui->toStudent->hide();
    }
}

void MainWindow::show_random_researcher_budget(bool show) {
    if (show) {
        ui->fromResearcherLabel->show();
        ui->toResearcherLabel->show();
        ui->fromResearcher->show();
        ui->toResearcher->show();
    } else {
        ui->fromResearcherLabel->hide();
        ui->toResearcherLabel->hide();
        ui->fromResearcher->hide();
        ui->toResearcher->hide();
    }
}

void MainWindow::on_randomUsers_toggled(bool checked)
{
    if (checked) {
        ui->constantUsers->hide();
        show_random_users(true);
    } else {
        ui->constantUsers->show();
        show_random_users(false);
    }
}

void MainWindow::on_randomJobs_toggled(bool checked)
{
    if (checked) {
        ui->constantJobs->hide();
        show_random_jobs(true);
    } else {
        ui->constantJobs->show();
        show_random_jobs(false);
    }
}

void MainWindow::on_randomStudent_toggled(bool checked)
{
    if (checked) {
        ui->constantStudentBudget->hide();
        show_random_student_budget(true);
    } else {
        ui->constantStudentBudget->show();
        show_random_student_budget(false);
    }
}

void MainWindow::on_randomResearcher_toggled(bool checked)
{
    if (checked) {
        ui->constantResearcher->hide();
        show_random_researcher_budget(true);
    } else {
        ui->constantResearcher->show();
        show_random_researcher_budget(false);
    }
}

void MainWindow::on_constantUsers_valueChanged(int arg1)
{

}


void MainWindow::on_simulateButton_released()
{
    ui->simulateButton->setEnabled(false);
    System * system = new System(config);
    QString qstr = QString::fromStdString(system->get_results());
    ui->outputBox->setText(qstr);
    ui->simulateButton->setEnabled(true);
}

void MainWindow::set_initial_values() {
    ui->constantUsers->setValue(USERS_NR);
    ui->constantUsers->setMinimum(USERS_NR_MIN);
    ui->constantUsers->setMaximum(USERS_NR_MAX);

    ui->fromUsers->setValue(USERS_NR_MIN);
    ui->fromUsers->setMinimum(USERS_NR_MIN);

    ui->toUsers->setValue(USERS_NR_MAX);
    ui->toUsers->setMaximum(USERS_NR_MAX);

    ui->constantJobs->setValue(JOBS_NR);
    ui->constantJobs->setMinimum(JOBS_NR_MIN);
    ui->constantJobs->setMaximum(JOBS_NR_MAX);

    ui->fromJobs->setValue(JOBS_NR_MIN);
    ui->fromJobs->setMinimum(JOBS_NR_MIN);

    ui->toJobs->setValue(JOBS_NR_MAX);
    ui->toJobs->setMaximum(JOBS_NR_MAX);

    ui->nodesSpinBox->setValue(NODES_NR);
    ui->nodesSpinBox->setMinimum(NODES_NR_MIN);
    ui->nodesSpinBox->setMaximum(NODES_NR_MAX);

    ui->coresSpinBox->setValue(CORES_NR);
    ui->coresSpinBox->setMinimum(CORES_NR_MIN);
    ui->coresSpinBox->setMaximum(CORES_NR_MAX);

    ui->constantStudentBudget->setValue(STUDENT_BUDGET);
    ui->constantStudentBudget->setMinimum(STUDENT_BUDGET_MIN);
    ui->constantStudentBudget->setMaximum(STUDENT_BUDGET_MAX);

    ui->fromStudent->setValue(STUDENT_BUDGET_MIN);
    ui->fromStudent->setMinimum(STUDENT_BUDGET_MIN);

    ui->toStudent->setValue(STUDENT_BUDGET_MAX);
    ui->toStudent->setMaximum(STUDENT_BUDGET_MAX);

    ui->constantResearcher->setValue(RESEARCHER_BUDGET);
    ui->constantResearcher->setMinimum(RESEARCHER_BUDGET_MIN);
    ui->constantResearcher->setMaximum(RESEARCHER_BUDGET_MAX);

    ui->fromResearcher->setValue(RESEARCHER_BUDGET_MIN);
    ui->fromResearcher->setMinimum(RESEARCHER_BUDGET_MIN);

    ui->toResearcher->setValue(RESEARCHER_BUDGET_MAX);
    ui->toResearcher->setMaximum(RESEARCHER_BUDGET_MAX);

    ui->operationalCostSpinBox->setValue(OPERATIONAL_COST);
    ui->operationalCostSpinBox->setMinimum(OPERATIONAL_COST_MIN);
    ui->operationalCostSpinBox->setMaximum(OPERATIONAL_COST_MAX);

    ui->usagePriceSpinBox->setValue(USAGE_PRICE);
    ui->usagePriceSpinBox->setMinimum(USAGE_PRICE_MIN);
    ui->usagePriceSpinBox->setMaximum(USAGE_PRICE_MAX);

    ui->requestsSpinBox->setValue(REQUESTS_SPAN);
    ui->requestsSpinBox->setMinimum(REQUESTS_SPAN_MIN);
    ui->requestsSpinBox->setMaximum(REQUESTS_SPAN_MAX);
}

