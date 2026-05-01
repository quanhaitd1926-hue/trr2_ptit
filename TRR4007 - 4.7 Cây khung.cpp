#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

struct edge{
	int x, y, w;
};

int n, m;
int parent[200005];
vector<edge> dscanh;

bool cmp(edge a, edge b){
	if(a.w != b.w) return a.w < b.w;
	else{
		if(a.x != b.x) return a.x < b.x;
		else return a.y < b.y;
	}
}

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		dscanh.push_back({x, y, w});
	}
	sort(dscanh.begin(), dscanh.end(), cmp);
}

int Find(int u){
	if(u == parent[u]) return u;
	return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
	u = Find(u);
	v = Find(v);
	if(u == v) return false;
	else{
		if(u < v) parent[v] = u;
		else parent[u] = v;
		return true;
	}
}

void Kruskal(){
	vector<edge> MST;
	int d = 0;
	for(int i = 0; i < m; i++){
		edge e = dscanh[i];
		if(MST.size() == n - 1) break;
		if(Union(e.x, e.y)){
			MST.push_back(e);
			d += e.w;
		}
	}
	if(MST.size() < n - 1) cout << "0\n";
	else{
		cout << d << endl;
		for(edge e : MST){
			if(e.x < e.y){
				cout << e.x << " " << e.y << " " << e.w << endl;
			}
			else cout << e.y << " " << e.x << " " << e.w << endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("CK.INP", "r", stdin);
	freopen("CK.OUT", "w", stdout);
	
	nhap();
	Kruskal();
	return 0;
}