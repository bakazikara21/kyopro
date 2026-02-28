#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18;
int main(){
    // setを使ってsortをやめましょう
    int N;  cin >> N;
    set<ll> st;
    st.insert(0);
    ll sum = 0;
    for(int i = 0; i < N; i++){
        ll X; cin >> X;
        auto itr = st.lower_bound(X);   // Xnext
        ll Xnext = INF;
        ll Xnene = INF;
        ll Xprev = INF;
        ll Xprpr = INF;
        if(itr != st.end()){
            Xnext = *itr;
            itr = next(itr);
            if(itr != st.end()){
                Xnene = *itr;
            }
            itr = prev(itr);
        }
        if(itr != st.begin()){
            itr = prev(itr);
            Xprev = *itr;
            if(itr != st.begin()){
                itr = prev(itr);
                Xprpr = *itr;
            }
        }
        if(Xprev < INF and Xnext < INF){
            sum += min(Xnext-X,X-Xprev);    // Xを中心としたdi
        }
        else if(Xprev < INF){
            sum += X-Xprev;
        }
        else if(Xnext < INF){
            sum += Xnext-X;
        }
        if(Xprev < INF){
            if(Xprpr < INF){
                sum -= min(Xnext-Xprev,Xprev-Xprpr);    // Xprev中心としたdi
                sum += min(X-Xprev,Xprev-Xprpr);
            }
            else if(Xnext < INF){
                sum -= Xnext-Xprev;
                sum += X-Xprev;
            }
            else sum += X-Xprev;
        }
        if(Xnext < INF){
            if(Xnene < INF and Xprev < INF){
                sum -= min(Xnene-Xnext,Xnext-Xprev);    // Xnext中心としたdi
                sum += min(Xnene-Xnext,Xnext-X);
            }
            else if(Xnene < INF){
                sum -= Xnene-Xnext;
                sum += min(Xnene-Xnext,Xnext-X);
            }
            else if(Xprev < INF){
                sum -= Xnext-Xprev;
                sum += Xnext-X;
            }
            else sum += Xnext-X;
        }

        st.insert(X);
        cout << sum << endl;
    }
}