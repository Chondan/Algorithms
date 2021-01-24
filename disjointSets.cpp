#include <iostream>
#include <unordered_map>
using namespace std;

class DisjointSets {
	unordered_map<char, char> PARENT;
	unordered_map<char, int> RANK;
public:
	DisjointSets() {
		char universe[] = { 'a', 'b', 'c', 'd', 'e' };
		for (char x : universe) {
			PARENT[x] = x; // we have 5 disjoint sets, each set contain one item.
			RANK[x] = 0;
		}
		PARENT['d'] = 'b'; // 'b' and 'd' are in same set.
		RANK['b'] = 1;
	}

	char Find(char item) {
		if (PARENT[item] == item) return item;
		return Find(PARENT[item]);
	}

	void Union(char set_1, char set_2) {
		// optimize the depth of the tree by set the deeper tree as a new root
		if (RANK[set_1] > RANK[set_2]) {
			PARENT[set_2] = set_1;
		} else if (RANK[set_2] > RANK[set_1]) {
			PARENT[set_1] = set_2;
		} else {
			PARENT[set_1] = set_2;
			RANK[set_2]++;
		}
	}

	int getRank(char set) {
		return RANK[set];
	}
};

int main(void) {

	DisjointSets *dj = new DisjointSets();

	dj->Union('a', 'e');
	cout << dj->Find('a') << " " << dj->Find('e') << endl;
	cout << dj->getRank('e') << endl;

}