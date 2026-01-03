#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    set<int> st;
    bool ok = true;
    int n = N;
    while(n != 1){
        int sum = 0;
        if(st.count(n)){
            ok = false;
            break;
        }
        else st.insert(n);
        while(n > 0){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        n = sum;
        //cout << n << endl;
    }
    if(ok){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
