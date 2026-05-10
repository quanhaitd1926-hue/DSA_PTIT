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
		string s; cin >> s;
		stack<char> st;
		int cnt = 0;
		for(char x : s){
			if(x == '(') st.push(x);
			else{
				if(st.empty()){
					st.push('(');
					++cnt;
				}
				else{
					st.pop();
				}
			}
		}
		cnt += st.size() / 2;
		cout << cnt << endl;
	}
	return 0;
}