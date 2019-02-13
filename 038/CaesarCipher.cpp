#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {

    std::string::iterator it = s.begin();
    string result;
    k = k % 26;
    while( it != s.end() )
    {
        if ( 'A' <= *it && *it <= 'Z' )
        {
            if ( *it + k <= 'Z' )
            {
                result.push_back( *it + k );
            }
            else
            {
                result.push_back( *it + k - 'Z' + 'A' - 1 ); 
            }
        }
        else if( 'a' <= *it && *it <= 'z' )
        {
            if ( *it + k <= 'z' )
            {
                result.push_back( *it + k );
            }
            else
            {
                result.push_back( *it + k - 'z' + 'a' - 1 ); 
            }
        }
        else
        {
            result.push_back( *it );
        }
        ++it;
    }
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
