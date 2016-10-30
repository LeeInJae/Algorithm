#include <iostream>
using namespace std;

void PrintString( char* Str )
{
	for(int i = 0; i < strlen( Str ); ++i)
	{
		cout << Str << endl;
		char temp = Str[ 0 ];
		for(int j = 1; j < strlen( Str ); ++j)
		{
			Str[ j - 1 ] = Str[ j ];
		}
		Str[ strlen( Str ) - 1 ] = temp;
	}
}

int main( void )
{
	char Str[] = "ABCDEF";
	PrintString( Str );

	getchar(  );
	return 0;
}