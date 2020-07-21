#ifndef _NEGATIVEORZEROAMOUNTEXCEPTION_H_
#define _NEGATIVEORZEROAMOUNTEXCEPTION_H_

#include <exception>

class NegativeOrZeroAmountException : public std::exception
{
	virtual const char* what() const noexcept override { return "Error - Negative Or Zero Amount Exception: Account cannot do any action with negative or zero amount."; }
};

#endif // _NEGATIVEORZEROAMOUNTEXCEPTION_H_