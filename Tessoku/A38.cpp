#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
int main(){
  int D,N;
  cin >> D >> N;
  vector<int> ika(D+1,inf);
  vector<int> ijo(D+1,inf);
  vector<int> dif(24+1);
  for(int i = 0; i < N; i++){
    int L,R,H;
    cin >> L >> R >> H;
    ijo[L] = min(ijo[L],H);
    ika[R] = min(ika[R],H);
  }
  int ans = 0;
  for(int d = 1; d <= D; d++){
    if(ijo[d] < inf){
        dif[ijo[d]] += 1;
    }
    bool ok = false;
    int h = 10;
    for(h = 10; h <= 24; h++){
        if(dif[h] > 0){
            ok = true;
            break;
        }
    }
    if(ok){
        ans += h;
    }else{
        ans += 24;
    }
    if(ika[d] < inf){
        dif[ika[d]] -= 1;
    }
  }
  cout << ans << endl;
}