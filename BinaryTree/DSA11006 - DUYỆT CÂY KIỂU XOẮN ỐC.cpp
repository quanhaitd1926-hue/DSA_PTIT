#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
const int mod = 1000000007;

struct Node{
	int data;
	Node *left;
	Node *right;

	Node(int x){
		data = x;
		left = right = NULL;
	}
};

void makeNode(Node *root, int u, int v, char c){
	if(c == 'L') root->left = new Node(v);
	else root->right = new Node(v);
}

void insertNode(Node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root->data == u){
		makeNode(root, u, v, c);
	}
	else{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);
	}
}

void printSpiral(Node *root){
	stack<Node*> s1, s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			Node *tmp = s1.top(); s1.pop();
			cout << tmp->data << " ";
			if(tmp->right != NULL) s2.push(tmp->right);
			if(tmp->left != NULL) s2.push(tmp->left);
		}
		while(!s2.empty()){
			Node *tmp = s2.top(); s2.pop();
			cout << tmp->data << " ";
			if(tmp->left != NULL) s1.push(tmp->left);
			if(tmp->right != NULL) s1.push(tmp->right);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t; cin >> t;
	while(t--){
		Node *root = NULL;
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			int u, v; char c; cin >> u >> v >> c;
			if(root == NULL){
				root = new Node(u);
				makeNode(root, u, v, c);
			}
			else{
				insertNode(root, u, v, c);
			}
		}
		printSpiral(root);
		cout << endl;
	}
	return 0;
}