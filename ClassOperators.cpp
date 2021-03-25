//ClassOperators.cpp
#include <iomanip>
#include "classesOperator.hpp"

Box::Box ( double lv, double wv, double hv ) : length { lv }, width { wv }, heigth { hv } {}
Box::Box ( const Box &aBox ) : length { aBox.length }, width { aBox.width }, heigth { aBox.heigth }
{
	std::cout << "Copy constructor called." << std::endl;
}
bool Box::operator < ( const Box& aBox ) const
{
	return volume () < aBox.volume ();
}
bool Box::operator < ( double value ) const
{
	return volume () < value;
}
Box& Box::operator += ( const Box& aBox )
{
	length = std::max ( length, aBox.length );
	width = std::max ( width, aBox.width );
	heigth += aBox.heigth;
	return *this;
}
Box& Box::operator += ( double value )
{
	length += value;
	width += value;
	heigth += value;
	return *this;
}
Box Box::operator + ( const Box& aBox ) const
{
	Box copy { *this };
	copy += aBox;
	return copy;
}
Box& Box::operator *= ( double value )
{
	length *= value;
	width *= value;
	heigth *= value;
	return *this;
}
Box Box::operator ~() const
{
	return Box { 1 / length, 1 / width, 1 / heigth };
}
Box& Box::operator ++ ()
{
	++length;
	++width;
	++heigth;
	return *this;
}
const Box Box::operator ++ ( int )
{
	auto copy { *this };
	++ ( *this );
	return copy;
}
Box& Box::operator = ( const Box& aBox )
{
	if ( length == aBox.length && width == aBox.width && heigth == aBox.heigth ) {}
	else
	{
		length = aBox.length;
		width = aBox.width;
		heigth = aBox.heigth;
	}
	return *this;
}
AnotherBox::AnotherBox ( double lv, double wv, double hv ) : length { lv }, width { wv }, heigth { hv } {}
AnotherBox::AnotherBox ( const AnotherBox &TBox ) : length { TBox.length }, width { TBox.width }, heigth { TBox.heigth }
{
	std::cout << "Copy constructor called." << std::endl;
}
bool AnotherBox::operator < ( const AnotherBox& aBox ) const
{
	return volume () < aBox.volume ();
}
bool AnotherBox::operator < ( double value ) const
{
	return volume () < value;
}
AnotherBox& AnotherBox::operator += ( const AnotherBox& aBox )
{
	length = std::max ( length, aBox.length );
	width = std::max ( width, aBox.width );
	heigth += aBox.heigth;
	return *this;
}
AnotherBox& AnotherBox::operator += ( double value )
{
	length += value;
	width += value;
	heigth += value;
	return *this;
}
AnotherBox AnotherBox::operator + ( const AnotherBox& aBox ) const
{
	AnotherBox copy { *this };
	copy += aBox;
	return copy;
}
AnotherBox& AnotherBox::operator *= ( double value )
{
	length *= value;
	width *= value;
	heigth *= value;
	return *this;
}
AnotherBox AnotherBox::operator ~() const
{
	return AnotherBox { 1 / length, 1 / width, 1 / heigth };
}
AnotherBox& AnotherBox::operator ++ ()
{
	++length;
	++width;
	++heigth;
	return *this;
}
const AnotherBox AnotherBox::operator ++ ( int )
{
	auto copy { *this };
	++ ( *this );
	return copy;
}
AnotherBox& AnotherBox::operator = ( const AnotherBox& aBox )
{
	if ( length == aBox.length && width == aBox.width && heigth == aBox.heigth ) {}
	else
	{
		length = aBox.length;
		width = aBox.width;
		heigth = aBox.heigth;
	}
	return *this;
}
Node::Node ()
{
	std::cout << "'Node constructor called." << std::endl;
}
std::ostream& operator << ( std::ostream& stream, const Box& aBox )
{
	stream << "Box (" << std::setw ( 1 ) << aBox.getLength() << ','
	<< std::setw ( 2 ) << aBox.getWidth() << ','
	<< std::setw ( 2 ) << aBox.getHeigth() << ')';
	return stream;
}
std::ostream& operator << ( std::ostream& stream, const AnotherBox& aBox )
{
	stream << "Box (" << std::setw ( 1 ) << aBox.getLength() << ','
	<< std::setw ( 2 ) << aBox.getWidth() << ','
	<< std::setw ( 2 ) << aBox.getHeigth() << ')';
	return stream;
}
void printList ( Node * n )
{
	int items { 0 };
	std::cout << "Data of nodes:";
	while ( n != nullptr )
	{
		if ( items == 15 )
		{
			items = 0;
			std::cout << std::endl;
			std::cout << std::setw ( 15 );
		}
		items ++;
		std::cout << " " <<  n -> nodeData;
		n = n -> pNext;
	}
	std::cout << std::endl;
}
void insertAtStart ( Node** node, int data )
{
	Node* ptr;
	ptr = ( Node * ) malloc ( sizeof ( Node ) );
	ptr -> nodeData = data;
	ptr -> pNext = *node;
	( *node ) -> pLast = ptr;
	*node = ptr;
	ptr -> pLast = nullptr;
}
