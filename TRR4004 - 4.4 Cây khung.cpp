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

int n, s;
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
int visited[200005] = {0};
vector<ii> ke[200005];
int a[205][205];
vector<edge> dscanh;

void nhap(){
	cin >> n >> s;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] != 0 && a[i][j] != 10000){
				ke[i].push_back({j, a[i][j]});
			}
		}
	}
}

void Prim(int s){
	visited[s] = 1;
	int d = 0;
	priority_queue<iii, vector<iii>, greater<iii>> Q;
	for(auto it : ke[s]){
		Q.push({it.second, {s, it.first}});
	}
	while(!Q.empty()){
		iii p = Q.top(); Q.pop();
		int w = p.first;
		ii tmp = p.second;
		int x = tmp.first, y = tmp.second;
		if(!visited[y]){
			d += w;
			visited[y] = 1;
			dscanh.push_back({x, y, w});
			for(auto it : ke[y]){
				if(!visited[it.first]){
					Q.push({it.second, {y, it.first}});
				}
			}
		}
	}
	if((int)dscanh.size() < n - 1) cout << "0\n";
	else{
		cout << d << endl;
		for(edge e : dscanh){
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
	Prim(s);
	return 0;
}