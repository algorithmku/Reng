#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {

    vector< int > sorted_arr( arr.begin(), arr.end() );
    vector< int > unsorted_index;
    sort( sorted_arr.begin(), sorted_arr.end() );
    for( int i = 0; i < arr.size(); ++i )
    {
        if ( arr[ i ] != sorted_arr [ i ] )
        {
            unsorted_index.push_back( i );
        }
    }
    int unsorted_count = unsorted_index.size() ;
    switch ( unsorted_count )
    {
    case 1:
        {
            cout << "no" << endl;
        }
        break;
    case 2:
        {
            cout << "yes" << endl;
            cout << "swap " << unsorted_index[ 0 ] + 1 << " " << unsorted_index[ 1 ] + 1 << endl;
        }
        break;
    default:
        {
            bool can_reverse = true;
            vector< int > tmp( arr.begin() + unsorted_index[ 0 ] , arr.begin() + unsorted_index[ unsorted_count - 1 ] + 1); 

            for( int i = 0; i < tmp.size() - 1; ++i )
            {
                if ( tmp [ i ] < tmp [ i + 1 ] )
                {
                    can_reverse = false;
                }
            }

            if ( can_reverse )
            {
                cout << "yes" << endl;
                cout << "reverse " << unsorted_index[ 0 ] + 1  << " " << unsorted_index[ unsorted_count - 1 ] + 1  << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        break;
    }
    

}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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