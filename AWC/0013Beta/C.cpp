#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; cin >> N >> K; K--;
    int target;
    vector<int> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
        if(i == K) target = S[i];
    }
    sort(S.begin(),S.end());
    for(int i = 0; i < N; i++){
        if(S[i] == target){
            cout << i << endl;
            break;
        }
    }
}
