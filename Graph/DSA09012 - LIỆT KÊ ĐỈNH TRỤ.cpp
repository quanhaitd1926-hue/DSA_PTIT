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

void DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
			DFS(v);
		}
	}
}

int tplt(){
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
	
	int T; cin >> T;
	while(T--){
		nhap();
		int TPLT = tplt();
		for(int i = 1; i <= n; i++){
			memset(visited, 0, sizeof(visited));
			visited[i] = 1;
			if(TPLT < tplt()){
				cout << i << " ";
			}
		}
		cout << endl;
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= 200005; i++){
			ke[i].clear();
		}
	}
	return 0;
}