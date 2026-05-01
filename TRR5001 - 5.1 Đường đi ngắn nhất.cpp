#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m, s, t;
int parent[200005];
#define ii pair<int, int>
vector<ii> ke[200005];
int a[205][205];

void nhap(){
	cin >> n >> s >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] != 10000 && a[i][j] != 0){
				ke[i].push_back({j, a[i][j]});
			}
		}
	}
}

void Dijkstra(int s){
	vector<int> d(n + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	d[s] = 0;
	Q.push({0, s});
	while(!Q.empty()){
		ii p = Q.top(); Q.pop();
		int u = p.second, dis = p.first;
		if(dis > d[u]) continue;
		for(auto it : ke[u]){
			int v = it.first, w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
				parent[v] = u;
			}
		}
	}
	if(d[t] != 1e9){
		cout << d[t] << endl;
		vector<int> ans;
		while(t != s){
			ans.push_back(t);
			t = parent[t];
		}
		ans.push_back(s);
		reverse(ans.begin(), ans.end());
		for(int x : ans) cout << x << " ";
	}
	else cout << "0\n";
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