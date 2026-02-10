#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)2e18;
const int inf = (int)1e9;

int main(){
    int N;
    cin >> N;

    cout << fixed << setprecision(15);
    long double sum = 0.0;
    long double x = 0.0, y = 0.0;
    for(int i = 0; i < N; i++){
        long double X,Y;
        cin >> X >> Y;
        sum += sqrt((x-X)*(x-X)+(y-Y)*(y-Y));
        x = X;
        y = Y;
    }
    sum += sqrt((x)*(x)+(y)*(y));
    cout << sum << endl;
}
