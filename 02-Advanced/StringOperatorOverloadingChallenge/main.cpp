#include <iostream>
#include "String.h"



int main()
{
	// Test cases:

	mdrn::String me{ "Natan Meirov" };
	std::cout << me << std::endl; // Natan Meirov

	--me;
	std::cout << me << std::endl; // natan meirov

	me++;
	std::cout << me << std::endl;	// NATAN MEIROV

	mdrn::String otherMe = -me;
	std::cout << me << std::endl; // NATAN MEIROV
	std::cout << otherMe << std::endl; // natan meirov

	mdrn::String myself{ me + " is " + otherMe + "!" };
	std::cout << myself << std::endl; // NATAN MEIROV is natan meirov!

	std::cout << myself * 2 << std::endl; // NATAN MEIROV is natan meirov!NATAN MEIROV is natan meirov!
	std::cout << myself << std::endl; // NATAN MEIROV is natan meirov!

	me *= 3;
	std::cout << me << std::endl; // NATAN MEIROVNATAN MEIROVNATAN MEIROV

	otherMe += "...";
	std::cout << otherMe << std::endl; // natan meirov...
	
	me == myself ? std::cout << me[0] << std::endl : std::cout << myself[myself.getLength() - 1] << std::endl; // !

	me != myself ? std::cout << me[0] << std::endl : std::cout << myself[myself.getLength() - 1] << std::endl; // N

	me[0] = '-';

	std::cout << me << std::endl; // -ATAN MEIROVNATAN MEIROVNATAN MEIROV

	otherMe = mdrn::String{ "N.M" };
	me = myself = otherMe;

	std::cout << "~" << me << " -> " << myself << " -> " << otherMe + "~" << std::endl; // N.M->N.M->N.M~

	return 0;
}