#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using std::vector;

int binary_search(const vector<int> &points, int l, int r, int x) {

	while (l <= r) {
        int m = l + (r - l) / 2;

        if (points[m] == x)
            return m;

        else if (points[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }
    return -1;
}

vector<int> fast_count_segments(vector<pair<int,int>> &v, int m, const vector<int> &points) {

    vector<int> cnt(m);

    int total=v.size(), count_left=0, allpoints=0, index=-1;

    for(int i=0; i<total; i++){
        if(v[i].second!=0)
            count_left+=v[i].second;
        else{
            allpoints++;
            index=binary_search(points, 0, m-1, v[i].first);
            cnt[index]=count_left;

            if(allpoints==m)
                break;
        }
    }

    return cnt;
}

int main() {
  int n, m,a,b,p;

  std::cin >> n >> m;
  std::vector<pair<int,int>> v;

  for(auto i =0;i<n;i++)
  {
    cin>>a>>b;
    v.push_back(make_pair(a,1));
    v.push_back(make_pair(b,-1));
  }

  vector<int> points(m);

  for (auto i = 0; i < m; i++) {
    std::cin >> p;
    points[i]=p;
    v.push_back(make_pair(p,0));
  }

  sort(v.begin(),v.end());

  vector<int> cnt = fast_count_segments(v, m, points);

  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
