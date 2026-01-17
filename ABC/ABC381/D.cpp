#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N),cnt(N+1);
    set<int> st;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    int ans = 0;
    // leftが偶数のときのansの最大値を求めに行く
    int left = 0, right = 1;
    while(left+1 < N){
        // 左端がleftのときのrの最大を求める
        right = max(left+1,right);
        if(A[right] != A[left] and left+1 == right){
            left += 2;
            continue;
        }
        st.insert(A[left]);
        while(right+2 < N and A[right+1] == A[right+2] and !st.count(A[right+1])){
            st.insert(A[right+1]);
            right += 2;
        }
        ans = max(ans,right-left+1);
        st.erase(A[left]);
        left += 2;
    }
    // leftが奇数のときのansの最大値を求めに行く
    left = 1;
    right = 2;
    st.clear();
    while(left+1 < N){
        // 左端がleftのときのrの最大を求める
        right = max(left+1,right);
        if(A[right] != A[left] and left+1 == right){
            left += 2;
            continue;
        }
        st.insert(A[left]);
        while(right+2 < N and A[right+1] == A[right+2] and !st.count(A[right+1])){
            st.insert(A[right+1]);
            right += 2;
        }
        ans = max(ans,right-left+1);
        st.erase(A[left]);
        left += 2;
    }
    cout << ans << endl;
}
