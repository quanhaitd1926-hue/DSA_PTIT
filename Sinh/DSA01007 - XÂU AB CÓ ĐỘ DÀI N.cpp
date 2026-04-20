#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int n, k, a[100], used[100];

void result(){
	for(int i = 1; i <= n; i++){
		if(a[i] == 0) cout << 'A';
		else cout << 'B'; 
	}
	cout << " ";
}

void Try(int i){
	for(int j = 0; j <= 1; j++){
		a[i] = j;
		if(i == n) result();
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
		cout << endl;
	}
	return 0;
}