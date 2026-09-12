#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        if (i % 3 == 0)
            cout << "Fizz" << endl;
        else
            cout << i << endl;
    }
}
