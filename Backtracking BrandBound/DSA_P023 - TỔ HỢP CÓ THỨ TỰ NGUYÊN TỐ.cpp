#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, k, a[100];
vector<vector<int>> v;

bool prime(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return n > 1;
}

void Try(int i){
	for(int j = a[i - 1] + 1; j <= n - k + i; j++){
		a[i] = j;
		if(i == k){
			vector<int> tmp;
			for(int l = 1; l <= k; l++){
				tmp.push_back(a[l]);
			}
			v.push_back(tmp);
		}
		else Try(i + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> k;
	Try(1);
	for(int i = 0; i < v.size(); i++){
		if(prime(i + 1)){
			cout << i + 1 << ": ";
			for(int x : v[i]) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}