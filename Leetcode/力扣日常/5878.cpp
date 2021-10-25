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
	bool check(string& str, string& p , int k){
		unsigned int i = 0, j = 0, size = 0;
		for(i = 0; i < str.length(); i++){
			if(str[i] == p[j]) j++;
			if(j == p.length()) size++ , j = 0; 
		}
		// cout << size;
		return size >= k;
	}
    string longestSubsequenceRepeatedK(string s, int k) {
    	vector<string> ans[8];
    	int n = s.length();
    	int len = min(n/k, 7);
    	string p;
    	int cnt[27];
    	memset(cnt, 0, sizeof(cnt));
    	for(auto &ch : s) cnt[ch- 'a']++;
    	for(int i = 0; i <= 26; i++) if(cnt[i] >= k) p = p + (char)(i + 'a');

    	ans[0].push_back("");
    	// cout << p << endl;
    	for(int i = 1; i <= len; i++){
    		for(auto str : ans[i-1]){
    			for(auto ch : p){
    				string t = str + ch;
    				// cout << t << endl;
    				if(check(s, t, k)) {
    					// cout << s << " " << t << " " << k << endl;
    					ans[i].push_back(t);
    				}
    			}
    		}
    	}
    	// for(int i = 0; i <= 7; i++){
    	// 	for(auto ss : ans[i]){
    	// 		cout << ss << " ";
    	// 	}
    	// 	cout << endl;
    	// }
    	for(int i = len; i >= 1; i--){
    		if(ans[i].size() != 0){
    			sort(ans[i].begin(), ans[i].end());
    			return ans[i].back();
    		}
    	}
    	return "";
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string ss = "bbabbabbbbabaababab";
	cout << s.longestSubsequenceRepeatedK(ss, 3);

	// cout << s.check("bbabbabbbbabaababab", "a", 3);
	/* code */


    return 0;
}