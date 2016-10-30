#include <iostream>

using namespace std;

void Swap( int &a , int &b )
{
	int temp = a;
	a = b;
	b = temp;
}

void InsertionSort( int a[], int n )
{
	for(int i = 1; i < n; ++i)
	{
		int pivot = i;
		for(int j = i - 1; j >= 0; --j)
		{
			if(a[ pivot ] < a[ j ])
			{
				Swap( a[ pivot ] , a[ j ] );
				pivot = j;
			}
			else
			{
				break;
			}
		}
	}
}

int main( void )
{
	int a[ ] = { 3,1,2,7,9,5,4 ,1000,200,300,243,1,2,4,1,52,5,6236};
	int n = sizeof( a ) / sizeof( int );
	InsertionSort( a , n);

	for(int i = 0; i < n; ++i)
	{
		cout << a[ i ] << " ";
	}
	getchar( );

	return 0;
}