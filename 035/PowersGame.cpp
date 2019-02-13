#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the powersGame function below.
 */
string powersGame(int n) {
    
    if ( n % 8 == 0 )
    {
        return "Second";
    }
    return "First";
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

        string result = powersGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}