#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int Explore(vector<vector<int>> &adj, vector<int> &visited, int x)
{
    visited[x]=1;
    bool IsCycle=false;
    size_t i = 0;
    while ((i<adj[x].size()) && (IsCycle == false)){
        if (visited[adj[x][i]] == 0)
        IsCycle = Explore(adj, visited, adj[x][i]);
        else if (visited[adj[x][i]] == 1)
        IsCycle = true;

        i++;
    }
    visited[x]=2;
    return IsCycle;
}


int acyclic(vector<vector<int> > &adj, int vertices, int edges) {
    if (vertices == 0 || edges == 0)
    return 0;

    bool IsCycle = false;
    size_t i = 0;
    vector<int> visited(vertices, 0);

    while ((i < vertices) && (IsCycle == false)){
        IsCycle = Explore(adj, visited, i);
        i++;
    }
    return IsCycle;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    std::cout << acyclic(adj, n, m);
}
