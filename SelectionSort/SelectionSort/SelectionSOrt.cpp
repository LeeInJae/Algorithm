#include <iostream>
#include <vector>

#define INPUT_FILE_NAME		"Input.txt"
#define OUTPUT_FILE_NAME	"output.txt"

void Swap( int& a , int& b )
{
	int temp = a;
	a = b;
	b = temp;
}

void SelectionSort( std::vector<int>& InNumbers )
{
	int n = InNumbers.size( );
	for(int i = 0; i < n - 1; ++i)
	{
		int PivotIndexNumber = InNumbers[ i ];
		for(int j = i + 1; j < n; ++j)
		{
			if(PivotIndexNumber > InNumbers[ j ])
			{
				PivotIndexNumber = InNumbers[ j ];
				Swap( InNumbers[i] , InNumbers[ j ] );
			}
		}
	}
}

int main( void )
{
	FILE* fin;
	fopen_s( &fin , INPUT_FILE_NAME , "r" );

	int n;
	fscanf_s( fin , "%d" , &n );

	std::vector<int> Numbers;
	for(int i = 0; i < n; ++i)
	{
		int number;
		fscanf_s( fin , "%d" , &number );
		Numbers.emplace_back( number );
	}

	SelectionSort( Numbers );

	FILE* fout;
	fopen_s( &fout , OUTPUT_FILE_NAME , "w" );
	for(int i = 0; i < n; ++i)
	{
		fprintf_s( fout , "%d " , Numbers[ i ] );
	}
	fclose( fin );
	fclose( fout );
	
	return 0;
}