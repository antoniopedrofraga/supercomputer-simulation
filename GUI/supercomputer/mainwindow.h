#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void show_random_users(bool show);
    void show_random_jobs(bool show);

    void on_randomUser_clicked(bool checked);

    void on_randomUsers_clicked(bool checked);

    void on_constantUsers_valueChanged(int arg1);

    void on_randomUsers_toggled(bool checked);

    void on_randomJobs_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
