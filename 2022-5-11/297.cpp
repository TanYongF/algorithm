#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Codec {
public:
	string str = "";
    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
    	if(not root) return "";
    	queue<TreeNode*> q;
    	q.push(root);
    	str += to_string(root->val) + ",";
    	while(not q.empty()){
    		int len = q.size();
    		for(int i = 0; i < len; i++){
    			TreeNode* cur = q.front();
    			q.pop();
    			str += (cur->left ? to_string(cur->left->val) : "#")+ ",";
    			str += (cur->right ? to_string(cur->right->val) : "#") + ",";
    		}
    	}
    	str.pop_back();
    	deserialize(str);
    	return str;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	int idx = 0, len = data.size();
    	TreeNode* root = nullptr;
    	if(data.size() == 0) return root;
    	while(idx < data.size() and data[idx] != ',') idx++;
    	root = new TreeNode(stoi(data.substr(0, idx)));
    	queue<TreeNode*> q;
    	q.push(root);
    	idx++;
    	while(idx < len){
    		//get left and right node
    		int end = idx;
    		while(end < len and data[end] != ',') end++;
    		string left = data.substr(idx, end-idx);
    		idx = ++end;
    		while(end < len and data[end] != ',') end++;
			string right = data.substr(idx, end-idx);
    		TreeNode* cur = q.front();
    		q.pop();
    		if(left != "#") {
    			root->left = new TreeNode(stoi(left));
    			q.push(root->left);
    		}
    		if(right != "#") {
    			root->right = new TreeNode(stoi(right)); 
    			q.push(root->right);
    		}
    		idx = end + 1;
    	}
    	// cout << root->val << endl;
    	return root;
    }
};
int main(int argc, char * argv[]){

	Codec s = Codec();
	TreeNode* root = new TreeNode(-1);
	s.serialize(root);

	/* code */


    return 0;
}