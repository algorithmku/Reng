#include <bits/stdc++.h>

using namespace std;


// Complete the gemstones function below.
int gemstones(vector<string> arr) {
//97~122
    vector< int > gem( 26 );
    
    for( int i = 0; i < arr.size(); ++i )
    {
        string::iterator it;
        for ( it = arr[i].begin(); it < arr[i].end(); ++it )
        {
            int index = *it - 97;
            if ( i != 0 && gem [ index ] == 0 )
            {
                continue;
            }
            else if ( gem [ index ] == i )
            {
                ++gem[ index ];
            }
        }

    }
    int result = 0;
    for( int i = 0; i < gem.size(); ++i )
    {
        if ( gem[ i ] == arr.size() )
        {
            ++result;
        }
    }
    
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}