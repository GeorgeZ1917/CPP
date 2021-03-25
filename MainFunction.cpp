#include "definitions.hpp"
#include <string>
#include <iostream>
#include <windows.h>

namespace myNamespace
{
	int number;
	int value1 = 5;
	int value2 = 10;
	int powerTwo = 200;
}
namespace
{
	std::string string2 {};
	int referenceVariable = 0;
}
namespace outerNamespace
{
	double outer = 2.718;
	namespace innerNamespace
	{
		float inner = 12.1f;
	}
}
template <typename T1, typename T2> decltype ( auto ) larger2 ( T1& A, T2& B )
{
	return A > B ? A : B;
}
template <typename T> T assertFunction ( T A, T B )
{
	static_assert ( std::is_arithmetic_v<T>, "The parameter for assertFunction () shall be arithmetic." );
	return A > B ? A : B;
}
int main ( int argc, char *argv [] )
{
	std::string string1 { argv [ 1 ] };
	for ( int i = 0; i < string1.length (); i ++ )
	{
		string2 += string1.at ( string1.length () - i - 1 );
	}
	std::cout << "Original string: " + string1 << std::endl;
	std::cout << "Reversed string: " + string2 << std::endl;
	/*****************************************************************************************************************************************************/
	std::cout << "Greater value before assignment: " << *function ( &myNamespace::value1, &myNamespace::value2 ) << std::endl;
	*function ( &myNamespace::value1, &myNamespace::value2 ) = 50;
	std::cout << "Greater value after assignment:  " << *function ( &myNamespace::value1, &myNamespace::value2 ) << std::endl;
	//std::cout << "Greater value of 3.1 and 2.7  :  " << function ( 3.1, 2.7 ) << std::endl;
	std::cout << "Specialized float template:      " << function ( 3.1416f, 2.178f ) << std::endl;
	std::cout << "&value1 = " << &myNamespace::value1 << std::endl;
	std::cout << "&value2 = " << &myNamespace::value2 << std::endl;
	std::string s1 { "The first string." };
	std::string s2 { "The second string." };
	//std::cout << "The larger string:   " << larger<std::string> ( s1, s2 ) << std::endl;
	//larger<std::string> ( s1, s2 ) = "The new string.";
	//std::cout << "The assigned string: " << larger<std::string> ( s1, s2 ) << "\n\n\n\n\n";
	/*****************************************************************************************************************************************************/
	std::cout << "Modifying the static variable:             ";
	for ( int j = 0; j < 10; j ++ )
	{
		std::cout << std::to_string ( staticFunction () ) + " ";
	}
	std::cout << std::endl;
	std::cout << "Modifying the variable by reference:       ";
	for ( int j = 0; j < 10; j ++ )
	{
		std::cout << std::to_string ( modifyByReference ( referenceVariable ) ) + " ";
	}
	std::cout << std::endl; 
	/*****************************************************************************************************************************************************/
	std::cout << "Enter a number to calculate its factorial: ";
	std::cin >> myNamespace::number;
	std::cout << "Factorial of " + std::to_string ( myNamespace::number ) + " is " + std::to_string ( factorial ( myNamespace::number ) ) << "\n\n\n\n\n";
	/*****************************************************************************************************************************************************/
	std::string T1 = "First string";
	std::string T2 = "Second string";
	float first = 2.178;
	float second = 3.141592f;
	std::cout << "Larger string with multiple-parameter template and decltype: " + larger2 ( T1, T2 ) << std::endl;
	std::cout << "Larger float with multiple-parameter template and decltype:  " + std::to_string ( larger2 ( first, second ) ) << "\n\n\n\n\n";
	/*****************************************************************************************************************************************************/
	std::cout << "Pi through macro-defined: " << PI << "\n\n\n\n\n";
	/*****************************************************************************************************************************************************/
	std::cout << "Outer namespace variable: " << outerNamespace::outer << std::endl;
	std::cout << "Inner namespace variable: " << outerNamespace::innerNamespace::inner << std::endl;
	std::cout << "Program last compiled at  " << __TIME__ << " on " << __DATE__ << std::endl;
	std::cout << "Name of the file:         " << __FILE__ << std::endl;
	std::cout << "C++ compiler version:     " << __cplusplus << std::endl;
	std::cout << "GCC compiler version:     " << __GNUC__ << "\n\n\n\n\n";
	/*****************************************************************************************************************************************************/
	std::cout << "Larger of 4 and 8 is:                 " << assertFunction ( 4, 8 ) << std::endl;
	std::cout << "Size of int*: " << sizeof ( int* ) << std::endl;
	//std::cout << "Larger of 'string1' and 'string2' is: " << assertFunction<int> ( string1, string2 ) << std::endl;
	system ( "PAUSE" );
	return 0;
}
