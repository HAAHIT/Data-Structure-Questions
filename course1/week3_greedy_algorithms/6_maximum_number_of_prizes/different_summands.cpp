
// Completed //

#include <iostream>
#include <vector>
#include<math.h>

using std::vector;

vector<int> optimal_summands(long long n) {
  vector<int> summands;
  //write your code here
  if (n==2)
  {
    summands.push_back(2);
    return summands;
  }
  
  long long np=0,sum=0;
  np = ((-1) + sqrt(1+8*n))/2;
  for (int i = 1; i <= np; i++)
  {
    summands.push_back(i);
    sum = sum +i;
  }
  if (n>sum)
  {
    summands.push_back(n-sum);
  }
  int sz=0;
  sz= summands.size();
  if (summands[sz-1]<=summands[sz-2])
  {
    summands[sz-2]=summands[sz-1]+summands[sz-2];
    summands.pop_back();
  }
  
  
  return summands;
}

int main() {
  long long n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
