#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
    vector<int> dist(adj.size(), -1);
    dist[s]=0;
    queue<int> vertices;
    vertices.push(s);
    while(!vertices.empty()){
        int source=vertices.front();
        vertices.pop();
        for(size_t i=0; i<adj[source].size(); i++){
            if(dist[adj[source][i]]==-1){
                vertices.push(adj[source][i]);
                dist[adj[source][i]]=dist[source]+1;
            }
        }
    }
    return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
