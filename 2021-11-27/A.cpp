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
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> mp1, mp2;
        for(auto word : words1) mp1[word]++;
        for(auto word : words2) mp2[word]++;
        int ans =0 ;
        for(auto it : mp1){
            if(it.second == 1 and mp2[it.first] == 1) ans++;
        }
        return ans;
    }
};

int main(int argc, char * argv[]){

    Solution s = Solution();
    /* code */


    return 0;
}