#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int F[n + 1];
	for(int i = 0; i < n; i++){
		F[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[j] < a[i]){
				F[i] = max(F[i], F[j] + 1);
			}
		}
	}
	cout << *max_element(F, F + n) << endl;
	return 0;
}