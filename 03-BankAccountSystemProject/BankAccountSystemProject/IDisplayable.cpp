#include "IDisplayable.h"


std::ostream& operator<<(std::ostream& os, const IDisplayable& obj)
{
	obj.display(os);
	return os;
}