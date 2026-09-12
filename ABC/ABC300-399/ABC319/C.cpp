#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N = 3;
    vector<int> c(N*N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c[i*N+j];
        }
    }
    int num = 0;    // がっかりする場合の数
    vector<int> pos(N*N);
    for(int i = 0; i < N*N; i++){
        pos[i] = i;
    }

    // 選ぶ順番を全探索
    do{ 
        vector<int> row(N),column(N),cross(2);
        vector<int> rowfirst(N,-1),columnfirst(N,-1),crossfirst(2,-1);
        
        for(int i = 0; i < N*N; i++){
            // 3つ連続してることはあり得ない
            int rowid = pos[i]/3;
            int colid = pos[i]%3;

            row[rowid]++;
            if(row[rowid] == 1){
                rowfirst[rowid] = c[pos[i]];
            }else if(row[rowid] == 2 and c[pos[i]] == rowfirst[rowid]){
                num++;
                break;
            }
            column[colid]++;
            if(column[colid] == 1){
                columnfirst[colid] = c[pos[i]];
            }else if(column[colid] == 2 and c[pos[i]] == columnfirst[colid]){
                num++;
                break;
            }

            if(pos[i] == 4){
                cross[0]++;
                cross[1]++;
                if(cross[0] == 1){
                    crossfirst[0] = c[pos[i]];
                }
                if(cross[0] == 2 and crossfirst[0] == c[pos[i]]){
                    num++;
                    break;
                }
                if(cross[1] == 1){
                    crossfirst[1] = c[pos[i]];
                }
                if(cross[1] == 2 and crossfirst[1] == c[pos[i]]){
                    num++;
                    break;
                }
            }else if(pos[i]%4 == 2){
                cross[1]++;
                if(cross[1] == 1){
                    crossfirst[1] = c[pos[i]];
                }
                if(cross[1] == 2 and crossfirst[1] == c[pos[i]]){
                    num++;
                    break;
                }
            }else if(pos[i]%4 == 0){
                cross[0]++;
                if(cross[0] == 1){
                    crossfirst[0] = c[pos[i]];
                }
                if(cross[0] == 2 and crossfirst[0] == c[pos[i]]){
                    num++;
                    break;
                }
            }
        }
    }while(next_permutation(pos.begin(),pos.end()));
    double ans = 1.0*num / 362880.0;
    cout << fixed << setprecision(12);
    cout << 1-ans << endl;
}