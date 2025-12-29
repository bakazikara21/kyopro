#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> cnt(N);
    pair<int,int> winner = {0,0};   // {票数,num}
    for(int i = 0; i < M; i++){
        int A;
        cin >> A;
        A--;

        cnt[A]++;
        int maxi = winner.first;
        int num = winner.second;
        if(cnt[A] > maxi){
            winner.first = cnt[A];
            winner.second = A;
        }
        else if(cnt[A] == maxi and A <= num){
            winner.second = A;
        }
        cout << winner.second+1 << endl;
    }
}
