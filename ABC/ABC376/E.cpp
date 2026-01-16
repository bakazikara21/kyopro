#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e17;
int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int N,K;
        cin >> N >> K;
        vector<ll> A(N),B(N);
        vector<pair<ll,int>> absort(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        for(int i = 0; i < N; i++){
            cin >> B[i];
            absort[i] = {A[i],i};
        }
        sort(absort.begin(),absort.end());
        set<pair<ll,int>> st;    // sizeをKに保ったまま、最大最小を追加、削除
        ll sum = 0;
        ll ans = INF;
        for(int i = 0; i < K; i++){
            // 最初のK個は問答無用で加算する
            auto [a,bid] = absort[i];
            sum += B[bid];
            st.insert({B[bid],bid});
            if(i == K-1){
                ans = sum*a;
            }
        }
        //cout << "sum = " << sum << endl;
        for(int i = K; i < N; i++){
            // K番目から計算開始
            auto [a,bid] = absort[i];
            // aを選ぶとき、sum_bの値は一意に定まる

            // 最大の要素を消して、代わりにB[bid]を追加する
            auto itr = prev(st.end());
            sum -= itr->first;
            sum += B[bid];
            st.erase(itr);
            st.insert({B[bid],bid});

            ans = min(ans,sum*a);
        }
        cout << ans << endl;
    }
}
