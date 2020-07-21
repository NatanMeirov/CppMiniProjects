#include "CheckingAccount.h"


CheckingAccount::CheckingAccount(std::string name, double balance)
	: Account(name, balance)
{
}

void CheckingAccount::withdraw(double amountToWithdraw)
{

	if (this->balance - amountToWithdraw - this->feePerWithdrawal >= 0)
	{
		Account::withdraw(amountToWithdraw);
		this->balance -= this->feePerWithdrawal;
	}
	else
	{
		throw InsufficentFundsException();
	}
}

void CheckingAccount::deposit(double amountToDeposit)
{
	return Account::deposit(amountToDeposit);
}

void CheckingAccount::display(std::ostream& os) const
{
	os << "[ Checking Account Info - Owner's name: " << this->ownerName << ", Balance: " << this->balance << "$" << ", Fee per withdrawal transaction: " << this->feePerWithdrawal << "$" << " ]";
}