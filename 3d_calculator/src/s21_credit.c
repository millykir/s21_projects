#include "s21_calc.h"

double calculate_annuity_payment(int months, double interest_rate,
                                 double loan_amount) {
  double monthly_interest_rate = interest_rate / 100 / 12;
  double annuity_coefficient =
      (monthly_interest_rate * pow(1 + monthly_interest_rate, months)) /
      (pow(1 + monthly_interest_rate, months) - 1);
  double monthly_payment = loan_amount * annuity_coefficient;
  return monthly_payment;
}

double calculate_differentiated_payment(int months, double interest_rate,
                                        double loan_amount, double* payments) {
  double monthly_interest_rate = interest_rate / 100 / 12;
  double total_payment = 0;

  for (int i = 1; i <= months; i++) {
    double interest_payment = loan_amount * monthly_interest_rate;
    double principal_payment = loan_amount / months;
    double monthly_payment = interest_payment + principal_payment;
    total_payment += monthly_payment;
    loan_amount -= principal_payment;

    payments[i - 1] =
        monthly_payment;  // Сохраняем значение ежемесячного платежа в массив
  }

  // Добавляем последний платеж, чтобы общая сумма платежей была равна сумме
  // всех платежей
  double interest_payment = loan_amount * monthly_interest_rate;
  double last_payment = loan_amount + interest_payment;
  total_payment += last_payment;
  payments[months - 1] = last_payment;

  return total_payment;  // Возвращаем общую сумму платежей
}