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
		int index = -1;
		for(int i = s.size() - 1; i >= 0; i--){
			if(s[i] == '0'){
				index = i;
				break;
			}
		}
		if(index == -1){
			for(int i = 0; i < s.size(); i++){
				cout << 0;
			}
			cout << endl;
		}
		else{
			s[index] = '1';
			for(int i = index + 1; i < s.size(); i++){
				s[i] = '0';
			}
			for(int i = 0; i < s.size(); i++){
				cout << s[i];
			}
			cout << endl;
		}
	}
	return 0;
}