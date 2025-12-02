#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = (int)1e9;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> dp(N);  // 最後の要素がA[i]である部分列のうち最長
    vector<int> L(N+1,inf); // 長さxの部分列のうち、最後の要素として考えられる最小値
    dp[0] = 1;
    L[0] = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(i == 0){
            L[1] = A[i];
            continue;
        }else{
            //int t = lower_bound(L.begin(),L.begin()+i,A[i])-L.begin();
            int left = 0,right = i+1;
            int mid = (right+left)/2;
            while((right-left) > 1){
                if(A[i] <= L[mid]){
                    right = mid;
                }else{
                    left = mid;
                }
                mid = (right+left)/2;
            }
            if(left >= 0 and left < i+1){
                dp[i] = L[left]+1;
                L[dp[i]] = min(L[dp[i]],A[i]);
            }
        }
    }
    int maxi = 0;
    for(int i = 0; i < N; i++){
        maxi = max(maxi,dp[i]);
    }
    cout << maxi << endl;
}
