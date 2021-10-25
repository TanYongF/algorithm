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
    int maxConsecutiveAnswers(string answerKey, int k) {
    	vector<int> num(2);
    	unordered_map<char, int> mp;
    	string s = answerKey;
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n) {
        	// if(s[right] == 'T') num[1]++;
        	mp[s[right]]++;
            maxn = max(maxn, mp[s[right]]);
            if (right - left + 1 - maxn > k) {
                mp[s[right]]--;
                left++;
            }
            right++;
        }
        return right - left;
        
    }
};

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
    	string s= answerKey;
        vector<int> num(26);
        int n = s.length();
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n) {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k) {
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}