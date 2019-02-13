#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {

    std::map < char, int > string_map;
    string::iterator it = b.begin();
    
    while( it != b.end() )
    {
        ++string_map[ *it ];
        
        ++it;
    }
    
    std::map< char, int >::iterator iter;
    for( iter = string_map.begin(); iter != string_map.end(); ++iter )
    {
        if ( (*iter).first != '_' && (*iter).second <= 1 )
        {
            return "NO";
        }
    }
 
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
