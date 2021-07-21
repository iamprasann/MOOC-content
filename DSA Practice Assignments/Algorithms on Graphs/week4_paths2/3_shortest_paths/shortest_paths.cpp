#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

using namespace std;

bool found(vector<int> &loop_elements, int key){
    for(size_t i=0; i<loop_elements.size(); i++){
        if(loop_elements[i]==key){
            return true;
        }
    }
    return false;
}

void shortest_paths(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {

    int no_v=adj.size();
    distance[s]=0;
    reachable[s]=1;
    vector<int> loop_elements;
    vector<int> visited(no_v, 0);

    for(int k=0; k<adj.size()-1; k++){
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                long long dist=distance[i]+cost[i][j];
                if(dist<distance[adj[i][j]]){
                    distance[adj[i][j]]=dist;
                    reachable[adj[i][j]]=1;
                }
            }
        }
    }

    for(int i=0; i<adj.size(); i++){
        for(int j=0; j<adj[i].size(); j++){
            long long dist=distance[i]+cost[i][j];
            if(dist<distance[adj[i][j]]){
                if(!found(loop_elements, adj[i][j]))
                    loop_elements.push_back(adj[i][j]);
            }
        }
    }

    while(!loop_elements.empty()){
        int u=loop_elements[0];
        loop_elements.erase(loop_elements.begin());
        visited[u]=1;
        shortest[u]=0;
        for(int j=0; j<adj[u].size(); j++){
            if(visited[adj[u][j]]==0 && !found(loop_elements, adj[u][j]))
                loop_elements.push_back(adj[u][j]);
        }
    }
    return;
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<long long>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if(!reachable[i])
      std::cout << "*\n";
    else if(!shortest[i])
      std::cout << "-\n";
    else
      std::cout << distance[i] << "\n";

  }
}
