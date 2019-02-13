#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0; width_i < n; width_i++){
       cin >> width[width_i];
    }
    vector< int > result;
    for( int i = 0; i < t; ++i )
    {
        int i1, i2;
        cin >> i1;
        cin >> i2;
        result.push_back( *std::min_element( width.begin() + i1, width.begin() + i2 + 1 ) );     
    }

    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}

//https://www.hackerrank.com/challenges/service-lane/problem