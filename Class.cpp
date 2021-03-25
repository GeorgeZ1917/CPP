// Class.cpp
#include <iostream>
#include "class.hpp"

Box::Box ( double side) : Box { side, side, side }
{
	std::cout << "Delegating constructor called." << std::endl;
}
Box::Box ( double lV, double wV, double hV ) : length { lV }, width { wV }, heigth { hV }
{
	objectCount ++;
	std::cout << "Constructor 1 called." << std::endl;
}
Box::Box ( const Box &object ) : length { object.length }, width { object.width }, heigth { object.heigth }
{
	objectCount ++;
	std::cout << "Copy constructor called." << std::endl;
}
Box::Box ()
{
	objectCount ++;
	std::cout << "Default constructor called." << std::endl;
}
Box:: ~Box ()
{
	std::cout << "Box destructor called." << std::endl;
	objectCount --;
}
double Box::volume () const
{
	return length * width * heigth;
}
double Box::getLength () const
{
	return length;
}
double Box::getWidth () const
{
	return width;
}
double Box::getHeigth () const
{
	return heigth;
}
void Box::setLength ( double lV )
{
	if ( lV > 0 )
	{
		length = lV;
	}
}
void Box::setWidth ( double wV )
{
	if ( wV > 0 )
	{
		width = wV;
	}
}
void Box::setHeigth ( double hV )
{
	if ( hV > 0 )
	{
		heigth = hV;
	}
}
Box &Box::setLengthR ( double lV )
{
	if ( lV > 0 )
	{
		length = lV;
	}
	return *this;
}
Box &Box::setWidthR ( double wV )
{
	if ( wV > 0 )
	{
		width = wV;
	}
	return *this;
}
Box &Box::setHeigthR ( double hV )
{
	if ( hV > 0 )
	{
		heigth = hV;
	}
	return *this;
}
double surfaceArea ( const Box& aBox )
{
	return 2.0 * ( aBox.length * aBox.width + aBox.length * aBox.heigth + aBox.heigth * aBox.width );
}
Node::Node ()
{
	std::cout << "Default constructor for 'Node' called." << std::endl;
}
Node::Node ( double value2 )
{
	nodeData = value2;
	std::cout << "'Node' constructor called." << std::endl;
}
void insertList ( Node **node, int obj )
{
	Node *ptr;
	ptr = ( Node * ) malloc ( sizeof ( Node ) );
	ptr -> nodeData = obj;
	ptr -> pNext = *node;
	( *node ) -> pLast = ptr;
	ptr -> pLast = nullptr;
	*node = ptr;
}
void appendList ( Node ** headRef, int obj )
{
    Node * ptr = ( Node * ) malloc ( sizeof ( struct Node ) );
    Node * last = * headRef;
    ptr -> nodeData = obj;
    ptr -> pNext = nullptr;
    while ( last -> pNext != nullptr )
    {
    	last = last -> pNext;
    	last -> pNext = ptr;
    }
}
void printList ( Node * n )
{
    while ( n != nullptr )
	{
        std::cout << n -> nodeData << " ";
        n = n -> pNext;
    }
    std::cout << std::endl;
}
void printReversed ( Node * n )
{
	while ( n != nullptr )
	{
		std::cout << n -> nodeData << " ";
		n = n -> pLast;
	}
	std::cout << std::endl;
}
int countNodes ( Node * n )
{
	static int nodeCount { 1 };
	Node *current;
	if ( n -> pNext == nullptr )
	{
		return nodeCount;
	}
	else
	{
		current = n -> pNext;
		nodeCount ++;
		countNodes ( current );
	}
}
// A utility function to print an array of size n  
void printArray ( int arr [], int n )  
{  
    int i;  
    for ( i = 0; i < n; i ++ )
	{
		std::cout << arr [ i ] << " ";  
	}
    std::cout << std::endl; 
}
