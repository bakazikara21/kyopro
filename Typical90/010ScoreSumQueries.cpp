#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double PI = acosl(-1);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> sumone(N+1),sumtwo(N+1);
    for(int i = 0; i < N; i++){
        int C,P; cin >> C >> P;
        if(C == 1){
            sumone[i+1] = P;
        }
        else sumtwo[i+1] = P;
        sumone[i+1] += sumone[i];
        sumtwo[i+1] += sumtwo[i];
    }
    int Q; cin >> Q;
    for(int q = 0; q < Q; q++){
        int L,R; cin >> L >> R;
        cout << sumone[R]-sumone[L-1] << " " << sumtwo[R]-sumtwo[L-1] << endl;
    }
}
