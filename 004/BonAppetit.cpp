#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k, b;
    cin >> n ;
    cin >> k;
    std::vector< int > costs(n);
    int a_cost = 0; 
    for( int i = 0; i < n; ++i )
    {
        cin >> costs[i];
        if ( i != k )
        {
            a_cost += costs[ i ];
        }
    }
    cin >> b;
    
    a_cost /= 2;
    
    if ( b <= a_cost )
    {
        cout << "Bon Appetit" << endl;
    }
    else
    {
        cout << b - a_cost << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}