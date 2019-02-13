#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void print_matrix ( vector< string > matrix )
{
    for( int i = 0; i < matrix.size() ; ++i )
    {
        for( int j = 0; j < matrix[0].size(); ++j )
        {
           cout << matrix[ i ][ j ];
        }
        cout << endl;
    }
}

//int wand_count = 0;
bool FindKey ( vector<string> matrix, int x, int y, int* wand_count )
{
   // print_matrix( matrix );
    if ( x < 0 || y < 0 || x > matrix.size() - 1 || y > matrix[ 0 ].size() - 1 ) 
    {
        return false;
    }
    if ( matrix[ x ][ y ] == 'X' || matrix[ x ][ y ] == 'O' )
    {
        return false;
    }
    else if ( matrix[ x ][ y ] == '*' )
    {
        cout << " !!! " << endl;
        return true;
    }
    else
    {
        
        int count = 0;
        matrix[ x ][ y ] = 'O';
        if ( x - 1 > 0 && matrix[ x - 1 ][ y ] == '.' ) { count ++; }
        if ( x + 1 < matrix.size()  && matrix[ x + 1 ][ y ] == '.' ) { count ++; }
        if ( y - 1 > 0 && matrix[ x ][ y - 1 ] == '.' ) { count ++; }
        if ( y + 1 < matrix[0].size() && matrix[ x ][ y + 1 ] == '.' ) {  count ++; }
        if ( count >= 2 )
        {
            *wand_count += 1 ;            
        }
        if ( FindKey( matrix, x - 1, y, wand_count ) || FindKey( matrix, x + 1, y, wand_count ) 
            || FindKey( matrix, x, y - 1, wand_count ) || FindKey( matrix, x, y + 1, wand_count ) )
            {
                return true;
            }
        else
        {  
            matrix[ x ][ y ] = 'X';
            return false;
        }
    }
    return false;
}
// Complete the countLuck function below.
string countLuck(vector<string> matrix, int k) {

    int start_x, start_y;
    for( int i = 0; i < matrix.size() ; ++i )
    {
        for( int j = 0; j < matrix[0].size(); ++j )
        {
            if ( matrix[ i ][ j ] == 'M' )
            {
                start_x = i;
                start_y = j;
            }
        }
    }
    
    int wand_count = 0;
    FindKey( matrix, start_x, start_y, &wand_count );
   
    return ( wand_count == k ) ? "Impressed" : "Oops!";
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = countLuck(matrix, k);

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
