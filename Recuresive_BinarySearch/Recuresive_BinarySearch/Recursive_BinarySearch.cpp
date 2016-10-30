#include <iostream>

int BinarySearch( int left , int right , int* arr, int findNumber )
{
	int mid = left + ( right - left ) / 2;
	if(arr[ mid ] == findNumber)
	{
		return mid;
	}
	else if(arr[ mid ] < findNumber)
	{
		return BinarySearch( mid + 1 , right , arr , findNumber );
	}
	else
	{
		return BinarySearch( left , mid - 1 , arr , findNumber );
	}
}

int main( void )
{

	int a[ ] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof( a ) / sizeof( int );
	int findNumber = 2;

	int findNubmerIndex = BinarySearch( 0 , n - 1 , a, findNumber );
	getchar( );
	return 0;
}