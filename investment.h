/*
******************************
*  Name: Khalid Brock        *
*  Date: June 11, 2023       *
*  Class: CS-210             *
******************************
*/
#ifndef INVESTMENT_H_
#define INVESTMENT_H_

#include <vector>

class Investment {
private:
    double m_initialInvestmentAmount;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;
    std::vector<double> m_yearEndBalances;
    std::vector<double> m_yearEndEarnedInterests;

public:
    Investment(double initialInvestmentAmount, double monthlyDeposit, double annualInterest, int numberOfYears);
    void calculateInvestmentGrowth();
    void displayInvestmentTable() const;

private:
    double calculateInterest(double openingAmount, double depositedAmount) const;
};

#endif // INVESTMENT_H_
