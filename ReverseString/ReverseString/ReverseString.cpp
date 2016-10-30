#include <iostream>

class Stack
{
public:
	Stack( int n) : Size(n)  
	{
		CharArr = new char[ n ];
		memset( CharArr , '\0' , sizeof( char ) * ( Size) );
	}
	~Stack( ) {}

	void Push( char character )
	{
		CharArr[ Top ] = character;

		++Top;
	}

	char Pop( )
	{
		--Top;
		return CharArr[ Top ];
	}

private:
	int Size = 0;
	int Top = 0;
	char* CharArr = nullptr;;
};

void ReverseString( char* TargetString )
{
	int StringLength = strlen( TargetString );
	Stack* ReverseStack = new Stack( StringLength );

	for(int i = 0; i < StringLength; ++i)
	{
		ReverseStack->Push( TargetString[ i ] );
	}

	for(int i = 0; i < StringLength; ++i)
	{
		char Character = ReverseStack->Pop( );
		TargetString[ i ] = Character;
	}
}

int main( void )
{
	char String[ ] = "hi, My name is Lee In Jae";
	ReverseString( String );
	getchar( );

	return 0;
}