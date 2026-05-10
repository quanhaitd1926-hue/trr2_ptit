#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
int a[205][205];
int b[205][205];

void init(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		a[x][y] = 1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
	
	int t; cin >> t;
	init();
	if(t == 1){
		for(int i = 1; i <= n; i++){
			int degAdd = 0, degSub = 0;
			for(int j = 1; j <= n; j++){
				if(a[i][j] == 1) ++degAdd;
				if(a[j][i] == 1) ++degSub;
			}
			cout << degSub << " " << degAdd << endl;
		}
	}
	else{
		int m = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i][j] == 1){
					++m;
					b[i][m] = 1;
					b[j][m] = -1;
				}
			}
		}
		cout << n << " " << m << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cout << b[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}