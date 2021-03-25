// Main.cpp
#include <iostream>
#include <memory>
#include <array>
#include "class.hpp"

int main ()
{
	Box myBox1 { 15.0, 5.0, 25.0 };
	std::cout << "Volume of myBox1 through created constructor:   " << myBox1.volume() << std::endl;
	Box myBox2;
	std::cout << "Volume of myBox2 through default constructor:   " << myBox2.volume() << std::endl;
	Box myBox3 { 6 };
	std::cout << "Volume of myBox3 through delegated constructor: " << myBox3.volume() << std::endl;
	std::cout << "Width of myBox1 before setter:                  " << myBox1.getWidth() << std::endl;
	myBox1.setWidth ( 20 );
	std::cout << "Width of myBox1 after setter:                   " << myBox1.getWidth() << std::endl;
	Box myBox4 { myBox3 };
	std::cout << "Volume of myBox 4 through copy constructor:     " << myBox4.volume () << std::endl;
	Box myBox5 { 10.0, 15.0, 20.0 };
	myBox5.setLengthR( 5.0 ).setWidthR( 6.0 ).setHeigthR( 7.0 );
	std::cout << "Volume of myBox5 through 'this' pointer:        " << myBox5.volume() << std::endl;
	const Box myBox6;
	std::cout << "Volume of myBox6 through const member function  " << myBox6.volume() << std::endl;
	std::cout << "Surface area of myBox5 through friend function: " << surfaceArea( myBox5 ) << std::endl;
	std::cout << "There exist " << Box::objectCount << " Box objects before array." << std::endl;
	std::array <Box, 6> boxArray { myBox1, myBox2, myBox3, myBox4, myBox5, myBox6 }; 
	for ( int i = 0; i < 6; i ++ )
	{
		printValues ( boxArray [ i ] );
		std::cout << std::endl;
	}
	std::cout << "Size of boxArray is " << sizeof ( boxArray ) << "." << std::endl;
	std::cout << "There exist " << Box::objectCount << " Box objects after array." << std::endl;
	std::cout << "Static member constant: " << Box::constant << "\n\n\n\n";
	/*********************************************************************************************************************/
	Node *head = nullptr;
	Node *second = nullptr;
	Node *third = nullptr;
	head = new Node ();
	second = new Node ();
	third = new Node ();
	head -> nodeData = 1;
	head -> pNext = second;
	second -> nodeData = 2;
	second -> pNext = third;
	third -> nodeData = 3;
	third -> pNext = nullptr;
	third -> pLast = second;
	second -> pLast = head;
	head -> pLast = nullptr;
	printList ( head );
	insertList ( &head, 11 );
	insertList ( &head, 21 );
	insertList ( &head, 13 );
	insertList ( &head, 19 );
	std::cout << "Printed list before reversal:" << std::endl;
	printList ( head );
	std::cout << "Printed list after reversal:" << std::endl;
	printReversed (  third );
	std::cout << "Number of nodes: " << countNodes ( head ) << std::endl;
	std::cout << "Press any key to exit... ";
	std::cin.get();
	return 0;
}
