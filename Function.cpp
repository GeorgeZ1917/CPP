#include <iostream>
#include <type_traits>
template <typename TReturn, typename T1, typename T2> TReturn& larger ( T1& A, T2& B )
{
	return A > B ? A : B;
}
template <typename T> T function ( T A, T B )
{
	return A > B ? A : B;
}
template <> float function <float> ( float a, float b )
{
	std::cout << "The specialized float template was executed. ";
	return a > b ? a : b;
}
template <> int* function <int*> ( int* a, int* b )
{
	return *a > *b ? a : b;
}
int staticFunction ()
{
	static unsigned int staticInt = 0;
	staticInt ++;
	return staticInt;
}
int modifyByReference ( int &referenceOfVariable )
{
	referenceOfVariable ++;
	return referenceOfVariable;
}
long long int factorial ( int n )
{
	if ( n <= 1 )
	{
		return 1;
	}
	return n * factorial ( n - 1 );
}