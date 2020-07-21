#include "RegularAccount.h"

RegularAccount::RegularAccount(std::string name, double balance)
	: Account(name, balance)
{
}

void RegularAccount::deposit(double amountToDeposit)
{
	return Account::deposit(amountToDeposit);
}

void RegularAccount::withdraw(double amountToWithdraw)
{
	return Account::withdraw(amountToWithdraw);
}

void RegularAccount::display(std::ostream& os) const
{
	os << "[ Regular Account Info - Owner's name: " << this->ownerName << ", Balance: " << this->balance << "$" << " ]";
}
