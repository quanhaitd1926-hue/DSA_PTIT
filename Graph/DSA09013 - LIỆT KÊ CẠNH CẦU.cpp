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
vector<pair<int, int>> dscanh;

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		dscanh.push_back({x, y});
		ke[x].push_back(y);
		ke[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		sort(ke[i].begin(), ke[i].end());
	}
}

void DFS(int u, int s, int t){
	visited[u] = 1;
	for(int v : ke[u]){
		if((u == s && v == t) || (u == t && v == s)){
			continue;
		}
		if(!visited[v]){
			DFS(v, s, t);
		}
	}
}

int tplt(int s, int t){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			++cnt;
			DFS(i, s, t);
		}
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T; cin >> T;
	while(T--){
		nhap();
		sort(dscanh.begin(), dscanh.end());
		int TPLT = tplt(0, 0);
		int cnt = 0;
		for(auto it : dscanh){
			int x = it.first; int y = it.second;
			memset(visited, 0, sizeof(visited));
			if(TPLT < tplt(x, y)){
				cout << x << " " << y << " ";
			}
		}
		cout << endl;
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= 200005; i++){
			ke[i].clear();
		}
		dscanh.clear();
	}
	return 0;
}