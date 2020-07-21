#ifndef _ILLEGALBALANCEEXCEPTION_H_
#define _ILLEGALBALANCEEXCEPTION_H_

#include <exception>

class IllegalBalanceException : public std::exception
{
	virtual const char* what() const noexcept override { return "Error - Illegal Balance Exception: Account cannot be created with negative balance."; }
};

#endif // _ILLEGALBALANCEEXCEPTION_H_