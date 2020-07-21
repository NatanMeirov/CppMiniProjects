#ifndef _STRING_H_
#define _STRING_H_


namespace mdrn
{

	class String
	{

	private:

		char* str;
		int length;

	public:

		// C'tors and D'tor
		String();
		String(const char* s);
		String(const String& otherStr);
		String(String&& tempStr) noexcept;
		~String();

		// Getters
		int getLength() const;
		const char* getStr() const;

		// Operators
		String& operator=(const String& otherStr); // Assignment
		String& operator=(String&& tempStr) noexcept;
		char& operator[](int index) const; 
		bool operator==(const String& otherStr) const; // Equality
		bool operator!=(const String& otherStr) const;
		bool operator>(const String& otherStr) const; // Lexicaly bigger
		bool operator<(const String& otherStr) const;
		String operator+(const String& otherStr) const; // Concatination
		String& operator+=(const String& otherStr);
		String operator*(int numOfTimes) const; // Concatination with itself * num of times
		String& operator*=(int numOfTimes);
		String operator-() const; // Unary minus - To lower without changing the current object (this)
		String& operator++(); // To upper
		String operator++(int);
		String& operator--(); // To lower
		String operator--(int);

	};

}

std::ostream& operator<<(std::ostream& os, const mdrn::String& s);
std::istream& operator>>(std::istream& is, mdrn::String& s);

#endif // _STRING_H_

