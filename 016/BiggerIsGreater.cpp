#include <bits/stdc++.h>



using namespace std;



// Complete the biggerIsGreater function below.

string biggerIsGreater(string w) {



    string result;

    

    vector< int > w_value;

    w_value.resize( w.size() );

    for ( int i = 0; i < w.size(); ++i )

    {

        w_value[ i ] = ( w[ i ] - 96 );

    }

    

    bool is_changed = false;

    for ( int i = w_value.size()-1; i > 0; --i )

    {

        int ref_val = w_value[ i ];

        for( int j = i - 1; j >= 0; -- j )

        {

            if ( ref_val > w_value [ j ] ) 

            {

                is_changed = true;

                swap( w_value[ i ], w_value[ j ] );

                sort( w_value.begin() + j+1, w_value.end() );

                break;

            }

        }

        if ( is_changed )

        {

            break;

        }

    }



    for( int i = 0 ; i < w_value.size(); ++i )

    {

        result.push_back(w_value[ i ] + 96);

    }

    return is_changed ? result : "no answer"; 

}



int main()

{

    ofstream fout(getenv("OUTPUT_PATH"));



    int T;

    cin >> T;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');



    for (int T_itr = 0; T_itr < T; T_itr++) {

        string w;

        getline(cin, w);



        string result = biggerIsGreater(w);



        fout << result << "\n";

    }



    fout.close();



    return 0;

}