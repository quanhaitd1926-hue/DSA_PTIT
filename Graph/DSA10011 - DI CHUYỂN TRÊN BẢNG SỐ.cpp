#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m, s;
vector<pair<int, int>> ke[200005];
int a[1001][1001];
int d[1001][1001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			d[i][j] = 1e9;
		}
	}
}

#define ii pair<int, int>
#define iii pair<int, ii>

void Dijkstra(int i, int j){
	d[i][j] = a[i][j];
	priority_queue<iii, vector<iii>, greater<iii>> Q;
	Q.push({0, {i, j}});
	while(!Q.empty()){
		iii p1 = Q.top(); Q.pop();
		int w = p1.first;
		ii p2 = p1.second;
		int i1 = p2.first, j1 = p2.second;
		if(w > d[i1][j1]) continue;
		for(int k = 0; k < 4; k++){
			int i2 = dx[k] + i1;
			int j2 = dy[k] + j1;
			if(i2 >= 1 && i2 <= n && j2 >= 1 && j2 <= m && a[i1][j1] + w < d[i2][j2]){
				d[i2][j2] = a[i1][j1] + w;
				Q.push({d[i2][j2], {i2, j2}});
			}
		}
	}
	cout << d[n][m] + a[n][m] << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		nhap();
		Dijkstra(1, 1);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				d[i][j] = 1e9;
			}
		}
	}
	return 0;
}