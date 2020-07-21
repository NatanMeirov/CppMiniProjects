#ifndef _CHECKINGACCOUNT_H_
#define _CHECKINGACCOUNT_H_

#include "Account.h"
#include "InsufficentFundsException.h"

class CheckingAccount : public Account
{

protected:
	static constexpr double feePerWithdrawal{ 1.5 }; // in $

public:
	CheckingAccount(std::string name = "Unnamed Checking Account", double balance = 0.0);
	virtual ~CheckingAccount() = default;
	virtual void withdraw(double amountToWithdraw) override;
	virtual void deposit(double amountToDeposit) override;
	// Interface implementations:
	virtual void display(std::ostream& os) const override;

};

#endif // _CHECKINGACCOUNT_H_
