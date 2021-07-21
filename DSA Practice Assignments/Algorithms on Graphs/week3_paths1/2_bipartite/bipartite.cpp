#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int>> &adj) {
    vector<int> colour(adj.size(), -1);
    colour[0]=1;
    queue<int> vertices;
    vertices.push(0);
    while(!vertices.empty()){
        int source=vertices.front();
        vertices.pop();
        for(size_t i=0; i<adj[source].size(); i++){
            if(colour[adj[source][i]]==-1){
                vertices.push(adj[source][i]);
                colour[adj[source][i]]=1-colour[source];
            }
            else if(colour[adj[source][i]]==colour[source])
                return 0;
        }
    }
    return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
