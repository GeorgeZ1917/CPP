// Stack.hpp

class Stack
{
	public :
		Stack ();
		unsigned long long int * array = new unsigned long long int [ 1 ];
		unsigned long long int n { 0 };
		unsigned long long int m { 1 };
};
void push ( Stack& stack, unsigned long long int data );
void pop ( Stack& stack );
void resize ( Stack& stack );
void printStack ( Stack& stack );
