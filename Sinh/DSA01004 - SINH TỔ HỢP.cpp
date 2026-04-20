#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, k, a[100], used[100];

void result(){
	for(int i = 1; i <= k; i++){
		cout << a[i];
	}
	cout << " ";
}

void Try(int i){
	for(int j = a[i - 1] + 1; j <= n - k + i; j++){
		a[i] = j;
		if(i == k){
			result();
		}
		else Try(i + 1);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		Try(1);
		cout << endl;
	}
	return 0;
}