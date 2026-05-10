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

	int n; cin >> n;
	cin.ignore();
	stack<int> st;
	string s;
	while(getline(cin, s)){
		if(s.size() >= 6){
			stringstream ss(s);
			string w;
			string digit;
			while(ss >> w){
				digit = w;
			}
			int tmp = stoi(digit);
			st.push(tmp);
		}
		else if(s == "POP"){
			if(!st.empty()){
				st.pop();
			}
			else 
				continue;
		}
		else{
			if(!st.empty()){
				cout << st.top() << endl;
			}
			else cout << "NONE\n";
		}
	}
	return 0;
}