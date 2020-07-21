#include "BankAccountSystemUtils.h"
#include "IllegalBalanceException.h"
#include "NegativeOrZeroAmountException.h"
#include "InsufficentFundsException.h"
#include "IllegalRateException.h"
#include "NoRemainingWithdrawalsException.h"
#include "PassedAllowedWithdrawValueException.h"


void BankAccountSystemUtils::displayAccounts(std::vector<std::shared_ptr<Account>>& accountCollection)
{
	for (const auto& account : accountCollection)
	{
		std::cout << *account << std::endl;
	}
}

void BankAccountSystemUtils::depositToAllAccounts(std::vector<std::shared_ptr<Account>>& accountCollection, double amountToDeposit)
{
	for (const auto& account : accountCollection)
	{
		try
		{
			account->deposit(amountToDeposit);
			std::cout << "Successfully deposited " << amountToDeposit << "$ " << "To: " << "\n" << *account << "\n" << std::endl;
		}
		catch (std::exception& ex)
		{
			std::cout << "Could not deposit " << amountToDeposit << "$ " << "To: " << "\n" << *account << std::endl;
			std::cout << ex.what() << "\n" << std::endl;
		}
	}
}

void BankAccountSystemUtils::withdrawToAllAccounts(std::vector<std::shared_ptr<Account>>& accountCollection, double amountToWithdraw)
{
	for (const auto& account : accountCollection)
	{
		try
		{
			account->withdraw(amountToWithdraw);
			std::cout << "Successfully withdrew " << amountToWithdraw << "$ " << "To: " << "\n" << *account << "\n" << std::endl;
		}
		catch (std::exception& ex)
		{
			std::cout << "Could not withdraw " << amountToWithdraw << "$ " << "To: " << "\n" << *account << std::endl;
			std::cout << ex.what() << "\n" << std::endl;
		}
	}
}
