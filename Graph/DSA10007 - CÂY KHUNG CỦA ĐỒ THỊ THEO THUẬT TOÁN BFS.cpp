#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m, s;
vector<int> ke[200005];
int visited[200005] = {0};
vector<pair<int, int>> treeBFS;

void nhap(){
	cin >> n >> m >> s;
	for(int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
}

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(int y : ke[x]){
			if(!visited[y]){
				treeBFS.push_back({x, y});
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
		BFS(s);
		if(treeBFS.size() < n - 1) cout << "-1\n";
		else{
			for(auto it : treeBFS){
				cout << it.first << " " << it.second << endl;
			}
		}
		memset(visited, 0, sizeof(visited));
		treeBFS.clear();
		for(int i = 1; i <= n; i++){
			ke[i].clear();
		}
	}

	return 0;
}