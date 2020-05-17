#include <iostream>
#include <algorithm> 

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long lcm(long long a,long long b)
{
  for (long i = std::min(a,b); i >=1; i--)
  {
    if ((a*b/i)%a==0 && (a*b/i)%b==0)
    {
      return(a*b/i);
      break;
    }
    
  }
  return 1;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
