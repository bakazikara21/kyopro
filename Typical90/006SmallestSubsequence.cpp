#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;
const ll mod = (ll)10007; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,K; cin >> N >> K;
    string S; cin >> S;
    vector<bool> used(N,false);
    set<int> id;
    for(int i = 0; i < K; i++){
        // 最初のK文字を答えの候補とする
        used[i] = true;
        id.insert(i);
    }
    int left = 0,right = 1;
    // while(right < K and S[left] <= S[right]){
    //     left++,right++;
    // }
    for(int i = K; i < N; i++){
        id.insert(i);
        used[i] = true;
        // K+1個の文字の中で一つ消す
        // 最初にS[left]>S[right]となるleftを消す
        
        auto ritr = id.lower_bound(right);
        while(ritr != prev(id.end()) and S[left] <= S[right]){
            left = right;
            ritr = next(ritr);
            if(ritr!=id.end()) right = *ritr;
            else right = i;
        }
        //cout << "i = " << i << " left = " << left << " right = " << right << endl;
        if(S[left] > S[right]){
            // S[left]を取っ払ってS[i]を追加する
            used[left] = false;
            id.erase(left);
            //cout << "erased = " << S[left] << endl;
            auto itr = id.lower_bound(right);
            left = right;
            if(itr!=id.begin()){
                auto pitr = prev(itr);
                left = *pitr;
            }
            else if(itr != prev(id.end())){
                itr = next(itr);
                right = *itr;
            }
            else right = i;
        }
        if((int)id.size() > K){
            // 一つも消していないとき
            // 末尾の要素を消す
            id.erase(i);
            used[i] = false;
            //cout << "erased = " << S[i] << endl;
            if(right == i) right++;
        }
    }
    for(int i = 0; i < N; i++){
        if(used[i]) cout << S[i];
    }
    cout << endl;
}
