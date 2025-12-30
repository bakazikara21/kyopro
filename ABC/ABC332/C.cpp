#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    string S;
    cin >> N >> M >> S;

    int notag = M;
    int logo = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == '0'){
            notag = M;
            logo = ans;
        }
        if(S[i] == '1'){
            if(notag > 0) notag--;
            else if(logo > 0) logo--;
            else ans++; 
        }
        if(S[i] == '2'){
            if(logo > 0) logo--;
            else ans++;
        }
    }
    cout << ans << endl;
}
