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
	cin.ignore();
	while(t--){
		string s; getline(cin, s);
		stringstream ss(s);
		string w;
		stack<string> st;
		while(ss >> w){
			st.push(w);
		}
		while(!st.empty()){
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
	return 0;
}