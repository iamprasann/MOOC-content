#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  long long start, last;
};

bool compareInterval(Segment i1, Segment i2)
{
    return (i1.last < i2.last);
}

vector<long long> optimal_points(vector<Segment> &segments, int n) {

    vector<long long> points;
    points.clear();

    sort(segments.begin(), segments.end(), compareInterval);

    int i=0;

    while(true){
        int j=i;
        points.push_back(segments[j].last);
        while((segments[j].last)>=(segments[i+1].start))
            i++;

        if(i<n-1)
            i++;
        else
            break;
    }
    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].last;
    }
    vector<long long> points = optimal_points(segments, n);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
    return 0;
}