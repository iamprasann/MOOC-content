#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::pair;

using namespace std;

void ExploreR(vector<vector<int>> &adjR, vector<int> &used1, vector<int> &order, int x){
    if(used1[x]==2)
        return;

    used1[x]=1;
    for(size_t i=0; i<adjR[x].size(); i++){
        if(used1[adjR[x][i]]==0)
            ExploreR(adjR, used1, order, adjR[x][i]);
    }
    order.push_back(x);
    used1[x]=2;
    return;
}

void Explore(vector<vector<int>> &adj, vector<int> &used2, int x){
    used2[x]=1;
    for(size_t i=0; i<adj[x].size(); i++){
        if(used2[adj[x][i]]==0)
            Explore(adj, used2, adj[x][i]);
    }
    return;
}

int number_of_strongly_connected_components(vector<vector<int>> &adj, vector<vector<int>> &adjR) {
    int result = 0;
    vector<int> used1(adj.size(), 0);
    vector<int> order;

    for(size_t i=0; i<adjR.size(); i++){
            ExploreR(adjR, used1, order, i);
    }

    vector<int> used2(adj.size(), 0);

    reverse(order.begin(), order.end());

    for(size_t i=0; i<order.size(); i++){
        if(used2[order[i]]==0){
            Explore(adj, used2, order[i]);
            result++;
        }
    }
    return result;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>()), adjR(n, vector<int>());
    for (size_t i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x-1].push_back(y-1);
        adjR[y-1].push_back(x-1);
    }
    std::cout << number_of_strongly_connected_components(adj, adjR);
    return 0;
}
