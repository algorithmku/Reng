#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {

    std::string::iterator it = s.begin();

    char compare_charactor = *it;
    it += 1;
    while( it != s.end() )
    {
        if ( s.empty() )
        {
            return "Empty String";
        }
        if ( compare_charactor == *it ) 
        {
            s.erase( it - 1 - s.begin(), 2 );
            it = s.begin();
        }
        compare_charactor = *it;
        ++it;
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}