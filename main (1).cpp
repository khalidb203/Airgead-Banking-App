/*
******************************
*  Name: Khalid Brock        *
*  Date: June 11, 2023       *
*  Class: CS-210             *
******************************
*/
#include <iostream>
#include <limits>
#include "Investment.h"

int main() {
    // Display screen
    std::cout << "Airgead Banking - Investment Calculator\n\n";

    // Get user input
    double initialInvestmentAmount;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;

    std::cout << "Initial Investment Amount: $";
    std::cin >> initialInvestmentAmount;

    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest (%): ";
    std::cin >> annualInterest;

    std::cout << "Number of Years: ";
    std::cin >> numberOfYears;

    // Create Investment object
    Investment investment(initialInvestmentAmount, monthlyDeposit, annualInterest, numberOfYears);

    // Calculate investment growth
    investment.calculateInvestmentGrowth();

    // Display table headers
    std::cout << "\nYear\tYear End Balance\tYear End Earned Interest\n";

    // Display investment growth table
    investment.displayInvestmentTable();

    // Wait for user input before exiting
    std::cout << "\nPress any key to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    return 0;
}
