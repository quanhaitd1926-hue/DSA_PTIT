#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

vector<int> ke[200005];
int visited[200005] = {0};

void DFS(int u){
	cout << u << " ";
	visited[u] = 1;
	for(int x : ke[u]){
		if(!visited[x]){
			DFS(x);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		int v, e, u; cin >> v >> e >> u;
		for(int i = 1; i <= e; i++){
			int x, y; cin >> x >> y;
			ke[x].push_back(y);
			//ke[y].push_back(x);
		}
		for(int i = 1; i <= v; i++){
			sort(ke[i].begin(), ke[i].end());
		}
		DFS(u);
		cout << endl;
		for(int i = 1; i <= v; i++){
			ke[i].clear();
		}
		for(int i = 1; i <= 200005; i++){
			visited[i] = 0;
		}
	}
	return 0;
}