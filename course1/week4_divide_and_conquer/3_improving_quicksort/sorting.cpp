#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
void partition(vector<int> &a, int l, int r, int &i, int &j) 
{ 
    i = l-1, j = r; 
    int p = l-1, q = r; 
    int v = a[r]; 
  
    while (true) 
    { 
        // From left, find the first element greater than 
        // or equal to v. This loop will definitely terminate 
        // as v is last element 
        while (a[++i] < v); 
  
        // From right, find the first element smaller than or 
        // equal to v 
        while (v < a[--j]) 
            if (j == l) 
                break; 
  
        // If i and j cross, then we are done 
        if (i >= j) break; 
  
        // Swap, so that smaller goes on left greater goes on right 
        swap(a[i], a[j]); 
  
        // Move all same left occurrence of pivot to beginning of 
        // array and keep count using p 
        if (a[i] == v) 
        { 
            p++; 
            swap(a[p], a[i]); 
        } 
  
        // Move all same right occurrence of pivot to end of array 
        // and keep count using q 
        if (a[j] == v) 
        { 
            q--; 
            swap(a[j], a[q]); 
        } 
    } 
  
    // Move pivot element to its correct index 
    swap(a[i], a[r]); 
  
    // Move all left same occurrences from beginning 
    // to adjacent to arr[i] 
    j = i-1; 
    for (int k = l; k < p; k++, j--) 
        swap(a[k], a[j]); 
  
    // Move all right same occurrences from end 
    // to adjacent to arr[i] 
    i = i+1; 
    for (int k = r-1; k > q; k--, i++) 
        swap(a[i], a[k]); 
} 
  
// 3-way partition based quick sort 
void quicksort(vector<int> &a, int l, int r) 
{ 
    if (r <= l) return; 
  
    int i, j; 
  
    // Note that i and j are passed as reference 
    partition(a, l, r, i, j); 
  
    // Recur 
    quicksort(a, l, j); 
    quicksort(a, i, r); 
} 

void randomized_quick_sort1(vector<int> &a1, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  int count = 1, m1 = 0, m2 = 0;
  swap(a1[l], a1[k]);
  for (int i = l+1; i < a1.size(); i++)
  {
    if (a1[l]==a1[i])
    {
      count++;
    }
   
  }
  std::cout<<std::endl<<count<<std::endl;
  int m = partition2(a1, l, r);
  if (count == 1)
  {
    m1 = m;
    m2 = m;
  }
  else
  {
    m1 = m - count;
    m2 = m;
  }
  
  
  randomized_quick_sort1(a1, l, m1 - 1);
  randomized_quick_sort1(a1, m2 + 1, r);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  int count = 1, m1 = 0, m2 = 0;
  swap(a[l], a[k]);
  for (int i = l+1; i < a.size(); i++)
  {
    if (a[l]==a[i])
    {
      count++;
    }
    
  }
  //std::cout<<std::endl<<count<<std::endl;
  int m = partition2(a, l, r);
  
  
  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
  // while (true)
  // {
  //   int br=0;
  //   std::cout<<endl;
  //   int n = rand()%10 +2;
  //   std::cout<<n<<" ";
  //   vector<int> a;
  //   vector<int> a1;
  //   for (size_t i = 0; i < n; i++)
  //   {
  //     int ram = rand() % 100;
  //     a.push_back(ram);
  //     a1.push_back(ram);
  //     cout<<a[i]<<" ";
  //   }
  //   //replace with the call to binary_search when implemented
  //   randomized_quick_sort(a, 0, a.size() - 1);
  //   randomized_quick_sort1(a1, 0, a1.size() - 1);
  //   for(int i=0;i<a.size();i++)
  //   {
  //     //cout<<" "<<a[i]<<" ";
  //     if (a[i] != a1[i])
  //     {
  //     std::cout<<std::endl<<"Wrong Answer: "<<a[i]<<" "<<a1[i]<<endl;
  //     for (size_t i = 0; i < a.size(); i++)
  //     {
  //       cout<<a[i]<<" ";
  //     }
  //     cout<<endl;
  //     for (size_t i = 0; i < a.size(); i++)
  //     {
  //       cout<<a1[i]<<" ";
  //     }
  //     br=1;
  //     break;
  //     } 
  //     // else
  //     // {
  //     // std::cout<<std::endl<<"OK";
  //     // }
    
  //   }
  //   if (br == 1)
  //   {
  //     break;
  //   }
    
  // } 
  
  

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  quicksort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
