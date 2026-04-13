#include "Investment.h"
#include <iostream>
#include <iomanip>

//Constant for the month in  year
static const int MONTHS_IN_YEAR = 12;

//Constructor to initialize values
Investment::Investment()
  : m_initialInvestment(0.0),
    m_monthlyDeposit(0.0),
    m_annualInterestRate(0.0),
    m_numYears(0)
{
}

//Store initial investment
void Investment::setInitialInvestment(double t_initialInvestment)
{
    m_initialInvestment = t_initialInvestment;
}

//Store monthly deposit amount
void Investment::setMonthlyDeposit(double t_monthlyDeposit)
{
    m_monthlyDeposit = t_monthlyDeposit;
}

//Store annual interest rate
void Investment::setAnnualInterestRate(double t_annualInterestRate)
{
    m_annualInterestRate = t_annualInterestRate;
}

//Store number of years
void Investment::setNumberOfYears(int t_numYears)
{
    m_numYears = t_numYears;
}

//Calculates interest for one month
double Investment::calculateMonthlyInterest(double t_balance, double t_monthlyDeposit) const
{
    return (t_balance + t_monthlyDeposit) * ((m_annualInterestRate / 100.00) / MONTHS_IN_YEAR);
}

//Report with NO monthly deposit
void Investment::displayReportWithoutMonthlyDeposits() const
{
    double balance = m_initialInvestment;
    double yearlyInterest = 0.0;

    std::cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    std::cout << "========================================================\n";
    std::cout << "Year    Year End Balance    Year End Earned Interest\n";
    std::cout << "--------------------------------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);

    //Loop through each year
    for (int year = 1; year <= m_numYears; ++year)
    {
        yearlyInterest = balance * (m_annualInterestRate / 100);
        balance += yearlyInterest;

        
        //Displays year-end totals
        std::cout << std::setw(4) << year
                  << std::setw(20) << balance
                  << std::setw(28) << yearlyInterest
                  << std::endl;
    }
}

//Report WITH monthly deposits
void Investment::displayReportWithMonthlyDeposits() const
{
    double balance = m_initialInvestment;
    double monthlyInterestRate = (m_annualInterestRate / 100) / 12;
    double yearlyInterest = 0.0;

    std::cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    std::cout << "========================================================\n";
    std::cout << "Year    Year End Balance    Year End Earned Interest\n";
    std::cout << "--------------------------------------------------------\n";

    std::cout << std::fixed << std::setprecision(2);

    //Loop through each year
    for (int year = 1; year <= m_numYears; ++year)
    {
        yearlyInterest = 0.0;

        //Loop through each month
        for (int month = 1; month <= MONTHS_IN_YEAR; ++month)
        {
            double interest =
                (balance + m_monthlyDeposit) * monthlyInterestRate;

            yearlyInterest += interest;
            balance += m_monthlyDeposit + interest;
        }

        //Displays year-end totals
        std::cout << std::setw(4) << year
                  << std::setw(20) << balance
                  << std::setw(28) << yearlyInterest
                  << std::endl;
    }
}
