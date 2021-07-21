#include <iostream>
#include <vector>

using std::vector;
using std::pair;

using namespace std;

void Explore(vector<int> &visited, vector<vector<int>> &adj, int x){
    visited[x]=1;
    for(size_t i=0; i<adj[x].size(); i++){
        if(visited[adj[x][i]]==0)
            Explore(visited, adj, adj[x][i]);
    }
}

int IsVisited(vector<vector<int>> &adj, int x, int y){
    int m=adj.size();
    vector<int> visited(m, 0);

    Explore(visited, adj, x);

    return visited[y];
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
  int x, y;
  std::cin >> x >> y;
  std::cout << IsVisited(adj, x - 1, y - 1);
}
