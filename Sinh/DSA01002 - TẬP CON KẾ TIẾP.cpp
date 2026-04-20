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
	
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int a[k + 1];
		for(int i = 1; i <= k; i++){
			cin >> a[i];
		}
		int index = -1;
		for(int i = k; i >= 1; i--){
			if(a[i] < n - k + i){
				index = i;
				break;
			}
		}
		if(index == -1){
			for(int i = 1; i <= k; i++){
				cout << i << " ";
			}
			cout << endl;
		}
		else{
			a[index] += 1;
			for(int i = index + 1; i <= k; i++){
				a[i] = a[i - 1] + 1;
			}
			for(int i = 1; i <= k; i++){
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}