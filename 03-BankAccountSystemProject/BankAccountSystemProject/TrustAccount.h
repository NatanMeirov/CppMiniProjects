#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_

#include "SavingsAccount.h"
#include "NoRemainingWithdrawalsException.h"
#include "PassedAllowedWithdrawValueException.h"

class TrustAccount : public SavingsAccount
{
	
protected:
	unsigned int remainingNumberOfWithdrawalsForThisYear;
	static constexpr unsigned int totalNumberOfWithdrawalsPerYear{ 3 };
	static constexpr double neededDepositAmountForBonus{ 5000.0 }; // in $
	static constexpr double bonusValueToAdd{ 50.0 }; // in $
	static constexpr double maxWithrawalPercent{ 20.0 }; // in %
	
public:
	TrustAccount(std::string name = "Unnamed Trust Account", double balance = 0.0, double interestRate = 0.0);
	virtual ~TrustAccount() = default;
	virtual void deposit(double amountToDeposit) override; // Deposits of 5000$ or more will receive 50$ bonus
	virtual void withdraw(double amountToWithdraw) override; // Only allowed maximum of 3 withdrawals per year, each can be maximum of 20% of the account's balance
	// Getters:
	unsigned int getRemainingNumberOfWithdrawalsForThisYear() const;
	// Interface implementations:
	virtual void display(std::ostream& os) const override;

};

#endif // _TRUSTACCOUNT_H_