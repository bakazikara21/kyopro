#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    // setを使ってsortをやめましょう
    int N;
    cin >> N;
    vector<ll> X(N+1);
    vector<ll> pos;
    map<ll,ll> d;
    ll sum = 0;
    X[0] = 0;
    pos.push_back(0);
    for(int i = 1; i <= N; i++){
        cin >> X[i];
        // i+1人立っている
        if(i == 1){
            d[0] = X[i];
            d[X[i]] = X[i];
            sum += 2*X[i];
        }else{
            int k = pos.size();
            int id = upper_bound(pos.begin(),pos.end(),X[i])-pos.begin();
            //cout << id << " ";
            if(id == k){
                // X[i]が一番大きいとき
                sum += X[i]-pos[k-1];
                if(d[pos[id-1]] > X[i]-pos[id-1]){
                    sum -= (d[pos[id-1]] - (X[i]-pos[id-1]));
                    d[pos[id-1]] = X[i]-pos[id-1];
                }
                d[X[i]] = X[i]-pos[k-1];
            }else if(id > 0){
                // X[i]が二人の間になるとき
                sum += min(pos[id]-X[i],X[i]-pos[id-1]);
                if(d[pos[id]] > pos[id]-X[i]){
                    sum -= (d[pos[id]] - (pos[id]-X[i]));
                    d[pos[id]] = pos[id]-X[i];
                }
                if(d[pos[id-1]] > X[i]-pos[id-1]){
                    sum -= (d[pos[id-1]] - (X[i]-pos[id-1]));
                    d[pos[id-1]] = X[i]-pos[id-1];
                }
                d[X[i]] = min(pos[id]-X[i],X[i]-pos[id-1]);
            }else{
                // X[i]が一番小さいとき
                sum += pos[id]-X[i];
                if(d[pos[id]] > pos[id]-X[i]){
                    sum -= (d[pos[id]] - (pos[id]-X[i]));
                    d[pos[id]] = pos[id]-X[i];
                }
                d[X[i]] = pos[id]-X[i];
            }
        }
        pos.push_back(X[i]);
        sort(pos.begin(),pos.end());
        cout << sum << endl;
    }
}