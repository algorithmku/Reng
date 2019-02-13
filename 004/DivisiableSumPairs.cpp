#include <bits/stdc++.h>

using namespace std;

int divisibleSumPairs(int n, int k, vector <int> ar) {
    // Complete this function
    int result = 0; 
    for( int i = 0; i < n; ++i )
    {
        for( int j = i + 1; j < n; ++j )
        {
            int sum = ar[ i ] + ar [ j ];
            if ( sum == k || sum == 0 )
            {
                ++result;
            }
        }
    }
    return result;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
        cin >> ar[ar_i];
        ar[ ar_i ] = ar[ ar_i ] % k; 
    }
    int result = divisibleSumPairs(n, k, ar);
    cout << result << endl;
    return 0;
}
