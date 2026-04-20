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
int degree[200005];

void nhap(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		ke[x].insert(y);
		ke[y].insert(x);
		degree[x]++;
		degree[y]++;
	}
}

void euler(int u){
	stack<int> st;
	vector<int> EC;
	st.push(u);
	while(!st.empty()){
		int v = st.top();
		if(ke[v].size() != 0){
			set<int>::iterator it = ke[v].begin();
			st.push(*it);
			ke[v].erase(*it);
			ke[*it].erase(v);
		}
		else{
			st.pop();
			EC.push_back(v);
		}
	}
	for(int x : EC) cout << x << " ";
	cout << endl;
}

void DFS(int u){
	visited[u] = 1;
	for(int v : ke[u]){
		if(!visited[v]){
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
		int start = -1;
		for(int i = 1; i <= n; i++){
			if(degree[i] > 0){
				start = i;
				break;
			}
		}
		if(start != -1) DFS(start);
		
		int check = 1;
		for(int i = 1; i <= n; i++){
			if(degree[i] > 0 && !visited[i]){
				check = 0;
				break;
			}
		}
		if(check == 0){
			cout << "0\n";
		}
		else{
			int odd = 0;
			for(int i = 1; i <= n; i++){
				if(degree[i] % 2 == 1) odd++;
			}

			if(odd == 0) cout << "2\n";
			else if(odd == 2) cout << "1\n";
			else cout << "0\n";
		}
		memset(visited, 0, sizeof(visited));
		memset(degree, 0, sizeof(degree));
		for(int i = 1; i <= 200005; i++){
			ke[i].clear();
		}
	}
	return 0;
}