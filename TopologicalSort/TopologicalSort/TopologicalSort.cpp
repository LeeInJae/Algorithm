#include <iostream>
#include <queue>
#include <map>
#include <list>

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
	list<Node*> DirectConnectedNodeList;
	char NodeData;
};


class Graph
{
public:
	Graph( ) {}
	~Graph( ) {}

	vector<Node*> Vertex;
};

void DFS( Node* Root, map<Node* , bool>& VisitNode, list<Node*>& TopologicalVertex )
{
	if(Root == nullptr)
	{
		return;
	}

	VisitNode[ Root ] = true;

	for(auto AdjacentNode : Root->DirectConnectedNodeList)
	{
		if(VisitNode[ AdjacentNode ] == false)
		{
			DFS( AdjacentNode , VisitNode, TopologicalVertex );
		}
	}

	TopologicalVertex.emplace_front( Root );
}

void TopologicalSort( Graph* DirectedGraph, list<Node*>& TopologicalVertex)
{
	map<Node* , bool> VisitVertex;
	for(auto NodeElem : DirectedGraph->Vertex)
	{
		VisitVertex.emplace( NodeElem , false );
	}

	for(auto NodeElem : DirectedGraph->Vertex)
	{
		if(VisitVertex[ NodeElem ] == false)
		{
			DFS( NodeElem , VisitVertex, TopologicalVertex );
		}
	}


	
}

int main( void )
{
	Node* A = new Node( 'A' );
	Node* B = new Node( 'B' );
	Node* C = new Node( 'C' );
	Node* D = new Node( 'D' );
	Node* E = new Node( 'E' );
	Node* F = new Node( 'F' );


	Graph* DirectedGraph = new Graph;
	DirectedGraph->Vertex.emplace_back( A );
	DirectedGraph->Vertex.emplace_back( B );
	DirectedGraph->Vertex.emplace_back( C );
	DirectedGraph->Vertex.emplace_back( D );
	DirectedGraph->Vertex.emplace_back( E );
	DirectedGraph->Vertex.emplace_back( F );

	A->DirectConnectedNodeList.emplace_back( B );
	B->DirectConnectedNodeList.emplace_back( C );
	B->DirectConnectedNodeList.emplace_back( F );
	D->DirectConnectedNodeList.emplace_back( B );
	D->DirectConnectedNodeList.emplace_back( E );
	E->DirectConnectedNodeList.emplace_back( C );

	list<Node*> TopologicalSortVertex;
	TopologicalSort( DirectedGraph,TopologicalSortVertex);

	for(auto TopologicalVertex : TopologicalSortVertex)
	{
		cout << TopologicalVertex->NodeData << " ";
	}
	getchar( );
	return 0;
}