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
		int n; cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		int index = -1;
		for(int i = n - 1; i >= 1; i--){
			if(a[i] < a[i + 1]){
				index = i;
				break;
			}
		}
		if(index == -1){
			for(int i = 1; i <= n; i++){
				cout << i << " ";
			}
			cout << endl;
		}
		else{
			int idx = - 1;
			for(int i = n; i >= index + 1; i--){
				if(a[i] > a[index]){
					idx = i;
					break;
				}
			}
			swap(a[index], a[idx]);
			reverse(a + index + 1, a + n + 1);
			for(int i = 1; i <= n; i++){
				cout << a[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}