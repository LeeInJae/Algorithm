#include <iostream>
#include <string>

using namespace std;

void Swap( char& a , char& b )
{
	char c = a;
	a = b;
	b = c;
}
	
void Permutation(int startIndex, int n , char* a )
{
	if(startIndex >= n)
	{
		cout << a << endl;

		return;
	}

	for(int pivotIndex = startIndex; pivotIndex < n; ++pivotIndex)
	{
		Swap( a[ startIndex ], a[ pivotIndex ]);
		Permutation( startIndex + 1 , n , a );
		Swap( a[ startIndex ] , a[ pivotIndex ] );
	}
}

int main( void )
{
	char a[] = "abcd";
	int n = strlen( a );

	Permutation( 0, n, a );

	getchar( );
	return 0;
}