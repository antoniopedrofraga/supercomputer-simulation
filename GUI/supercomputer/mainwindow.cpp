#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config = new Configuration();

    ui->constantUsers->setValue(100);
    ui->fromUsers->setValue(1);
    ui->toUsers->setValue(100);

    ui->constantJobs->setValue(100);
    ui->fromJobs->setValue(1);
    ui->toJobs->setValue(100);

    show_random_users(false);
    show_random_jobs(false);
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

void MainWindow::on_constantUsers_valueChanged(int arg1)
{

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

void MainWindow::on_simulateButton_released()
{
    System * system = new System(config);
    QString qstr = QString::fromStdString(system->get_results());
    ui->outputBox->setText(qstr);
}
