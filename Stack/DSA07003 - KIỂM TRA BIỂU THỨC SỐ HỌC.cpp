#include <bits/stdc++.h>
using namespace std;

void RegularExpression(string s){
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ')')
            st.push(s[i]);
        else {
            bool ok = false;
            while (!st.empty()) {
                char c = st.top(); st.pop();
                if (c == '+' || c == '-' || c == '*' || c == '/')
                    ok = true;
                if (c == '(')
                    break;
            }
            if (ok == false) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		RegularExpression(s);
	}
    return 0;
}