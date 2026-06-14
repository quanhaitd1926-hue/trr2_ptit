#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, s, cnt = 0;
int a[205][205];
vector<int> ke[205];
int visited[205];
vector<int> res(205);

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

void DFS(int s){
	visited[s] = 1;
	for(int v : ke[s]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

void Hamilton(int k){
	int pre = res[k - 1];
	for(int u : ke[pre]){
		if(k == n + 1 && u == s){
			++cnt;
			for(int i = 1; i <= n; i++){
				cout << res[i] << " ";
			}
			cout << s << endl;
		}
		else if(!visited[u]){
			visited[u] = 1;
			res[k] = u;
			Hamilton(k + 1);
			visited[u] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);
	
	nhap();
	DFS(s);
	int check = 1;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			check = 0;
			break;
		}
	}
	if(check == 0) cout << "0\n";
	else{
		memset(visited, 0, sizeof(visited));
		res[1] = s;
		visited[s] = 1;
		Hamilton(2);
		if(cnt == 0) cout << "0\n";
		else cout << cnt << endl;
	}
	return 0;
}