#ifndef _INSUFFICENTFUNDSEXCEPTION_H_
#define _INSUFFICENTFUNDSEXCEPTION_H_

#include <exception>

class InsufficentFundsException : public std::exception
{
	virtual const char* what() const noexcept override { return "Error - Insufficent Funds Exception: Account action should not result a negative balance."; }
};

#endif // _INSUFFICENTFUNDSEXCEPTION_H_