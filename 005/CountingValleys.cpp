#include <bits/stdc++.h>

using namespace std;

int countingValleys(int n, string s) {
    // Complete this function
    int floor = 0, old_floor = 0;
    int vally_count = 0; 
    for( int i = 0; i < n; ++i )
    {
        if ( s[i] == 'D')
        {
            --floor;
        }
        else if ( s[i] == 'U' )
        {
            ++floor;
        }
        
        if ( floor < 0 && old_floor >= 0 )
        {
            ++vally_count;
        }
        old_floor = floor;
    }
    return vally_count;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = countingValleys(n, s);
    cout << result << endl;
    return 0;
}