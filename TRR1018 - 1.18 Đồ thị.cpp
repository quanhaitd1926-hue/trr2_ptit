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
	cin.ignore();
	for(int i = 1; i <= n; i++){
		string s; getline(cin, s);
		string temp = "";
		temp = s.substr(2);
		stringstream ss(temp);
		string w;
		while(ss >> w){
			a[i][stoi(w)] = 1;
		}
	}
	if(t == 1){
		for(int i = 1; i <= n; i++){
			int in = 0;
			int out = 0;
			for(int j = 1; j <= n; j++){
				if(a[j][i] != 0) ++in;
			}
			for(int j = 1; j <= n; j++){
				if(a[i][j] != 0) ++out;
			}
			cout << in << " " << out << endl;
		}
	}
	else{
		cout << n << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}