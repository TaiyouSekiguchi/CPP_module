#include "Span.hpp"

void	result(const std::string& test_name, const Span& sp, unsigned int expectShort, unsigned int expectLong)
{
	std::cout << "[ " << test_name << " ]" << std::endl;
	std::cout << "expect short : " << expectShort << std::endl;
	std::cout << "expect long  : " << expectLong << std::endl;

	if (sp.shortestSpan() == expectShort)
		std::cout << "shortestSpan [ OK ] ;)" << std::endl;
	else
		std::cout << "shortestSpan [ NG ] :(" << std::endl;

	if (sp.longestSpan() == expectLong)
		std::cout << "longestSpan [ OK ] ;)" << std::endl;
	else
		std::cout << "longestSpan [ NG ] :(" << std::endl;
	std::cout << std::endl;
}

void	SubjectTest(void)
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	result("SubjectTest", sp, 2, 14);
}

void	MaxTest(void)
{
	Span	sp = Span(5);
	unsigned long	ans;

	ans = 2147483647 - (-2147483648);

	sp.addNumber(-6);
	sp.addNumber(2147483647);
	sp.addNumber(17);
	sp.addNumber(-2147483648);
	sp.addNumber(11);

	result("MaxTest", sp, 6, ans);
}

void	MinTest(void)
{
	Span	sp = Span(6);
	unsigned long	ans;

	ans = 2147483647 - (-2147483648);

	sp.addNumber(-6);
	sp.addNumber(2147483647);
	sp.addNumber(17);
	sp.addNumber(-2147483648);
	sp.addNumber(11);
	sp.addNumber(17);

	result("MinTest", sp, 0, ans);
}

void	OverSizeTest(void)
{
	Span	sp = Span(5);

	try
	{
		sp.addNumber(-6);
		sp.addNumber(2147483647);
		sp.addNumber(17);
		sp.addNumber(-2147483648);
		sp.addNumber(11);
		sp.addNumber(17);
	}
	catch (const char* msg)
	{
		std::cerr << "[ OverSizeTest ]" << std::endl;
		std::cerr << msg << std::endl;
		std::cerr << "catch exception!! [ OK ]" << std::endl;
	}
	std::cerr << std::endl;
}

void	shortestSpanExceptionTest(void)
{
	Span	sp = Span(5);

	std::cerr << "[ shortestSpanExceptionTest ]" << std::endl;
	try
	{
		sp.shortestSpan();
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
		std::cerr << "catch exception!! [ OK ]" << std::endl;
	}

	try
	{
		sp.addNumber(17);
		sp.shortestSpan();
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
		std::cerr << "catch exception!! [ OK ]" << std::endl;
	}
	std::cerr << std::endl;
}

void	longestSpanExceptionTest(void)
{
	Span	sp = Span(5);

	std::cerr << "[ longestSpanExceptionTest ]" << std::endl;
	try
	{
		sp.longestSpan();
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
		std::cerr << "catch exception!! [ OK ]" << std::endl;
	}

	try
	{
		sp.addNumber(17);
		sp.longestSpan();
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
		std::cerr << "catch exception!! [ OK ]" << std::endl;
	}
	std::cerr << std::endl;
}

void	rondomTest()
{
	Span	sp = Span(20000);

	std::cerr << "[ rondom test ]" << std::endl;
	sp.setRandomNumber(20000);
	std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
}

int	main( void )
{
	SubjectTest();
	MaxTest();
	MinTest();
	OverSizeTest();
	shortestSpanExceptionTest();
	longestSpanExceptionTest();
	rondomTest();

	return ( 0 );
}
