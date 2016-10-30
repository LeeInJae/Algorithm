#include <iostream>

using namespace std;

void Merge( int a[ ] , int buff[ ] , int n , int left , int right )
{
	int mid = left + ( right - left ) / 2;
	for(int i = left; i <= right; ++i)
	{
		buff[ i ] = a[ i ];
	}

	int leftIndex = left;
	int RightIndex = mid + 1;

	for(int i = left; i <= right; ++i)
	{
		if(leftIndex > mid)
		{
			a[ i ] = buff[ RightIndex ];
			++RightIndex;
		}
		else if(RightIndex > right)
		{
			a[ i ] = buff[ leftIndex ];
			++leftIndex;
		}
		else if(buff[ leftIndex ] < buff[ RightIndex ])
		{
			a[ i ] = buff[ leftIndex ];
			++leftIndex;
		}
		else
		{
			a[ i ] = buff[ RightIndex ];
			++RightIndex;
		}
	}
}

void MergeSort( int a[ ] , int buff[ ] , int n , int left , int right )
{
	if(left >= right)
	{
		return;
	}

	int mid = left + ( right - left ) / 2;
	MergeSort( a , buff , n , left , mid );
	MergeSort( a , buff , n , mid + 1 , right );
	Merge( a , buff , n , left , right );
}

int main( void )
{
	int a[ ] = { 4,1,3,2,7,5 };
	const int n = sizeof( a ) / sizeof( int );
	int b[ n  ] = { 0, };

	MergeSort( a , b , n , 0 , n - 1 );

	for(int i = 0; i < n; ++i)
	{
		cout << a[ i ] << " ";
	}
	getchar( );
	return 0;
}