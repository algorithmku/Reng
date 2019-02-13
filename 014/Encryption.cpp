#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// Complete the encryption function below.
string encryption(string s) {

    string result;
    int count = s.size();
    double root = sqrt( (double) count );
    int row = (int)root , col = ( (root - (int)root) == 0 ) ? (int)root : (int)root + 1;

    for( int i = 0; i < col; ++i )
    {
        for ( int j = 0; j <= row; ++j )
        {
            if( i + (j * col) < s.size() )
            {
                result.push_back( s[ i + (j * col) ] );
            }
        }
        result.push_back( ' ' );
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}