#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

class Graph{
	public:
		int dau, cuoi, w;
};

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
			int cnt = 0;
			for(int j = 1; j <= n; j++){
				if(a[i][j] != 0 && a[i][j] != 10000) ++cnt;
			}
			cout << cnt << " ";
		}
	}
	else{
		vector<Graph> g;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				Graph temp;
				if((i < j) && (a[i][j] != 0 && a[i][j] != 10000)){
					temp.dau = i;
					temp.cuoi = j;
					temp.w = a[i][j];
					g.push_back(temp);
				}
			}
		}
		cout << n << " " << g.size() << endl;
		for(Graph x : g){
			cout << x.dau << " " << x.cuoi << " " << x.w << endl;
		}
	}
	return 0;
}