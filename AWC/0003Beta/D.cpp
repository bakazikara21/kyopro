#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N,K; ll M;
    cin >> N >> K >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    ll sum = 0, ans = 0;
    int right = -1;
    for(int i = 0; i <= N-K; i++){
        // 左端固定
        while(right+1 < N and (right-i+1) < K){
            sum += A[right+1];
            right++;
        }
        while(right+1 < N and sum < M){
            sum += A[right+1];
            right++;
        }
        if(sum >= M){
            ans += (ll)N - right;
        }
        //cout << "right = " << right << " sum = " << sum << endl;
        sum -= A[i];
    }
    cout << ans << endl;
}
