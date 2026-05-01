#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m, S, T;
vector<int> ke[200005];
int visited[200005] = {0};
int parent[200005];
int a[205][205];

void nhap(){
	cin >> n >> S >> T;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				ke[i].push_back(j);
				//ke[j].push_back(i);
			}
		}
	}
}

void DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			parent[v] = u;
			DFS(v);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);
	
	int t; cin >> t;
	nhap();
	if(t == 1){
		int cnt = 0;
		for(int k = 1; k <= n; k++){
			if(a[S][k] == 1 && a[k][T] == 1){
				++cnt;
			}
		}
		cout << cnt << endl;
	}
	else{
		memset(parent, 0, sizeof(parent));
		DFS(S);
		if(visited[T] == 0){
			cout << "0\n";
		}
		else{
			vector<int> ans;
			int cur = T;
			while(cur != S){
				ans.push_back(cur);
				cur = parent[cur];
			}
			ans.push_back(S);
			reverse(ans.begin(), ans.end());
			for(int x : ans) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}