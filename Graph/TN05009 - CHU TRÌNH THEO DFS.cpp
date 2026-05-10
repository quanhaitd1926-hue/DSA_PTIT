#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, m, S;
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
		else if(parent[u] != v && v == 1){
			S = u;
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
		if(DFS(1) == false){
			cout << "NO\n";
		}
		else{
			vector<int> ans;
            int cur = S;
            while (cur != 1) {
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(1);
            reverse(ans.begin(), ans.end());
			ans.push_back(1);
			for(int x : ans) cout << x << " ";
			cout << endl;
		}
		for(int i = 1; i <= n; i++){
			ke[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
	}
	return 0;
}