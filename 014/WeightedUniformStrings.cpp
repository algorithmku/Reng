#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    
    vector< string > result;
   
    vector< int > numbers;
    numbers.resize( s.size() );

    for ( int i = 0; i < s.size(); ++i )
    {
        numbers[ i ] = s[ i ] - 96;
    }
    int number_size = numbers.size();

    for ( int i = 0; i < number_size; ++i )
    {
        if ( i != 0 )
        {
            int count = 1;
            for ( int j = i - 1 ; j >= 0 ; -- j )
            {
                if ( numbers[ j ] == numbers [ i ] )
                {
                    ++count;
                    numbers.push_back( numbers [ i ] * count );
                }             
            }
        }
    }

    sort( numbers.begin(), numbers.end() );
    vector< int >::iterator pos;
    pos = unique( numbers.begin(), numbers.end() );
    numbers.erase( pos, numbers.end() );

    result.resize( queries.size() );
    for ( int i = 0; i < queries.size(); ++i )
    {
        result[ i ] = "No";
        
        for( int j = 0; j < numbers.size(); ++j )
        {
            if ( queries[ i ] == numbers[ j ] )
            {
                result [ i ] = "Yes";
            }
        }   
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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

