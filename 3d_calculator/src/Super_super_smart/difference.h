#ifndef DIFFERENCE_H
#define DIFFERENCE_H

#include <QWidget>

namespace Ui {
class Difference;
}

class Difference : public QWidget
{
    Q_OBJECT

public:
    explicit Difference(QWidget *parent = nullptr);
    ~Difference();

private:
    Ui::Difference *ui;
};

#endif // DIFFERENCE_H
