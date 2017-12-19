#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <ctime>

#include "src/configuration/configuration.h"
#include "src/system/system.h"
#include "src/utils/utils.h"

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
    void set_initial_values();
    void show_random_users(bool show);
    void show_random_jobs(bool show);
    void show_random_student_budget(bool show);
    void show_random_researcher_budget(bool show);

    void on_constantUsers_valueChanged(int arg1);

    void on_randomUsers_toggled(bool checked);

    void on_randomJobs_toggled(bool checked);

    void on_simulateButton_released();

    void on_randomStudent_toggled(bool checked);

    void on_randomResearcher_toggled(bool checked);

    void on_nowDate_toggled(bool checked);

    void on_constantJobs_valueChanged(int arg1);

    void on_constantStudentBudget_valueChanged(double arg1);

    void on_constantResearcher_valueChanged(double arg1);

    void on_requestsSpinBox_valueChanged(int arg1);

    void on_usagePriceSpinBox_valueChanged(double arg1);

    void on_operationalCostSpinBox_valueChanged(double arg1);

    void on_nodesSpinBox_valueChanged(int arg1);

    void on_coresSpinBox_valueChanged(int arg1);

    void on_startDateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_fromUsers_valueChanged(int arg1);

    void on_toUsers_valueChanged(int arg1);

    void on_fromJobs_valueChanged(int arg1);

    void on_toJobs_valueChanged(int arg1);

    void on_fromStudent_valueChanged(double arg1);

    void on_toStudent_valueChanged(double arg1);

    void on_fromResearcher_valueChanged(double arg1);

    void on_toResearcher_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    Configuration * config;
};

#endif // MAINWINDOW_H
