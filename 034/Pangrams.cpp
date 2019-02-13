#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {

    bool is_pangrams = true;
    std::vector< int > alphabet_index( 26 );
    std::string::iterator it = s.begin();

    for( ; it != s.end(); ++it )
    {
        if ( *it == ' ' )
        {
            continue;
        }
        int index;
        if ( *it >= 65 && *it <= 90 )
        {
            index = *it - 65;
        }
        else
        {
            index = *it - 97;
        }
        ++alphabet_index[ index ];
    }

    for( int i = 0; i < alphabet_index.size(); ++i )
    {
        if ( alphabet_index[ i ] == 0 )
        {
            is_pangrams = false; 
        }
    }
    return is_pangrams ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
