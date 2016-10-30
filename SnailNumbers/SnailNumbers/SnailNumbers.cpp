#include <iostream>
#include <vector>
using namespace std;


void Swap(int& a , int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

class BaseSnailNumbers
{
public:
	BaseSnailNumbers( ) {}
	BaseSnailNumbers( int InSize, int InRow, int InCol, int IndetaRowValue, int IndeltaColValue) : 
		Size(InSize), row(InRow), col(InCol), deltaRowValue(IndetaRowValue), deltaColValue(IndeltaColValue){}
	virtual ~BaseSnailNumbers( ) {}
	virtual void InsertSnailNumber( int& InPivotNumber, vector<vector<int>>& Numbers, bool bReverse ) = 0;


protected:
	int		Size, row , col, deltaRowValue, deltaColValue;
};

class CRightSnail : public BaseSnailNumbers
{
public:
	CRightSnail( ) {}
	CRightSnail(int InSize ) : BaseSnailNumbers(InSize, 0, 0, 0, 0){}
	~CRightSnail( ) {}

	void InsertSnailNumber( int& InPivotNumber, vector<vector<int>>& Numbers, bool bReverse ) override
	{
		for(int i = deltaColValue; i < Size - deltaColValue - 1; ++i)
		{
			if(bReverse)
				Numbers[ i ][ deltaRowValue ] = ++InPivotNumber;
			else
				Numbers[ deltaRowValue ][ i ] = ++InPivotNumber;
			
		}

		++deltaRowValue;
		++deltaColValue;
	}
};

class CDownSnail : public BaseSnailNumbers
{
public:
	CDownSnail( ) {}
	CDownSnail( int InSize ) : BaseSnailNumbers( InSize , 0 , 0 , 0 , 0 ) {}
	~CDownSnail( ) {}

	void InsertSnailNumber( int& InPivotNumber , vector<vector<int>>& Numbers, bool bReverse ) override
	{
		for(int i = deltaRowValue; i < Size - deltaRowValue - 1; ++i)
		{
			if(bReverse)
				Numbers[ Size - deltaColValue - 1][ i ] = ++InPivotNumber;
			else
				Numbers[ i ][ Size - deltaColValue - 1 ] = ++InPivotNumber;
				
		}

		++deltaRowValue;
		++deltaColValue;
	}
};

class CLeftSnail : public BaseSnailNumbers
{
public:
	CLeftSnail( ) {}
	CLeftSnail( int InSize ) : BaseSnailNumbers( InSize , 0 , 0 , 0 , 0 ) {}
	~CLeftSnail( ) {}

	void InsertSnailNumber( int& InPivotNumber , vector<vector<int>>& Numbers, bool bReverse ) override
	{
		for(int i = Size - 1 - deltaColValue; i > deltaColValue; --i)
		{
			if(bReverse)
				Numbers[ i ][ Size - 1 - deltaRowValue ] = ++InPivotNumber;
			else
				Numbers[ Size - 1 - deltaRowValue ][ i ] = ++InPivotNumber;
		}

		++deltaRowValue;
		++deltaColValue;
	}
};

class CUpSnail : public BaseSnailNumbers
{
public:
	CUpSnail( ) {}
	CUpSnail( int InSize ) : BaseSnailNumbers( InSize , 0 , 0 , 0 , 0 ) {}
	~CUpSnail( ) {}

	void InsertSnailNumber( int& InPivotNumber , vector<vector<int>>& Numbers, bool bReverse ) override
	{
		for(int i = Size - 1 - deltaRowValue; i > deltaRowValue; --i)
		{
			if(bReverse)
				Numbers[ deltaColValue ][ i ]= ++InPivotNumber;
			else
				Numbers[ i ][ deltaColValue ] = ++InPivotNumber;
		}

		++deltaRowValue;
		++deltaColValue;
	}
};

class CSnailNumbers
{
public:
	CSnailNumbers( int InSize, int bReverse) : Size(InSize) , Reverse(bReverse)
	{
		
		for(int i = 0; i < InSize;++i)
		{
			vector<int> InitVector( InSize , 0 );
			Numbers.emplace_back( InitVector );
		}

		if(Size == 1)
		{
			Numbers[ 0 ][ 0 ] = 1;
			PivotNumber = 1;
			return;
		}

		RightSnail	= new CRightSnail( Size );
		DownSnail	= new CDownSnail( Size );
		LeftSnail	= new CLeftSnail( Size );
		UpSnail		= new CUpSnail( Size );

	}
	
	~CSnailNumbers( ) 
	{
		delete RightSnail;
		delete DownSnail;
		delete LeftSnail;
		delete UpSnail;
	}

public:
	void InsertSnailNumber( )
	{
		int FinishNumber = 0;
		if(Size % 2 == 1)
		{
			FinishNumber = Size * Size - 1;
			Numbers[ Size / 2 ][ Size / 2 ] = Size*Size;
		}
		else
		{
			FinishNumber = Size * Size;
		}

		while(PivotNumber < FinishNumber)
		{
			RightSnail->InsertSnailNumber( PivotNumber , Numbers, Reverse );
			DownSnail->InsertSnailNumber( PivotNumber , Numbers, Reverse );
			LeftSnail->InsertSnailNumber( PivotNumber , Numbers, Reverse );
			UpSnail->InsertSnailNumber( PivotNumber , Numbers, Reverse );
		}
	}

	void PrintOut( )
	{
		for(auto& VectorElem : Numbers)
		{
			for(auto& VectorNumberElem : VectorElem)
			{
				cout << VectorNumberElem << " ";
			}
			cout << endl;
		}
	}
public:
	CRightSnail*	RightSnail;
	CDownSnail*		DownSnail;
	CLeftSnail*		LeftSnail;
	CUpSnail*		UpSnail;
	const int Size;
	int PivotNumber = 0;
	bool Reverse = false;
	vector<vector<int>> Numbers;
};

int main( void )
{
	vector<CSnailNumbers*> SnailNumberVector;
	for(int i = 1; i <= 9; ++i)
	{
		CSnailNumbers* SnailNumbers = new CSnailNumbers( i, true );
		SnailNumbers->InsertSnailNumber( );
		SnailNumbers->PrintOut( );
		SnailNumberVector.emplace_back( SnailNumbers );
		cout << endl << endl << endl;
	}

	for(auto SnailNumberElem : SnailNumberVector)
	{
		delete SnailNumberElem;
	}

	getchar( );

	return 0;
}