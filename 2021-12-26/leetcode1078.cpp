#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
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

class Solution{
public:
    vector<string> findOcurrences(string text, string first, string second) {
		vector<string> words;
		int len = text.size();
		int i = 0, j = 0;
		vector<string> ans;
		//分割字符串
/*		while(i < len and  j < len){
			while(i < len and text[i] == ' ') i++;
			j = i;
			while(j < len and text[j] != ' ') j++;
			if(i < len) words.push_back(text.substr(i, j - i));
			i = j;
		}*/
		istringstream ss(text);
		string word;
		while(std::getline(ss, word, ' ')){
			words.push_back(word);
		}
		for(int i = 0; i < len - 2; i++){
			if(words[i] == first and words[i+1] == second) ans.push_back(words[i+2]);
		}
		// return ans;
		for(auto word : words) cout << word << endl;
		return ans;
	}
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	s.findOcurrences(" tan fafda fa fa ", " fafa", " faf");
	/* code */


    return 0;
}