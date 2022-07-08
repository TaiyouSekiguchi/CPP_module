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

void	AddRangeTest(void)
{
	const int	set_size = 5;
	int			array[set_size];

	array[0] = 12;
	array[1] = 42;
	array[2] = -3;
	array[3] = 123432;
	array[4] = 33;

	Span	sp = Span(set_size);
	sp.addRange(array, array + set_size);

	result("AddRangeTest", sp, 9, 123435);
}

void	AddRangeExceptionTest(void)
{
	const int	set_size = 5;
	int			array[set_size];

	std::cerr << "[ AddRangeExceptionTest ]" << std::endl;
	try
	{
		array[0] = 12;
		array[1] = 42;
		array[2] = -3;
		array[3] = 123432;
		array[4] = 33;

		Span	sp = Span(3);
		sp.addRange(array, array + set_size);
		std::cerr << "Not throw Exception [ NG ]" << std::endl;
	}
	catch(const char* msg)
	{
		std::cerr << msg << std::endl;
		std::cerr << "catch exception!! [ OK ]" << std::endl;
	}

	return ;
}

void	BigTest(void)
{
	const int	set_size = 20000;
	int			array[set_size];
	int			i = 0;

	std::srand( time( NULL ) );

	while (i < set_size - 4)
	{
		int	num = std::rand() % 100000;
		array[i] = num;
		i++;
	}
	array[i++] = 100000;
	array[i++] = 100000;
	array[i++] = 200000;
	array[i] = -1;

	Span	sp = Span(set_size);
	sp.addRange(array, array + set_size);

	result("BigTest", sp, 0, 200001);
}

int	main( void )
{
	SubjectTest();
	MaxTest();
	MinTest();
	OverSizeTest();
	shortestSpanExceptionTest();
	longestSpanExceptionTest();
	AddRangeTest();
	AddRangeExceptionTest();
	BigTest();

	return ( 0 );
}
