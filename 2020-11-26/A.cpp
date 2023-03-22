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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回Mr.Seven最后的坐标
     * @param m int整型 正整数，代表地图的横向长度
     * @param n int整型 正整数，代表地图的纵向长度
     * @param x int整型 非负整数，代表Mr.Seven的横坐标x
     * @param y int整型 非负整数，代表Mr.Seven的纵坐标y
     * @param dirs int整型vector 全部是由0,1,2,3,4组成的数列
     * @return int整型vector
     */
    int xx[5] = {0, 0, 1, 0, -1}, yy[5] = {0, 1, 0, -1, 0};
    vector<int> GetLocation(int m, int n, int x, int y, vector<int>& dirs) {
    	for(auto &dir : dirs){
    		int nx = x + xx[dir], ny = y + yy[dir];
    		if(nx >= 0 and nx < m and ny >= 0 and ny < n) x = nx, y = ny;
    	}
    	return vector<int>({x, y});
        // write code here
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}