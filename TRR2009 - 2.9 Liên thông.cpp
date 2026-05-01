#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n;
int a[201][201];
vector<int> ke[200005];
int visited[200005];	
vector<vector<int>> v;
vector<int> temp;

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

void DFS(int u){
	visited[u] = 1;
	temp.push_back(u);
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

int main(){
	freopen("TK.INP", "r", stdin);
	freopen("TK.OUT", "w", stdout);
	
	nhap();
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			DFS(i);
			sort(temp.begin(), temp.end());
			v.push_back(temp);
			temp.clear();
		}
	}
	cout << v.size() << endl;
	for(auto it : v){
		for(int x : it) cout << x << " ";
		cout << endl;
	}
	return 0;
}