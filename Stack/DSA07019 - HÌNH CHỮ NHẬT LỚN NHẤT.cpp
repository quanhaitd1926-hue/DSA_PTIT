#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

void FirstElementLeftMin(int a[], int n, int L[]){
	stack<int> st;
	for(int i = n - 1; i >= 0; i--){
		while(!st.empty() && a[i] < a[st.top()]){
			L[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		L[st.top()] = -1;
		st.pop();
	}
}

void FirstElementRightMin(int a[], int n, int R[]){
	stack<int> st;
	for(int i = 0; i < n; i++){
		while(!st.empty() && a[i] < a[st.top()]){
			R[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		R[st.top()] = n;
		st.pop();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int a[n], L[n], R[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		FirstElementLeftMin(a, n, L);
		FirstElementRightMin(a, n, R);

		ll S = 0;
		for(int i = 0; i < n; i++){
			int w = R[i] - L[i] - 1;
			S = max((ll)w * a[i], S);
		}
		cout << S << endl;
	}
	return 0;
}