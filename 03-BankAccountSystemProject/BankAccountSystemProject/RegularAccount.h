#ifndef _REGULARACCOUNT_H_
#define _REGULARACCOUNT_H_

#include "Account.h"

class RegularAccount : public Account
{

public:
	RegularAccount(std::string name = "Unnamed Account", double balance = 0.0); // Default params c'tor
	virtual ~RegularAccount() = default;
	virtual void deposit(double amountToDeposit);
	virtual void withdraw(double amountToWithdraw);
	// Interface implementations:
	virtual void display(std::ostream& os) const override;
};

#endif // _REGULARACCOUNT_H_

