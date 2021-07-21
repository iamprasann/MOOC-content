#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>
#include <sstream>
using std::vector;
using std::string;
using std::max;
using std::min;

using namespace std;

#define MAX_INT 2147483647
#define MIN_INT -2147483647



long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {

    int length = exp.size();
    int n = (length + 1) / 2;
    long long m[n][n];
    long long M[n][n];


    for (int i = 0; i < n; i++)
    {
        stringstream read(exp.substr(2*i,1));
	    read>>m[i][i];
	    read<<exp.substr(2*i,1);
	    read>>M[i][i];
    }

    for(int s=0; s<n-1; s++){
        for(int i=0; i<n-s-1; i++){

            int j=i+s+1;

            long long minVal=MAX_INT;
            long long maxVal=MIN_INT;

            for (int k = i; k < j; k++ )
	        {
                long long a = eval(m[i][k],m[k + 1][j],exp[2 * k + 1]);
                long long b = eval(m[i][k],M[k + 1][j],exp[2 * k + 1]);
                long long c = eval(M[i][k],m[k + 1][j],exp[2 * k + 1]);
                long long d = eval(M[i][k],M[k + 1][j],exp[2 * k + 1]);
                minVal = min(minVal,min(a,min(b,min(c,d))));
                maxVal = max(maxVal,max(a,max(b,max(c,d))));
	        }
            m[i][j] = minVal;
            M[i][j] = maxVal;
        }
    }

    return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
