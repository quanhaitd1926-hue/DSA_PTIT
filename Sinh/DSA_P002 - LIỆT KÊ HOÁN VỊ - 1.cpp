#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, a[100];
int visited[100] = {0};
vector<vector<int>> v;

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(!visited[j]){
			a[i] = j;
			visited[j] = 1;
			if(i == n){
				vector<int> tmp;
				for(int k = 1; k <= n; k++){
					tmp.push_back(a[k]);
				}
				v.push_back(tmp);
			}
			else Try(i + 1);
			visited[j] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	Try(1);
	for(int i = 0; i < v.size(); i++){
		cout << i + 1 << ": ";
		for(int x : v[i]) cout << x << " ";
		cout << endl;
	}
	return 0;
}	