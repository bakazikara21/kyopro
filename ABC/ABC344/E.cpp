#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct List{
  ll pre;   // x の直前にいる整数ノード-> いなかったらx
  ll nxt;   // x の直後にいる整数ノード-> いなかったらx
};

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    unordered_map<ll,List> mp;
    ll start = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(i == 0){
          start = A[i];
          mp[start].pre = start;
        } 
        else {
            mp[A[i-1]].nxt = A[i];
            mp[A[i]].pre = A[i-1];
        }
        if(i == N-1){
          mp[A[i]].nxt = A[i];
        }
    }
    int Q;
    cin >> Q;
    for(int q = 0; q < Q; q++){
        int num;
        cin >> num;

        if(num == 1){
            ll x,y;
            cin >> x >> y;
            // A内の要素x の直後にyを挿入する
            if(mp[x].nxt != x){
                // xの後ろがいるのならば
                ll to = mp[x].nxt;
                mp[x].nxt = y;
                mp[y].pre = x;

                mp[y].nxt = to;
                mp[to].pre = y;
            }
            else {
                mp[x].nxt = y;
                mp[y].nxt = y;
                mp[y].pre = x;
            }
        }
        if(num == 2){
            ll x;
            cin >> x;
            // A内の要素x を削除する
            if(x == start){
                start = mp[x].nxt;
                mp[start].pre = start;
            }
            else if(mp[x].nxt == x){
                // xの後ろがいないとき
                ll from = mp[x].pre;   // xの直前にいるやつ
                mp[from].nxt = from;
            }
            else{
                // 前も後ろもいるとき->前と後ろをつなげばよい
                ll from = mp[x].pre;
                ll to = mp[x].nxt;
                mp[from].nxt = to;
                mp[to].pre = from;
            }
            mp[x].pre = x;
            mp[x].nxt = x;
        }
        // Aの各要素は相異なることが保証されている
    }
    cout << start << " ";
    while(mp[start].nxt != start){
        // 後ろがいるかぎり
        start = mp[start].nxt;
        cout << start << " ";
    }
    cout << endl;
}
