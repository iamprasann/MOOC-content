#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

/*int find_candidate(vector<int> &a){
    int count=0, candidate=a[0];

    for(size_t i=1; i<a.size(); i++){
        if(candidate==a[i]){
            count++;
        }
        else{
            count--;
            if(count==0)
                candidate=a[i];
        }
    }
    return candidate;
}

int check_candidate(vector<int> &a){

    int candidate=find_candidate(a);
    int check=0;
    for(size_t i=0; i<a.size(); ++i){
        if(a[i]==candidate)
            check++;
    }
    if(check>=((a.size()/2)+1))
        return 1;
    else
        return 0;
}*/

int findCandidate(vector<int> &a, int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

bool isMajority(vector<int> &a, int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)

    if (a[i] == cand)
    count++;

    if (count > size/2)
    return 1;

    else
    return 0;
}

void printMajority(vector<int> &a, int size)
{
   int cand = findCandidate(a, size);

   if (isMajority(a, size, cand))
   std::cout <<"1"<<'\n';

   else
   std::cout <<"0"<<'\n';
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  int size = a.size();
  printMajority(a, size);
  return 0;
}
