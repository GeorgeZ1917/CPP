//classesOperator
#ifndef CLASSESOPERATOR_HPP
#define CLASSESOPERATOR_HPP

#include <iostream>
class Box
{
private:
	double length { 0 };
	double width { 0 };
	double heigth { 0 };
public:
	Box ( double lv, double wv, double hv );
	Box ( const Box &aBox );
	Box () = default;
	explicit operator double () const
	{
		return volume();
	}
	double volume () const
	{
		return length * width * heigth;
	}
	double getLength () const
	{
		return length;
	}
	double getWidth () const
	{
		return width;
	}
	double getHeigth () const
	{
		return heigth;
	}
	bool operator < ( const Box& aBox ) const;
	bool operator < ( double value ) const;
	Box& operator += ( const Box& aBox );
	Box& operator += ( double value );
	Box operator + ( const Box& aBox ) const;
	Box& operator *= ( double value );
	Box operator ~() const;
	Box& operator ++ ();
	const Box operator ++ ( int );
	Box& operator = ( const Box& aBox );
};
class AnotherBox
{
private:
	double length { 0 };
	double width { 0 };
	double heigth { 0 };
public:
	AnotherBox ( double lv, double wv, double hv );
	AnotherBox ( const AnotherBox &TBox );
	AnotherBox () = default;
	double volume () const
	{
		return length * width * heigth;
	}
	double getLength () const
	{
		return length;
	}
	double getWidth () const
	{
		return width;
	}
	double getHeigth () const
	{
		return heigth;
	}
	bool operator < ( const AnotherBox& aBox ) const;
	bool operator < ( double value ) const;
	AnotherBox& operator += ( const AnotherBox& aBox );
	AnotherBox& operator += ( double value );
	AnotherBox operator + ( const AnotherBox& aBox ) const;
	AnotherBox& operator *= ( double value );
	AnotherBox operator ~() const;
	AnotherBox& operator ++ ();
	const AnotherBox operator ++ ( int );
	AnotherBox& operator = ( const AnotherBox& aBox );
};
class Node
{
public:
	Node ();
	int nodeData { 0 };
	Node *pHead;
	Node *pNext;
	Node *pLast;
	Node* operator [] ( size_t index )
	{
		size_t count {};
		for ( Node* node { pHead }; node; node = node -> pLast )
		{
			if ( index == count ++ )
			{
				return node;
			}
		}
		return nullptr;
	}
};
std::ostream& operator << ( std::ostream& stream, const Box& aBox );
std::ostream& operator << ( std::ostream& stream, const AnotherBox& aBox );
void printList ( Node * n );
void insertAtStart ( Node** node, int data );
template <class T> inline bool operator < ( double value, const T& TBox )
{
	return value < TBox.volume ();
}
template <class T> inline bool operator == ( const T& TBox1, const T& TBox2 )
{
	return TBox1.volume () == TBox2.volume ();
}

#endif
