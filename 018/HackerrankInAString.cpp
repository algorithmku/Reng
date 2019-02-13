#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {

    string hacker_rank = "hackerrank";
    string::iterator it = hacker_rank.begin();

    string result = "NO";
    std::size_t found = s.find( *it );
    while( found != string::npos )
    {
        if ( it == hacker_rank.end() - 1 )
        {
            result = "YES";
            break;
        }
        ++it;
        found = s.find( *it, found + 1 );
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}