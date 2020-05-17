#include <bits/stdc++.h> 

using std::vector;
using std::string;
using namespace std;

string largest_number(vector<string> a) {
  //write your code here
  int size = a.size();
  int count =0;
  vector<double> lessThanTen;
  vector<double> lessThanHun;
  vector<double> lessThanTho;
  for (size_t i = 0; i < size; i++)
  {
    double num = stoi(a[i]); 
    if (num == 1000) //equal to 1000
    {
      count++;
    }
    else if (num/10 == 0)  //less than 10
    {
      lessThanTen.push_back(num);
    }
    else if (num/100 == 0) //less than 100
    {
      lessThanHun.push_back(num); 
    }
    else if (num/1000 == 0) //less than 1000
    {
      lessThanTho.push_back(num);
    }
  }
  
  sort(lessThanHun.begin(), lessThanHun.end(), greater<int>());
  sort(lessThanTen.begin(), lessThanTen.end(), greater<int>());
  sort(lessThanTho.begin(), lessThanTho.end(), greater<int>());

  int specialCount =0;
  int ten=0,hun=0,tho=0;
  int spc;

  while(specialCount < size-count)
  {
    if ((lessThanTen[ten] >= lessThanHun[hun]/10.00) && (lessThanTen[ten] >= lessThanTho[tho]/100.00))
    {
        spc = lessThanTen[ten];
        a[specialCount] = to_string(spc) ;
        specialCount++;
        ten++;
    }
    else if ((lessThanTen[ten] <= lessThanHun[hun]/10.00) && (lessThanHun[hun]/10.00 >= lessThanTho[tho]/100.00))
    {
        spc = lessThanTen[hun];
        a[specialCount] = to_string(spc);
        specialCount++;
        hun++;
    }
    else if((lessThanTho[tho]/100.00 >= lessThanHun[hun]/10.00) && (lessThanTen[ten] <= lessThanTho[tho]/100.00))
    {
        spc = lessThanTen[tho];
        a[specialCount] = to_string(spc);
        specialCount++;
        tho++;
    }
    
  }
  while (count != 0)
  {
    a[specialCount]="1000";
    specialCount++;
    count--;
  }
  

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
