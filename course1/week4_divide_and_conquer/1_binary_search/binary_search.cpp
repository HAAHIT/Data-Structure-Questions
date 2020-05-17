#include <iostream>
#include <cassert>
#include <vector>
#include<stdlib.h>
#include<algorithm>
//#include <bits/stdc++.h> 

typedef long long int ll;
using std::vector;
using std::cout;
using std::endl;

ll binary_search(const vector<int> &a, ll x) 
{
  ll left = 0, right = (int)a.size()-1, med=0; 
  //write your code here'
  
  while (right >= left )
  {
    med = (left + (right - left)/2);
    if (x>a[med])
    {
      left = med+1;
    }
    else if (x<a[med])
    {
      right = med-1;
    }
    else if (x == a[med])
    {
      return med;
    }
  }
  return -1;
}

ll linear_search(const vector<int> &a, ll x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  // while (true)
  // {
  //   cout<<endl;
  //   int hit=0;
  //   int n = rand()%10 +2;
  //   cout<<n<<" ";
  //   vector<int> a;
  //   for (size_t i = 0; i < n; i++)
  //   {
  //     a.push_back(rand() % 100);
  //   }
  //   sort(a.begin(), a.end());
  //   for (size_t i = 0; i < n; i++)
  //   {
  //     cout<<a[i]<<" ";
  //   }
    
  //   cout<<endl;
  //   int m = rand()%10 +2;
  //   cout<<m<<" ";
  //   vector<int> b;
  //   for (size_t i = 0; i < m; i++)
  //   {
  //     b.push_back(rand() % 100);
  //     cout<<b[i]<<" ";
  //   }
    
  //   for (ll i = 0; i < m; ++i) {
  //   //replace with the call to binary_search when implemented
  //   ll res1 = linear_search(a, b[i]);
  //   ll res2 = binary_search(a, b[i]);
  //   if (res1 != res2)
  //   {
  //     cout<<endl<<"Wrong Answer: "<<res1<<" "<<res2;
  //     hit=1;
  //   }
  //   else
  //   {
  //     cout<<endl<<"OK";
  //   }
    
  // }
  //  if (hit == 1)
  //  {
  //    break;
  //  }
    
    
  // }
  
  ll n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (ll i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (ll i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
