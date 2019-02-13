#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for( int i = 0; i < n; ++i )
    {
        cin >> ar[ i ];
    }
    int result = 0;
    std::for_each( ar.begin(), ar.end(), [ &result ] ( const int& item ) {
        result += item;
    } );
    cout << result << endl;
    return 0;
}