#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void Explore(vector<int> &visited, vector<vector<int>> &adj, int x, int grpno){
    visited[x]=grpno;
    for(size_t i=0; i<adj[x].size(); i++){
        if(visited[adj[x][i]]==0)
            Explore(visited, adj, adj[x][i], grpno);
    }
}

int number_of_components(vector<vector<int>> &adj){
    int m=adj.size();
    vector<int> visited(m, 0);
    int groups=1;
    for(size_t i=0; i<m; i++){
        if(visited[i]==0){
            Explore(visited, adj, i, groups);
            groups++;
        }
    }
    return groups-1;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
