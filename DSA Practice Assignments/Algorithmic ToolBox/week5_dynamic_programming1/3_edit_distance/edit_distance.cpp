#include <iostream>
#include <string>
#include <algorithm>

using std::string;

#define MAX_INT 2147483647;

int minimum(int a, int b, int c){

    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}

int edit_distance(const string &str1, const string &str2) {

    int m=str1.length()+1, n=str2.length()+1;
    int D[m][n];
    D[0][0]=0;

    for(int i=1; i<m; i++)
        D[i][0]=i;
    for(int j=1; j<n; j++)
        D[0][j]=j;

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){

            D[i][j]=MAX_INT;

            int min_val=0;

            int insertion=D[i][j-1]+1;
            int deletion=D[i-1][j]+1;
            int mismatch=D[i-1][j-1]+1;
            int match=D[i-1][j-1];

            if(str1[i-1]==str2[j-1])
                D[i][j]=minimum(insertion, deletion, match);
            else
                D[i][j]=minimum(insertion, deletion, mismatch);

        }
    }

    return D[m-1][n-1];
}

int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
