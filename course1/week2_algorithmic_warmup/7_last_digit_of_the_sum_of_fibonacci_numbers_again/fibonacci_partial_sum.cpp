#include <iostream>

// CORE LOGIC OF THIS PROBLEM
// sum[f(i)] = f(n+2) - 1

typedef unsigned long long int ll; 

ll fib(ll f[], ll n) 
{ 
    // 0th and 1st number of 
    // the series are 0 and 1 
    f[0] = 0; 
    f[1] = 1; 
  
    // Add the previous 2 numbers  
    // in the series and store  
    // last digit of result 
    for (ll i = 2; i <= n; i++) 
        f[i] = (f[i - 1] + f[i - 2]) % 10; 
  
    return f[n]; 
} 
ll findLastDigit(ll n) 
{ 
    ll f[60] = {0}; 
  
    // Precomputing units digit of   
    // first 60 Fibonacci numbers 
    fib(f, 60); 
  
    return f[(n) % 60]; 
} 

int main() {
    ll n,m;
    std::cin>>m;
    std::cin >> n;

    //int c = get_fibonacci_last_digit_naive(n);
    if (n==0 || n==1)
    {
        std::cout<<n;
    }
    else
    {
        ll c = findLastDigit(n+2)-1;
        c = c % 10;
        ll b = findLastDigit(m+1)-1;
        b = b % 10;
        std::cout<<c-b;
    }
    
    return 0;
    }
