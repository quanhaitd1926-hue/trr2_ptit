#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

#define ii pair<int, int>

int n, s, t;
int a[205][205];
vector<pair<int, int>> ke[20005];
int parent[20005];
int d[20005];

void nhap(){
	cin >> n >> s >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(i != j && a[i][j] != 0 && a[i][j] != 10000){
				ke[i].push_back({j, a[i][j]});
			}
		}
	}
}

void Dijkstra(int s){
	for(int i = 1; i <= n; i++){
		d[i] = 1e9;
	}
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.push({0, s});
	while(!Q.empty()){
		ii p = Q.top(); Q.pop();
		int u = p.second, dis = p.first;
		if(dis > d[u]) continue;
		for(auto it : ke[u]){
			int v = it.first, w = it.second;
			if(d[u] + w < d[v]){
				d[v] = d[u] + w;
				parent[v] = u;
				Q.push({d[v], v});
			}
		}
	}
	if(d[t] == 1e9) cout << "0\n";
	else{
		cout << d[t] << endl;
		vector<int> path;
		while(s != t){
			path.push_back(t);
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for(int x : path) cout << x << " ";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("DN.INP", "r", stdin);
	freopen("DN.OUT", "w", stdout);
	
	nhap();
	Dijkstra(s);
	return 0;
}