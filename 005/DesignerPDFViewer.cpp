
#include <bits/stdc++.h>

using namespace std;
// 97 = 'a'
int designerPdfViewer(vector <int> h, string word) {
    // Complete this function
    int max_size = 0;
    for( int i = 0; i < word.size(); ++i )
    {
        int size = h [ (int)word[i] - 97 ];
        if ( max_size < size )
        {
            max_size = size;
        }
    }
    return max_size * word.size() ;
    
}

int main() {
    vector<int> h(26);
    for(int h_i = 0; h_i < 26; h_i++){
       cin >> h[h_i];
    }
    string word;
    cin >> word;
    int result = designerPdfViewer(h, word);
    cout << result << endl;
    return 0;
}