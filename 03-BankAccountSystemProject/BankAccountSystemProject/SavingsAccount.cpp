#include "SavingsAccount.h"


SavingsAccount::SavingsAccount(std::string name, double balance, double interestRate)
	: Account(name, balance), interestRate{interestRate}
{
	if (this->interestRate > 100.0 || this->interestRate < 0.0)
	{
		throw IllegalRateException();
	}
}

void SavingsAccount::deposit(double amountToDeposit)
{
	amountToDeposit += amountToDeposit * (this->interestRate / 100);
	return Account::deposit(amountToDeposit);
}

void SavingsAccount::withdraw(double amountToWithdraw)
{
	return Account::withdraw(amountToWithdraw);
}

double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::display(std::ostream& os) const
{
	os << "[ Savings Account Info - Owner's name: " << this->ownerName << ", Balance: " << this->balance << "$" << ", Interest rate: " << this->interestRate << "%" << " ]";
}

