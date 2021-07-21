#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

using namespace std;

#define MAX_INT 9999999999

int distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t) {
    vector<long long> dist(adj.size(), MAX_INT);
    vector<int> prev(adj.size(), -1);

    dist[s]=0;

    auto cmp = [](pair<int, long long int> left, pair<int, long long int> right){
        return (((left.second) > (right.second)) || (((left.second) == (right.second)) && ((left.first) > (right.first))));
    };

    priority_queue <pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> H(cmp);
    H.push(make_pair(s, dist[s]));

    while(!H.empty()){
        int vertex=H.top().first;
        int vertex_cost=H.top().second;
        H.pop();

        for(size_t i=0; i<adj[vertex].size(); i++){
            long long distance = dist[vertex] + cost[vertex][i];
            if(dist[adj[vertex][i]]>distance){
                dist[adj[vertex][i]] = distance;
				H.push(make_pair(adj[vertex][i], distance));
            }
        }
    }
    return((dist[t]<MAX_INT)? dist[t]: -1);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
