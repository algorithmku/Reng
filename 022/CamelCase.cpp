#include <bits/stdc++.h>

using namespace std;

// Complete the camelcase function below.
int camelcase(string s) {

    int words = 1;
    string::iterator iter = s.begin();
    
    for( ; iter != s.end(); ++iter )
    {
        if ( 65 <= *iter && *iter <= 90 )
        {
            ++words;
        }
    }
    return words;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = camelcase(s);

    fout << result << "\n";

    fout.close();

    return 0;
}