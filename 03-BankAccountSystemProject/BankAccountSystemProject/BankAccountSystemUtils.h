#ifndef _BANKACCOUNTSYSTEMUTILS_H_
#define _BANKACCOUNTSYSTEMUTILS_H_

#include <vector>
#include <memory>
#include <exception>
#include "Account.h"

class BankAccountSystemUtils
{

public:
	static void displayAccounts(std::vector<std::shared_ptr<Account>>& accountCollection);
	static void depositToAllAccounts(std::vector<std::shared_ptr<Account>>& accountCollection, double amountToDeposit);
	static void withdrawToAllAccounts(std::vector<std::shared_ptr<Account>>& accountCollection, double amountToWithdraw);

};

#endif // _BANKACCOUNTSYSTEMUTILS_H_
