#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

struct matrix{
	ll a[2][2];
	friend matrix operator * (matrix x, matrix y){
		matrix tmp;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				tmp.a[i][j] = 0;
				for(int k = 0; k < 2; k++){
					tmp.a[i][j] += x.a[i][k] * y.a[k][j];
					tmp.a[i][j] %= mod;
				}
			}
		}
		return tmp;
	}
};

ll binpow(int n, ll k){
	if(k == 0) return 1;
	if(k == 1) return n;
	ll x = binpow(n, k / 2);
	ll y = (x * x) % mod;
	if(k % 2 == 0) return y;
	else return (n * y) % mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		int n;
		ll k;
		cin >> n >> k;
		cout << binpow(n, k) << endl;
	}
	return 0;
}