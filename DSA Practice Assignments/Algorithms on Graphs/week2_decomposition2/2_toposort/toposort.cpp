#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void Explore(vector<vector<int>> &adj, vector<int> &used, vector<int> &order, int x){
    if(used[x]==2)
        return;

    used[x]=1;
    for(size_t i=0; i<adj[x].size(); i++){
        if(used[adj[x][i]]==0)
            Explore(adj, used, order, adj[x][i]);
    }
    order.push_back(x);
    used[x]=2;
    return;
}

void DFS(vector<vector<int>> &adj, vector<int> &used, vector<int> &order) {
    for(size_t i=0; i<adj.size(); i++){
            Explore(adj, used, order, i);
    }
}

vector<int> toposort(vector<vector<int>> adj) {
    vector<int> used(adj.size(), 0);
    vector<int> order;
    DFS(adj, used, order);
    reverse(order.begin(), order.end());
    return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
