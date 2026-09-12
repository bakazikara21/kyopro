#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    string S,T;
    cin >> S >> T;
    set<char> taka;
    set<char> aoki;
    for(int i = 0; i < N; i++){
        taka.insert(S[i]);
    }
    for(int i = 0; i < M; i++){
        aoki.insert(T[i]);
    }
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        string w;
        cin >> w;

        bool tak = true;
        bool aok = true;
        int siz = (int)w.size();
        for(int j = 0; j < siz; j++){
            if(!taka.count(w[j])){
                tak = false;
            }
            if(!aoki.count(w[j])){
                aok = false;
            }
        }
        if(tak == aok){
            cout << "Unknown" << endl;
        }
        else if(tak == true){
            cout << "Takahashi" << endl;
        }
        else if(aok == true){
            cout << "Aoki" << endl;
        }
    }
}
