#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    customPlot = new QCustomPlot(this);
    QWidget *widget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->addWidget(customPlot);
    ui->widget->setLayout(layout);


}


MainWindow::~MainWindow()
{
    delete ui;
}


double result = 0;

void MainWindow::on_l_brecket_clicked()
{
    ui->line_insert->insert("(");
    isNewExpression =   false;
}


void MainWindow::on_r_brecket_clicked()
{
   ui->line_insert->insert(")");
   isNewExpression =   false;
}


void MainWindow::on_plus_clicked()
{
    ui->line_insert->insert("+");
    isNewExpression =   false;
}


void MainWindow::on_minus_clicked()
{
    ui->line_insert->insert("-");
    isNewExpression =   false;
}


void MainWindow::on_six_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("6");
}


void MainWindow::on_seven_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("7");
}


void MainWindow::on_eight_2_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("8");
}


void MainWindow::on_nine_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("9");
}


void MainWindow::on_degree_clicked()
{
    ui->line_insert->insert("^");
    isNewExpression =   false;
}


void MainWindow::on_div_clicked()
{
    ui->line_insert->insert("/");
    isNewExpression =   false;
}


void MainWindow::on_mul_clicked()
{
    ui->line_insert->insert("*");
    isNewExpression =   false;
}


void MainWindow::on_two_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("2");
}


void MainWindow::on_three_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("3");
}


void MainWindow::on_four_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("4");
}


void MainWindow::on_five_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("5");
}

void MainWindow::on_cos_clicked()
{
    ui->line_insert->insert("cos");
    isNewExpression =   false;
}

void MainWindow::on_sin_clicked()
{
    ui->line_insert->insert("sin");
    isNewExpression =   false;
}

void MainWindow::on_tan_clicked()
{
    ui->line_insert->insert("tan");
    isNewExpression =   false;
}

void MainWindow::on_acos_clicked()
{
    ui->line_insert->insert("acos");
    isNewExpression =   false;
}


void MainWindow::on_uno_minus_plus_clicked()
{
    QString expression = ui->line_insert->text();
    QRegularExpression re("[0-9.]+$");
    QRegularExpressionMatch match = re.match(expression);
    if (match.hasMatch()) {
        QString lastNumber = match.captured();
        QString modifiedExpression = expression.left(match.capturedStart()) + "(-" + lastNumber + ")";
        ui->line_insert->setText(modifiedExpression);
    }
}


void MainWindow::on_zero_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("0");
}


void MainWindow::on_one_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("1");
}


void MainWindow::on_point_clicked()
{
    ui->line_insert->insert(".");
    isNewExpression =   false;
}


void MainWindow::on_asin_clicked()
{
    ui->line_insert->insert("asin");
    isNewExpression =   false;
}



void MainWindow::on_atan_clicked()
{
    ui->line_insert->insert("atan");
    isNewExpression =   false;
}


void MainWindow::on_sqrt_clicked()
{
    ui->line_insert->insert("sqrt");
    isNewExpression =   false;
}


void MainWindow::on_ln_clicked()
{
    ui->line_insert->insert("ln");
    isNewExpression =   false;
}




void MainWindow::on_log_clicked()
{
    ui->line_insert->insert("log");
    isNewExpression =   false;
}



void MainWindow::on_clear_clicked()
{
    ui->line_insert->clear();

}

void MainWindow::on_mod_clicked()
{
    ui->line_insert->insert("mod");
    isNewExpression =   false;
}


void MainWindow::initializeGraph()
{
    // Инициализация данных графика
    QVector<double> x(101), y(101);
    for (int i = 0; i < 101; ++i)
    {
        x[i] = i / 50.0 - 1;

            y[i] = 0;


    }

    // Добавление графика на объект QCustomPlot
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    customPlot->xAxis->setRange(-1, 1);
    customPlot->yAxis->setRange(-1, 1);
    customPlot->replot();
}



void MainWindow::on_mashtab_cursorPositionChanged()
{
    QString text = ui->mashtab->text();
        bool ok;
        mashtabValue_x = text.toDouble(&ok);

        // Изменение диапазона оси x
        customPlot->xAxis->setRange(-mashtabValue_x, mashtabValue_x);
        customPlot->replot();
}



void MainWindow::on_y_cursorPositionChanged()
{
    QString text = ui->y->text();
        bool ok;
        mashtabValue_y = text.toDouble(&ok);

        // Изменение диапазона оси x
        customPlot->yAxis->setRange(-mashtabValue_y, mashtabValue_y);
        customPlot->replot();
}


void MainWindow::on_equals_clicked()
{

    QString inputText = ui->line_insert->text(); // Получение текстового значения из QLineEdit

    if ( !inputText.contains("x"))
    {
    std::string expression = inputText.toStdString(); // Преобразование QString в std::string
    char* charArray = new char[expression.length() + 1]; // +1 для завершающего нулевого символа
    std::strcpy(charArray, expression.c_str());
    result = convertToRPN(charArray);
    QString resultText = QString::number(result);
    ui->line_insert->setText(resultText);
    isNewExpression = true;
        bool ok;
        mashtabValue_insert = resultText.toDouble(&ok);
        if (ok)
 {

     QVector<double> x(101), y(101);
     int i = 0;
     double j = (2*mashtabValue_x)/100;
     x[0] = -(mashtabValue_x +j);

     for (; i < 101; i++)
     {
         if (mashtabValue_x)
         {x[i] = x[0] + j;
         j++;}
         else
         {x[i] = i / 50.0 - 1;}

        y[i] = mashtabValue_insert;
     }

     customPlot->addGraph();
     customPlot->graph(0)->setData(x, y);
     customPlot->xAxis->setLabel("x");
     customPlot->yAxis->setLabel("y");
     customPlot->replot();
 }
 }

    else
       {
//        QString modifiedText = inputText;
        QVector<double> x(101), y(101);
        int i = 0;
        double j = (2*mashtabValue_x)/100;
        double l = j;
        x[0] = -(mashtabValue_x);
        for (i=0; i < 101; )
        {
            x[i] = x[0] + l;
            if(x[i] < 0.0000000000057 && x[i] > -0.0000000000057){
                x[i] = 0;
            }
            l = l  + j;
            QString modifiedText = inputText;
            modifiedText = modifiedText.replace("x", QString::number(x[i])); // Выполняем замену в измененной строке
            std::string expression = modifiedText.toStdString();
            char* charArray = new char[expression.length() + 1];
            std::strcpy(charArray, expression.c_str());
            result = convertToRPN(charArray);
            y[i] = result;
            i++;
            delete[] charArray;
        }
        customPlot->addGraph();
        customPlot->graph(0)->setData(x, y);
        customPlot->xAxis->setLabel("x");
        customPlot->yAxis->setLabel("y");
        customPlot->replot();
    }
}



void MainWindow::on_x_clicked()
{
    if (isNewExpression)
       {
           ui->line_insert->clear();
           isNewExpression =   false;
       }
    ui->line_insert->insert("x");
}




void MainWindow::on_eq_clicked()
{
    const int MAX_MONTHS = 300;
    double payments[MAX_MONTHS];

    QLineEdit *sum_LineEdit = findChild<QLineEdit*>("sum");
    double sum = sum_LineEdit->text().toDouble();

    QLineEdit *month_LineEdit = findChild<QLineEdit*>("month");
    int month = month_LineEdit->text().toDouble();

    QLineEdit *procent_LineEdit = findChild<QLineEdit*>("procent");
    double procent = procent_LineEdit->text().toDouble();

    QComboBox* creditComboBox = ui->credit;
    int index = creditComboBox->currentIndex();

    if(index == 0){
        double res_annuit = calculate_annuity_payment(month,procent,sum);
        double res = res_annuit * month;
        double over = res - sum;
        QLineEdit *pay_month = findChild<QLineEdit*>("pay_month");
        pay_month->setText(QString::number(res_annuit));
        QLineEdit *over_pay = findChild<QLineEdit*>("over_pay");
        over_pay->setText(QString::number(over));
        QLineEdit *all_pay = findChild<QLineEdit*>("all_pay");
        all_pay->setText(QString::number(res));
    }

    else if(index == 1){
        double res = calculate_differentiated_payment(month,procent,sum,payments);
        double res_annuit = 0;
        double over = res - sum;

        QLineEdit *pay_month = findChild<QLineEdit*>("pay_month");
        pay_month->setText(QString::number(res_annuit));
        QLineEdit *over_pay = findChild<QLineEdit*>("over_pay");
        over_pay->setText(QString::number(over));
        QLineEdit *all_pay = findChild<QLineEdit*>("all_pay");
        all_pay->setText(QString::number(res));

        QTextEdit *textEdit = findChild<QTextEdit*>("textEdit");
            textEdit->clear();
            for (int i = 0; i < month; ++i) {
                QString line = "месяц " + QString::number(i + 1) + ": платеж = " + QString::number(payments[i]) + " руб";

                textEdit->append(line);
            }

    }
}

