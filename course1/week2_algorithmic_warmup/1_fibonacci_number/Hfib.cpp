#include <iostream>
#include <cassert>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

unsigned long long int fibonacci_fast(int n) {
    // write your code here
    unsigned long long int fib1=0;
    unsigned long long int fib2=1;
    unsigned long long int fib=0;
    if (n==1)
    {
        std::cout<<1<<"\n";
    }
    else
    {
        //0 1 1 2 3 5 8 13 21 34 55
        for (int h = 2; h <= n; h++)
        {
            fib = fib1 + fib2;
            fib1=fib2;
            fib2=fib;
            std::cout<<h<<" : "<<fib<<"\n";
        }
    }
    
    
    
    return fib;
}

// void test_solution() {
//     assert(fibonacci_fast(3) == 2);
//     assert(fibonacci_fast(10) == 55);
//     for (int n = 0; n < 20; ++n)
//         assert(fibonacci_fast(n) == fibonacci_naive(n));
// }

int main() {
    unsigned long long int n = 0;
    unsigned long long int m = 0;
    std::cin >> n;
    std::cin>>m;
    //std::cout << fibonacci_naive(n) << '\n';
    //  test_solution();
    unsigned long long fib = fibonacci_fast(n);
    std::cout<<fib%m;

    return 0;
}
