//class.hpp
#ifndef CLASS_HPP
#define CLASS_HPP

class Box
{
	private:
		double length { 1.0 };
		double width { 1.0 };
		double heigth { 1.0 };
	public:
		Box ( double lV, double wV, double hV );
		Box ( const Box &object );
		Box ( double side );
		Box ();
		~Box ();
		double volume () const;
		double getLength () const;
		double getWidth () const;
		double getHeigth () const;
		void setLength ( double lV );
		void setWidth ( double wV );
		void setHeigth ( double hV );
		Box &setLengthR ( double lV );
		Box &setWidthR ( double wV );
		Box &setHeigthR ( double hV );
		friend double surfaceArea ( const Box& aBox );
		//friend void printValues ( const Box& aBox );
		static inline size_t objectCount {};
		static inline const float constant { 2.71828f };
};
class Node
{
	public:
		Node ();
		Node ( double value2 );
		int nodeData;
		Node *pNext;
		Node *pLast;
};
void insertList ( Node **node, int obj );
void appendList ( Node ** headRef, int obj );
void printList ( Node * n );
void printReversed ( Node * n );
int countNodes ( Node * n );
void printArray ( int arr [], int n );
template <class T> void printValues ( const T& aBox )
{
	std::cout << "Length is " << aBox.getLength() << std::endl;
	std::cout << "Width is  " << aBox.getWidth() << std::endl;
	std::cout << "Heigth is " << aBox.getHeigth() << std::endl;
	std::cout << "Volume is " << aBox.volume() << std::endl;
}

#endif