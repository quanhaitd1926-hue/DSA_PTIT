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
		cout << a[i];
	}
	cout << " ";
}

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(used[j] == 0){
			used[j] = 1;
			a[i] = j;
			if(i == n){
				result();
			}
			else Try(i + 1);
			used[j] = 0;
		}
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