#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Edge {
	int src, dest;
};

class Graph {
public:
	int *parent;
	vector<Edge> *edges;
	Graph(vector<Edge> *edges, int N);
	int Find(int item);
	void Union(int a, int b);
};

bool findCycle(Graph *graph, int N);

int main(void) {
	// vector of graph edges as per above diagram
	vector<Edge> edges = {
		{1, 2}, {3, 4}, {2, 4},

		// edge (11, 12) introduces a cycle in the graph
	};

	// Number of nodes in the graph
	int N = 12;

	// create a graph from edges
	Graph graph(&edges, N);

	if (findCycle(&graph, N)) cout << "Cycle Found" << endl;
	else cout << "No Cycle Found" << endl;
}

Graph::Graph(vector<Edge> *edges, int N) {
	this->edges = edges;
	parent = new int[N];
	for (int i = 0; i < N; i++) {
		*(parent + i) = -1;
	}
}

int Graph::Find(int item) {
	if (parent[item] < 0) return item;
	return Find(parent[item]);
}

void Graph::Union(int a, int b) {
	int parent_a = Find(a);
	int parent_b = Find(b);

	if (parent[parent_a] * -1 > parent[parent_b]) {
		parent[parent_b] += parent[parent_a];
		parent[parent_a] = parent_b;
	} else {
		parent[parent_a] += parent[parent_b];
		parent[parent_b] = parent_a;
	}
}

bool findCycle(Graph *graph, int N) {
	vector<Edge> *edges = graph->edges;
	int *parent = graph->parent;

	for (Edge &edge : *edges) {		
		int u = edge.src;
		int v = edge.dest;

		int parent_u = graph->Find(u - 1);
		int parent_v = graph->Find(v - 1);

		if (parent_u == parent_v) return true;
		else graph->Union(u - 1, v - 1);
	}

	return false;
}