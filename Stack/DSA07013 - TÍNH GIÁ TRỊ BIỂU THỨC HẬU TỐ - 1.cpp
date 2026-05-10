#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

void solve(string s){
	stack<int> st;
	for(char c : s){
		if(isdigit(c)){
			st.push(c - '0');
		}
		else{
			char x = st.top(); st.pop();
			char y = st.top(); st.pop();
			if(c == '+') st.push(y + x);
			else if(c == '-') st.push(y - x);
			else if(c == '*') st.push(y * x);
			else st.push(y / x);
		}
	}
	cout << st.top() << endl;
	st.pop();
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