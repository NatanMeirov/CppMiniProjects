#ifndef _PASSEDALLOWEDWITHDRAWVALUEEXCEPTION_H_
#define _PASSEDALLOWEDWITHDRAWVALUEEXCEPTION_H_

#include <exception>

class PassedAllowedWithdrawValueException : public std::exception
{
	virtual const char* what() const noexcept override { return "Error - Passed Allowed Withdraw Value Exception: Account cannot do a withdraw action, there is a limit for the value per withdrawal."; }
};

#endif // _PASSEDALLOWEDWITHDRAWVALUEEXCEPTION_H_
