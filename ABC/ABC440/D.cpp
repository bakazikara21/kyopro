#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e10;

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<ll> A(N),covered;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vector<pair<ll,ll>> st;
    for(int i = 0; i < N; i++){
        if(i == 0 and 1LL <= A[0]-1){
            st.push_back({1LL,A[0]-1});
            covered.push_back(A[0]-1);
        }
        else if(i > 0 and A[i-1]+1 <= A[i]-1){
            st.push_back({A[i-1]+1,A[i]-1});

            int siz = (int)covered.size();
            if(siz > 0) covered.push_back(A[i]-A[i-1]-1 + covered[siz-1]);
            else covered.push_back(A[i]-A[i-1]-1);
        }
    }
    st.push_back({A[N-1]+1,INF});

    int siz = (int)covered.size();
    if(siz > 0) covered.push_back(INF-A[N-1] + covered[(int)covered.size()-1]);
    else covered.push_back(INF-A[N-1]);
    siz++;

    for(int q = 0; q < Q; q++){
        ll X,Y;
        cin >> X >> Y;

        int t = upper_bound(st.begin(),st.end(),make_pair(X+1, -1LL)) - st.begin();
        ll cnt = 0;

        // Xがt-1番目の区間と被っているとき
        if(t > 0 and st.at(t-1).second >= X) cnt += st.at(t-1).second - X + 1;   // 区間にあるX以上の整数の個数

        // 残り Y-cnt 個の整数の先に答えがある
        if(cnt >= Y){
            //cout << "cnt = " << cnt << " st[t].first = " << st[t].first << endl;
            cout << X + Y - 1 << endl;
            continue;
        }

        // Y-cnt 以上の整数が見つかるまで二分探索でジャンプする
        int u = 0;
        if(t > 0){
            u = lower_bound(covered.begin() + t,covered.end(),(Y-cnt)+covered.at(t-1))-covered.begin();
            if(t > 0 and u > 0) cnt += covered[u-1]-covered.at(t-1);    // 直前までの区間の整数の個数を加算する
        }
        else{
            u = lower_bound(covered.begin() + t,covered.end(),(Y-cnt))-covered.begin();
            if(t > 0 and u > 0) cnt += covered[u-1]-covered.at(t-1);    // 直前までの区間の整数の個数を加算する
        }
        //cout << "count = " << cnt << " st.at(t).first = " << st.at(u).first << endl;
        cout << st.at(u).first + (Y-cnt)-1 << endl;
    }
}