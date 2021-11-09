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
#include <bitset>
#include <list>
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
	bool isTrue(unordered_map<char, int> & mp){
		return mp['a'] and mp['e'] and mp['i'] and mp['o'] and mp['u'];
	}
	bool check(char c){
		return c == 'a' or c == 'e' or c =='i' or c == 'o' or c =='u';
	}

    int countVowelSubstrings(string word) {
    	int ans = 0;
    	int len = word.size();
    	unordered_map<char, int> mp;
    	int i = 0, j = 0;
    	while(i < len){
    		// cout << 1;
    		mp = unordered_map<char, int>();
    		mp[word[i]] = 1;
    		for(j = i + 1; j < word.length(); j++){
    			if(not check(word[j])){

    				break;
    			} 
    			else{
    				mp[word[j]]++;
    				if(isTrue(mp)) ans++;
    			}
    		}
    		i++;
    	}
    	return ans;    
    }
};

int main(int argc, char * argv[]){
	string word = "cuaieuouac";
	Solution s = Solution();
	cout << s.countVowelSubstrings(word);
	/* code */


    return 0;
}