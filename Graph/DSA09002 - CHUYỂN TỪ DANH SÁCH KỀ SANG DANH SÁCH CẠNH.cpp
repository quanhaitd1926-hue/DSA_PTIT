#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

vector<int> a[1005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	int quantity = 0;
	cin.ignore();
	for(int i = 1; i <= n; i++){
		string s; getline(cin, s);
		stringstream ss(s);
		string w;
		while(ss >> w){
			int temp = stoi(w);
			if(i < temp){
				a[i].push_back(temp);
				++quantity;
			}
		}
	}
	for(int i = 1; i <= quantity; i++){
		for(int x : a[i]) cout << i << " " << x << endl;
	}
	
	return 0;
}