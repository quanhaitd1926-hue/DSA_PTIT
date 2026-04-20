#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

struct Edge{
	int x, y, w;
};

int n, m;
vector<Edge> dscanh;

void nhap(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		dscanh.push_back({x, y, w});
	}
}

bool BellmanFord(int s){
	vector<int> d(n + 5, 1e9);
	d[s] = 0;
	for(int i = 1; i <= n - 1; i++){
		for(Edge e : dscanh){
			int u = e.x, v = e.y, w = e.w;
			if(d[u] < 1e9){
				if(d[u] + w < d[v]){
					d[v] = d[u] + w;
				}
			}
		}
	}
	bool check = false;
	for(Edge e : dscanh){
		int u = e.x, v = e.y, w = e.w;
		if(d[u] < 1e9){
			if(d[u] + w < d[v]){
				check = true;
				break;
			}
		}
	}
	return check;
}

bool check(){
	bool ok = false;
	for(int i = 1; i <= n; i++){
		if(BellmanFord(i)){
			ok = true;
			break;
		}
	}
	return ok;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		nhap();
		if(check()) cout << "1\n";
		else cout << "0\n";
		dscanh.clear();
	}
	return 0;
}