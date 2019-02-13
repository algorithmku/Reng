#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {

    int count = 0;
    for( int num = p; num <= q; ++num )
    {
        string square = to_string( (long)pow( num, 2 ) );
    
        int front = 0, back = 0;
        string::iterator iter = square.begin();
       // cout << "num : " << square << " " << (long)pow( num, 2 ) << endl;
        for ( int i = 0; i < square.size() / 2 ; ++i )
        {
            front += ( (int)*(iter+i) - 48 ) * (int)pow( 10, square.size() / 2 - i - 1);
            back += (  (int)*( iter + square.size() / 2 + i ) - 48 ) * (int)pow( 10, square.size() / 2 - i - 1 );
        }
        if ( square.size() % 2 == 1 )
        {
            back *= 10;
            back += (int)square[ square.size() - 1] - 48;
        }
      //  cout << "f , b : "<< front <<  " " << back << endl;
        if ( ( front + back )== num ) 
        {
            cout << num << " ";
            ++count;
        }
        
    }
    if ( count == 0 )
    {
        cout << "INVALID RANGE";
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}