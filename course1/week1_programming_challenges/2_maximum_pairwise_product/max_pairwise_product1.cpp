#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll MaxPairwiseProduct(const std::vector<int>& numbers) {
    //int max_product = 0;
    int n = numbers.size();

    int index_max1=-1;
    int index_max2=-1;
    for (int first = 0; first < n; first++) {
        if ((index_max1 == -1) || (numbers[first]>numbers[index_max1]))
        {
            index_max1 = first;
        }
        }
        //std::cout<<index_max1<<" ";

    for (int sec = 0; sec < n; sec++)
    {
        if ((index_max1 == -1) || (numbers[sec]>numbers[index_max2]) && (index_max1 != sec))
        {
            index_max2 = sec;
        }
    }
    //std::cout<<index_max2<<" ";
    
    

    return ((ll)numbers[index_max1])*numbers[index_max2];
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers)<< "\n";
    return 0;
}
