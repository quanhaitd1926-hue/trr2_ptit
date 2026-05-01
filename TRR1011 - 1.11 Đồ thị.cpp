#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

class Graph{
	public:
		int dau, cuoi, w;
};

vector<int> ke[200005];
int a[205][205] = {0};
int n, m;

int main(){
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
	
	int t; cin >> t;
	cin >> n >> m;
	Graph g[105];
	for(int i = 1; i <= m; i++){
		cin >> g[i].dau >> g[i].cuoi >> g[i].w;
		a[g[i].dau][g[i].cuoi] = a[g[i].cuoi][g[i].dau] = g[i].w;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 0){
				if(i != j) a[i][j] = 10000;
			}
		}
	}
	if(t == 1){
		for(int i = 1; i <= n; i++){
			int cnt = 0;
			for(int j = 1; j <= n; j++){
				if(a[i][j] != 0 && a[i][j] != 10000){
					++cnt;
				}
			}
			cout << cnt << " ";
		}
	}
	else{
		cout << n << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}