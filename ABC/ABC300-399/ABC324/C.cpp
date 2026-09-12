#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    string T;
    cin >> N >> T;

    vector<int> ans;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;

        if(S == T){
            ans.push_back(i+1);
        }
        else if(S.size() == T.size()){
            int err = 0;
            for(int t = 0; t < (int)T.size(); t++){
                if(S[t] != T[t]){
                    err++;
                }
            }
            if(err == 1){
                ans.push_back(i+1);
            }
        }
        else if((int)S.size()-(int)T.size() == 1){   
            // Tの文字が順番通りに全部含まれているかどうか
            int correct = 0;
            int s = 0;  // 尺取り
            for(int t = 0; t < (int)T.size(); t++){
                char Tc = T[t];
                while(s < S.size() and S[s] != Tc){
                    s++;
                }
                if(s < S.size() and S[s] == Tc){
                    correct++;
                    s++;
                }
            }
            if(correct == (int)T.size()){
                ans.push_back(i+1);
            }
        }
        else if((int)T.size()-(int)S.size() == 1){   
            // Sの文字が順番通りに全部含まれているかどうか
            int correct = 0;
            int t = 0;  // 尺取り
            for(int s = 0; s < (int)S.size(); s++){
                char Sc = S[s];
                while(t < T.size() and T[t] != Sc){
                    t++;
                }
                if(t < T.size() and T[t] == Sc){
                    correct++;
                    t++;
                }
            }
            if(correct == (int)S.size()){
                ans.push_back(i+1);
            }
        }
    }
    int K = (int)ans.size();
    cout << K << endl;
    for(int i = 0; i < K; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
