#include <iostream>

using namespace std;

class Node
{
public:
	Node( )
	{

	}

	Node( char InNewNode )
	{
		NodeData = InNewNode;
	}

	~Node( )
	{

	}

public:
	Node* LeftChild;
	Node* RightChilde;

	char NodeData;
};

void PreOrder( Node* Root )
{
	if(Root == nullptr)
	{
		return;
	}

	cout << Root->NodeData << " ";
	PreOrder( Root->LeftChild );
	PreOrder( Root->RightChilde );
}

void InOrder( Node* Root )
{
	if(Root == nullptr)
	{
		return;
	}

	InOrder( Root->LeftChild );
	cout << Root->NodeData << " ";
	InOrder( Root->RightChilde );
}

void PostOrder( Node* Root )
{
	if(Root == nullptr)
	{
		return;
	}

	PostOrder( Root->LeftChild );
	PostOrder( Root->RightChilde );
	cout << Root->NodeData << " ";
}

Node* CopyTree( Node* Root )
{
	if(Root == nullptr)
	{
		return nullptr;
	}

	Node* NewNode = new Node;
	NewNode->NodeData = Root->NodeData;
	NewNode->LeftChild = CopyTree( Root->LeftChild );
	NewNode->RightChilde = CopyTree( Root->RightChilde );


	return NewNode;
}

bool EqualTree( Node* Root1 , Node* Root2 )
{
	if(Root1 == nullptr && Root2 == nullptr)
	{
		return true;
	}
	else if(Root1 == nullptr || Root2 == nullptr)
	{
		return false;
	}



	if(Root1->NodeData != Root2->NodeData)
	{
		return false;
	}

	if(EqualTree( Root1->LeftChild , Root2->LeftChild ) == false)
	{
		return false;
	}

	if(EqualTree( Root1->RightChilde , Root2->RightChilde ) == false)
	{
		return false;
	}

	return true;
}

int InterNodecount( Node* Root )
{
	if(Root==nullptr)
	{
		return 0;
	}

	if(Root->LeftChild != nullptr || Root->RightChilde != nullptr)
	{
		return InterNodecount( Root->LeftChild ) + InterNodecount( Root->RightChilde ) + 1;
	}
	
	return 0;
}

int main( void )
{
	Node* Root = new Node( 'A' );
	Node* B = new Node( 'B' );
	Node* C = new Node( 'C' );
	Node* D = new Node( 'D' );
	Node* E = new Node( 'E' );
	Node* F = new Node( 'F' );
	Node* G = new Node( 'G' );
	Node* H = new Node( 'H' );
	Node* I = new Node( 'I' );
	Node* J = new Node( 'J' );

	Root->LeftChild = B;
	Root->RightChilde = C;
	B->LeftChild = D;
	B->RightChilde = E;
	C->LeftChild = F;
	C->RightChilde = G;
	G->LeftChild = H;
	G->RightChilde = I;

	Node* Root2 = CopyTree( Root );
	Root2->LeftChild->LeftChild = J;

	PreOrder( Root );
	cout << endl;
	InOrder( Root );
	cout << endl;
	PostOrder( Root );

	cout << endl;
	cout << endl;
	PreOrder( Root2 );
	cout << endl;
	InOrder( Root2 );
	cout << endl;
	PostOrder( Root2 );

	cout << endl;

	if(EqualTree( Root , Root2 ) == true)
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "Not Equal" << endl;
	}

	cout << endl << endl << endl;

	cout << "internal Node Coutn = " << InterNodecount( Root ) << endl;
	getchar( );
	return 0;
}