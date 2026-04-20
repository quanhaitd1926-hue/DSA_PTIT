#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m, s, t;
vector<int> ke[200005];
int visited[200005] = {0};
int parent[200005];

void nhap(){
	cin >> n >> m >> s >> t;
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
	for(int v : ke[u]){
		if(visited[v] == 0){
			DFS(v);
			parent[v] = u;
		}
	}
}

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		cout << x << " ";
		for(int y : ke[x]){
			if(visited[y] == 0){
				q.push(y);
				visited[y] = 1;
				parent[y] = x;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T;
	while(T--){
		nhap();
		DFS(s);
		if(visited[t] == 0){
			cout << "-1\n";
		}
		else{
			vector<int> ans;
			while(t != s){
				ans.push_back(t);
				t = parent[t];
			}
			ans.push_back(s);
			reverse(ans.begin(), ans.end());
			for(int x : ans) cout << x << " ";
			cout << endl;
		}
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		for(int i = 1; i <= 200005; i++){
			ke[i].clear();
		}

	}
	return 0;
}