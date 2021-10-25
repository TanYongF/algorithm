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
	int base = 131313;
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> ans;
    	if(s.length() <= 10) return ans;
    	unordered_map<int,int> mp; 
    	int slen = s.length();
    	int  Hash[slen + 1], power[slen + 1];
    	power[0] = 1;
    	Hash[0]  = 0;
    	for(int i = 1; i <= slen; i++) {
    		Hash[i] = Hash[i-1] * base + (s[i-1] - 'a' + 1); 
    		power[i] = power[i-1]*base;

    	}
    	for(int i = 0; i <= slen; i++) cout << Hash[i] << " ";
    		cout << endl;

    	for(int i = 1 ; i <= slen - 9; i++){
    		int j = i + 10 - 1;
    		int hash = Hash[j] - Hash[i-1] * power[j - i + 1];
    		int cnt = mp[hash];
    		if(cnt == 1) ans.push_back(s.substr(i-1, 10));
    		mp[hash] = cnt + 1;
    	}
    	for(auto it : ans) cout << it << " ";
    	return ans;


    }
};

// class Solution {
// public:
// 	const unsigned long long base = 23;
// 	const int N = 1e9 + 9;

//     vector<string> findRepeatedDnaSequences(string s) {
//     	vector<string> ans;
//     	unordered_map<string, int> mp;
//     	// cout << s.length() << endl;
//     	for(int i = 0; i <= s.length() - 10; i++){
//     		string sub = s.substr(i, 10);
//     		// cout << sub;
//     		mp[sub]++;
//     	}
//     	for(auto it : mp){
//     		if(it.second > 1) ans.push_back(it.first); 
//     	}
//     	return ans;

//     }
// };


int main(int argc, char * argv[]){

	Solution s = Solution();
	s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	


    return 0;
}