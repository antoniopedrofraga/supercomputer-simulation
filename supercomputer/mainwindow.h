#ifndef MAINWINDOW_H //Define header if it's not defined
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


//! MainWindow class
/*!
  This object is the GUI.
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //! MainWindow object default contructor.
    /*!
        Initializes a MainWindow object.
    */
    explicit MainWindow(QWidget *parent = 0);

    //! MainWindow object default destructor.
    /*!
        Destructs a MainWindow object.
    */
    ~MainWindow();

private slots:

    //! Public method. Method to set default values to GUI inputs.
    void set_initial_values();

    //! Public method. Method to hide constant number of users value, showing bounds of randomly generated number of users.
    /*!
        \param bool show. True if show, false if hide.
    */
    void show_random_users(bool show);

    //! Public method. Method to hide constant number of jobs value, showing bounds of randomly generated number of jobs.
    /*!
        \param bool show. True if show, false if hide.
    */
    void show_random_jobs(bool show);

    //! Public method. Method to hide constant student budget, showing bounds of randomly generated student budget.
    /*!
        \param bool show. True if show, false if hide.
    */
    void show_random_student_budget(bool show);

    //! Public method. Method to hide constant researcher budget, showing bounds of randomly generated researcher budget.
    /*!
        \param bool show. True if show, false if hide.
    */
    void show_random_researcher_budget(bool show);

    //! Public method. Method to alternate between randomly generated and constant number of users.
    /*!
        \param bool checked. True if random, false if constant.
    */
    void on_randomUsers_toggled(bool checked);

    //! Public method. Method to alternate between randomly generated and constant number of jobs.
    /*!
        \param bool checked. True if random, false if constant.
    */
    void on_randomJobs_toggled(bool checked);

    //! Public method. Method to alternate between randomly generated and constant student budget.
    /*!
        \param bool checked. True if random, false if constant.
    */
    void on_randomStudent_toggled(bool checked);

    //! Public method. Method to alternate between randomly generated and constant researcher budget.
    /*!
        \param bool checked. True if random, false if constant.
    */
    void on_randomResearcher_toggled(bool checked);

    //! Public method. Method to alternate between simulation running in a defined date or present.
    /*!
        \param bool checked. True if present, false if defined date.
    */
    void on_nowDate_toggled(bool checked);

    //! Public method. Method to run a simulation.
    void on_simulateButton_released();

    //! Public method. This method is triggered when the constant number of users spin box value is changed.
    /*!
        \param int arg1. New value of constant number of users.
    */
    void on_constantUsers_valueChanged(int arg1);

    //! Public method. This method is triggered when the constant number of jobs spin box value is changed.
    /*!
        \param int arg1. New value of constant number of jobs.
    */
    void on_constantJobs_valueChanged(int arg1);

    //! Public method. This method is triggered when the constant student budget spin box value is changed.
    /*!
        \param double arg1. New value of constant student budget.
    */
    void on_constantStudentBudget_valueChanged(double arg1);

    //! Public method. This method is triggered when the constant researcher budget spin box value is changed.
    /*!
        \param double arg1. New value of constant researcher budget.
    */
    void on_constantResearcher_valueChanged(double arg1);

    //! Public method. This method is triggered when the requests time span spin box value is changed.
    /*!
        \param int arg1. New value of requests time span.
    */
    void on_requestsSpinBox_valueChanged(int arg1);

    //! Public method. This method is triggered when the usage price spin box value is changed.
    /*!
        \param double arg1. New value of usage price.
    */
    void on_usagePriceSpinBox_valueChanged(double arg1);

    //! Public method. This method is triggered when the operational cost spin box value is changed.
    /*!
        \param double arg1. New value of operational cost.
    */
    void on_operationalCostSpinBox_valueChanged(double arg1);

    //! Public method. This method is triggered when the number of nodes spin box value is changed.
    /*!
        \param int arg1. New value of number of nodes.
    */
    void on_nodesSpinBox_valueChanged(int arg1);

    //! Public method. This method is triggered when the number of cores spin box value is changed.
    /*!
        \param int arg1. New value of number of cores.
    */
    void on_coresSpinBox_valueChanged(int arg1);

    //! Public method. This method is triggered when the simulation starting date value is changed.
    /*!
        \param const QDateTime &dateTime. New simulation starting date.
    */
    void on_startDateTimeEdit_dateTimeChanged(const QDateTime &dateTime);

    //! Public method. This method is triggered when the lower bound of randomly generated numbers of users value is changed.
    /*!
        \param int arg1. New lower bound of randomly generated numbers of users.
    */
    void on_fromUsers_valueChanged(int arg1);

    //! Public method. This method is triggered when the upper bound of randomly generated numbers of users value is changed.
    /*!
        \param int arg1. New upper bound of randomly generated numbers of users.
    */
    void on_toUsers_valueChanged(int arg1);

    //! Public method. This method is triggered when the lower bound of randomly generated numbers of jobs value is changed.
    /*!
        \param int arg1. New lower bound of randomly generated numbers of jobs.
    */
    void on_fromJobs_valueChanged(int arg1);

    //! Public method. This method is triggered when the upper bound of randomly generated numbers of jobs value is changed.
    /*!
        \param int arg1. New upper bound of randomly generated numbers of jobs.
    */
    void on_toJobs_valueChanged(int arg1);

    //! Public method. This method is triggered when the lower bound of randomly generated student budget value is changed.
    /*!
        \param double arg1. New lower bound of randomly generated student budget.
    */
    void on_fromStudent_valueChanged(double arg1);

    //! Public method. This method is triggered when the upper bound of randomly generated student budget value is changed.
    /*!
        \param double arg1. New upper bound of randomly generated student budget.
    */
    void on_toStudent_valueChanged(double arg1);

    //! Public method. This method is triggered when the lower bound of randomly generated researcher budget value is changed.
    /*!
        \param double arg1. New lower bound of randomly generated researcher budget.
    */
    void on_fromResearcher_valueChanged(double arg1);

    //! Public method. This method is triggered when the upper bound of randomly generated researcher budget value is changed.
    /*!
        \param double arg1. New upper bound of randomly generated researcher budget.
    */
    void on_toResearcher_valueChanged(double arg1);

    void on_simulateButton_pressed();

private:
    Ui::MainWindow *ui; /*! Private Ui::MainWindow *ui. The GUI. */
    Configuration * config; /*! Private Configuration. Object containing the configuration of the simulation. */
};

#endif // MAINWINDOW_H
