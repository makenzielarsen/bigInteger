#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <vector>

#include "BigInteger.hpp"

using namespace std;


BigInteger::BigInteger() {
    m_number = new uint8_t[4]();
    m_sizeReserved = 4;
    m_digitCount = 0;
}

int countDigits(int value) {
    unsigned int number_of_digits = 0;

    do {
        ++number_of_digits;
        value /= 10;
    } while (value);

    return number_of_digits;
}

BigInteger::BigInteger(int value) {
    if (value == 0) {
        m_sizeReserved = countDigits(value);
        m_number = new uint8_t[m_sizeReserved];
        m_digitCount = 0;
    } else {
        m_sizeReserved = countDigits(value);
        m_number = new uint8_t[m_sizeReserved];

        for (int i = 0; i < m_sizeReserved; i++) {
            int digit = value % 10;
            value = value / 10;
            setDigit(i, digit);
        }
    }
}

BigInteger::BigInteger(std::string s) {

    m_sizeReserved = s.length();
    m_number = new uint8_t[m_sizeReserved]();

    for (int i = 0; i < m_sizeReserved; i++) {
        int digit = s[m_sizeReserved - 1 - i] - '0';
        setDigit(i, digit);
    }
}

BigInteger::~BigInteger() {
    if (m_number)
    {
        delete[](m_number);
    }
}

void BigInteger::makeCopy(const BigInteger &first) {
    m_digitCount = first.m_digitCount;
    m_sizeReserved = first.m_sizeReserved;
    m_number = first.m_number;
}

BigInteger BigInteger::operator=(const BigInteger &first) {
    if (m_number)
    {
        delete[](m_number);
    }

    makeCopy(first);
    return *this;
}

BigInteger::BigInteger(const BigInteger &first) {
    makeCopy(first);
}

BigInteger BigInteger::operator+(const BigInteger &rhs){
    BigInteger result;
    unsigned int length = (this->m_digitCount > rhs.m_digitCount) ? this->m_digitCount : rhs.m_digitCount;

    int carry = 0;
    for (unsigned int digit = 0; digit < length; digit++)
    {
        int v1 = this->getDigit(digit);
        int v2 = rhs.getDigit(digit);
        int sum = v1 + v2 + carry;
        int single = sum % 10;
        carry = ((sum - single) > 0) ? (sum - single) / 10 : 0;

        result.setDigit(digit, single);
    }
    if (carry > 0)
    {
        result.setDigit(length, carry);
    }

    return result;
}

BigInteger BigInteger::operator+(unsigned int value){
    BigInteger result = BigInteger(value) + *this;
    return result;
}

BigInteger& BigInteger::operator+=(const BigInteger &rhs) {
    BigInteger result = *this + rhs;
    makeCopy(result);
    return *this;
}

BigInteger BigInteger::operator++(int value){
    m_number[m_digitCount] += value;
    return *this;
}

BigInteger BigInteger::operator*(const BigInteger &rhs) {
    BigInteger result;
    const BigInteger& b = (this->m_digitCount < rhs.m_digitCount) ? *this : rhs;
    const BigInteger& t = (this->m_digitCount < rhs.m_digitCount) ? rhs : *this;

    for (unsigned int bDigit = 0; bDigit < b.m_digitCount; bDigit++)
    {
        BigInteger temp(0);
        int v1 = b.getDigit(bDigit);
        int carry = 0;
        for (unsigned int tDigit = 0; tDigit < t.m_digitCount; tDigit++)
        {
            int v2 = t.getDigit(tDigit);
            int sum = v1 * v2 + carry;
            int single = sum % 10;
            carry = ((sum - single) > 0) ? (sum - single) / 10 : 0;

            temp.setDigit(bDigit + tDigit, single);
        }
        if (carry > 0)
        {
            temp.setDigit(bDigit + t.m_digitCount, carry);
        }
        result = result + temp;
    }

    return result;
}

BigInteger BigInteger::operator*=(const BigInteger &rhs) {
    BigInteger result;
    const BigInteger& b = (this->m_digitCount < rhs.m_digitCount) ? *this : rhs;
    const BigInteger& t = (this->m_digitCount < rhs.m_digitCount) ? rhs : *this;

    for (unsigned int bDigit = 0; bDigit < b.m_digitCount; bDigit++)
    {
        BigInteger temp(0);
        int v1 = b.getDigit(bDigit);
        int carry = 0;
        for (unsigned int tDigit = 0; tDigit < t.m_digitCount; tDigit++)
        {
            int v2 = t.getDigit(tDigit);
            int sum = v1 * v2 + carry;
            int single = sum % 10;
            carry = ((sum - single) > 0) ? (sum - single) / 10 : 0;

            temp.setDigit(bDigit + tDigit, single);
        }
        if (carry > 0)
        {
            temp.setDigit(bDigit + t.m_digitCount, carry);
        }
        result = result + temp;
    }

    return result;
}

bool BigInteger::operator<=(const BigInteger &rhs){
    if (this->m_digitCount < rhs.m_digitCount) return true;
    if (this->m_digitCount > rhs.m_digitCount) return false;
    //
    // Have to go digit by digit
    for (int digit = m_digitCount - 1; digit >= 0; digit--)
    {
        if (this->m_number[digit] < rhs.m_number[digit]) return true;
        if (this->m_number[digit] > rhs.m_number[digit]) return false;
    }
    return true;
}

bool BigInteger::operator==(const BigInteger &rhs){
    bool keepGoing = false;

    if (this->m_digitCount == rhs.m_digitCount){
        keepGoing = true;
        while (keepGoing) {
            for (int digit = m_digitCount - 1; digit >= 0; digit--) {
                keepGoing = m_number[digit] == rhs.m_number[digit];
            }
        }
    }
    return keepGoing;
}

BigInteger::operator double() const {
    double number = 0;
    for (int i = 0; i < m_digitCount; i++) {
        number += m_number[i] * pow(10,i);
    }
    return number;
}


//BigInteger BigInteger::multiply(const BigInteger& rhs) {
//	BigInteger result;
//	const BigInteger& b = (this->m_digitCount < rhs.m_digitCount) ? *this : rhs;
//	const BigInteger& t = (this->m_digitCount < rhs.m_digitCount) ? rhs : *this;
//
//	for (unsigned int bDigit = 0; bDigit < b.m_digitCount; bDigit++)
//	{
//		BigInteger temp(0);
//		int v1 = b.getDigit(bDigit);
//		int carry = 0;
//		for (unsigned int tDigit = 0; tDigit < t.m_digitCount; tDigit++)
//		{
//			int v2 = t.getDigit(tDigit);
//			int sum = v1 * v2 + carry;
//			int single = sum % 10;
//			carry = ((sum - single) > 0) ? (sum - single) / 10 : 0;
//
//			temp.setDigit(bDigit + tDigit, single);
//		}
//		if (carry > 0)
//		{
//			temp.setDigit(bDigit + t.m_digitCount, carry);
//		}
//		BigInteger temp2 = result.add(temp);
//		result = temp2;
//	}
//
//	return result;
//}

std::uint8_t BigInteger::getDigit(unsigned int position) const {
	if (position < m_digitCount)
    {
		return m_number[position];
	}

	return 0;
}

void BigInteger::setDigit(unsigned int position, std::uint8_t digit) {
    if (position >= m_sizeReserved) {
        while (m_sizeReserved < position) {
            m_sizeReserved = m_sizeReserved * 2;
        }
        std::uint8_t* temp = new uint8_t[m_sizeReserved];
        std::copy(m_number, m_number + m_digitCount, temp);

        if (m_number) {
            delete[](m_number);
        }
        m_number = temp;
    }
    m_number[position] = digit;
    m_digitCount = position + 1;
}

std::ostream &operator<<(std::ostream &outputStream, const BigInteger &integer) {
    for (unsigned int digit = integer.m_digitCount; digit > 0; digit--)
    {
        outputStream << static_cast<int>(integer.m_number[digit - 1]);
    }
    return outputStream;
}
