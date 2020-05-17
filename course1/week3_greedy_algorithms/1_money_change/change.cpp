#include <iostream>

// Completed //

int get_change(int m) {
  //write your code here
  int ten=0,fiv=0,one=0;
  ten = m/10;
  fiv = (m%10)/5;
  one = m%5;

  return(ten+fiv+one);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
