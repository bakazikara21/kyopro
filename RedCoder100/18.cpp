#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const int inf = 1e9;
const ll mod = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> S(n);
    for(int i = 0; i < n; i++) cin >> S[i];

    int q;
    cin >> q;
    int ans = 0;
    for(int i = 0; i < q; i++){
        int T;
        cin >> T;
        // Sは昇順に並んでいるので二分探索可能->O(qlog(N))
        int left = 0, right = n;
        int med = (right+left)/2;
        while((right-left) > 1){
            if(S[med] > T){
                right = med;
            }else{
                left = med;
            }
            med = (right+left)/2;
        }
        if(S[left] == T) ans++;
    }
    cout << ans << endl;
}