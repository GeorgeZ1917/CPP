//MainOperator.cpp
#include <iostream>
#include <utility>
#include "classesOperator.hpp"

using namespace std::rel_ops;

int main ()
{
	Node *head = nullptr;
	head = new Node ();
	head -> nodeData = 3;
	head -> pNext = nullptr;
	insertAtStart ( &head, 5 );
	insertAtStart ( &head, 2 );
	insertAtStart ( &head, 7 );
	insertAtStart ( &head, 9 );
	for ( int i { 0 }; i < 100; i ++ )
	{
		insertAtStart ( &head, i * i );
	}
	Box Box1 { 1.0, 2.0, 3.0 };
	Box Box2 { 4.0, 5.0, 6.0 };
	AnotherBox Box3 { 7.0, 8.0, 9.0 };
	AnotherBox Box4 { 10.0, 11.0, 12.0 };
	printList ( head );
	std::cout << "Box1 < Box2:   " << ( Box1 < Box2 ) << std::endl;
	std::cout << "Box1 + Box2:   " << Box1 + Box2 << std::endl;
	std::cout << "Box1 < 10.0:   " << ( Box1 < 10.0 ) << std::endl;
	std::cout << "35.0 < Box2:   " << ( 35.0 < Box2 ) << std::endl;
	std::cout << "Box1 <= Box2:  " << ( Box1 <= Box2 ) << std::endl;
	std::cout << "Box1 != Box2:  " << ( Box1 != Box2 ) << std::endl;
	std::cout << "Box1 >= Box2:  " << ( Box1 >= Box2 ) << std::endl;
	std::cout << "Box1 == Box2:  " << ( Box1 == Box2 ) << std::endl;
	std::cout << "Box1:          " << Box1 << std::endl;
	std::cout << "Box2:          " << Box2 << std::endl;
	std::cout << "Box3 < Box4:   " << ( Box3 < Box4 ) << std::endl;
	std::cout << "120.0 < Box3:  " << ( 120.0 < Box3 ) << std::endl;
	std::cout << "Box3 += Box4:  " << ( Box3 += Box4 ) << std::endl;
	Box4 += 10;
	Box1 *= 3;
	std::cout << "Box4:          " << Box4 << std::endl;
	std::cout << "Box1:          " << Box1 << std::endl;
	std::cout << "~Box1:         " << ~Box1 << std::endl;
	++ Box4;
	std::cout << "++ Box4:       " << Box4 << std::endl;
	Box4 ++;
	std::cout << "Box4 ++:       " << Box4 << std::endl;
	double convertedVolume = static_cast<double> ( Box1 );
	std::cout << "Converted vol: " << convertedVolume << std::endl;
	std::cout << "Before assig.: " << Box1 << std::endl;
	Box1 = Box1;
	std::cout << "After assig.:  " << Box1 << std::endl;
	std::cout << "\n\nPress any key to exit...";
	std::cin.get();
	return 0;
}