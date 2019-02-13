#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {


    long time = 3 ;
    long value = 1 ;
    long square = 1; 
    
    while( 1 ) {
        
        if ( time < t )
        {
            square *= 2;
            time = 3 * (square - 1);
        }
        else
        {
            break;
        }
    }
    
    while( time != t ) {
        time--;
        value++; 
    }
    return value;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}