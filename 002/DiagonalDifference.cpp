#include <bits/stdc++.h>
#include <math.h>
using namespace std;

/*
 * Complete the diagonalDifference function below.
 */
int diagonalDifference(vector<vector<int>> a) {
    
    int primary_sum = 0, secondary_sum = 0;

    for ( int i = 0; i < a.size(); ++i )
    {
        for ( int j = 0; j < a[i].size(); ++j )
        {
            if ( i == j )
            {
                primary_sum += a[ i ][ j ];
            }
            if ( ( a.size() - 1 ) == ( i + j ) )
            {
                secondary_sum += a[ i ][ j ];
            }
        }
        
    }
    return abs( primary_sum - secondary_sum );
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> a(n);
    for (int a_row_itr = 0; a_row_itr < n; a_row_itr++) {
        a[a_row_itr].resize(n);

        for (int a_column_itr = 0; a_column_itr < n; a_column_itr++) {
            cin >> a[a_row_itr][a_column_itr];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(a);

    fout << result << "\n";

    fout.close();

    return 0;
}
// https://www.hackerrank.com/challenges/diagonal-difference/problem?h_r=internal-search