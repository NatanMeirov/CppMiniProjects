#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cctype>
#include "String.h"




mdrn::String::String()
	: str{ nullptr }, length{ 0 }
{
	str = new char[1];
	*str = '\0';
}


mdrn::String::String(const char* s)
	: str{ nullptr }, length{ 0 }
{
	if (s == nullptr)
	{
		str = new char[1];
		*str = '\0';
	}
	else
	{
		this->length = std::strlen(s);
		str = new char[this->length + 1]; // + 1 - for the NULL character ('\0')
		std::strcpy(this->str, s);
	}
}


mdrn::String::String(const mdrn::String& otherStr)
	: str{ nullptr }, length{ otherStr.length }
{
	str = new char[this->length + 1];
	std::strcpy(this->str, otherStr.str);
}


mdrn::String::String(mdrn::String&& tempStr) noexcept // Move C'tor - "steal" the raw pointer (address value) of the temp r-value object (avoid allocation of new memory for nothing)
	: str{ tempStr.str }, length{ tempStr.length }
{
	tempStr.str = nullptr; // Must null the temp object's pointer. Now the d'tor will not free the memory at the address that in use of the new constructer String object 
}


mdrn::String::~String()
{
	delete[] this->str;
}


int mdrn::String::getLength() const
{
	return this->length;
}


const char* mdrn::String::getStr() const
{
	return this->str;
}


mdrn::String& mdrn::String::operator=(const mdrn::String& otherStr)
{
	if (this == &otherStr) // Same object
	{
		return *this;
	}
	
	delete[] this->str; // Free the current used memory - to avoid memory leak

	this->length = otherStr.length;
	this->str = new char[otherStr.length + 1];
	std::strcpy(this->str, otherStr.str);

	return *this;
}


mdrn::String& mdrn::String::operator=(mdrn::String&& tempStr) noexcept
{
	if (this == &tempStr) // Same object
	{
		return *this;
	}

	delete[] this->str; // Deallocate the ptr first

	this->length = tempStr.length;
	this->str = tempStr.str; // "Moves" the pointer
	tempStr.str = nullptr;

	return *this;
}


char& mdrn::String::operator[](int index) const // Included bound checking
{
	if (index < 0 || index > length - 1)
	{
		throw -1; // Error: Out of bounds error
	}

	return this->str[index]; // (return this->str + index) -> returning the address of the str with an offset of the value of the index
}


bool mdrn::String::operator==(const mdrn::String& otherStr) const
{
	return std::strcmp(this->str, otherStr.str) == 0; // Equality (lexically)
}


bool mdrn::String::operator!=(const mdrn::String& otherStr) const
{
	return std::strcmp(this->str, otherStr.str) != 0;
}


bool mdrn::String::operator>(const mdrn::String& otherStr) const
{
	return std::strcmp(this->str, otherStr.str) == 1; // Left side is bigger (lexically) [-> Could also check if > 0]
}


bool mdrn::String::operator<(const mdrn::String& otherStr) const
{
	return std::strcmp(this->str, otherStr.str) == -1; // Right side is bigger (lexicaly) [-> Could also check if < 0]
}


mdrn::String mdrn::String::operator+(const mdrn::String& otherStr) const
{
	char* buffer = new char[this->length + otherStr.length + 1];

	std::strcpy(buffer, this->str);
	std::strcat(buffer, otherStr.str);

	String tempString{ buffer }; // Creating the new String object from the two concatinated String objects 
	delete[] buffer;

	return tempString;
}


mdrn::String& mdrn::String::operator+=(const mdrn::String& otherStr)
{
	return *this = this->operator+(otherStr);
}


mdrn::String mdrn::String::operator*(int numOfTimes) const
{
	if (numOfTimes < 0)
	{
		throw - 1; // Error: Not a valid number error
	}

	if (numOfTimes == 0) // Like in math - will make the String object empty (""), with a null character ('\0')
	{
		String tempString{};
		return tempString;
	}

	char* buffer = new char[(this->length * numOfTimes) + 1];

	std::strcpy(buffer, this->str); // First time

	for (size_t i{ 0 }; i < numOfTimes - 1; i++)
	{
		std::strcat(buffer, this->str);
	}

	String tempString{ buffer };
	delete[] buffer;

	return tempString;
}


mdrn::String& mdrn::String::operator*=(int numOfTimes)
{
	return *this = this->operator*(numOfTimes);
}


mdrn::String mdrn::String::operator-() const
{
	char* buffer = new char[this->length + 1];
	std::strcpy(buffer, this->str);

	for (size_t i{ 0 }; i < this->length; i++)
	{
		buffer[i] = std::tolower(buffer[i]);
	}

	String tempString{ buffer };
	delete[] buffer;

	return tempString;
}


mdrn::String& mdrn::String::operator++() // Pre-increment
{
	for (size_t i{ 0 }; i < this->length; i++)
	{
		this->str[i] = std::toupper(this->str[i]);
	}

	return *this;
}


mdrn::String mdrn::String::operator++(int) // Post-increment
{
	String tempString{ *this }; // First save the current stat object, and then use ToUpper operator on itself
	this->operator++();

	return tempString;
}


mdrn::String& mdrn::String::operator--() // Pre-decrement
{
	/* ====================================
	 *
	 * Could've written this easy line of code:
	 *
	 * return *this = -(*this);
	 * 
	 * To reusing the implemented unary minus operator on the current object itself, and assign it back,
	 * But it whould cost A LOT of useless stack calls and several copy c'tor calls for nothing much...
	 *
	 * ====================================
	 */

	for (size_t i{ 0 }; i < this->length; i++)
	{
		this->str[i] = std::tolower(this->str[i]);
	}

	return *this;
}


mdrn::String mdrn::String::operator--(int) // Post-decrement
{
	String tempString{ *this }; // First save the current stat object, and then use ToLower operator on itself
	this->operator--();

	return tempString;
}


std::ostream& operator<<(std::ostream& os, const mdrn::String& s)
{
	os << s.getStr();
	return os;
}


std::istream& operator>>(std::istream& is, mdrn::String& s)
{
	char* buffer = new char[2048];
	std::cin >> buffer;
	s = mdrn::String{ buffer };
	delete[] buffer;
	return is;
}
