#include "difference.h"
#include "ui_difference.h"

Difference::Difference(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Difference)
{
    ui->setupUi(this);
}

Difference::~Difference()
{
    delete ui;
}
