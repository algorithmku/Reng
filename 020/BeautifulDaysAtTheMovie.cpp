#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int reverse( int number )
{
    int cipher = 0;
    string s = to_string(number);
    cipher = s.size();
    
    int n = 1;
    int result = 0;
    while( n <= cipher )
    {
        int tmp = number / (int)pow( 10, cipher - n ); 
        number -= tmp * (int)pow( 10, cipher - n );
        result += tmp * (int)pow( 10, n-1 );
        ++n;
    }
    return result;
}
// Complete the beautifulDays function below.
int beautifulDays(int i, int j, int k) {
    
    int beautiful_days = 0;

    for ( int day = i; day <= j; ++day )
    {
        float num = (float) abs( day - reverse( day ) ) / (float)k;
        if ( (int)num == num )
        {
            ++beautiful_days;
        }
    }
    return beautiful_days;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautifulDays(i, j, k);

    fout << result << "\n";

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