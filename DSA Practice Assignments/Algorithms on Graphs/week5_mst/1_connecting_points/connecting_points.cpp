#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>

using std::vector;
using namespace std;

#define MAX_DOUBLE 999999999

double minimum_distance(vector<int> x, vector<int> y) {
    double result = 0.0;
    vector<long double> costs(x.size(), MAX_DOUBLE);
    costs[0]=0.0;
    vector<bool> visited(x.size(), false);

    auto cmp = [](pair<int, double> left, pair<int, double> right){
    return (((left.second)>(right.second)) || (((left.second)==(right.second)) && ((left.first)>(right.first))));
    };
    priority_queue<pair<int, double>, std::vector<pair<int, double>>, decltype(cmp)> PrioQ(cmp);
    PrioQ.push(make_pair(0, costs[0]));

    while(!PrioQ.empty()){
        int v=PrioQ.top().first;
        PrioQ.pop();

        if(!visited[v]){
            for(size_t i=0; i<x.size(); i++){
                if(i!=v && !visited[i]){
                    double x_d=x[i]-x[v];
                    double y_d=y[i]-y[v];
                    long double dist=sqrt((x_d*x_d)+(y_d*y_d));

                    if(costs[i]>dist){
                        costs[i]=dist;
                        PrioQ.push(make_pair(i, costs[i]));
                    }
                }
            }
            visited[v]=true;
        }

    }

    for(size_t t=0; t<x.size(); t++)
        result+=costs[t];

    return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
