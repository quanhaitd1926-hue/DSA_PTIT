#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m;
int cnt = 0;
vector<int> ke[200005];
int visited[200005] = {0};
int id[200005];
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

void DFS(int u){
	visited[u] = 1;
	id[u] = cnt;
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		id[x] = cnt;
		for(int y : ke[x]){
			if(!visited[y]){
				q.push(y);
				visited[y] = 1;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		nhap();
		for(int i = 1; i <= n; i++){
			if(!visited[i]){
				++cnt;
				DFS(i);
			}
		}
		int q; cin >> q;
		while(q--){
			int x, y; cin >> x >> y;
			if(id[x] == id[y]) cout << "YES\n";
			else cout << "NO\n";
		}
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= 200005; i++){
			ke[i].clear();
		}
		cnt = 0;
		memset(id, 0, sizeof(id));
	}
	return 0;
}