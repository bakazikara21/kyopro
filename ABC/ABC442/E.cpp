#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    偏角ソートの練習問題らしいです。
*/
int main(){
    int N,Q;
    cin >> N >> Q;
    vector<pair<ll,ll>> pos(N);
    vector<vector<double>> shogen(5);
    for(int i = 0; i < N; i++){
        // N体のモンスターの座標
        ll X,Y;
        cin >> X >> Y;
        pos[i].first = X;
        pos[i].second = Y;

        if(X >= 0 and Y >= 0){
            // 第一象限
            shogen[1].push_back({1.0*X/Y});
        }
        if(X >= 0 and Y < 0){
            // 第2象限
            shogen[2].push_back({1.0*X/Y});
        }
        if(X < 0 and Y < 0){
            // 第3象限
            shogen[3].push_back({1.0*X/Y});
        }
        if(X < 0 and Y >= 0){
            // 第4象限
            shogen[4].push_back({1.0*X/Y});
        }
        //cout << "pos[" << i << "] = " << pos[i].first << " " << pos[i].second << endl;
    }
    sort(shogen[1].rbegin(),shogen[1].rend());    // 降順
    sort(shogen[2].rbegin(),shogen[2].rend());
    sort(shogen[3].begin(),shogen[3].end());
    sort(shogen[4].begin(),shogen[4].end());

    for(int q = 0; q < Q; q++){
        int A,B;
        cin >> A >> B;
        A--; B--;
        int Ax = pos[A].first;
        int Ay = pos[A].second;
        int Bx = pos[B].first;
        int By = pos[B].second;

        int dirA = 0;
        if(Ax >= 0 and Ay >= 0){
            // 第一象限
            dirA = 1;
        }
        if(Ax >= 0 and Ay < 0){
            // 第2象限
            dirA = 2;
        }
        if(Ax < 0 and Ay < 0){
            // 第3象限
            dirA = 3;
        }
        if(Ax < 0 and Ay >= 0){
            // 第4象限
            dirA = 4;
        }

        int dirB = 0;
        if(Bx >= 0 and By >= 0){
            // 第一象限
            dirB = 1;
        }
        if(Bx >= 0 and By < 0){
            // 第2象限
            dirB = 2;
        }
        if(Bx < 0 and By < 0){
            // 第3象限
            dirB = 3;
        }
        if(Bx < 0 and By >= 0){
            // 第4象限
            dirB = 4;
        }
        /*
        
        cout << "Ax = " << Ax << " Ay = " << Ay << " dirA = " << dirA << endl;
        cout << "Bx = " << Bx << " By = " << By << " dirB = " << dirB << endl;
        */
        double rotA = 1.0*Ax/Ay;
        double rotB = 1.0*Bx/By;
        if(dirA == dirB){
            int ta,tb;
            if(dirA <= 2){
                int ta = lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA,greater<double>())-shogen[dirA].begin();
                int tb = lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotB,greater<double>())-shogen[dirA].begin();
            }
            else{
                int ta = lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA)-shogen[dirA].begin();
                int tb = lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotB)-shogen[dirA].begin();
            }

            if(ta == tb){
                int cnt;
                if(dirA <= 2){
                    cnt = upper_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA,greater<double>())-lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA,greater<double>());
                }else{
                    cnt = upper_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA)-lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA);
                }
                cout << cnt << endl;
                continue;
            }
            if(tb > ta){
                int cnt;
                if(dirA <= 2){
                    cnt = upper_bound(shogen[dirA].begin(),shogen[dirA].end(),rotB,greater<double>())-lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA,greater<double>());
                }else{
                    cnt = upper_bound(shogen[dirA].begin(),shogen[dirA].end(),rotB)-lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA);
                }
                cout << cnt << endl;
                continue;
            }
            if(tb < ta){
                int cnt = N;
                if(dirA <= 2){
                    cnt -= lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA,greater<double>())-upper_bound(shogen[dirB].begin(),shogen[dirB].end(),rotB,greater<double>()); 
                }else{
                    cnt -= lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA)-upper_bound(shogen[dirB].begin(),shogen[dirB].end(),rotB);      
                }
                cout << cnt << endl;
                continue;
            }
        }
        else if((dirB-dirA) == 1 or (dirA == 4 and dirB == 1)){
            int cnt = 0,ta,tb;
            if(dirA <= 2){
                ta = lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA,greater<double>())-shogen[dirA].begin();
            }else{
                ta = lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA)-shogen[dirA].begin();
            }
            if(dirB <= 2){
                tb = upper_bound(shogen[dirB].begin(),shogen[dirB].end(),rotB,greater<double>())-shogen[dirB].begin();
            }else{
                tb = upper_bound(shogen[dirB].begin(),shogen[dirB].end(),rotB)-shogen[dirB].begin();
            }
            cnt += (int)shogen[dirA].size()-ta; 
            cnt += tb;
            cout << cnt << endl;
            continue;
        }
        else{
            vector<int> path;
            int pa = dirA;
            while(pa%4+1 != dirB){
                path.push_back(pa%4 + 1);
                pa++;
            }
            int cnt = 0,ta,tb;
            for(int dir : path){
                cnt += (int)shogen[dir].size();
            }
            if(dirA <= 2){
                ta = lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA,greater<double>())-shogen[dirA].begin();
            }else{
                ta = lower_bound(shogen[dirA].begin(),shogen[dirA].end(),rotA)-shogen[dirA].begin();
            }
            if(dirB <= 2){
                tb = upper_bound(shogen[dirB].begin(),shogen[dirB].end(),rotB,greater<double>())-shogen[dirB].begin();
            }else{
                tb = upper_bound(shogen[dirB].begin(),shogen[dirB].end(),rotB)-shogen[dirB].begin();
            }
            cnt += (int)shogen[dirA].size()-ta; 
            cnt += tb;
            cout << cnt << endl;
            continue;
        }
    }
}
