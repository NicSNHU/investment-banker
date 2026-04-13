#ifndef AIRGEAD_INVESTMENT_H_
#define AIRGEAD_INVESTMENT_H_

//Investment data and calculations
class Investment 
{
public:
	Investment();

	//Setters for input values
	void setInitialInvestment(double t_initialInvestment);
	void setMonthlyDeposit(double t_monthlyDeposit);
	void setAnnualInterestRate(double t_annualInterestRate);
	void setNumberOfYears(int t_numYears);

	//Display the two required reports
	void displayReportWithoutMonthlyDeposits() const;
	void displayReportWithMonthlyDeposits() const;

private:

	//Priate member variables
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterestRate;
	int m_numYears;

	//Function to calculate monthly interest
	double calculateMonthlyInterest(double t_balance, double t_monthlyDeposit) const;
};

#endif // AIRGEAD_INVESTMENT_H_