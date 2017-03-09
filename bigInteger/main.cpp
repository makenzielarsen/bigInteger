#include <iostream>

#include "BigInteger.hpp"
#include "TestCases.hpp"

// ------------------------------------------------------------------
//
// Site to compare long factorial results: http://www.dcode.fr/factorial
//
// ------------------------------------------------------------------
BigInteger factorial(BigInteger value)
{
	BigInteger result(1);

	for (BigInteger next = 1; next <= value; next++)
	{
		result *= next;
	}

	return result;
}

int main()
{
    //mine

    BigInteger three("0");
	BigInteger four("1");
	BigInteger result2 = three * four;
	std::cout << "three * four = ";
    std::cout << result2 << std::endl;
	three *= four;
	std::cout << "three *= four = ";
    std::cout << three << std::endl;


    //theirs

//	BigInteger one(1234);
//	BigInteger two(9999);
//	BigInteger result = one + two;
//	std::cout << "one + two = ";
//    std::cout << result << std::endl;
//	std::cout << "one + two (as double) = " << static_cast<double>(result) << std::endl;
//	one += two;
//	std::cout << "one += two = ";
//    std::cout << one << std::endl;
//
//	BigInteger three("1234567890");
//	BigInteger four("123456789");
//	BigInteger result2 = three * four;
//	std::cout << "three * four = ";
//    std::cout << result2 << std::endl;
//	three *= four;
//	std::cout << "three *= four = ";
//    std::cout << three << std::endl;
//
//	BigInteger f = factorial(123);
//	std::cout << "factorial of 123 is: ";
//    std::cout << f << std::endl;
//	std::cout << "factorial (as double) = " << static_cast<double>(f) << std::endl;
//	BigInteger factorialFromWeb("12146304367025329675766243241881295855454217088483382315328918161829235892362167668831156960612640202170735835221294047782591091570411651472186029519906261646730733907419814952960000000000000000000000000000");
//
//	if (f == factorialFromWeb)
//	{
//		std::cout << "My factorial result matches!!" << std::endl;
//	}
//	else
//	{
//		std::cout << "Still work left to do..." << std::endl;
//	}
//
//	TestCases::runTestCases();

	return 0;
}
