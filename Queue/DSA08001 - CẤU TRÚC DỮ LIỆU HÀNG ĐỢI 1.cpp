#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

void solve(int n){
	queue<int> Q;
	while(n--){
		int q; cin >> q;
		if(q == 1){
			cout << Q.size() << endl;
		}
		else if(q == 2){
			if(Q.empty()) cout << "YES\n";
			else cout << "NO\n";
		}
		else if(q == 3){
			int tmp; cin >> tmp;
			Q.push(tmp);
		}
		else if(q == 4){
			if(!Q.empty()) Q.pop();
		}
		else if(q == 5){
			if(Q.empty()) cout << "-1\n";
			else cout << Q.front() << endl;
		}
		else{
			if(Q.empty()) cout << "-1\n";
			else cout << Q.back() << endl;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		solve(n);
	}
	return 0;
}