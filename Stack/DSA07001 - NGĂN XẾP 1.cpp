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

	stack<int> st;
	string s;
	while(getline(cin, s)){
		if(s.size() > 4){
			stringstream ss(s);
			string w;
			string digit;
			while(ss >> w){
				digit = w;
			}
			int tmp = stoi(digit);
			st.push(tmp);
		}
		else if(s == "pop"){
			if(!st.empty()){
				st.pop();
			}
			else 
				continue;
		}
		else{
			if(!st.empty()){
				vector<int> v;
				while(!st.empty()){
					v.push_back(st.top());
					st.pop();
				}
				for(int i = v.size() - 1; i >= 0; i--){
					cout << v[i] << " ";
					st.push(v[i]);
				}
				cout << endl;
			}
			else cout << "empty\n";
		}
	}
	return 0;
}