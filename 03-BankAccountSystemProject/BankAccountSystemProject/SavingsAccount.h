#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_

#include "Account.h"
#include "IllegalRateException.h"
#include "NegativeOrZeroAmountException.h"

class SavingsAccount : public Account
{

protected:
	double interestRate; // in %

public:
	SavingsAccount(std::string name = "Unnamed Saving Account", double balance = 0.0, double interestRate = 0.0);
	virtual ~SavingsAccount() = default;
	virtual void deposit(double amountToDeposit) override;
	virtual void withdraw(double amountToWithdraw) override;
	// Getters:
	double getInterestRate() const;
	// Interface implementations:
	virtual void display(std::ostream& os) const override;
};

#endif // _SAVINGSACCOUNT_H_

