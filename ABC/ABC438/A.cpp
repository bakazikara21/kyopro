#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int D,F;
    cin >> D >> F;

    int day = F;
    while(day <= D){
        day += 7;
    }
    day %= D;
    if(day == 0) day += 7;
    cout << day << endl;
}
