#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {

    long count = n / s.size();
    long remain = n % s.size();
    long remain_count = 0;
    long a_count =0;
    for( int i = 0; i < s.size(); ++i )
    {
        if ( s[ i ] == 'a' )
        {
            a_count++;
            if ( i < remain )
            {
                remain_count++;
            }
        }
    }
    return a_count * count + remain_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
