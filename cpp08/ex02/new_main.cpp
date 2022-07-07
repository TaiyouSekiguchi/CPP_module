#include "MutantStack.hpp"

void	StackTest(void)
{
	MutantStack<int>	mstack;

	if (!mstack.empty())
		throw "StackTest failed.";
	if (mstack.size() != 0)
		throw "StackTest failed.";

	mstack.push( 1031 );
	mstack.push( 42 );
	mstack.push( -1234 );
	mstack.push( 9999 );
	mstack.push( 33 );

	if (mstack.empty())
		throw "StackTest failed.";
	if (mstack.size() != 5)
		throw "StackTest failed.";

	if (mstack.top() == 33)
		mstack.pop();
	else
		throw "StackTest failed.";

	if (mstack.top() == 9999)
		mstack.pop();
	else
		throw "StackTest failed.";

	if (mstack.top() == -1234)
		mstack.pop();
	else
		throw "StackTest failed.";

	if (mstack.top() == 42)
		mstack.pop();
	else
		throw "StackTest failed.";

	if (mstack.top() == 1031)
		mstack.pop();
	else
		throw "StackTest failed.";

	std::cout << "PushTest [ OK ]" << std::endl;
	std::cout << std::endl;
}

void	IteratorTest(void)
{
	MutantStack<int>	mstack;

	mstack.push( 1031 );
	mstack.push( 42 );
	mstack.push( -1234 );
	mstack.push( 9999 );
	mstack.push( 33 );

	MutantStack<int>::iterator	it;
	MutantStack<int>::iterator	itEnd;

	it = mstack.begin();
	itEnd = mstack.end();

	if (*it == 1031)
		++it;
	else
		throw "IteratorTest failed.";

	if (*it == 42)
		++it;
	else
		throw "IteratorTest failed.";

	if (*it == -1234)
		++it;
	else
		throw "IteratorTest failed.";

	if (*it == 9999)
		++it;
	else
		throw "IteratorTest failed.";

	if (*it == 33)
		++it;
	else
		throw "IteratorTest failed.";

	if (it == itEnd)
		;
	else
		throw "IteratorTest failed.";

	std::cout << "IteratorTest [ OK ]" << std::endl;
	std::cout << std::endl;
}

void	ReverseIteratorTest(void)
{
	MutantStack<int>	mstack;

	mstack.push( 1031 );
	mstack.push( 42 );
	mstack.push( -1234 );
	mstack.push( 9999 );
	mstack.push( 33 );

	MutantStack<int>::reverse_iterator	rit;
	MutantStack<int>::reverse_iterator	ritEnd;

	rit = mstack.rbegin();
	ritEnd = mstack.rend();

	if (*rit == 33)
		++rit;
	else
		throw "ReverseIteratorTest failed.";

	if (*rit == 9999)
		++rit;
	else
		throw "ReverseIteratorTest failed.";

	if (*rit == -1234)
		++rit;
	else
		throw "ReverseIteratorTest failed.";

	if (*rit == 42)
		++rit;
	else
		throw "ReverseIteratorTest failed.";

	if (*rit == 1031)
		++rit;
	else
		throw "ReverseIteratorTest failed.";

	if (rit == ritEnd)
		;
	else
		throw "ReverseIteratorTest failed.";

	std::cout << "ReverseIteratorTest [ OK ]" << std::endl;
	std::cout << std::endl;
}

void	ConstIteratorTest(void)
{
	MutantStack<int>	mstack;

	mstack.push( 1031 );
	mstack.push( 42 );
	mstack.push( -1234 );
	mstack.push( 9999 );
	mstack.push( 33 );

	MutantStack<int>::const_iterator	it;
	MutantStack<int>::const_iterator	itEnd;

	it = mstack.begin();
	itEnd = mstack.end();

	if (*it == 1031)
		++it;
	else
		throw "ConstIteratorTest failed.";

	if (*it == 42)
		++it;
	else
		throw "ConstIteratorTest failed.";

	if (*it == -1234)
		++it;
	else
		throw "ConstIteratorTest failed.";

	if (*it == 9999)
		++it;
	else
		throw "ConstIteratorTest failed.";

	if (*it == 33)
		++it;
	else
		throw "ConstIteratorTest failed.";

	if (it == itEnd)
		;
	else
		throw "ConstIteratorTest failed.";

	std::cout << "ConstIteratorTest [ OK ]" << std::endl;
	std::cout << std::endl;
}

void	ConstReverseIteratorTest(void)
{
	MutantStack<int>	mstack;
	MutantStack<int>	cmstack;

	mstack.push( 1031 );
	mstack.push( 42 );
	mstack.push( -1234 );
	mstack.push( 9999 );
	mstack.push( 33 );

	cmstack = mstack;

	MutantStack<int>::const_reverse_iterator	rit;
	MutantStack<int>::const_reverse_iterator	ritEnd;

	rit = cmstack.rbegin();
	ritEnd = cmstack.rend();

	if (*rit == 33)
		++rit;
	else
		throw "ConstReverseIteratorTest failed.";

	if (*rit == 9999)
		++rit;
	else
		throw "ConstReverseIteratorTest failed.";

	if (*rit == -1234)
		++rit;
	else
		throw "ConstReverseIteratorTest failed.";

	if (*rit == 42)
		++rit;
	else
		throw "ConstReverseIteratorTest failed.";

	if (*rit == 1031)
		++rit;
	else
		throw "ConstReverseIteratorTest failed.";

	if (rit == ritEnd)
		;
	else
		throw "ConstReverseIteratorTest failed.";

	std::cout << "ConstReverseIteratorTest [ OK ]" << std::endl;
	std::cout << std::endl;
}

int	main( void )
{
	try
	{
		StackTest();
		IteratorTest();
		ReverseIteratorTest();
		ConstIteratorTest();
		ConstReverseIteratorTest();
	}
	catch(const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	return ( 0 );
}
