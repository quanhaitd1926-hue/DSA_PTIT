#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m, s;
vector<pair<int, int>> ke[200005];
int taken[200005];

void nhap(){
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++){
		int x, y, w; cin >> x >> y >> w;
		ke[x].push_back({y, w});
		ke[y].push_back({x, w});
	}
}

#define ii pair<int, int>

void Dijkatra(int s){
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.push({d[s], s});
	while(!Q.empty()){
		pair<int, int> p = Q.top(); Q.pop();
		int u = p.second; int dist = p.first;
		if(dist > d[u]) continue;
		for(auto it : ke[u]){
			int v = it.first; int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		nhap();
		Dijkatra(s);
		for(int i = 1; i <= 200005; i++){
			ke[i].clear();
		}
	}
	return 0;
}