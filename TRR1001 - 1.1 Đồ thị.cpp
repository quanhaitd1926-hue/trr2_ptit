#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

vector<int> ke[200005];
int a[205][205];

int main(){
	freopen("DT.INP", "r", stdin);
	freopen("DT.OUT", "w", stdout);
	
	int t, n; cin >> t >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	if(t == 1){
		for(int i = 1; i <= n; i++){
			int dem = 0;
			for(int j = 1; j <= n; j++){
				if(a[i][j] == 1) ++dem;
			}
			cout << dem << " ";
		}
	}
	else{
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i < j && a[i][j] == 1){
					ke[i].push_back(j);
					++cnt;
				}
			}
		}
		cout << n << " " << cnt << endl;
		for(int i = 1; i <= n; i++){
			for(int x : ke[i]) cout << i << " " << x << endl;
		}
	}
	return 0;
}