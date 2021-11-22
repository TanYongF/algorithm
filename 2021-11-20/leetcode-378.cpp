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

class Solution {
public:
	int len, k;
	int check(int mid, vector<vector<int>>& matrix){
		int i = len - 1, j = 0;
		int leftSize = 0;
		while(i >= 0 and j < len){
			if(matrix[i][j] <= mid){
				leftSize += i + 1;
				j++;
			}else{
				i--;
			}
		}
		return leftSize >= k;

	}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	this->k = k;
    	len = matrix.size();
    	int left = matrix[0][0], right = matrix[len-1][len-1];
    	int ans = 0;
    	while(left <= right){
    		int mid = (left + right) >> 1;
    		if(check(mid, matrix)) ans = mid, right = mid - 1;
    		else left = mid + 1; 
    	}
    	return ans;
    }
};
int main(int argc, char * argv[]){

	vector<vector<int>> vs = {{1,5,9},{10,11,13},{12,13,15}};

	Solution s = Solution();
	cout << s.kthSmallest(vs, 8);	


    return 0;
}