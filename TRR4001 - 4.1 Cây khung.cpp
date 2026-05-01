#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, s;
vector<int> ke[200005];
int visited[200005] = {0};
int a[205][205];
vector<pair<int, int>> treeDFS;
vector<pair<int, int>> treeBFS;

void nhap(){
	cin >> n >> s;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				ke[i].push_back(j);
			}
		}
	}
}

void DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			treeDFS.push_back({u, v});
			DFS(v);
		}
	}
}

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int y : ke[x]){
			if(!visited[y]){
				treeBFS.push_back({x, y});
				q.push(y);
				visited[y] = 1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("CK.INP", "r", stdin);
	freopen("CK.OUT", "w", stdout);
	
	int t; cin >> t;
	nhap();
	
	if(t == 1){
		DFS(s);
		if(treeDFS.size() < n - 1) cout << "0\n";
		else{
			cout << n - 1 << endl;
			for(auto it : treeDFS){
				if(it.first < it.second){
					cout << it.first << " " << it.second << endl;
				}
				else cout << it.second << " " << it.first << endl;
			}
		}
	}
	else{
		BFS(s);
		if(treeBFS.size() < n - 1) cout << "0\n";
		else{
			cout << n - 1 << endl;
			for(auto it : treeBFS){
				if(it.first < it.second){
					cout << it.first << " " << it.second << endl;
				}
				else cout << it.second << " " << it.first << endl;
			}
		}
	}
	return 0;
}