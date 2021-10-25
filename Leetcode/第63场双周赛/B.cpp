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
    bool winnerOfGame(string colors) {
    	int sizea =0 ,sizeb = 0;
    	int len = colors.size();
    	int j = 0;
    	for(int i = 0; i < len; i = j){
    		j = i;
    		while(j < len and colors[j] == colors[i]){
    			j++;
    		}
    		if (colors[i] == 'A'){
    			sizea += (j - i - 2 ) > 0 ? j - i - 2 : 0;
    		}else{
				sizeb += (j - i - 2 ) > 0 ? j - i - 2 : 0;
    		}
    	}
    	if(sizea == sizeb) return false;
    	if(sizea <  sizeb) return false;
    	else return true;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.winnerOfGame("ABBBBBBBAAA");
	/* code */


    return 0;
}