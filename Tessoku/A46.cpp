#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int randint(int a, int b){
    // a以上、b以下のランダムな整数を返す関数
    return a + rand() % (b-a+1);
}
int main(){
    int N; cin >> N;
    vector<long double> X(N),Y(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }
    auto x = X[0];
    auto y = Y[0];
    vector<bool> used(N,false);
    used[0] = true;
    vector<int> path;
    path.push_back(1);
    while(true){
        long double mn = 1e9;
        int index = 0;
        bool flag = true;
        for(int i = 0; i < N; i++){
            if(used[i]) continue;
            flag = false;
            long double dist = (X[i]-x)*(X[i]-x) + (Y[i]-y)*(Y[i]-y);
            if(mn > dist){
                mn = dist;
                index = i;
            }
        }
        if(flag) break;
        used[index] = true;
        x = X[index];
        y = Y[index];
        path.push_back(index+1);
    }
    path.push_back(1);
    // pathには貪欲のパスが刻まれている
    auto dist = [&](int a, int b) {
        --a;
        --b;
        return hypotl(X[a] - X[b], Y[a] - Y[b]);
    };

    for(int i = 0; i < 4e6; i++){
        // 4e6回、ランダム2-optを行う
        int left = 0, right = 0;
        while(left == right){
            left = randint(1,N-1);
            right = randint(1,N-1);
        }
        if(left > right) swap(left,right);
        // leftからrightまでの順番をすべて逆にする
        // path[:left] + path[left:right:-1] + path[right:]
        long double before =
            dist(path[left - 1], path[left]) +
            dist(path[right], path[right + 1]);
    
        long double after =
            dist(path[left - 1], path[right]) +
            dist(path[left], path[right + 1]);
    
        if (after < before) {
            reverse(path.begin() + left, path.begin() + right + 1);
        }
    }
    for(int i = 0; i <= N; i++){
        cout << path[i] << endl;
    }
}
