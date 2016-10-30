#include <iostream>

using namespace std;

class Node
{
public:
	Node( )
	{

	}

	Node( int InNewNode )
	{
		NodeData = InNewNode;
	}

	~Node( )
	{

	}

public:
	Node* LeftChild;
	Node* RightChilde;

	int NodeData;
};

int CheckTree( Node* Root )
{
	if(Root == nullptr)
	{
		return 1;
	}

	int leftSubTreeCheck = CheckTree( Root->LeftChild );
	int RightSubTreeCheck = CheckTree( Root->RightChilde );
	if(leftSubTreeCheck != 1 || RightSubTreeCheck != 1)
	{
		return 0;
	}

	if(Root->LeftChild != nullptr && Root->NodeData <= Root->LeftChild->NodeData)
	{
		return 0;
	}

	if(Root->RightChilde != nullptr && Root->NodeData <= Root->RightChilde->NodeData)
	{
		return 0;
	}

	return 1;
}

int main( void )
{
	Node* Root = new Node( 10 );
	Node* B = new Node( 9 );
	Node* C = new Node( 15 );
	Node* D = new Node( 7 );
	Node* E = new Node( 8 );

	Root->LeftChild = B;
	Root->RightChilde = C;
	B->LeftChild = D;
	B->RightChilde = E;

	cout << CheckTree( Root ) << endl;
	getchar( );
	return 0;
}