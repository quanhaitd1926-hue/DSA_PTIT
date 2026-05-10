#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n;
vector<int> ke[200005];
int visited[200005] = {0};
vector<pair<int, int>> treeDFS;

void nhap(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		sort(ke[i].begin(), ke[i].end());
	}
}

void DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			treeDFS.push_back({u, v});
			DFS(v);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		nhap();
		DFS(1);
		if(treeDFS.size() < n - 1) cout << "NO\n\n";
		else{
			cout << "YES\n";
		}
		memset(visited, 0, sizeof(visited));
		treeDFS.clear();
		for(int i = 1; i <= n; i++){
			ke[i].clear();
		}
	}
	return 0;
}