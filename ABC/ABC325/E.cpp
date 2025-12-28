#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int main(){
    int N;
    ll A,B,C;
    cin >> N >> A >> B >> C;

    vector<vector<ll>> dist(N,vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dist[i][j];
        }
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0LL,0});
    
    vector<ll> train(N,INF),car(N,INF);
    train[N-1] = 0; // N-1からの最短距離
    car[0] = 0;   // 0からの最短距離
    vector<bool> usedtrain(N,false);
    vector<bool> usedcar(N,false);
    // ダイクストラ法かも train = 1, car = 0として考える
    while(!pq.empty()){
        auto [tim,v] = pq.top(); pq.pop();
      
        // 車のみで行くときの最小値を求める
        if(usedcar[v]) continue;

        usedcar[v] = true;
        for(int i = 1; i < N; i++){
            if(usedcar[i]) continue;

            car[i] = min(car[i],car[v]+dist[i][v]*A);
            pq.push({car[i],i});
        }
    }
    pq.push({0LL,N-1}); // 次はN-1からの電車での最短距離
    while(!pq.empty()){
        auto [tim,v] = pq.top(); pq.pop();
      
        // 車のみで行くときの最小値を求める
        if(usedtrain[v]) continue;

        usedtrain[v] = true;
        for(int i = 0; i < N-1; i++){
            if(usedtrain[i]) continue;

            train[i] = min(train[i],train[v]+dist[i][v]*B+C);
            pq.push({train[i],i});
        }
    }
    ll mini = INF;
    for(int i = 0; i < N; i++){
        mini = min(mini,car[i]+train[i]);
    }
    cout << mini << endl;
}
