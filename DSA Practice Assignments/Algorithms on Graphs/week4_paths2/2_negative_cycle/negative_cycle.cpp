#include <iostream>
#include <vector>

using std::vector;
using namespace std;

#define MAX_INT 2147483647

int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost) {
    vector<long long> dist(adj.size(), MAX_INT);
    dist[0]=0;
    bool relaxed;

    for(int k=0; k<adj.size(); k++){
        relaxed=false;
        for(int i=0; i<adj.size(); i++){
            for(int t=0; t<adj[i].size(); t++){
                long long distance=dist[i]+cost[i][t];
                if(distance<dist[adj[i][t]]){
                    dist[adj[i][t]]=distance;
                    relaxed=true;
                }
            }
        }
    }
    return relaxed;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
