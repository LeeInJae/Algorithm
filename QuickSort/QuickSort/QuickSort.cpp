#include <iostream>

using namespace std;

void Swap( int& a , int & b )
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition( int a[ ] , int left, int right )
{
	int wall = left - 1;
	for(int i = left ; i <= right - 1; ++i)
	{
		if(a[ i ] < a[ right ])
		{
			Swap( a[ i ] , a[ wall + 1 ] );
			++wall;
		}
	}
	++wall;
	Swap( a[ wall ] , a[ right ] );

	return wall;
}

void QuickSort( int a[ ] , int n , int left , int right )
{
	if(left >= right)
	{
		return;
	}

	int Pivot = Partition( a , left , right );
	QuickSort( a , n , left , Pivot - 1 );
	QuickSort( a , n , Pivot + 1 , right );
}



int main( void )
{
	int a[ ] = { 2,8,7,1,3,5,6,4 };
	int n = sizeof( a ) / sizeof( n );
	
	//cout << Partition( a , n ) << endl;

	for(int i = 0; i < n; ++i)
	{
		cout << a[ i ] << " ";
	}

	cout << endl;

	QuickSort( a , n , 0 , n - 1 );

	for(int i = 0; i < n; ++i)
	{
		cout << a[ i ] << " ";
	}

	getchar( );
	return 0;
}