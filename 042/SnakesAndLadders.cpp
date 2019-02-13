#include <bits/stdc++.h>

using namespace std;

struct queueEntry 
{ 
    int v;     // Vertex number 
    int dist;  // Distance of this vertex from source 
}; 

int getMinDiceThrows( vector< int > move, int N )
{
    bool *visited = new bool[ N ];
    for( int i = 0; i < N; ++i )
    {
        visited[ i ] = false;
    }

    queue< queueEntry > q;

    visited[0] = true;
    queueEntry s = { 0, 0 };
    q.push( s );

    queueEntry qe;

    bool is_success = false;
    while( !q.empty() )
    {
        qe = q.front();
        int v = qe.v;

        if ( v == N-1 ){
            is_success = true;
            break;
        }

        q.pop();

        for( int j = v+1; j <= (v+6) && j<N; ++j )
        {
            if ( !visited[j] )
            {
                queueEntry a;
                a.dist = (qe.dist + 1 );
                visited[j] = true;

                if ( move[j] != -1 )
                {
                     a.v = move[j];
                }
                else
                {
                    a.v = j;
                }

                q.push(a);
            }
        }
    }
    return is_success ? qe.dist : -1;
}
// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {

    int N = 100;
    vector< int > moves( N, -1 );

    for( int i = 0; i < ladders.size(); ++i )
    {
        moves[ ladders[i][0] - 1  ] = ladders[i][1]-1;
    }

    for( int i = 0; i < snakes.size(); ++i ) 
    {
        moves[ snakes[i][0]- 1 ] = snakes[i][1]-1;
    }
    return getMinDiceThrows( moves, N );
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

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}