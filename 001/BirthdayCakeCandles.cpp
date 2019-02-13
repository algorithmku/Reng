#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int candle_count = 0;
    cin >> candle_count;
    std::vector < int > heights( candle_count );
    std::for_each( heights.begin(), heights.end(), [] ( int& height ){
       cin >> height;
    } );
    std::sort( heights.begin(), heights.end(), greater<int>() );
    int tmp = heights[0], result = 0;
    std::for_each( heights.begin(), heights.end(), [&tmp, &result] ( int& height ){
        if ( tmp == height )
        {
            ++result;
        }
    } );
    cout << result << endl;
    return 0;
}

//https://www.hackerrank.com/challenges/birthday-cake-candles/problem?h_r=internal-search
