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
    string decodeCiphertext(string encodedText, int rows) {
    	int strLen = encodedText.length();
    	if(strLen == 0) return "";
    	const int maxW = strLen / rows;
    	const int maxH = rows;
    	char mp[maxH + 1][maxW + 1];
    	int idx= 0;
    	for(int i = 1; i <= maxH; i++){
    		for(int j = 1; j <= maxW; j++){
    			mp[i][j] = encodedText[idx++];
    		}
    	}
    	string ans = "";
    	for(int j = 1; j <= maxW; j++){
    		for(int i = 1; i <= maxH; i++){
    			int x = i + j -1;
    			if(x > maxW) break;
    			ans += mp[i][x];
    		}
    	}
    	int i;
    	for(i = (int)ans.length()-1; i >= 0; i--) if(ans[i] == ' ') i--;
    	return ans.substr(0, i + 1);
        
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	string s1= "iveo    eed   l te   olc";
	cout << s.decodeCiphertext(s1,4);
	/* code */


    return 0;
}