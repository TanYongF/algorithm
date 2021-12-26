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
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int len = apples.size();
        map<int,int> mp;
    	int curday = 1, ans;
        map<int,int>::iterator eat;
        for(int i = 0; i < len; i++){
        	mp[days[i] + i] += apples[i];
 			if((eat = mp.upper_bound(curday)) != mp.end()){
 				ans++;
 				eat->second--;
 				if(eat->second == 0) mp.erase(eat);
 			} 	
        	curday++;
        }

        //处理后面天数情况
        while((eat = mp.upper_bound(curday)) != mp.end()){
        	ans++;
        	eat->second--;
        	if(eat->second == 0) mp.erase(eat);
        	curday++;
        }   
        return ans;
    }

};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}