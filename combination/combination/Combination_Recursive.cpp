#include <iostream>

using namespace std;

void Combination( int n , int r , char* Result, char* a )
{
	if(n < r)
	{
		return;
	}

	if(r == 0)
	{
		cout << Result << endl;

		return;
	}

	Result[ r - 1 ] = a[ n - 1 ];
	Combination( n - 1 , r - 1 , Result, a );
	Result[ r - 1] = '\0';

	Combination( n - 1 , r , Result , a );
}

int main( void )
{
	char a[ ] = "abcd";
	int n = strlen( a );
	char* Result = new char[ n + 1 ];
	memset( Result , '\0' , sizeof(char) * (n + 1) );
	
	for(int i = 0; i < n; ++i)
	{
		Combination( n , i + 1 , Result , a );
	}
	
	getchar();
	delete[ ] Result;
	return 0;
}