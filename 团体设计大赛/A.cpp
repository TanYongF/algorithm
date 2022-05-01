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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int top;
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++){
            int cur = temperatures[i];
            if((top = st.top())) cout << "test";
            while(not st.empty() and (top = st.top()) and temperatures[top] < cur){
                // cout << top << endl;
                ans[top] = (i - top);
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<int> v = {73,74,75,71,69,72,76,73};
	s.dailyTemperatures(v);
	/* code */


    return 0;
}
