#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

using namespace std;

struct DisjointSetsElement {
	int size, parent, rank;

	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

struct DisjointSets {
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int size): size(size), max_table_size(0), sets(size) {
		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int table) {
		if(table!=sets[table].parent)
            sets[table].parent=getParent(sets[table].parent);
        return sets[table].parent;
	}

	void update_tables(int realDestination, int realSource) {
		sets[realDestination].size += sets[realSource].size;
		sets[realSource].size = 0;
		if (this->max_table_size < sets[realDestination].size)
			this->max_table_size = sets[realDestination].size;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
			if(sets[realSource].rank>sets[realDestination].rank){
                sets[realDestination].parent = sets[realSource].parent;
                swap(realSource, realDestination);
            }
            else{
                sets[realSource].parent = sets[realDestination].parent;
                if(sets[realSource].rank==sets[realDestination].rank)
                    sets[sets[realDestination].parent].rank++;
            }
            update_tables(realDestination, realSource);
        }
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	DisjointSets tables(n);
	for (auto &table : tables.sets) {
		cin >> table.size;
		tables.max_table_size = max(tables.max_table_size, table.size);
	}

	for (int i = 0; i < m; i++) {
		int destination, source;
		cin >> destination >> source;
                --destination;
                --source;

		tables.merge(destination, source);
	        cout << tables.max_table_size << endl;
	}

	return 0;
}
