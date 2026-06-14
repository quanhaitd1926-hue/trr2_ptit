#include <bits/stdc++.h>
using namespace std;

int V;
int a[105][105], b[105][105];

struct edge{
    int u, v;
    bool operator < (const edge &other) const {
        if(u < other.u) return true;
        if(u == other.u && v < other.v) return true;
        return false;
    }
};

vector<vector<int>> ad;
void case1(){
    ad.assign(V+5, vector<int>());
    for(int i = 1; i <= V; i++){
        int k, v;
        cin >> k;
        while(k--){
            cin >> v;
            ad[i].push_back(v);
        }
    }
    for(int i=1; i<=V; i++){
        cout << ad[i].size() << " ";
    }
    cout << "\n";
}

vector<edge> ed;
void case2(){
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    ed.clear();
    for(int i=1; i<=V; i++){
        int k, v;
        cin >> k;
        while(k--){
            cin >> v;
            a[i][v] = a[v][i] = 1;
        }
    }
    for (int i = 1; i <= V; i++) {
        for (int j = i + 1; j <= V; j++) {
            if (a[i][j] == 1) {
                ed.push_back({i, j});
            }
        }
    }
    int m = ed.size();
    for(int k=0; k<m; k++){
        int u = ed[k].u;
        int v = ed[k].v;
        b[u][k+1] = b[v][k+1] = 1;
    }
    cout << V << " " << m << "\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    int T; cin >> T;
    cin >> V;
    if(T == 1){
        case1();
    }
    else if(T == 2){
        case2();
    }
    return 0;
}