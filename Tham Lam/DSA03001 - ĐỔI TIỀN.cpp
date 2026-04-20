#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

vector<int> v = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ans = 0;
		for(int i = 0; i < v.size(); i++){
			int quantity = n / v[i];
			ans += quantity;
			n -= quantity * v[i];
		}
		cout << ans << endl;
	}
	return 0;
}