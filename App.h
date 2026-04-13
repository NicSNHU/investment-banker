#ifndef AIRGEAD_APP_H_
#define AIRGEAD_APP_H_

#include <memory>
#include "Investment.h"

//Controls the overall program 
class App
{
public:
	void run();

private:
	//Pointer to Investment object
	std::unique_ptr<Investment> m_investment;

	//Dsplays the opening screen
	void displayInputScreen() const;
};

#endif // AIRGEAD_INVESTMENT_H_

