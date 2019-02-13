#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


// Complete the bomberMan function below.
vector<string> bomberMan(int n, vector<string> grid) {

    vector< string > base_grid;
    for( int i = 0; i < grid.size(); ++i )
    {
        base_grid.push_back( grid[ i ] );
    }
    vector< string > result;
    int second = 0;
    while( second != n )
    {
        ++second;
        if ( ( second % 3 ) == 2 )
        {
            for ( int j = 0; j < base_grid.size(); ++j )
            {
                string grid_item;
                for( int i = 0; i < base_grid[0].size(); ++i )
                {
                    grid_item += "O";
                }
                result[j]= grid_item ;
            }
        }
        else if ( ( second % 3 ) == 1 )
        {
            result = base_grid;
        }
        else
        {
            int width= base_grid[0].size();
            int height= base_grid.size();

            int x = 0, y = 0;

            for( int y = 0; y < height; ++y )
            {
                for ( int x = 0; x < width; ++x )
                {
                    if ( base_grid[y][x] == 'O' )
                    {
                        result[y][x] = '.';
                        if ( x >0 ) result[y][x-1] = '.';
                        if ( y >0 ) result[y-1] [x]= '.';
                        if ( x < width-1 ) result[y][x+1] = '.';
                        if ( y < height-1 ) result[y+1][x] ='.';
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
