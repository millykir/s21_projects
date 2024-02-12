#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QRegularExpression>
#include "qcustomplot.h"

extern "C" {
#include "/Users/ahaicris/C7_SmartCalc_v1.0-1/src/s21_calc.h"
}



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();



private slots:

    void on_l_brecket_clicked();

    void on_r_brecket_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_2_clicked();

    void on_nine_clicked();

    void on_degree_clicked();

    void on_div_clicked();

    void on_mul_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_cos_clicked();

    void on_sin_clicked();

    void on_tan_clicked();

    void on_acos_clicked();

    void on_uno_minus_plus_clicked();

    void on_zero_clicked();

    void on_one_clicked();

    void on_point_clicked();

    void on_asin_clicked();

    void on_atan_clicked();

    void on_sqrt_clicked();

    void on_ln_clicked();

    void on_log_clicked();

    void on_clear_clicked();

    void on_equals_clicked();

    void on_mod_clicked();

    void on_mashtab_cursorPositionChanged();

    void on_y_cursorPositionChanged();

    void initializeGraph();

//    void on_line_insert_cursorPositionChanged();

    void on_x_clicked();

//    void on_line_insert_editingFinished();



    void on_eq_clicked();

private:
    Ui::MainWindow *ui;
    QCustomPlot *customPlot;

private:
    bool isNewExpression;
    double mashtabValue_x = 0;
    double mashtabValue_y = 0;
    double mashtabValue_insert = 0;


};
#endif // MAINWINDOW_H
