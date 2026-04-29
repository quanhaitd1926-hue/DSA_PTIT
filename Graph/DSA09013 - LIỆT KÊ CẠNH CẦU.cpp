#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
set<int> ke[200005];
int visited[200005] = {0};
vector<pair<int, int>> dscanh;

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		dscanh.push_back({x, y});
		ke[x].insert(y);
		ke[y].insert(x);
	}
}

void DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

int ConnectedComponent(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			++cnt;
			DFS(i);
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		nhap();
		int cc = ConnectedComponent();
		for(auto it : dscanh){
			memset(visited, 0, sizeof(visited));
			int x = it.first, y = it.second;
			ke[x].erase(y);
			ke[y].erase(x);
			if(cc < ConnectedComponent()){
				cout << x << " " << y << " ";
			}
			ke[x].insert(y);
			ke[y].insert(x);
		}
		cout << endl;
		for(int i = 1; i <= n; i++){
			ke[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		dscanh.clear();
	}
	return 0;
}