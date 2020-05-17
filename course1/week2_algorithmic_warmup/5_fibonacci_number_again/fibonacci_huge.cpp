#include <iostream>
#include<math.h>
/**/
typedef unsigned long long int ll; 
using std::cout;
using std::cin;
using std::endl;

ll get_fibonacci_huge_naive(ll n, ll m) {
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current  = 1;

    for (ll i = 0; i < n-1 ; ++i) {
        ll tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// ll get_pisano_period(ll m) {
//     ll fib1=1;
//     ll fib2=1;
//     ll fib=0;
//     if (m==1)
//     {
//         return 1;
//     }
//     //0 1 1 2 3 5 8 13 21 34 55
//     for (ll h = 0; h < m*m; h++)
//     {
//         fib = fib1 + fib2;
//         cout<<"  fib1 = "<<fib1;
//         fib1 = fib2;
//         cout<<"  fib2 = "<<fib2<<endl;
//         fib2 = fib;
//         if ((fib2 % m == 1) && (fib1 % m == 1))
//         {
//             return h+1;
//         }
        
//     }
//     return 0;
// }

ll get_fibonacci_huge(ll n,ll m)
{
    ll fib = ((pow((1+sqrt(5)),(n))) - (pow((1-sqrt(5)),(n))))/(pow(2,n)*sqrt(5));
    cout<<fib<<endl;
    //ll sqrt = m*m-1;
   //cout<<endl<<get_pisano_period(m)<<endl;

    // n = ((n) % get_pisano_period(m));
    // cout<<n<<endl;
    // //ll fibfast = fibonacci_fast(n);
    // ll fib1=0;
    // ll fib2=1;
    // ll fib=0;
    // if (n==1)
    // {
    //     return 1;
    // }
    // //0 1 1 2 3 5 8 13 21 34 55
    // for (ll h = 0; h < n-1 ; h++)
    // { 
    //     fib = fib1 + fib2;
    //     cout<<"Index : "<<h<<"    fib : "<<fib<<endl;
    //     fib1 = fib2;
    //     fib2 = fib;
    // }
    return((fib) % m);
}

int main() {
    ll n, m;
    cin >> n >> m;
    std::cout<<get_fibonacci_huge(n, m)<<endl;
}
