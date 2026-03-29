#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int toInt(string S){
    int M = (int)S.size();
    int ret = 0;
    for(int i = 0; i < M; i++){
        ret = 10*ret+(S[i]-'0'); 
    }
    return ret;
}
int main(){
    int N; cin >> N;
    int a = 1;
    while(a < N){
        cout << a << endl;
        a *= 2;
    }
    /*
        整数の種類は
        1
        2
        4
        8
        16
        32
        64
        128
        256
        512
        1024
        2048
        4096
        8192
        16384
        32768
        65536
        131072
        262144
        524288
        1048576
        2097152
        4194304
        8388608
        16777216
        33554432
        67108864
        134217728
        268435456
        536870912
        の30種類のみ
    */
    vector<string> num = {
        "1",
        "2",
        "4",
        "8",
        "16",
        "32",
        "64",
        "128",
        "256",
        "512",
        "1024",
        "2048",
        "4096",
        "8192",
        "16384",
        "32768",
        "65536",
        "131072",
        "262144",
        "524288",
        "1048576",
        "2097152",
        "4194304",
        "8388608",
        "16777216",
        "33554432",
        "67108864",
        "134217728",
        "268435456",
        "536870912"
    };
    set<int> st;
    int K = (int)num.size();
    vector<int> siz(K);
    for(int k = 0; k < K; k++){
        int m = (int)num[k].size();
        siz[k] = m;
    }
    auto dfs = [&](auto self, string S)->void{
        st.insert(toInt(S));
        int M = (int)S.size();
        for(int k = 0; k < K; k++){
            // 次に選ぶ文字列
            if(siz[k]+M >= 10) break;
            self(self,num[k]+S);
        }
    };
    for(int k = 0; k < K; k++){
        // num[k]スタートの良い整数の全探索
        dfs(dfs,num[k]);
    }
    auto itr = st.begin();
    for(int i = 1; i <= N; i++){
        if(i == N) cout << *itr << endl;
        else itr++;
    }
}
