// Stack.cpp

#include <iostream>
#include "Stack.hpp"

Stack::Stack () {}
void push ( Stack& stack, unsigned long long int data )
{
	if ( stack.m == stack.n )
	{
		resize ( stack );
	}
	stack.array [ stack.n ] = data;
	stack.n += 1;
}
void resize ( Stack& stack )
{
	unsigned long long int * newArray = new unsigned long long int [ 2 * stack.n ];
	for ( int i { 0 }; i < stack.n; i ++ )
	{
		newArray [ i ] = stack.array [ i ];
	}
	stack.m *= 2;
	delete [] stack.array;
	stack.array = newArray;
}
void printStack ( Stack& stack )
{
	for ( unsigned long long int i { 0 }; i < stack.n; i ++ )
	{
		std::cout << stack.array [ i ] << " ";
	}
	std::cout << std::endl;
}
void pop ( Stack& stack )
{
	if ( stack.n == 0 )
	{
		std::cout << "Empty array." << std::endl;
	}
	else
	{
		std::cout << stack.array [ stack.n - 1 ] << std::endl;
		stack.array [ stack.n ] = 0;
		stack.n -= 1;
	}
}