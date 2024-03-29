#ifndef _BIGINTEGER_HPP_
#define _BIGINTEGER_HPP_

#include <cstdint>
#include <iostream>
#include <string>

class TestCases;

class BigInteger
{
public:
    BigInteger();
    BigInteger(int value);
    BigInteger(std::string value);
    ~BigInteger();
    BigInteger(const BigInteger &first);
    BigInteger operator=(const BigInteger &first);
    BigInteger operator+(const BigInteger &first);
    BigInteger operator+(unsigned int value);
    BigInteger& operator+=(const BigInteger &rhs);
    BigInteger operator++(int);
    BigInteger operator*(const BigInteger &first);
    BigInteger& operator*=(const BigInteger &rhs);
    bool operator<=(const BigInteger &rhs);
    bool operator==(const BigInteger &rhs);
	operator double() const;
	void makeCopy(const BigInteger &first);

	friend std::ostream &operator<<(std::ostream &os, const BigInteger &integer);

//    BigInteger add(const BigInteger& rhs);
//	BigInteger multiply(const BigInteger& rhs);

//	void display();

	friend class TestCases;

private:
	std::uint8_t* m_number;		// Internal representation of the number.
	unsigned int m_sizeReserved;	// Total size of the allocated space used to internally store the number
	unsigned int m_digitCount;	// How many digits are in the number.

	std::uint8_t getDigit(unsigned int position) const;
	void setDigit(unsigned int position, std::uint8_t digit);
};

#endif
