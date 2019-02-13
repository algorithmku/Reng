#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
bool appendAndDelete(string s, string t, const int k) {
    if ( s.compare( t ) == 0 )
    {
        return true;
    }
    
    int index =0;
    while( s[index] == t[index] )
    {
        ++index;
    }

    if ( s.size() == t.size() )
    {
        int L = s.size() - index;
        cout << s.size() << " " << index << endl;
        if ( ( L * 2 <= k)  )
        {
            return true;
        }
    }
    else if ( s.size() > t.size() )
    {
        int L = s.size() - index;
        int K = t.size() - index;
        if ( L + K <= k || k%2 == 0 )
        {
            return true;
        }
    }
    else if ( s.size() < t.size() )
    {
        int L = s.size() - index;
        int K = t.size() - index;
        int m = k - L - K;
        if ( L + K == k || ( m >= 0 && m % 2 == 0 ) )
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k) ? "Yes" : "No";

    fout << result << "\n";

    fout.close();

    return 0;
}