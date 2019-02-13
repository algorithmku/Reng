#include <bits/stdc++.h>

using namespace std;

int main() {
    int hh, mm, ss ;
    string time_format;
    time_format.resize(2);
    scanf("%d:%d:%d%s", &hh, &mm, &ss, &time_format[0] ) ;
        
    if ( time_format.compare( "PM" ) == 0 && hh!=12 ) hh += 12 ;
    if ( time_format.compare( "AM" ) == 0 && hh==12 ) hh = 0 ;
        
    printf("%02d:%02d:%02d", hh, mm, ss) ;
    return 0;
}