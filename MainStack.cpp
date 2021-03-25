// MainStack.cpp

#include <iostream>
#include "Stack.hpp"

int main()
{
	Stack firstStack;
	push ( firstStack, 3 );
	push ( firstStack, 5 );
	push ( firstStack, 7 );
	push ( firstStack, 13 );
	push ( firstStack, 9 );
	push ( firstStack, 5 );
	unsigned long long int j { 0 };
	/*while ( j < 1000000 )
	{
		push ( firstStack, j * j );
		j ++;
	}*/
	pop ( firstStack );
	pop ( firstStack );
	printStack ( firstStack );
	return 0;
}