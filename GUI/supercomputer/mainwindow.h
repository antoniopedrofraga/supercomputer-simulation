#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "configuration/configuration.h"
#include "system/system.h"
#include "utils/utils.h"

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

    void on_randomUser_clicked(bool checked);

    void on_randomUsers_clicked(bool checked);

    void on_constantUsers_valueChanged(int arg1);

    void on_randomUsers_toggled(bool checked);

    void on_randomJobs_toggled(bool checked);

    void on_simulateButton_released();

    void on_randomStudent_toggled(bool checked);

    void on_randomResearcher_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    Configuration * config;
};

#endif // MAINWINDOW_H
