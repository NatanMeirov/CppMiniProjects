#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name, double balance, double interestRate)
	: SavingsAccount(name, balance, interestRate), remainingNumberOfWithdrawalsForThisYear { totalNumberOfWithdrawalsPerYear }
{
}

void TrustAccount::deposit(double amountToDeposit)
{

	SavingsAccount::deposit(amountToDeposit);

	if (amountToDeposit >= this->neededDepositAmountForBonus) // If SavingsAccount::deposit method had succedded
	{
		this->balance += this->bonusValueToAdd;
	}

}

void TrustAccount::withdraw(double amountToWithdraw)
{
	double allowedWithdrawValue{ this->balance * (this->maxWithrawalPercent / 100) }; // Must be less then cap % of the account balance

	if (this->remainingNumberOfWithdrawalsForThisYear > 0 && amountToWithdraw < allowedWithdrawValue)
	{
		Account::withdraw(amountToWithdraw);
		this->remainingNumberOfWithdrawalsForThisYear--;
	}
	else
	{
		if (this->remainingNumberOfWithdrawalsForThisYear <= 0)
		{
			throw NoRemainingWithdrawalsException();
		}

		if (amountToWithdraw >= allowedWithdrawValue)
		{
			throw PassedAllowedWithdrawValueException();
		}
	}
}

unsigned int TrustAccount::getRemainingNumberOfWithdrawalsForThisYear() const
{
	return this->remainingNumberOfWithdrawalsForThisYear;
}

void TrustAccount::display(std::ostream& os) const
{
	os << "[ Trust Account Info - Owner's name: " << this->ownerName << ", Balance: " << this->balance << "$" << ", Interest rate: " << this->interestRate << "%" << ", Remaining withdrawals for this year: " << this->remainingNumberOfWithdrawalsForThisYear << " ]";
}
