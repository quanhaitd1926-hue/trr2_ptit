#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
set<int> ke[200005];
int visited[200005] = {0};
int a[205][205];
vector<pair<int, int>> dscanh;

void nhap(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				ke[i].insert(j);
				ke[j].insert(i);
				if(i < j){
					dscanh.push_back({i, j});
				}
			}
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
				q.push(y);
				visited[y] = 1;
			}
		}
	}
}

int ConnectComponent(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			++cnt;
			BFS(i);
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
	int cc = ConnectComponent();
	vector<pair<int, int>> ans;
	for(auto it : dscanh){
		memset(visited, 0, sizeof(visited));
		int x = it.first, y = it.second;
		ke[x].erase(y);
		ke[y].erase(x);
		if(cc < ConnectComponent()){
			ans.push_back({x, y});
		}
		ke[x].insert(y);
		ke[y].insert(x);
	}
	cout << ans.size() << endl;
	for(auto it : ans){
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}