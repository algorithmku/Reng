#include <bits/stdc++.h>
using namespace std;
// Complete the stones function below.
vector<int> stones(int n, int a, int b) {
    std::vector< int > results;
    
    for( int i = 0; i < n ; ++ i )
    {
        results.push_back( a * ( n - i - 1 ) + ( b * i ) );
    }
    sort( results.begin(), results.end() );
    results.erase(unique(results.begin(), results.end()), results.end());
    return results;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        vector<int> result = stones(n, a, b);
        for (int i = 0; i < result.size(); i++) {
            fout << result[i];
            if (i != result.size() - 1) {
                fout << " ";
            }
        }
        fout << "\n";
    }
    fout.close();
    return 0;
}
