#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops, int n) {

    int currentstop=0, stopindex=-1, counter=0;
    stops.push_back(dist);

    while(currentstop!=dist)
    {
        if(stops[stopindex+1]-currentstop>tank)
            return -1;
        else
        {
            while(stops[stopindex+1]-currentstop<=tank)
            {
                stopindex++;
                if(stopindex==n)
                {
                    currentstop=dist;
                    break;
                }
            }
            currentstop=stops[stopindex];
            counter++;
        }
    }
    return counter-1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops, n) << "\n";

    return 0;
}
