#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

vector<vector<int>> v;
int n, a[100];

bool check(vector<int> tmp){
	int l = 0, r = tmp.size() - 1;
	while(l <= r){
		if(tmp[l] != tmp[r]) return false;
		++l; --r;
	}
	return true;
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n){
			vector<int> tmp;
			for(int k = 1; k <= n; k++){
				tmp.push_back(a[k]);
			}
			v.push_back(tmp);
		}
		else Try(i + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	Try(1);
	for(auto it : v){
		if(check(it)){
			for(int x : it) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}