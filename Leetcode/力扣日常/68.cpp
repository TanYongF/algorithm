//https://leetcode-cn.com/problems/text-justification/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <climits>
#include <vector>
#include <iostream>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s,val) memset(s, val, sizeof(s))
const int inf = INT_MAX;

class Solution {
public:
	vector<string> res;
	string mk_string(vector<string> &words, int start, int end, int maxWidth){
		int sumlen = 0, inv = end - start, spaceSize =0 , i;
		for(i = start; i <= end; i++) sumlen += words[i].length();
		spaceSize = maxWidth - sumlen;
		string ans = "";
		//只包含一个单词或者是最后一行
		if(end-start == 0 || end == words.size() - 1){
	 		for(i = start; i <= end -1; i++) ans =ans + words[i] + " ";
	 		ans += words[i];
		 	for(i = ans.length() + 1; i <= maxWidth; i++) ans += " ";
		}else{
			//包含至少两个单词
			int lastSpace = spaceSize % inv;
			string inv_s = string(spaceSize / inv, ' ');
			//可以均匀间隔
			if(lastSpace == 0){
				for(i = start; i <= end-1; i++) ans = ans + words[i] + inv_s;
				ans += words[end];
			//不可以均匀间隔
			}else{
				for(i = start; i <= end-1; i++) {
					ans = ans + words[i] + inv_s;
					if(lastSpace) ans += " ", lastSpace--;
				} 
				ans += words[end];
			}
		}
		return ans;
	}
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	int len = words.size(), curlen , j;
    	for(int i = 0; i < len ;i = j){
    		curlen = 0 ;
    		j = i;
    		while(j < len && curlen - 1 <= maxWidth){
    			curlen += (words[j].length() + 1);
    			if(curlen - 1 > maxWidth) break;
    			j++;
    		}
    		res.push_back(mk_string(words, i, j-1 , maxWidth));
    	}
    	return res;
    }
};



int main(int argc, char * argv[]){

	Solution s = Solution();
	vector<string> temp ={"a"};
	// cout << s.mk_string(temp, 6, 6, 50);
	s.fullJustify(temp, 1);
	/* code */


    return 0;
}