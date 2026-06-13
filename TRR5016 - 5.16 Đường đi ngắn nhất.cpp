#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int d[205][205];
int n;
int parent[205][205];

void nhap(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> d[i][j];
			if(i != j && d[i][j] == 10000){
				d[i][j] = 1e9;
			}
			parent[i][j] = i;
		}
	}
}

void Floyd(){
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(d[i][k] < 1e9 && d[k][j] < 1e9){
					if(d[i][j] > d[i][k] + d[k][j]){
						d[i][j] = d[i][k] + d[k][j];
						parent[i][j] = parent[k][j];
					}
				}
			}
		}
	}
}

void printPath(int u, int v){
    if(u == v){
        cout << u;
        return;
    }
    printPath(u, parent[u][v]);
    cout << " " << v;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
	
	nhap();
	Floyd();

	int maxDis = -1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i != j && d[i][j] < 1e9){
				maxDis = max(maxDis, d[i][j]);
			}
		}
	}
	if(maxDis == -1){
		cout << "0\n";
	}
	else{
		vector<pair<int, int>> res;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i != j && d[i][j] == maxDis){
					res.push_back({i, j});
				}
			}
		}
		sort(res.begin(), res.end());
		auto [u, v] = res[0];
		cout << u << " " << v << " " << maxDis << "\n";
		printPath(u, v);
	}
	return 0;
}