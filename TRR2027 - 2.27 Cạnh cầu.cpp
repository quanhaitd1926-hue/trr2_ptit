#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n;
int a[101][101];
set<int> ke[101];
int visited[101];
vector<pair<int, int>> dscanh;

void nhap(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				ke[i].insert(j);
				if(i < j) dscanh.push_back({i, j});
			}
		}
	}
}

void DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

int ConnectedComponent(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			++cnt;
			DFS(i);
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);
	
	nhap();
	vector<pair<int, int>> res;
	int cc = ConnectedComponent();
	for(auto it : dscanh){
		memset(visited, 0, sizeof(visited));
		int x = it.first, y = it.second;
		ke[x].erase(y);
		ke[y].erase(x);
		if(cc < ConnectedComponent()){
			res.push_back({x, y});
		}
		ke[x].insert(y);
		ke[y].insert(x);
	}
	cout << res.size() << endl;
	for(auto it : res){
		cout << it.first << "  " << it.second << endl;
	}
	return 0;
}