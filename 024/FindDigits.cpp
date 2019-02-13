#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits( const int n) {
    int result = 0;
    int number = n; 
    while( number != 0 )
    {
        int remainder = number % 10;
        if ( remainder != 0 &&  n % remainder  == 0 )
        {
            result++;
        }
        number /= 10;
    }
    
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = findDigits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}