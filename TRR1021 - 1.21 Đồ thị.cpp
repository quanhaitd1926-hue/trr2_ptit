#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

vector<int> ke[200005];
int a[205][205] = {0};
int n, m;

int main(){
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
	
	int t; cin >> t;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	if(t == 1){
		for(int i = 1; i <= n; i++){
			int in = 0;
			int out = 0;
			for(int j = 1; j <= n; j++){
				if(a[j][i] != 0 && a[j][i] != 10000) ++in;
			}
			for(int j = 1; j <= n; j++){
				if(a[i][j] != 0 && a[i][j] != 10000) ++out;
			}
			cout << in << " " << out << endl;
		}
	}
	else{
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i][j] != 0 && a[i][j] != 10000) ++cnt;
			}
		}
		cout << n << " " << cnt << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(a[i][j] != 0 && a[i][j] != 10000){
					cout << i << " " << j << " " << a[i][j] << endl;
				}
			}
		}
	}
	return 0;
}