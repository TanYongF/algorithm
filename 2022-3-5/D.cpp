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
    int minMovesToMakePalindrome(string a) {
		int flag=0;
	    int i,j,len,ans=0;
	    len = a.size();
	    for (i=0;i<len;i++){
	        for (j=len-1;j>=i;j--) {
	            if (i==j){
	                if (a.size()%2==0||flag==1) return 0;
	                flag++;
	                ans+=a.size()/2-i;
	            }
	            else if (a[i]==a[j]){
	                for (int k=j;k<len-1;k++) swap(a[k],a[k+1]);
	                ans+=len-1-j;
	                len--;
	                break;
	            }
	        }
	    }
	   	return ans;
    }
};

int main(int argc, char * argv[]){

	// Solution s = Solution();
	/* code */


    return 0;
}