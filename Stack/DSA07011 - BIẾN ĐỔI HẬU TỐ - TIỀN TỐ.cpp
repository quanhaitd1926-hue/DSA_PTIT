#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

void solve(string s){
	stack<string> st;
	for(char c : s){
		if(isalpha(c)){
			string tmp = "";
			tmp = c;
			st.push(tmp);
		}
		else{
			string exp = "";
			string x = st.top(); st.pop();
			string y = st.top(); st.pop();
			exp += c + y + x;
			st.push(exp);
		}
	}
	string expression = st.top(); st.pop();
	cout << expression << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		solve(s);
	}
	return 0;
}