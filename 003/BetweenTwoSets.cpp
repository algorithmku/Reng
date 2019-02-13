#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int EU ( int x, int y )
{
    int n;
    while( 1 ) {
        n = x % y;
        if ( n == 0 ) return y;
        x = y;
        y = n;
    }
}

int getTotalX(vector<int> a, vector<int> b) {
    int gcm = a[0] , lcm = a[ 0];
    for( int i = 1; i < a.size(); ++i )
    {
        gcm = EU( gcm, a[i] );
        lcm = lcm * a[i] / EU ( lcm, a[i] );
    }
    
    if ( b[0] < lcm )
    {
        return 0;
    }
    int count = 1;
    while( 1 )
    {
        if ( b[ 0 ] <= ( lcm * count ) )
        {
            break;
        }
        ++count;
    }
    
    int result_count = 0;
    
    for( int i = 1 ; i <= count; ++i )
    {
        int target_num = lcm * i;
        for( int j = 0 ; j < b.size(); ++ j )
        {
            if ( b[ j ] % target_num != 0 )
            {
                break;
            }
            if ( j == (b.size() - 1) )
            {
                ++ result_count;
            }
        }
    }

    return result_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int a_itr = 0; a_itr < n; a_itr++) {
        int a_item = stoi(a_temp[a_itr]);

        a[a_itr] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int b_itr = 0; b_itr < m; b_itr++) {
        int b_item = stoi(b_temp[b_itr]);

        b[b_itr] = b_item;
    }

    int total = getTotalX(a, b);

    fout << total << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
// https://www.hackerrank.com/challenges/between-two-sets/problem?h_r=internal-search