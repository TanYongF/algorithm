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
    vector<string> g;
    void split(string input){
        int i = 0, j = 0;
        while(j < input.size()){
            while(i < input.size() and input[i] == '\n') i++;
            j = i;
            while(j < input.size() and input[j] != '\n') j++;
            if(i < input.size()) g.push_back(input.substr(i, j-i));    
        	i = j;
        }
    }
    int getDepth(string& input){
        int ret = 0;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '\t') ret++;
        }
        input = input.substr(ret);
        return ret;
    }
    int lengthLongestPath(string input) {
        stack<string> st;
        split(input);
        int cur = 0, ans = 0;
        for(int i = 0; i < g.size(); i++){
            int depth = getDepth(g[i]);
            while(st.size() > depth){
                cur = cur - st.top().size() - 1;
                st.pop();
            }
            // cout << g[i] << endl;
            st.push(g[i]);
            cur += g[i].size()+1;

            bool isFile = false;
            for(auto ch : g[i]) if(ch == '.') isFile = true;
            if(isFile) ans = max(ans, cur); 
        }
        return ans - 1;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.lengthLongestPath("a");
	/* code */


	// string t = "t\n";
	// cout << t.size();


    return 0;
}