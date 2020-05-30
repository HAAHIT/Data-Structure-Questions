#include <algorithm>
#include <iostream>
#include <vector>

typedef long long int ll;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

ll get_majority_element_naive(vector<int> &a,ll left,ll right){
  ll current;
  ll count;
  for (size_t i = 0; i < right; i++)
  {
    current = a[i];
    count=0;
    for (size_t j = 0; j < right; j++)
    {
      if (a[j] == current)
      {
        count++;
      }
      
    }
    if (count > (right-left)/2)
    {
      return 1;
    }
  }
  return 0;
  

}

ll get_majority_element(vector<int> &a, ll left, ll right) {
  //if (left == right) return -1;
  //if (left + 1 == right) return a[left];
  //write your code here
  //std::cout<<"left : "<<left<<" right : "<<right<<" "<<std::endl;
  ll Hlap = 1;
  sort(a.begin(),a.end());
  for (size_t i = left; i < right-1; i++)
  {
    if (a[i] == a[i+1])
    {
    //   std::cout<<a[i]<<" "<<a[i+1]<<" ";
    //   std::cout<<std::endl;
      Hlap++;
      if (Hlap > ((right-left)/2))
      {
        return 1;
      }
      //std::cout<<Hlap<<" "<<std::endl;
    }
    else
    {
      Hlap=1;
    }
  }
    return 0;
}

int main() 
{
//   while (true)
//   {
//     cout<<endl;
//     int n = rand()%10 +2;
//     cout<<n<<" ";
//     vector<int> a;
//     for (size_t i = 0; i < n; i++)
//     {
//       a.push_back(rand() % 100);
//     }
//     for (size_t i = 0; i < n; i++)
//     {
//         cout<<a[i]<<" ";
//     }
    
//     //replace with the call to binary_search when implemented
//     ll res1 = get_majority_element(a, 0, a.size() );
//     ll res2 = get_majority_element_naive(a, 0, a.size() );
//     if (res1 != res2)
//     {
//       cout<<endl<<"Wrong Answer: "<<res1<<" "<<res2;
//       break;
//     }
//     else
//     {
//       cout<<endl<<"OK";
//     }
    
//     } 
  
  

  ll hit=0;
  cin>>hit;
  vector<int> a(hit);
  for(size_t i = 0; i < a.size(); ++i) {
      cin >> a[i];
  }
  if (a.size()==1)
  {
    cout<<1;
  }
  else
  {
    cout << get_majority_element(a, 0, a.size())<< '\n';
  }
}  

