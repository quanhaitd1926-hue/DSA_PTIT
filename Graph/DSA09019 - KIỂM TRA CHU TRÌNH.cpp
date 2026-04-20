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
int parent[200005];

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		sort(ke[i].begin(), ke[i].end());
	}
}

bool DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			parent[v] = u;
			if(DFS(v)) return true;
		}
		else if(v != parent[u]){
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		nhap();
		int check = 0;
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				if(DFS(i)){
					check = 1;
					break;
				}
			}
		}
		if(check == 1) cout << "YES\n";
		else cout << "NO\n";
		memset(parent, 0, sizeof(parent));
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= 200005; i++){
			ke[i].clear();
		}
	}
	return 0;
}