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


  struct Point {
 	int x;
 	int y;
	Point(int xx, int yy) : x(xx), y(yy) {}
  };
 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求四个点的面积
     * @param p1 Point类 点1
     * @param p2 Point类 点2
     * @param p3 Point类 点3
     * @param p4 Point类 点4
     * @return long长整型
     */

	// long double cross(Point p1, Point p2, Point p3){
	// 	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
	// }

	double area(Point p1, Point p2, Point p3){
		return (p2.x * p3.y - p2.y * p3.x) - (p1.x * p3.y - p1.y * p3.x) + (p1.x * p2.y - p1.y  * p2.x); 
	}

    long long getArea(Point p1, Point p2, Point p3, Point p4) {
        // write code here
     	long double ans =  fabs(area(p1, p2, p3) + area(p1, p3, p4)) / 2.0;
     	return ans;

    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
		/* code */


    return 0;
}