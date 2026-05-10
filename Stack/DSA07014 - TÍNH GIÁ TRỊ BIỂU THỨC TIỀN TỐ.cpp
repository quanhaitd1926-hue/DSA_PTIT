#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

string Transform(string s){
	stack<string> st;
	for(int i = s.size() - 1; i >= 0; i--){
		string tmp;
		tmp = s[i];
		if(isdigit(s[i])){
			st.push(tmp);
		}
		else{
			string expression = "";
			string x = st.top(); st.pop();
			expression += x;
			string y = st.top(); st.pop();
			expression += y;
			expression += tmp;
			st.push(expression);
		}
	}
	string exp = st.top(); st.pop();
	return exp;
}

void solve(string s){
	stack<int> st;
	for(char c : s){
		if(isdigit(c)){
			st.push(c - '0');
		}
		else{
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
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
		string tmp = Transform(s);
		solve(tmp);
	}
	return 0;
}