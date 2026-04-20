#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, k, a[100], used[100];
vector<vector<int>> v;

bool check(vector<int> tmp){
	for(int i = 1; i < tmp.size() - 1; i++){
		if(tmp[i - 1] == 1 && tmp[i] == 1) return false;
	}
	return true;
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			vector<int> temp;
			for(int l = 1; l <= n; l++){
				temp.push_back(a[l]);
			}
			v.push_back(temp);
		}
		else Try(i + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		cin >> n;
		Try(1);
		for(vector<int> tmp : v){
			if(tmp[0] == 1 && tmp[tmp.size() - 1] == 0 && check(tmp)){
				for(int x : tmp){
					if(x == 0) cout << 'A';
					else cout << 'H';
				}
				cout << endl;
			}
		}
		v.clear();
	}
	return 0;
}