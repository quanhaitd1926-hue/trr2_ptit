#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, s;
int a[205][205];
set<int> ke[205];
int d[205] = {0};
int visited[205] = {0};

void nhap(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				ke[i].insert(j);
				ke[j].insert(i);
			}
		}
	}
}

void DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

void EulerCycle(int s){
	stack<int> st;
	st.push(s);
	vector<int> CE;
	while(!st.empty()){
		int u = st.top();
		if(ke[u].size() != 0){
			set<int>::iterator it = ke[u].begin();
			st.push(*it);
			ke[u].erase(*it);
			ke[*it].erase(u);
		}
		else{
			int x = st.top(); st.pop();
			CE.push_back(x);
		}
	}
	reverse(CE.begin(), CE.end());
	for(int x : CE) cout << x << " ";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);
	
	int t; cin >> t;
	if(t == 1){
		cin >> n;
		nhap();
		int check = 1;
		DFS(1);
		for(int i = 1; i <= n; i++){
			if(visited[i] == 0){
				check = 0;
			}
		}
		if(check == 0) cout << "0\n";
		else{
			for(int i = 1; i <= n; i++){
				int dem = 0;
				for(int j = 1; j <= n; j++){
					if(a[i][j] == 1) ++dem;
				}
				d[i] = dem;
			}
			int cnt = 0;
			for(int i = 1; i <= n; i++){
				if(d[i] % 2 != 0) ++cnt;
			}
			if(cnt == 0) cout << "1\n";
			else cout << "2\n";
		}
	}
	else{
		cin >> n >> s;
		nhap();
		EulerCycle(s);
	}
	return 0;
}