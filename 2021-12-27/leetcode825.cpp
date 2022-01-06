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
    int numFriendRequests(vector<int>& ages) {
        int len = ages.size();
        for(auto &it : ages) it *= 10;
        for(auto it : ages) cout << it << " " << endl;
        long long ans = 0;
    	int firstIdx, secondIdx, can;
        sort(ages.begin(), ages.end());
        int first, second;
        for(int i = 0;  i < len; i++){
            second = ages[i];
            if(ages[i] < 1000) second = min(second, 1000);
            first = ages[i] / 2 + 70;
            // cout << first << " " << second << endl;
            if(second <= first) continue;
            else{
                firstIdx = upper_bound(ages.begin(), ages.end(), first) - ages.begin();
                secondIdx = upper_bound(ages.begin(), ages.end(), second) - ages.begin() - 1;
                // cout << firstIdx << secondIdx << endl;
                can = secondIdx - firstIdx + 1;
                if(i >= firstIdx and i <= secondIdx) can--; 
            }
            if(can > 0) ans += can;
        }
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> test = {16,17,18};
	cout << s.numFriendRequests(test);
	



    return 0;
}