#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;

int main(){
    int N,W;
    cin >> N >> W;

    vector<tuple<int,int,int>> pairs(N);
    for(int i = 0; i < N; i++){
        // 左端からX列目、下からY行目
        int X,Y;
        cin >> X >> Y;

        // ブロックiが列X界隈の下から何個目かを記録するためにソートしたい
        pairs[i] = {X,Y,i};
    }
    /*
    以下、前処理
    */
    sort(pairs.begin(),pairs.end());
    vector<int> column(W+1);    // i列目のブロックの個数
    vector<int> row(N+1);   // 下からi番目界隈のYの最大値
    vector<int> block(N);   // ブロックiが下から何個目の界隈か
    for(int i = 0; i < N; i++){
        auto [x,y,id] = pairs[i];

        column[x]++;
        block[id] = column[x];
        row[column[x]] = max(row[column[x]],y);
    }
    int mini = N+1; // 列に含まれるブロックの個数の最小値
    for(int i = 0; i < W; i++){
        mini = min(mini,column[i+1]);
    }
    /*
    ここから、解答パート
    */
    int Q;
    cin >> Q;
    for(int q = 0; q < Q; q++){
        int T,A;
        cin >> T >> A;
        A--;
        // ブロックAが消滅しているか否か
        // 存在するならばYes
        if(T >= row[block[A]] and mini >= block[A]){
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
}