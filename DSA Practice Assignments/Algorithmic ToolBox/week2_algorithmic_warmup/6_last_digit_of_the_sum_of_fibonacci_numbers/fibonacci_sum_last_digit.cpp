#include <iostream>

int fibonacci_sum(long long n1, long long n2){

        int remainders[]={0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1};

        int c1=n1%60, c2=n2%60;

        int sum=0;

        if(c2>=c1)
        {
            for(int i=c1; i<=c2; i++)
                sum+=remainders[i];
        }
        else
        {
            for(int i=c1; i<=59; i++)
                sum+=remainders[i];

            for(int i=0; i<=c2; i++)
                sum+=remainders[i];
        }

        return sum%10;
    }

int main() {
    long long from=0, to=0;
    std::cin >> from >> to;
    int result=fibonacci_sum(from, to);
    std::cout << result;
}


