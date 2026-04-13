#include "App.h"
#include <iostream>
#include <limits>

//Displays the program header
void App::displayInputScreen() const
{
	std::cout << "**********************************\n";
	std::cout << "********** Airgead Bank **********\n";
	std::cout << "**********************************\n";
}

//Main program 

void App::run()
{
	//Creates Investment object with the pointer
	m_investment = std::make_unique<Investment>();

	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numYears;

	displayInputScreen();

	//Get user input
	std::cout << "Initial Investment Amount: ";
	std::cin >> initialInvestment;

	std::cout << "Monthly Deposit: ";
	std::cin >> monthlyDeposit;

	std::cout << "Annual Interest Rate (%): ";
	std::cin >> annualInterest;

	std::cout << "Number of Years: ";
	std::cin >> numYears;

	//Pass input to the Investment object
	m_investment->setInitialInvestment(initialInvestment);
	m_investment->setMonthlyDeposit(monthlyDeposit);
	m_investment->setAnnualInterestRate(annualInterest);
	m_investment->setNumberOfYears(numYears);

	//Pause to allow user to review input
	std::cout << "\nPress any key to continue...\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	//Displays both reports
	m_investment->displayReportWithoutMonthlyDeposits();
	m_investment->displayReportWithMonthlyDeposits();
}

