#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
vector<int> ke[1000];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			ke[x].push_back(y);
			//ke[y].push_back(x);
		}
		for(int i = 1; i <= n; i++){
			cout << i << ": ";
			for(int x : ke[i]){
				cout << x << " ";
			}
			cout << endl;
		}

		for(int i = 1; i <= 1000; i++){
			ke[i].clear();
		}
	}
	return 0;
}