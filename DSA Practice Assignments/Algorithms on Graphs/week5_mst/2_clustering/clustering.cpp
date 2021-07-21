#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using std::vector;
using std::pair;

using namespace std;

using namespace std;
class DisjSet {
    int *rank, *parent, n;

public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet() {
        for (int i = 0; i < n; i++){
            parent[i] = i;
            rank[i]=0;
         }
    }

    int Find(int x) {
        if (parent[x] != x){
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int xset = Find(x);
        int yset = Find(y);

        if (xset == yset)
            return;

        if (rank[xset] < rank[yset])
            parent[xset] = yset;
        else if (rank[xset] > rank[yset])
            parent[yset] = xset;
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

double clustering(vector<int> x, vector<int> y, int k) {
    int num_sets=x.size();
    DisjSet clusters(x.size());

    vector<pair<double, pair<int, int>>> edge_lengths;

    for(int i=0; i<x.size()-1; i++){
        for(int j=i+1; j<x.size(); j++){
            double x_d=x[j]-x[i];
            double y_d=y[j]-y[i];
            double dist=sqrt((x_d*x_d)+(y_d*y_d));
            edge_lengths.push_back(make_pair(dist, make_pair(i, j)));
        }
    }

    sort(edge_lengths.begin(), edge_lengths.end());

    for(size_t i=0; i<edge_lengths.size(); i++){
        if(clusters.Find(edge_lengths[i].second.first)!=clusters.Find(edge_lengths[i].second.second)){
            if(num_sets>k){
                clusters.Union(edge_lengths[i].second.first, edge_lengths[i].second.second);
                num_sets--;
            }
            else
                return edge_lengths[i].first;
        }
    }
}

int main() {
    size_t n;
    int k;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (size_t i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    std::cin >> k;
    std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
    return 0;
}
