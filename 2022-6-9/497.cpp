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
    map<long long, int> mp; 
    int len;
    vector<vector<int>> rects;
    long long MAXN;
    Solution(vector<vector<int>>& _rects) {
        len = _rects.size();
        rects = _rects;
        mp[-1] = 0;
        for(int index = 0; index < rects.size(); index++){
            int xx = rects[index][2] - rects[index][0] + 1;
            int yy = rects[index][3] - rects[index][1] + 1;
            long long area = 1LL * xx * yy;
            long long last = mp.rbegin()->first + area;
            mp[last] = index; 
        }
        MAXN = mp.rbegin()->first;
    }
    
    vector<int> pick() {
        int random = rand()%MAXN;
        auto it = mp.upper_bound(random);
        int index = it->second;
        int xx = rects[index][2] - rects[index][0] + 1;
        int yy = rects[index][3] - rects[index][1] + 1;
        int x = rects[index][0] + rand()%xx;
        int y = rects[index][1] + rand()%yy;
        return vector<int>({x, y});
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */


int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}