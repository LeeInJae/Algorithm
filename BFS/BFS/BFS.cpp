#include <iostream>
#include <queue>

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

void BFS( Node* Root )
{
	if(Root == nullptr)
	{
		return;
	}

	queue<Node*> Bfs;
	Bfs.emplace( Root );
	while(Bfs.empty( ) == false)
	{
		Node* node = Bfs.front();
		Bfs.pop( );

		cout << node->NodeData << " ";
	
		if(node->LeftChild != nullptr)
			Bfs.emplace( node->LeftChild );

		if(node->RightChilde != nullptr)
			Bfs.emplace( node->RightChilde );
	}
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

	BFS( Root );
	getchar( );
	return 0;
}