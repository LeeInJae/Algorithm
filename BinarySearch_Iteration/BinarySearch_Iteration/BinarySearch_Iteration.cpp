#include <iostream>
#include <vector>

int BinarySearch( std::vector<int>& InNumbers , const int InFindNumber )
{
	int left = 0;
	int right = InNumbers.size( ) - 1;
	int FindNumberIndex = -1;

	while(left <= right)
	{
		int mid = left + ( right - left ) / 2;

		int PivotNumber = InNumbers[ mid ];

		if(PivotNumber == InFindNumber)
		{
			FindNumberIndex = mid;

			break;
		}
		else if(PivotNumber < InFindNumber)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	return FindNumberIndex;
}
int main( void )
{
	FILE* fin;
	FILE* fout;

	fopen_s( &fin , "input.txt" , "r" );
	fopen_s( &fout , "output.txt" , "w" );

	int n, FindNumber;
	fscanf_s( fin , "%d %d" , &n, &FindNumber );

	std::vector<int> Numbers;
	for(int i = 0; i < n; ++i)
	{
		int number;
		fscanf_s( fin , "%d" , &number );
		Numbers.emplace_back( number );
	}

	fprintf_s(fout, "%d", BinarySearch( Numbers , FindNumber ));

	return 0;
}