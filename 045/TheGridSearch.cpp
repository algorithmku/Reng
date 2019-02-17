#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool IsValidGrid( int x, int y, vector<string> dest, vector<string> src ) {
     for( int j = 1; j < src.size(); ++j ) {
         ++y;
        if ( dest[y].compare( x, src[j].size(), src[j] ) != 0 ) {
            return false;
        }
    }
    return true;
}
// Complete the gridSearch function below.
string gridSearch(vector<string> G, vector<string> P) {

    int x, y;
    for( int i = 0; i < G.size(); ++i ) {
        ssize_t pos = G[i].find( P[0] );
        while( pos != std::string::npos  ) {
            y = i, x = pos;
            if ( IsValidGrid ( x, y, G, P ) ) {
                return "YES";
            }
            pos = G[i].find( P[0], pos + 1 );
        }
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

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
