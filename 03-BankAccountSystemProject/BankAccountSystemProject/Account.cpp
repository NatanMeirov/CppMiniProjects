#include "Account.h"

Account::Account(std::string name, double balance)
	: ownerName{name}, balance{balance}
{
	if (this->balance < 0)
	{
		throw IllegalBalanceException(); // Every exception in the code => throw by value (no "new" -> creation on stack and not on the heap), catch by reference
	}
}

//	implementation of both pure virtual function - only because it make sense (basic deposit and withdraw)
void Account::deposit(double amountToDeposit)
{
	if (amountToDeposit > 0)
	{
		this->balance += amountToDeposit;
	}
	else
	{
		throw NegativeOrZeroAmountException();
	}
}

void Account::withdraw(double amountToWithdraw)
{
	if (this->balance - amountToWithdraw >= 0 && amountToWithdraw > 0)
	{
		this->balance -= amountToWithdraw;
	}
	else
	{
		if (amountToWithdraw <= 0)
		{
			throw NegativeOrZeroAmountException();
		}

		if (this->balance - amountToWithdraw < 0) // Another if statement => More readable code
		{
			throw InsufficentFundsException();
		}
	}

}

void Account::setOwnerName(std::string name)
{
	this->ownerName = name;
}

std::string Account::getOwnerName() const
{
	return this->ownerName;
}

double Account::getBalance() const
{
	return this->balance;
}

void Account::display(std::ostream& os) const {}
