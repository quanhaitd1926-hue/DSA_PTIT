#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

bool check(string s){
	stack<char> st;
	for(char x : s){
		if(x == '(' || x == '[' || x == '{'){
			st.push(x);
		}
		else{
			if(st.empty()) return false;
			if(x == ')'){
				char c = st.top();
				if(c == '('){
					st.pop();
				}
				else return false;
			}
			else if(x == ']'){
				char c = st.top();
				if(c == '['){
					st.pop();
				}
				else return false;
			}
			else{
				char c = st.top();
				if(c == '{'){
					st.pop();
				}
				else return false;
			}
		}
	}
	return st.empty();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		if(check(s)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}