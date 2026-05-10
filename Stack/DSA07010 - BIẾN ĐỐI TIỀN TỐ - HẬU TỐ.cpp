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
		stack<string> st;
		for(int i = s.size() - 1; i >= 0; i--){
			string tmp;
			tmp = s[i];
			if(isalpha(s[i])){
				st.push(tmp);
			}
			else{
				string expression = "";
				string x = st.top(); st.pop();
				expression += x;
				string y = st.top(); st.pop();
				expression += y;
				expression += tmp;
				//expression = "(" + expression + ")";
				st.push(expression);
			}
		}
		string ans = st.top(); st.pop();
		cout << ans << endl;
	}
	return 0;
}