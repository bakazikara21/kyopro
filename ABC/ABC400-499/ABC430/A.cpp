#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,A,B;
    string S;
    cin >> N >> A >> B >> S;

    int rmin = 0,rmax = 0;
    int amin = 0, bmin = 0;
    int amax = 0, bmax = 0;
    ll ans = 0;
    for(int left = 0; left < N; left++){
        while(amin < A and rmin < N){
            if(S[rmin] == 'a'){
                amin++;
            }else{
                bmin++;
            }
            rmin++;
        }
        if(amin < A and rmin >= N) break;
        rmin--;
        //cout << rmin << endl;
        
        if(amin >= A and bmin < B){
            rmax = max(rmax,rmin);
            amax = max(amax,amin);
            bmax = max(bmax,bmin);
            while(bmax < B and rmax < N){
                if(S[rmax] == 'a'){
                    amax++;
                }else{
                    bmax++;
                }
                
                if(bmax >= B){
                    bmax--;
                    break;
                }
                rmax++;
            }
            rmax--;
            //rmax = min(rmax, N-1);
            //cout << left << endl;
            //cout << rmax << endl;
            ans += rmax-rmin + 1;
            //cout << ans << endl;
            rmax++;
        }
        //cout << amin << " " << bmin << " " << left << " " << rmin << " " << rmax << endl;
        if(S[left] == 'a'){
            amin--;
            amax--;
        }else{
            bmin--;
            bmax--;
        }
        //cout << a << " " << b << " " << left << " " << rmin << " " << rmax << endl;
        rmin++;
    }
    cout << ans << endl;
}