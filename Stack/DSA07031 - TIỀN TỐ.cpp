#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

ll solve(string s){
	stringstream ss(s);
	string w;
	vector<string> v;
	while(ss >> w){
		v.push_back(w);
	}
	stack<ll> st;
	for(int i = v.size() - 1; i >= 0; i--){
		if(v[i] != "+" && v[i] != "-" && v[i] != "*" && v[i] != "/"){
			st.push(stoll(v[i]));
		}
		else{
			ll x = st.top(); st.pop();
			ll y = st.top(); st.pop();
			if(v[i] == "+") st.push(x + y);
			else if(v[i] == "-") st.push(x - y);
			else if(v[i] == "*") st.push((ll)x * y);
			else st.push(x / y);
		}
	}
	return st.top();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cin.ignore();
		string s; getline(cin, s);
		cout << solve(s) << endl;
	}
	return 0;
}