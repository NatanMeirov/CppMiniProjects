#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include "IDisplayable.h"
#include "IllegalBalanceException.h"
#include "NegativeOrZeroAmountException.h"
#include "InsufficentFundsException.h"

// Account - Abstract class (root)
class Account : public IDisplayable
{

protected:
	std::string ownerName;
	double balance;

public:
	Account(std::string name = "Unnamed Account", double balance = 0.0); // Default params c'tor
	virtual ~Account() = default;
	// Pure virtual functions:
	virtual void deposit(double amountToDeposit) = 0;
	virtual void withdraw(double amountToWithdraw) = 0;
	// Getters and Setters:
	void setOwnerName(std::string name);
	std::string getOwnerName() const;
	double getBalance() const;
	// Interface implementations:
	virtual void display(std::ostream& os) const override;

};

#endif // _ACCOUNT_H_