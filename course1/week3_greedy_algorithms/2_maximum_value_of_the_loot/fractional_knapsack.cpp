
// completed //

#include<bits/stdc++.h> 
using namespace std;

double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  double n= weights.size();
  vector<double> netValue(n);
  // write your code here
  // double net_value = 0.0;
  double netMaxValue = 0.0;
 // cout<<endl;
  for (int i = 0; i < n; i++)
  {
   // cout<<"in the for loop calculating netValue vector"<<endl;
    netValue[i]=values[i]/weights[i];
  }

  while (capacity > 0)
  {
    //cout<<" capapcity = "<<capacity;
    //cout<<"Inside while loop"<<endl;
    netMaxValue = *std::max_element(netValue.begin(),netValue.end());
    //cout<<"Current Max Value = "<<netMaxValue<<endl;
    int maxElementIndex = std::max_element(netValue.begin(),netValue.end()) - netValue.begin();
    
   // cout<<"Current Max Value Index = "<<maxElementIndex<<endl;
    if ((weights[maxElementIndex] < capacity) && (netMaxValue != 0))
    {
      //cout<<" capapcity = "<<capacity;
      capacity = capacity - weights[maxElementIndex];
      //cout<<" capapcity = "<<capacity;
      value = value + values[maxElementIndex];
      //cout<<" Value = "<<value;
    }
    else
    {
      if (capacity > 0)
      {
        value = value + netMaxValue * capacity;
       // cout<<" Value = "<<value;
        capacity=0;
      }
      
    }
     netValue[maxElementIndex]=0;   
    
  }
  //std::cout << distance(netValue.begin(),max_element(net_value.begin(), net_value.end()));
  //"Max element Index: "<<max_element(arr, arr + num) - arr;

  
  

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  
  cout << fixed << setprecision(4) <<optimal_value << endl;
  return 0;
}
