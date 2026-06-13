#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

struct edge{
	int x, y, w;
};

int n, s, t;
vector<edge> dscanh;
int a[205][205];
int parent[20005];
int d[2005];

void nhap(){
	cin >> n >> s >> t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(i != j && a[i][j] != 0 && a[i][j] != 10000){
				dscanh.push_back({i, j, a[i][j]});
			}
		}
	}
}

bool BellmanFord(int s){
	for(int i = 1; i <= n; i++){
		d[i] = 1e9;
	}
	d[s] = 0;
	for(int i = 1; i < n; i++){
		for(edge e : dscanh){
			int u = e.x, v = e.y, w = e.w;
			if(d[u] < 1e9 && d[v] > d[u] + w){
				d[v] = d[u] + w;
				parent[v] = u;
			}
		}
	}
	for(edge e : dscanh){
		int u = e.x, v = e.y, w = e.w;
		if(d[u] != 1e9 && d[v] > d[u] + w){
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
	
	nhap();
	if(BellmanFord(s)){
		cout << "-1\n";
	}
	else if(d[t] == 1e9){
		cout << "0\n";
	}
	else{
		cout << d[t] << endl;
		vector<int> ans;
		while(s != t){
			ans.push_back(t);
			t = parent[t];
		}
		ans.push_back(s);
		reverse(ans.begin(), ans.end());
		for(int x : ans) cout << x << " ";
	}
	return 0;
}