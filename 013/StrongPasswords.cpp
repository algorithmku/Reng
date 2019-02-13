#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    bool has_number = false, has_lower = false, has_upper = false, has_special = false;
    int need_char = 0;
    for ( int i = 0; i < password.size() ; ++i ) {
        if ( '0' <= password[ i ] && password[ i ] <= '9' )
        {
            has_number = true;
        }
        if ( 'A' <= password[ i ] && password[ i ]  <= 'Z' )
        {
            has_upper = true;
        }
        if ( 'a' <= password[ i ] && password[ i ]<= 'z' )
        {
            has_lower = true;
        }
        if ( '!' <= password[ i ] && password[ i ]<= '/' )
        {
            has_special = true;
        }
    }

    if ( !has_number )
        ++need_char;
    if ( !has_lower )
        ++need_char;
    if ( !has_upper )
        ++need_char;
    if ( !has_special )
        ++need_char;
    
    
    if ( ( n + need_char ) < 6 )
    {
        need_char += ( 6 - ( n + need_char ) );
    }
    
    return need_char;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}