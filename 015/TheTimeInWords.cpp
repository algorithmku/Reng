#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
 

 

    string result;
    const char* times[21] = { "", "one", "two", "three", "four", "five", "six", "seven", 
                             "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                             "quarter", "sixteen", "seventeen", "eightteen", "nineteen",
                             "twenty"};

    string link = " past ";
    if ( m > 30 )
    {
        ++h;
        m = 60 - m;
        link = " to ";
    }
    
    switch( m )
    {
    case 0:
        {
            result += times[ h ];
            result += " o' clock";
            return result;
        }
    case 1:
        {
            result += times[ m ];
            result += " minute";
            result += link;
            result += times [ h ];
            return result;
        }
    case 15:
        {
            result += times[ m ];
            result += link;
            result += times[ h ];
            return result;
        }
    case 30:
        {
            result += "half";
            result += link;
            result += times [ h ];
            return result;
        }
    }
 
    
    if ( m < 20 )
    {
        result += times[ m ];
       
        result += " minutes";
        result += link;
        result += times[ h ];
    }
    else
    {
        result += times[ 20 ];
        result += " ";
        result += times[ m - 20 ];
        result += " minutes";
        result += link;
        result += times[ h ];
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}

