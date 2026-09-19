#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,M; ll K; cin >> N >> M >> K;
    ll X,Y; cin >> X >> Y;
    vector<ll> A(N),B(M),sumA(N+1);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int ans = 0;
    int left = 0;
    for(int i = 0; i < N; i++){
        // 1ドル紙幣, X枚がなくなるまで買い続ける
        if(A[i] <= X){
            ans++;
            X -= A[i];
            left = i+1;
        }
    }
    for(int i = left; i < N; i++){
        sumA[i+1] = sumA[i]+A[i];
    }
    int add = 0;
    ll money = X + K*Y;   

    // Bの商品を0個買うとき、
    // cout << "ans = " << ans << endl;
    // cout << "left = " << left << endl;
    int num = upper_bound(sumA.begin(),sumA.end(),money)-sumA.begin()-left-1;
    // cout << " Bの商品を0個買うとき、 num = " << num << endl;
    add = max(add,num);

    for(int i = 0; i < M; i++){
        // Bの商品を i+1個　買うとき
        ll r = (B[i]+K-1)/K;
        if(r <= Y){
            // 購入可能
            money -= K*r;
            money += (K*r - B[i]);
            Y -= r;
            num = upper_bound(sumA.begin(),sumA.end(),money)-sumA.begin()-left-1;
            add = max(add,num+i+1);
            // cout << " Bの商品を" << i+1 << "個買うとき、 num = " << num << endl;
        }
    }
    cout << ans + add << endl;
}
