#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    vector< int > string_count;
    string_count.resize( 26 );
    for( int i = 0; i < s.size(); ++i )
    {
        ++string_count [ s[ i ] - 97 ];
    }
    int odd = 0;
    for( int i = 0; i < string_count.size(); ++i )
    {
        if ( ( string_count[ i ] % 2 ) != 0 )
        {
            ++odd;
            if ( odd > 1 )
            {
                return "NO";
            }
        }
    }
    
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}