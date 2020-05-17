
// Completed //

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist,int num, int tank, vector<int> & stops) {
    // write your code here
    stops.push_back(dist);
    int ind=0,ref=0,con=0;

    for (int i = 0; i < num; i++)
    {
        if ((stops[i+1]-stops[i])>tank)
        {
            return -1;
        }
    }
    while (stops[ind]<=dist)
    {
            if (!(stops[ind] - ref <= tank) )
            {
                ref = stops[ind -1];
                con++;
            }
            ind++;
    }    
    return con;
}


int main() {
    int d = 0,m=0,n=0;
    cin >> d >> m >> n;
    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, n, m, stops) << "\n";

    return 0;
}
