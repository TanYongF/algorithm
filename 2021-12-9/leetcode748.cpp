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
bool cmp(string s1, string s2){
	if(s1.size() == s2.size()){
		for(int i = 0; i < min(s1.size(), s2.size()); i++){
			if(s1[i] != s2[i]) return s1[i] < s2[i];
		}
	}else{
		return s1.size() < s2.size();
	}
}
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> mp;
      	sort(words.begin(), words.end(),cmp);
      	for(auto ch : licensePlate){
      		if(ch <= 'z' and ch >= 'a') mp[ch]++;
      		else if(ch <= 'Z' and ch >= 'A') mp[ch + 32]++;
      	} 
      	for(auto str : words){
      		bool flag = true;
      		unordered_map<char,int> tem;
      		for(auto ch : str){
      			tem[ch]++;
      		}
      		for(auto kv : mp){
      			if(tem[kv.first] < mp[kv.first]){flag = false; break;}  
      		}
      		if(flag) return str;
      	}
      	return " ";
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}