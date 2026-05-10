#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

int priority(char c){
	if(c == '^') return 3;
	else if(c == '*' || c == '/') return 2;
	else if(c == '+' || c == '-') return 1;
	return 0;
}

void solve(string s){
	stack<char> st;
	string exp = "";
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') st.push(s[i]);
		else if(isalpha(s[i])) exp += s[i];
		else if(s[i] == ')'){
			while(st.top() != '('){
				exp += st.top(); st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && priority(st.top()) >= priority(s[i])){
				exp += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		if(st.top() != '('){
			exp += st.top();
		}
		st.pop();
	}
	cout << exp << endl;
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