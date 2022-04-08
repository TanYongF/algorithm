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
    string minWindow(string s, string t) {
        int len =  s.size();
        unordered_map<char,int> tnum;
        // vector<vector<int>> num(len, vector<int>(26,0));
        for(int i = 0; i < (int)t.size(); i++) tnum[t[i]]++;
        // for(int i = 0; i < s.size(); i++){
        //     if(i) num[i] = num[i-1];
        //     num[i][s[i] - 'a']++;
        // }
       	for(auto it : tnum) cout << it.first << " " << it.second;
        int an = 0;
        int i = 0, j = 0, ans = INT_MAX;
        unordered_map<char,int> cur;
        while(j <= len){
            if(check(cur, tnum)){
                if(j - i < ans) {an = i, ans = j - i;}
                cur[s[i]]--;
                i++;
            }else{
                if(j < len) cur[s[j]]++;
                j++;
            }
            cout << i << " " << j << endl;
        }
        // if(check(cur, tnum)) if(j - i < ans)  {an = i, ans = j - i;}
        return ans == INT_MAX ? "" :  s.substr(i-1, ans);
    }
    bool check(unordered_map<char,int>& s, unordered_map<char,int> &t){
        for(auto &it : t){
            if(s[it.first] < it.second) return false;
        }
        return true;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	string ss = "ADOBECODEBANC";
	string t = "ABC";
	cout << s.minWindow(ss, t);
	/* code */


    return 0;
}