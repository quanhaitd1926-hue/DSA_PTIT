#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

vector<vector<int>> v;
int n, k, a[100], X[100];

void nhap(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
}

void Try(int i, int st, ll sum){
	for(int j = st; j <= n; j++){
		X[i] = a[j];
		sum += a[j];
		if(sum == k){
			vector<int> tmp;
			for(int l = 1; l <= i; l++){
				tmp.push_back(X[l]);
			}
			v.push_back(tmp);
		}
		else if(sum < k){
			Try(i + 1, j + 1, sum);
		}
		sum -= a[j];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	nhap();
	Try(1, 1, 0);
	for(int i = v.size() - 1; i >= 0; i--){
		for(int x : v[i]) cout << x << " ";
		cout << endl;
	}
	cout << v.size() << endl;
	return 0;
}