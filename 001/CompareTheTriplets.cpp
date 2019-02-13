#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::vector < int > a(3);
    int a_result = 0, b_result = 0;
    
    std::for_each( a.begin(), a.end(), [] ( int& item ){
        cin >> item;
    } );
    std::for_each ( a.begin(), a.end(), [&a_result, &b_result] ( int & a ) {
        int b = 0;
        cin >> b;
        if ( a > b )
        {
            ++a_result;
        }
        else if ( a < b )
        {
            ++b_result;
        }
    } );
    cout << a_result << " " << b_result ;
    return 0;
}