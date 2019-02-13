#include <bits/stdc++.h>

using namespace std;

// Complete the powerSum function below.

int calSum( int X, int N, int num, int& count ) {
     if ( pow( num, N ) < X ) {
        return calSum( X, N, num+1, count ) + calSum( X - pow( num, N ), N, num+1 , count );
    }
    else if ( pow( num, N ) == X )
    {
        ++count;
        return 0;
    }
    else{
        return 0;
    }
}
int powerSum(int X, int N ) {
    int count = 0;
    calSum( X, N, 1, count );

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int X;
    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(X, N );

    fout << result << "\n";

    fout.close();

    return 0;
}