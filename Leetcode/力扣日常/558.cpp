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

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:

	int getN(Node *root){
		if(root->isLeaf) return 1;
		int childN = 0;
		childN = max(childN, getN(root->topLeft));
		childN = max(childN, getN(root->topRight));
		childN = max(childN, getN(root->bottomLeft));
		childN = max(childN, getN(root->bottomRight));
		return childN + 1;
	}
	void recovery(Node* root, vector<vector<bool>> &matrix, int x, int y, int len){
		if(root->isLeaf){
			for(int i = x; i < x + len; i++){
				for(int j = y; j < x + len; j++){
					matrix[i][j] = root->val;
				} 
			}
			return;
		}else{
			int newLen = len >> 1;
			recovery(root->topLeft, matrix, x, y, newLen);
			recovery(root->topRight, matrix, x, y + newLen, newLen);
			recovery(root->bottomLeft, matrix, x + newLen, y, newLen);
			recovery(root->bottomRight, matrix, x + newLen, y + newLen, newLen);
		}
	}

	Node* build(vector<vector<bool>> &matrix){
		int n = matrix.size();
		for(int m =n; m >= 1; )


	}
    
    Node* intersect(Node* quadTree1, Node* quadTree2) {
    	int n = pow(2, max(getN(quadTree1), getN(quadTree2)));
    	m1 = vector<vector<bool>>(n, vector<int>(n, 0));
    	m2 = vector<vector<bool>>(n, vector<int>(n, 0));
    	recovery(quadTree1, m1, 0, 0, n);
    	recovery(quadTree1, m2, 0, 0, n);
    	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) m1[i][j] |= m2[i][j];
    	return build(m1);
    }
};
int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}