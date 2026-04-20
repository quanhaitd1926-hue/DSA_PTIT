#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

struct edge{
	int x, y, w;
};

vector<edge> dscanh;

int n, m;
int parent[200005];

int Find(int u){
	while(u != parent[u]){
		u = parent[u];
	}
	return u;
}

bool Union(int u, int v){
	u = Find(u);
	v = Find(v);
	if(u == v){
		return false;
	}
	else{
		if(u < v) parent[v] = u;
		else parent[u] = v;
		return true;
	}
}

void Kruskal(){
	sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)->bool{
		return a.w < b.w;
	});
	int d = 0;
	vector<edge> MST;
	for(int i = 0; i < m; i++){
		if(MST.size() == n - 1){
			break;
		}
		edge e = dscanh[i];
		if(Union(e.x, e.y)){
			MST.push_back(e);
			d += e.w;
		}
	}
	cout << d << endl;
	// for(auto it : MST){
	// 	cout << it.x << " " << it.y << " " << it.w << endl;
	// }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1; i <= n; i++){
			parent[i] = i;
		}
		for(int i = 1; i <= m; i++){
			int x, y, w; cin >> x >> y >> w;
			edge e;
			e.x = x;
			e.y = y;
			e.w = w;
			dscanh.push_back(e);
		}
		Kruskal();
		memset(parent, 0, sizeof(parent));
		dscanh.clear();
	}
}