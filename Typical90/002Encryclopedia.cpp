#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)10007; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    if((N%2) == 1){
        cout << endl;
        return 0;
    }
    vector<int> pos(N,0);
    for(int i = N/2; i < N; i++) pos[i]=1;

    do{
        bool ok = true;
        int zero = 0;
        for(int i = 0; i < N; i++){
            if(pos[i]==0) zero++;
            else zero--;
            if(zero < 0){
                ok = false;
                break;
            }
        }
        if(ok){
            for(int i = 0; i < N; i++){
                if(pos[i] == 0){
                    cout << '(';
                }
                else cout << ')';
            }
            cout << endl;
        }
    }while(next_permutation(pos.begin(),pos.end()));
}
