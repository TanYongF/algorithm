#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

struct Node{
	int val;
	int color;
	Node *left;
	Node *right;
	Node(int _color){
		this->color = _color;
		left = nullptr;
		right = nullptr;
	}
};
int T;
// unordered_map<Node*, pair<int,int>> mp;

const int MAXN = 100001;
unordered_map<int, Node*> mp;
int ans = 0;
pair<int,int> cal(Node* node){
	if(not node) return {0, 0};
	auto leftHave = cal(node->left);
	auto righthave = cal(node->right);
	int R = leftHave.first + righthave.first + (node->color == 0);
	int L = leftHave.second + righthave.second + (node->color == 1);
	cout << R << L << endl;
	if(R == L) ans++;
	return make_pair(R, L); 
}
void print(Node* root){
	if(not root) return;
	print(root->left);
	cout << root->color;
	print(root->right);
}
int main(int argc, char * argv[]){
	int n;
	cin >> n;
	string color; 
	cin >> color;
	vector<Node*> s(n + 1);
	for(int i = 1; i <= n; i++){
		int c = color[i-1] == 'R' ? 0 : 1;
		s[i] = new Node(c);

	}
	int father;
	for(int i = 2; i <= n; i++) {
		cin >> father;
		if(not s[father]->left) s[father]->left = s[i];
		else s[father]->right = s[i];
	}
	// for(auto it : mp) {
	// 	// cout << it.first << it.second->color << endl;
	// 	Node* cur = it.second;
	// 	cout << it.first << endl;
	// }
 	// print(s[1]);
	ans = 0;
	cal(s[1]);
	cout << ans;
    return 0;
}