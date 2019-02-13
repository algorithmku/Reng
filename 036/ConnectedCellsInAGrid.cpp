#include <bits/stdc++.h>

using namespace std;

void print_matrix ( vector< vector< int > > matrix )
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

bool FindConnectedCell( vector< vector< int > >& matrix, int x, int y, int* count )
{
    if ( x < 0 || y < 0 || x > matrix.size() - 1 || y > matrix[ 0 ].size() - 1 )
    {
        return false;
    }
    if ( matrix[ x ][ y ] == 0 || matrix[ x ][ y ] == 'X')
    {
        count = 0;
        return false;
    }
    else
    {
        ++(*count); 
        matrix[ x ][ y ] = 'X';
        if ( FindConnectedCell( matrix, x - 1, y, count ) || FindConnectedCell( matrix, x + 1, y, count ) || 
        FindConnectedCell( matrix, x, y -1, count ) || FindConnectedCell( matrix, x, y + 1, count ) ||
        FindConnectedCell( matrix, x - 1, y - 1, count ) || FindConnectedCell( matrix, x - 1, y + 1, count ) ||
        FindConnectedCell( matrix, x + 1 , y - 1, count ) || FindConnectedCell( matrix, x + 1, y + 1, count ) )
        {
            return true;
        }
    }
    return false;
}
// Complete the connectedCell function below.
int connectedCell( vector<vector<int>> matrix ) {

    int count = 0, max_count = 0;
    int start_x, start_y;
    for( int i = 0; i < matrix.size(); ++i )
    {
        for( int j = 0; j < matrix[ 0 ].size(); ++j )
        {
            if( matrix[ i ][ j ] == 1 )
            {
                start_x = i;
                start_y = j;
                FindConnectedCell( matrix, start_x, start_x, &count );
                if ( count > max_count )
                {
                    max_count = count;
                    count = 0;
                }
            }
        }
    }
    return max_count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}