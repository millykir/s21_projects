/********************************************************************************
** Form generated from reading UI file 'difference.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFERENCE_H
#define UI_DIFFERENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Difference
{
public:

    void setupUi(QWidget *Difference)
    {
        if (Difference->objectName().isEmpty())
            Difference->setObjectName(QString::fromUtf8("Difference"));
        Difference->resize(400, 300);

        retranslateUi(Difference);

        QMetaObject::connectSlotsByName(Difference);
    } // setupUi

    void retranslateUi(QWidget *Difference)
    {
        Difference->setWindowTitle(QCoreApplication::translate("Difference", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Difference: public Ui_Difference {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFERENCE_H
