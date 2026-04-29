#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
vector<int> ke[200005];
int visited[200005] = {0};
int parent[200005] = {0};

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
}

int Find(int u){
	if(u = parent[u]) return u;
	return parent[u] = Find(parent[u]);
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T;
	while(T--){
		nhap();
		int check = 0;
		for(int i = 0; i < m; i++){
			int u, v; cin >> u >> v;
			if(Union(u, v) == false){
				check = 1;
			}
		}
		if(check == 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}