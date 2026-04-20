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
		int idx = -1;
		for(int i = s.size() - 1; i >= 0; i--){
			if(s[i] == '1'){
				idx = i;
				break;
			}
		}
		if(idx == -1){
			for(int i = 0; i < s.size(); i++){
				cout << "1";
			}
			cout << endl;
		}
		else{
			for(int i = 0; i < idx; i++){
				cout << s[i];
			}
			cout << 0;
			for(int i = idx + 1; i < s.size(); i++){
				cout << 1;
			}
			cout << endl;
		}
	}
	return 0;
}