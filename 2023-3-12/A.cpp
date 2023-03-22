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
     * 寻找包含e的单词的个数
     * @param string string字符串 输入字符串，不同单词用空格隔开
     * @return int整型
     */
    vector<string> split(string s){
        vector<string> words;
        int i = 0 , j = 0, n = s.size();
        while(j < n){
        	i = j;
        	while(i < n and s[i] == ' ') i++;
        	j = i;
        	while(j < n and s[j] != ' ') j++;
        	if(j - i) words.push_back(s.substr(i, j - i));  
        }
        return words;
    }
    int findEwordCount(string s) {
        // write code here
        vector<string> words = split(s);
        int ans = 0;
        for(auto word : words){
        	for(auto ch : word) if(ch == 'e' or ch == 'E') ans++;
        }
    	return ans;
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}