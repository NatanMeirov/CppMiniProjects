#include <iostream>
#include <memory>
#include "IDisplayable.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "RegularAccount.h"
#include "BankAccountSystemUtils.h"

int main()
{
	// Tests:

	try
	{
		std::unique_ptr<Account> illegalAccount = std::make_unique<RegularAccount>("Account", -1);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << "\n" << std::endl;
	}

	std::vector<std::shared_ptr<Account>> accountsVector // Base class ptr
	{
		std::make_shared<RegularAccount>("Natan Meirov", 100000),
		std::make_shared<RegularAccount>(),
		std::make_shared<CheckingAccount>("David Johnson", 5630),
		std::make_shared<SavingsAccount>("Moshe Moshe", 2000, 5),
		std::make_shared<TrustAccount>("Glen Morris", 30000, 15)
	};

	BankAccountSystemUtils::displayAccounts(accountsVector);

	BankAccountSystemUtils::depositToAllAccounts(accountsVector, 10);
	BankAccountSystemUtils::withdrawToAllAccounts(accountsVector, 10000);

	BankAccountSystemUtils::depositToAllAccounts(accountsVector, 11111);
	BankAccountSystemUtils::withdrawToAllAccounts(accountsVector, 100);

	BankAccountSystemUtils::displayAccounts(accountsVector);

	BankAccountSystemUtils::withdrawToAllAccounts(accountsVector, 100000);
	BankAccountSystemUtils::withdrawToAllAccounts(accountsVector, 0);
	BankAccountSystemUtils::depositToAllAccounts(accountsVector, -1);
	
	BankAccountSystemUtils::displayAccounts(accountsVector);

	BankAccountSystemUtils::withdrawToAllAccounts(accountsVector, 1);
	BankAccountSystemUtils::withdrawToAllAccounts(accountsVector, 1);
	BankAccountSystemUtils::withdrawToAllAccounts(accountsVector, 1);

	BankAccountSystemUtils::displayAccounts(accountsVector);

	return 0;
}