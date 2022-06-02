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
    int minStickers(vector<string>& stickers, string target) {
        int len = target.size();
        vector<int> dp((1 << len), 0);
        int status = 0;
        queue<int> q;
        q.push(status);
        while(not q.empty()){
        	int status = q.front();
        	q.pop();
        	for(auto &sticker : stickers){
        		vector<int> cnt(26,0);
        		for(auto &ch : sticker) cnt[ch-'0']++;
        		for(int i = 0; i < len; i++){
        			if(cnt[target[i]-'a'] > 0 and (status & (1 << i)) == 0){
        				dp[status|(1<<i)] = dp[status] + 1;
        				q.push(status|(1<<i));
        				cnt[target[i]-'a']--;
        			}
        		}
        		if(dp.back() != 0) return dp.back(); 
        	}
        }
        return -1;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}