#include <iostream> 
#include <vector> // Vectors are same as dynamic arrays with the ability to resize itself automatically.
using namespace std;

// data structure to store graph edges
struct Edge {
	int src, dest;
}

// class to represnet a graph object
class Graph {
public:
	// construct a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// 'const' keyword specifices that a variable's value in constant and tells the compiler to 
	// prevent the programmer from modifying it.
	Graph(vector<Edge> const &edges, int N) {

		// resize the vector to N elements of type vector<int>
		adjList.resize(N + 1);

		for (auto &edge: edges) {
			adjList[edge.src].push_back(edge.dest);
		}
	}
}

int main(void) {

}