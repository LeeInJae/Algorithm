#include <iostream>

using namespace std;

int Factorial( int n )
{
	if(n == 0 || n == 1)
	{
		return 1;
	}

	return n * Factorial( n - 1 );

}

int Fibonacci( int n )
{
	if(n <= 1)
	{
		return 1;
	}

	return Fibonacci( n - 1 ) + Fibonacci( n - 2 );
}

int main( void )
{
	int n = 5;

	cout << n << "ÀÇ Factorial = " << endl << Factorial( n ) << endl;

	cout << n << "ÀÇ Fibanicci = " << endl << Fibonacci( n );

	getchar( );

	return 0;
}