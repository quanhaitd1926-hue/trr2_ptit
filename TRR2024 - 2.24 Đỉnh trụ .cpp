#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
vector<int> ke[200005];
int visited[200005] = {0};
int a[205][205];

void nhap(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				ke[i].push_back(j);
				ke[j].push_back(i);
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
	vector<int> ans;
	for(int i = 1; i <= n; i ++){
		memset(visited, 0, sizeof(visited));
		visited[i] = 1;
		if(cc < ConnectComponent()){
			ans.push_back(i);
		}
		visited[i] = 0;
	}
	cout << ans.size() << endl;
	for(int x : ans){
		cout << x << " ";
	}
	return 0;
}