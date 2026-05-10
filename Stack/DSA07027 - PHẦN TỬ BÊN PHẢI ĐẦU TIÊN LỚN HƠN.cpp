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
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int d[n + 1];
		stack<int> st;
		for(int i = 0; i < n; i++){
			while(!st.empty() && a[i] > a[st.top()]){
				d[st.top()] = a[i];
				st.pop();
			}
			st.push(i);
		}
		while(!st.empty()){
			d[st.top()] = -1;
			st.pop();
		}
		for(int i = 0; i < n; i++){
			cout << d[i] << " ";
		}
		cout << endl;
	}
	return 0;
}