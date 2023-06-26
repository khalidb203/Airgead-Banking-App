/*
******************************
*  Name: Khalid Brock        *
*  Date: June 11, 2023       *
*  Class: CS-210             *
******************************
*/
#include <iostream>
#include <iomanip>
#include "Investment.h"

Investment::Investment(double initialInvestmentAmount, double monthlyDeposit, double annualInterest, int numberOfYears)
    : m_initialInvestmentAmount(initialInvestmentAmount),
      m_monthlyDeposit(monthlyDeposit),
      m_annualInterest(annualInterest),
      m_numberOfYears(numberOfYears) {}

void Investment::calculateInvestmentGrowth() {
    double openingAmount = m_initialInvestmentAmount;
    double depositedAmount = m_monthlyDeposit;

    for (int month = 1; month <= m_numberOfYears * 12; ++month) {
        double interest = calculateInterest(openingAmount, depositedAmount);
        double closingBalance = openingAmount + depositedAmount + interest;

        m_yearEndBalances.push_back(closingBalance);
        m_yearEndEarnedInterests.push_back(interest);

        openingAmount = closingBalance;
    }
}

void Investment::displayInvestmentTable() const {
    for (int year = 1; year <= m_numberOfYears; ++year) {
        int index = (year - 1) * 12;
        double yearEndBalance = m_yearEndBalances[index];
        double yearEndEarnedInterest = m_yearEndEarnedInterests[index];

        std::cout << year << "\t$" << std::fixed << std::setprecision(2) << yearEndBalance
