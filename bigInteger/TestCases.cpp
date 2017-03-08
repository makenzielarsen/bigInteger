
#include <sstream>
#include <string.h>

#include "TestCases.hpp"
#include "BigInteger.hpp"


void TestCases::runTestCases()
{
	std::cout << "[=================]" << std::endl;
	std::cout << "[-----------------] Running tests" << std::endl;
	std::cout << "[-----------------]" << std::endl;

	runTest(testCase1, "Constructor Test");
	runTest(testCase2, "Integer Convert Constructor Test");
	runTest(testCase3, "String Convert Constructor Test");
	runTest(testCase4, "Copy Constructor Test");
	runTest(testCase5, "Assignment Operator Test");
	runTest(testCase6, "Operator+ Test");
	runTest(testCase7, "Operator* Test");
	runTest(testCase8, "GetDigit Test");
	runTest(testCase9, "SetDigit Test");
	runTest(testCase10, "Operator+ Unsigned Int Test");
	runTest(testCase11, "Operator+= Test");
	runTest(testCase12, "Operator++ Test");
	runTest(testCase13, "Operator*= Test");
	runTest(testCase14, "Operator== Test");
	runTest(testCase15, "Operator<= Test");
	runTest(testCase16, "Operator double Test");
	runTest(testCase17, "Stream Operator Test");

	std::cout << "[-----------------]" << std::endl;
	std::cout << "[-----------------] Tests complete" << std::endl;
	std::cout << "[=================]" << std::endl;
}

void TestCases::runTest(std::function<bool(void)> testCase, std::string label)
{
	std::cout << "[ Running         ] " << label << std::endl;
	
	if (testCase())
	{
		std::cout << "[            PASS ]";
	}
	else
	{
		std::cout << "[          FAILED ]";
	}

	std::cout << " " << label << std::endl;
}

bool TestCases::testCase1(void)
{
	BigInteger i;
	
	return (i.m_number != nullptr) && (i.m_sizeReserved == 4) && (i.m_digitCount == 0);
}

bool TestCases::testCase2(void)
{
	BigInteger i(1234567);
	
	return (i.m_number != nullptr) && (i.m_sizeReserved > 0) && (i.m_digitCount == 7) && (i.m_number[6] == 1) && (i.m_number[5] == 2)
	  && (i.m_number[4] == 3) && (i.m_number[3] == 4) && (i.m_number[2] == 5) && (i.m_number[1] == 6) && (i.m_number[0] == 7);
}

bool TestCases::testCase3(void)
{
	bool ret = true;
	std::string value = "123456789123456789123456789";
	BigInteger i(value);
	
	if ((i.m_number == nullptr) || (i.m_sizeReserved <= 0) || (i.m_digitCount != value.length()))
	{
		ret = false;
	}
	else
	{
		for (int j = 0; j < value.length() && ret; j++)
		{
			if (i.m_number[j] != (value[value.length() - 1 - j] - '0'))
			{
				ret = false;
			}
		}
	}
	
	return ret;
}

bool TestCases::testCase4(void)
{
	bool ret = true;
	BigInteger i("123456789123456789123456789");
	BigInteger copy(i);
	
	if (copy.m_number == nullptr)
	{
		std::cout << "  The copy of m_number was NULL" << std::endl;
		ret = false;
	}
	else if (copy.m_sizeReserved != i.m_sizeReserved)
	{
		std::cout << "  The m_sizeReserved variables do not match" << std::endl;
		std::cout << "   Expected " << i.m_sizeReserved << std::endl;
		std::cout << "   Actual " << copy.m_sizeReserved << std::endl;
		ret = false;
	}
	else if (i.m_digitCount != copy.m_digitCount)
	{
		std::cout << "  The m_digitCount variables do not match" << std::endl;
		std::cout << "   Expected " << i.m_digitCount << std::endl;
		std::cout << "   Actual " << copy.m_digitCount << std::endl;
		ret = false;
	}
	else
	{
		for (unsigned int j = 0; j < copy.m_sizeReserved && j < i.m_sizeReserved && ret; j++)
		{
			if (i.m_number[j] != copy.m_number[j])
			{
				ret = false;
				std::cout << "  The m_number[" << j << "] Didn't match" << std::endl;
				std::cout << "   Expected " << i.m_number[j] << std::endl;
				std::cout << "   Actual " << copy.m_number[j] << std::endl;
			}
		}
	}
	
	return ret;
}

bool TestCases::testCase5(void)
{
	bool ret = true;
	BigInteger i("123456789123456789123456789");
	BigInteger copy("1");
	
	copy = i;
	
	if (copy.m_number == nullptr)
	{
		std::cout << "  The copy of m_number was NULL" << std::endl;
		ret = false;
	}
	else if (copy.m_sizeReserved != i.m_sizeReserved)
	{
		std::cout << "  The m_sizeReserved variables do not match" << std::endl;
		std::cout << "   Expected " << i.m_sizeReserved << std::endl;
		std::cout << "   Actual " << copy.m_sizeReserved << std::endl;
		ret = false;
	}
	else if (i.m_digitCount != copy.m_digitCount)
	{
		std::cout << "  The m_digitCount variables do not match" << std::endl;
		std::cout << "   Expected " << i.m_digitCount << std::endl;
		std::cout << "   Actual " << copy.m_digitCount << std::endl;
		ret = false;
	}
	else
	{
		for (unsigned int j = 0; j < copy.m_sizeReserved && j < i.m_sizeReserved && ret; j++)
		{
			if (i.m_number[j] != copy.m_number[j])
			{
				ret = false;
				std::cout << "  The m_number[" << j << "] Didn't match" << std::endl;
				std::cout << "   Expected " << i.m_number[j] << std::endl;
				std::cout << "   Actual " << copy.m_number[j] << std::endl;
			}
		}
	}
	
	return ret;
}

bool TestCases::testCase6(void)
{
	BigInteger item1("11111111111111");
	BigInteger item2("22222222222222");
	BigInteger expect("33333333333333");
	BigInteger copy = item2 + item1;
	
	return verifyMatch(expect, copy);
}

bool TestCases::testCase7(void)
{
	BigInteger item1("2345678904567");
	BigInteger item2("123456789056");
	BigInteger expect("289589985714237274018752");
	BigInteger copy = item2 * item1;
	
	return verifyMatch(expect, copy);
}

bool TestCases::testCase8(void)
{
	bool ret = true;
	std::string value = "2345678904567";
	BigInteger item(value);
	
	for (unsigned int i = 0; i < item.m_digitCount; i++)
	{
		unsigned int res = item.getDigit(item.m_digitCount - i - 1);
		if (res != value[i] - '0')
		{
			ret = false;
			std::cout << "  The getdigit(" << item.m_digitCount - i - 1 << ") Didn't match" << std::endl;
			std::cout << "   Expected " << res << std::endl;
			std::cout << "   Actual " << value[i] << std::endl;
		}
	}
	
	return ret;
}

bool TestCases::testCase9(void)
{
	unsigned int pos = 5;
	std::uint8_t digit = 1;
	BigInteger item;
	
	if (item.m_number == nullptr)
	{
		std::cout << "  An empty BigInteger should have a non-NULL m_number variable" << std::endl;
		return false;
	}
	else if (item.m_digitCount != 0)
	{
		std::cout << "  The m_digitcount variable was incorrect" << std::endl;
		std::cout << "   Expected " << 0 << std::endl;
		std::cout << "   Actual " << item.m_digitCount << std::endl;
		return false;
	}

	for (unsigned int i = 0; i < pos; i++)
	{
		item.setDigit(i, digit);
		
		if (item.m_number == nullptr)
		{
			std::cout << "  The m_number variable should not be NULL" << std::endl;
			return false;
		}
		else if (item.m_digitCount != i + 1)
		{
			std::cout << "  The m_digitcount variable was incorrect" << std::endl;
			std::cout << "   Expected " << i + 1 << std::endl;
			std::cout << "   Actual " << item.m_digitCount << std::endl;
			return false;
		}
		else if (item.getDigit(i) != digit)
		{
			std::cout << "  The getDigit(" << i << ") Didn't match" << std::endl;
			std::cout << "   Expected " << digit << std::endl;
			std::cout << "   Actual " << item.getDigit(i) << std::endl;
			return false;
		}

		digit++;
	}
	
	return true;
}

bool TestCases::testCase10(void)
{
	BigInteger item1("12345");
	unsigned int item2 = 54321;
	BigInteger expect("66666");
	BigInteger copy = item1 + item2;

	return verifyMatch(expect, copy);
}

bool TestCases::testCase11(void)
{
	BigInteger item1("12345");
	BigInteger item2("54321");
	BigInteger item3("11111");
	BigInteger expect1("66666");
	BigInteger expect2("77777");
	item3 += item2 += item1;

	return verifyMatch(expect1, item2) && verifyMatch(expect2, item3);
}

bool TestCases::testCase12(void)
{
	bool ret = true;
	unsigned int base = 12345;
	BigInteger item1(base);
	BigInteger item2("1234567890");
	BigInteger expect2("1234567891");

	for (unsigned int i = 0; i < 1 && ret; i++)
	{
		BigInteger expect(item1);
		BigInteger expect2(base + i + 1);
		BigInteger item2(item1++);
		ret = verifyMatch(expect, item2) && verifyMatch(expect2, item1);
	}

	return ret;
}

bool TestCases::testCase13(void)
{
	BigInteger item1("12345");
	BigInteger item2("54321");
	BigInteger item3("987654");
	BigInteger expect1("670592745");
	BigInteger expect2("662313606970230");
	item3 *= item2 *= item1;

	return verifyMatch(expect1, item2) && verifyMatch(expect2, item3);
}

bool TestCases::testCase14(void)
{
	bool ret = true;
	BigInteger item1("12345");
	BigInteger item2("54321");
	BigInteger item3("12345");

	if (item1 == item2)
	{
		std::cout << "  The expression " << item1 << " == " << item2 << " was expected to be false" << std::endl;
		ret = false;
	}
	else if (!(item1 == item3))
	{
		std::cout << "  The expression " << item1 << " == " << item3 << " was expected to be true" << std::endl;
		ret = false;
	}

	return ret;
}

bool TestCases::testCase15(void)
{
	bool ret = true;
	BigInteger item1("12345");
	BigInteger item2("54321");
	BigInteger item3("12345");
	BigInteger item4("12344");

	if (!(item1 <= item2))
	{
		std::cout << "  The expression " << item1 << " <= " << item2 << " was expected to be true" << std::endl;
		ret = false;
	}
	else if (!(item1 <= item3))
	{
		std::cout << "  The expression " << item1 << " <= " << item3 << " was expected to be true" << std::endl;
		ret = false;
	}
	else if (item1 <= item4)
	{
		std::cout << "  The expression " << item1 << " <= " << item4 << " was expected to be false" << std::endl;
		ret = false;
	}

	return ret;
}

bool TestCases::testCase16(void)
{
	bool ret = true;
	BigInteger item1("123456");
	double expect = 123456;
	double actual = static_cast<double>(item1);

	if (expect != actual)
	{
		std::cout << "  The double cast from " << item1 << " does not match expected" << std::endl;
		std::cout << "   Expected " << expect << std::endl;
		std::cout << "   Actual " << actual << std::endl;
		ret = false;
	}

	return ret;
}

bool TestCases::testCase17(void)
{
	bool ret = true;
	BigInteger item1("123456");

	std::stringstream os;
	os << item1;

	BigInteger actual(os.str());

	return verifyMatch(item1, actual);
}



bool TestCases::verifyMatch(const BigInteger& rExptected, const BigInteger& rActual)
{
	bool ret = true;

	if (rActual.m_number == nullptr)
	{
		std::cout << "  The result's m_number was NULL" << std::endl;
		ret = false;
	}
	else if (rExptected.m_digitCount != rActual.m_digitCount)
	{
		std::cout << "  The m_digitCount variables do not match" << std::endl;
		std::cout << "   Expected " << rExptected.m_digitCount << std::endl;
		std::cout << "   Actual " << rActual.m_digitCount << std::endl;
		ret = false;
	}
	else
	{
		for (unsigned int j = 0; j < rActual.m_digitCount && j < rExptected.m_digitCount && ret; j++)
		{
			if (rExptected.m_number[j] != rActual.m_number[j])
			{
				ret = false;
				std::cout << "  The m_number[" << j << "] Didn't match" << std::endl;
				std::cout << "   Expected " << (int)rExptected.m_number[j] << std::endl;
				std::cout << "   Actual " << (int)rActual.m_number[j] << std::endl;
			}
		}
	}

	return ret;
}
