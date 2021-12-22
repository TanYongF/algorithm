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

    int repeatedStringMatch(string a, string b) {
        int i = 0, j = 0;
        int lenA = a.size();
        bool ok = true;
        for(int k = 0; k < a.size(); k++){
            if(a[k] == b[0]){

            	ok = true;
                i = k, j = 0;
                while(j < b.size()){
                    if(a[i%lenA] != b[j]){
                        ok = false;
                        break;
                    }else{
                    	i++;
                    	j++;
                    }
                }
                if(ok) return ceil(1.0 * i / lenA);  
            }
        }
        return -1;
    }
    // bool check(string )
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.repeatedStringMatch("abcd","cc");
	/* code */


    return 0;
}