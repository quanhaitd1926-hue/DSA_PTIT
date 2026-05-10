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

void printLevel(Node *root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *tmp = q.front(); q.pop();
		cout << tmp->data << " ";
		if(tmp->left != NULL) q.push(tmp->left);
		if(tmp->right != NULL) q.push(tmp->right);
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
		printLevel(root);
		cout << endl;
	}
	return 0;
}