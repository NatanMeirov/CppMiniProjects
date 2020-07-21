#ifndef _IDISPLAYABLE_H_
#define _IDISPLAYABLE_H_

#include <iostream>

class IDisplayable // IDisplayable Interface
{
	friend std::ostream& operator<<(std::ostream& os, const IDisplayable& obj);

public:
	virtual void display(std::ostream& os) const = 0; // Pure virtual function
	virtual ~IDisplayable() = default;

};

#endif // _IDISPLAYABLE_H_