#ifndef _ILLEGALRATEEXCEPTION_H_
#define _ILLEGALRATEEXCEPTION_H_

#include <exception>

class IllegalRateException : std::exception
{
	virtual const char* what() const noexcept override { return "Error - Illegal Rate Exception: Account cannot have intrest rate less then 0.0% or more then 100.0%."; }
};

#endif // _ILLEGALRATEEXCEPTION_H_