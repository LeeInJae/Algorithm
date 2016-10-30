#include <iostream>

using namespace std;

class Heap
{
public:
	Heap( ) {}
	~Heap( ) {}

	void BuildMaxHeap( );
	void Max_Heapify( int pos );
	void PrintHeap( );
	void Sort( );
public:
	int Size;
	int Capacity;
	int* element;
};

void Swap( int& a , int &b )
{
	int temp = a;
	a = b;
	b = temp;
}
void Heap::PrintHeap( )
{
	for(int i = 1; i <= Size; ++i)
	{
		cout << element[ i ] << " ";
	}
}

void Heap::Max_Heapify( int pos )
{
	if(pos > Size)
		return;

	int MaxNodeValue = element[ pos ];
	int SwapTargetPos = pos;

	int leftChildPos = pos * 2;
	if(leftChildPos <= Size)
	{
		if(element[ leftChildPos ] > MaxNodeValue)
		{
			SwapTargetPos = leftChildPos;
			MaxNodeValue = element[ leftChildPos ];
		}
	}

	int rightChildPos = pos * 2 + 1;
	if(rightChildPos <= Size)
	{
		if(element[ rightChildPos ] > MaxNodeValue)
		{
			SwapTargetPos = rightChildPos;
			MaxNodeValue = element[ rightChildPos ];
		}
	}
	 
	if(SwapTargetPos != pos)
	{
		Swap( element[ SwapTargetPos ] , element[ pos ] );
		Max_Heapify( SwapTargetPos );
	}
}

void Heap::BuildMaxHeap( )
{
	for(int i = Size / 2; i >= 1; --i)
	{
		Max_Heapify( i );
	}
}

void Heap::Sort( )
{
	int TempSize = Size;
	for(int i = TempSize; i >= 2; --i)
	{
		Swap( element[ 1 ] , element[ i ] );
		--Size;

		Max_Heapify( 1 );
	}

	Size = TempSize;
}

int main( void )
{
	int a[ ] = { 7,2,5,3,10,8,9 };
	const int n = sizeof( a ) / sizeof( int );
	Heap* pHeap = new Heap;
	pHeap->Capacity = n * n;
	pHeap->element = new int[ n + 1 ];
	for(int i = 0; i < n; ++i)
	{
		pHeap->element[ i + 1 ] = a[ i ];
	}
	pHeap->Size = n;

	pHeap->BuildMaxHeap( );
	pHeap->PrintHeap( );

	cout << endl;
	pHeap->Sort( );
	pHeap->PrintHeap( );
	getchar( );
	delete pHeap;

}