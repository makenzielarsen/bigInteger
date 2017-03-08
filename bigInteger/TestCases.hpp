#ifndef _TEST_CASES_HPP
#define _TEST_CASES_HPP

#include <functional>

class BigInteger;

class TestCases
{
	public:
		static void runTestCases();

		static bool testCase1(void);
		static bool testCase2(void);
		static bool testCase3(void);
		static bool testCase4(void);
		static bool testCase5(void);
		static bool testCase6(void);
		static bool testCase7(void);
		static bool testCase8(void);
		static bool testCase9(void);
		static bool testCase10(void);
		static bool testCase11(void);
		static bool testCase12(void);
		static bool testCase13(void);
		static bool testCase14(void);
		static bool testCase15(void);
		static bool testCase16(void);
		static bool testCase17(void);
		
		static bool verifyMatch(const BigInteger& rExptected, const BigInteger& rActual);

	private:
		static void runTest(std::function<bool(void)> testCase, std::string label);

};

#endif // _TEST_CASES_HPP
