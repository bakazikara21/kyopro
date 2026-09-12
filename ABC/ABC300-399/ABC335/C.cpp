#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,Q;
    cin >> N >> Q;

    map<char,int> mp;
    mp['R'] = 0;
    mp['L'] = 1;
    mp['U'] = 2;
    mp['D'] = 3;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};

    int last = N-1;
    vector<pair<int,int>> movement1(N);
    for(int i = 0; i < N; i++){
        movement1[i] = {N-i,0};
    }
    int cnt = 0;
    for(int q = 0; q < Q; q++){
        int num;
        cin >> num;

        if(num == 1){
            char C;
            cin >> C;

            int dir = mp[C];

            auto [x,y] = movement1[last];
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            movement1.push_back({nx,ny});
            last++;
            cnt++;
        }
        if(num == 2){
            int p;
            cin >> p;
            // N-num+cnt
            auto [x,y] = movement1[N-p+cnt];
            cout << x << " " << y << endl;
        }
    }
}
