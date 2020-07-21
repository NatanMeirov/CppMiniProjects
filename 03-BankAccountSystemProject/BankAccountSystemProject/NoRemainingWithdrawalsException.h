#ifndef _NOREMAININGWITHDRAWALSEXCEPTION_H_
#define _NOREMAININGWITHDRAWALSEXCEPTION_H_

#include <exception>

class NoRemainingWithdrawalsException : public std::exception
{
	virtual const char* what() const noexcept override { return "Error - No Remaining Withdrawals Exception: Account cannot do a withdraw action, there are no more withrawals for this year."; }
};

#endif // _NOREMAININGWITHDRAWALSEXCEPTION_H_