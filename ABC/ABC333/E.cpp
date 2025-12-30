#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    vector<int> mon_pot(N);   // 各タイプのモンスター引くポーション 後ろから貪欲に拾えばよいかも
    vector<int> t(N),x(N);   // 後ろから貪欲に拾えばよいかも
    vector<int> ans;
    bool ok = true;
    for(int i = 0; i < N; i++){
        cin >> t[i] >> x[i];
        x[i]--;
    }
    for(int i = N-1; i >= 0; i--){
        int num = t[i];
        int type = x[i];

        if(num == 1){
            if(mon_pot[type] > 0){
                ans.push_back(1);
                mon_pot[type]--;
            }
            else{
                ans.push_back(0);
            }
        }
        if(num == 2){
            // モンスターと遭遇
            mon_pot[type]++;
        }
    }
    reverse(ans.begin(),ans.end());
    int K = 0;
    int cnt = 0;
    int id = 0;
    for(int i = 0; i < N; i++){
        int num = t[i];

        if(num == 1){
            if(ans[id]) cnt++;
            id++;
        }
        if(num == 2){
            cnt--;
        }
        K = max(K,cnt);
        //cout << "num = " << num << " i = " << i << " id = " << id << endl;
    }
    for(int i = 0; i < N; i++){
        if(mon_pot[i] > 0){
            ok = false;
            break;
        }
    }
   
    if(ok){
        cout << K << endl;
        int siz = (int)ans.size();
        for(int i = 0; i < siz; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}
