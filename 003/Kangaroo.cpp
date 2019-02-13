#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int a_a, a_d, b_a, b_d;
    cin >> a_a >> a_d >> b_a >> b_d ;
    int n = 0, frac_d = 0, frac_n = 0; 
    // a_a + ( n - 1 ) * a_d == b_a + ( n - 1 ) * b_d 
    // a_a + n * a_d - a_d == b_a + n * b_d - b_d 
    // n * a_d - n * b_d == b_a - b_d - a_a + a_d 
    // ( a_d - b_d ) * n == b_a - b_d - a_a + a_d 
    frac_d = (a_d - b_d);
    frac_n = (b_a - b_d - a_a + a_d);
    if ( frac_d == 0 || frac_n == 0 )
    {
        cout << "NO" << endl;
        return 0;
    }
    if ( frac_n % frac_d == 0 )
    {
        if ( ( frac_n / frac_d ) < 0 )
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl; 
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
// https://www.hackerrank.com/challenges/kangaroo/problem