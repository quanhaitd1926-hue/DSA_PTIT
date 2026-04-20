#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
int d[1005][1005];

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			if(i == j) d[i][j] = 0;
			else d[i][j] = 1e9;
		}
	}
	for(int i = 1; i <= m; i++){
		int x, y, w; cin >> x >> y >> w;
		d[x][y] = d[y][x] = w;
	}
}

void Floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	nhap();
	Floyd();
	int q; cin >> q;
	while(q--){
		int x, y; cin >> x >> y;
		cout << d[x][y] << endl;
	}
	return 0;
}