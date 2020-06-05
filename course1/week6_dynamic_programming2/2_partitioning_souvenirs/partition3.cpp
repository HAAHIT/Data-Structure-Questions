#include <bits/stdc++.h>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here
    int sum = 0,s1=0,s2=0;
    for (size_t i = 0; i < A.size(); i++) {
      sum = sum + A[i];
    }
    std::sort(A.begin(),A.end());
    for (size_t i = 0 ; i < A.size() ;  i++) {
        if (s1 == sum/3 && s2 == sum/3) {
          return 1;
        }
    }

  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
