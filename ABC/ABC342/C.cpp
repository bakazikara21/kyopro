#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    vector<int> hitomoji(26);
    for(int i = 0; i < 26; i++){
        hitomoji[i] = i;
    }
  
    for(int q = 0; q < Q; q++){
        char c,d;
        cin >> c >> d;

        int from = c-'a';
        int to = d-'a';

        for(int i = 0; i < 26; i++){
            if(hitomoji[i] == from){
                hitomoji[i] = to;
            }
        }
    }
    for(int i = 0; i < N; i++){
        int from = S[i]-'a';
        int to = hitomoji[from];
        S[i] = 'a'+to;
    }
    cout << S << endl;
    /*
    for(int i = 0; i < 26; i++){
        cout << char('a'+i) << " -> " << char('a'+hitomoji[i]) << endl; 
    }
    */
}
