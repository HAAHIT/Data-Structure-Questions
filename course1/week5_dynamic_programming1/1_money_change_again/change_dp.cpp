#include <iostream>

int get_change(int m) {
  //write your code here

  int four=0, three=0, one=0;
  
  four = m/4;
  three = (m % 4) / 3;
  one = m-4*four-3*three;
  if ((m-6)%4 == 0 && (m-6)>=0)
  {
    //std::cout<<"Special case"<<std::endl;
    return(four+three+one-1);
  }
  
  return(four+three+one);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
