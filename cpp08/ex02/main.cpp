#include "MutantStack.hpp"

int	main( void )
{
	MutantStack<int>	mstack;

	std::cout << "\n[ MutantStack info ]" << std::endl;
	std::cout << "Empty : " << (mstack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size  : " << mstack.size() << std::endl;

	std::cout << "\nPush to MutantStack [ 0, 42, -1234, 9999, 33 ]" << std::endl;
	mstack.push( 1031 );
	mstack.push( 42 );
	mstack.push( -1234 );
	mstack.push( 9999 );
	mstack.push( 33 );

	std::cout << "\n[ MutantStack info ]" << std::endl;
	std::cout << "Empty : " << (mstack.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size  : " << mstack.size() << std::endl;

	std::cout << "\n[ MutantStack copy to Stack ]" << std::endl;
	std::stack<int>		s(mstack);
	std::cout << "\n[ Copy Stack info ]" << std::endl;
	std::cout << "Empty : " << (s.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size  : " << s.size() << std::endl;

	std::cout << "\n[ MutantStack copy to MutantStack ]" << std::endl;
	MutantStack<int>	copy(mstack);
	std::cout << "\n[ Copy MutantStack info ]" << std::endl;
	std::cout << "Empty : " << (copy.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size  : " << copy.size() << std::endl;

	{
		MutantStack<int>::iterator	it;
		MutantStack<int>::iterator	itEnd;

		std::cout << "\nMutantStack [ ";
		it = mstack.begin();
		itEnd = mstack.end();
		for ( ; it != itEnd; ++it )
		{
			std::cout << *it << " ";
		}
		std::cout << "]  <<< USE ITERATOR ;) " << std::endl;

		MutantStack<int>::reverse_iterator	rit;
		MutantStack<int>::reverse_iterator	ritEnd;

		std::cout << "\nMutantStack [ ";
		rit = mstack.rbegin();
		ritEnd = mstack.rend();
		for ( ; rit != ritEnd; ++rit )
		{
			std::cout << *rit << " ";
		}
		std::cout << "]  <<< USE REVERSE_ITERATOR ;) " << std::endl;

		std::cout << "\nPop form MutantStack " << std::endl;
		for ( size_t i = 0; i < 5; ++i )
		{
			if ( !mstack.empty() )
			{
				std::cout << "top   : " << mstack.top() << std::endl;
				std::cout << "Size  : " << mstack.size() << std::endl;
				std::cout << mstack.top() << " is poping!!" << std::endl;
				mstack.pop();
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Size  : " << mstack.size() << std::endl;
				std::cout << "MutantStack is EMPTY!!" << std::endl;
			}
		}
		if ( !mstack.empty() )
		{
			std::cout << "top   : " << mstack.top() << std::endl;
			std::cout << "Size  : " << mstack.size() << std::endl;
			std::cout << mstack.top() << " is poping!!" << std::endl;
			mstack.pop();
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Size  : " << mstack.size() << std::endl;
			std::cout << "MutantStack is EMPTY!!" << std::endl;
		}

	}

	{
		std::cout << "\n##############  DEEP COPY CHECK ###############" << std::endl;

		MutantStack<int>::iterator	it;
		MutantStack<int>::iterator	itEnd;

		std::cout << "\nCOPY MutantStack [ ";
		it = copy.begin();
		itEnd = copy.end();
		for ( ; it != itEnd; ++it )
		{
			std::cout << *it << " ";
		}
		std::cout << "]  <<< USE ITERATOR ;) " << std::endl;

		MutantStack<int>::reverse_iterator	rit;
		MutantStack<int>::reverse_iterator	ritEnd;

		std::cout << "\nCOPY MutantStack [ ";
		rit = copy.rbegin();
		ritEnd = copy.rend();
		for ( ; rit != ritEnd; ++rit )
		{
			std::cout << *rit << " ";
		}
		std::cout << "]  <<< USE REVERSE_ITERATOR ;) " << std::endl;

		std::cout << "\nPop form COPY MutantStack " << std::endl;
		for ( size_t i = 0; i < 5; ++i )
		{
			if ( !copy.empty() )
			{
				std::cout << "top   : " << copy.top() << std::endl;
				std::cout << "Size  : " << copy.size() << std::endl;
				std::cout << copy.top() << " is poping!!" << std::endl;
				copy.pop();
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Size  : " << copy.size() << std::endl;
				std::cout << "MutantStack is EMPTY!!" << std::endl;
			}
		}
		if ( !copy.empty() )
		{
			std::cout << "top   : " << copy.top() << std::endl;
			std::cout << "Size  : " << copy.size() << std::endl;
			std::cout << copy.top() << " is poping!!" << std::endl;
			copy.pop();
			std::cout << std::endl;
		}
		else
		{
			std::cout << "Size  : " << copy.size() << std::endl;
			std::cout << "COPY MutantStack is EMPTY!!" << std::endl;
		}
	}
	std::cout << std::endl;

	return ( 0 );
}
