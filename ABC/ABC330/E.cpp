#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // mexは0以上N以下である->N+1以上の数字はN+1として扱ってよい
    vector<int> cnt(N+2);
    for(int i = 0; i < N; i++){
        if(A[i] > N+1) A[i] = N+1;
        cnt[A[i]] += 1;
    }
    // cnt[i] = 0なる最小のiを高速に求めればよい
    set<int> st;
    for(int i = 0; i <= N; i++){
        if(cnt[i] == 0) st.insert(i);
    }
    for(int q = 0; q < Q; q++){
        int i; ll x;
        cin >> i >> x;
        i--;
        cnt[A[i]]--;
        if(cnt[A[i]] == 0) st.insert(A[i]);

        A[i] = min((ll)N+1,x);
        cnt[A[i]]++;
        if(st.count(A[i])) st.erase(A[i]);

        auto itr = st.begin();
        cout << *itr << endl;
    }
}
