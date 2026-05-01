#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
vector<int> ke[200005], t_ke[200005];
int visited[200005] = {0};
int a[205][205];

void nhap(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				ke[i].push_back(j);
				t_ke[i].push_back(j);
				t_ke[j].push_back(i);
			}
		}
	}
}

void DFS1(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			DFS1(v);
		}
	}
}

void DFS2(int u){
	visited[u] = 1;
	for(int v : t_ke[u]){
		if(!visited[v]){
			DFS2(v);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);
	
	nhap();
	int check = 1;
	for(int i = 1; i <= n; i++){
		DFS1(i);
		for(int j = 1; j <= n; j++){
			if(visited[j] == 0){
				check = 0;
				break;
			}
		}
		if(check == 0) break;
		else memset(visited, 0, sizeof(visited));
	}
	if(check == 1){
		cout << "1\n";
	}
	else{
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				++cnt;
				DFS2(i);
			}
		}
		if(cnt == 1) cout << "2\n";
		else cout << "0\n";
	}
	return 0;
}