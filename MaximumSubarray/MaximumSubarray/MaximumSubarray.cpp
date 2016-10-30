#include <iostream>
using namespace std;

int GetCrossMaxSum( int n , int a[ ] , int left , int right )
{
	int mid = left + ( right - left ) / 2;

	int leftMaxSum = -100000000;
	int leftSideSum = 0;
	for(int i = mid; i >= left; --i)
	{
		leftSideSum += a[ i ];
		if(leftMaxSum < leftSideSum)
		{
			leftMaxSum = leftSideSum;
		}
	}

	int rightMaxSum = -100000000;
	int rightSideSum = 0;
	for(int i = mid + 1; i <= right; ++i)
	{
		rightSideSum += a[ i ];
		if(rightMaxSum < rightSideSum)
		{
			rightMaxSum = rightSideSum;
		}
	}

	return ( leftMaxSum + rightMaxSum );
}
int MaximumSubarray(int n ,int a[] , int left , int right )
{
	if(left == right)
	{
		return a[ left ];
	}

	int mid = left + ( right - left ) / 2;

	int leftMaxSum = MaximumSubarray( n , a , left , mid );
	int rightMaxSum = MaximumSubarray( n , a , mid + 1 , right );
	int CrossMaxSum = GetCrossMaxSum( n , a , left , right );

	if(leftMaxSum >= rightMaxSum && leftMaxSum >= CrossMaxSum)
		return leftMaxSum;

	if(rightMaxSum >= leftMaxSum  && rightMaxSum >= CrossMaxSum)
		return rightMaxSum;

	return CrossMaxSum;
}

int main( void )
{
	//int a[ ] = { 1,2,3};
	int a[ ] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int n = sizeof( a ) / sizeof( int );

	cout << MaximumSubarray( n , a , 0 , n - 1 ) << endl;
	getchar( );
	return 0;
}