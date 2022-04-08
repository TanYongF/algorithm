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

bool isPrime(int num){
    if(num==1)   return false;
	if(num==2)	return true;
	for(int i=2;i<sqrt(num)+1;i++){
		if((num%i)==0)	return false;
	}
	return true;
}
class Solution {
public:
	int gcd(int a,int b) {
	    return b>0 ? gcd(b,a%b):a;
	}
	int lcm(int a, int b){
		return a*b/gcd(a,b);
	}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
 
    	// vector<int> numss;
	    	// for(int i = 0; i < nums.size(); i++){
	    	// 	if(numss.size() == 0 or numss.back() != nums[i] or nums[i] == 1){
	    	// 		numss.push_back(nums[i]);
	    	// 	}
    	// }
    	bool flag = true;
    	vector<int> n, o = nums;
    	while(flag){
    		n.clear();
    		flag = false;
    		for(int i = 0; i < o.size()-1; i++){
    			if(gcd(o[i], o[i+1]) > 1){
    				flag = true;
    				n.push_back(lcm(o[i], o[i+1]));
    			}
    		}
    		o = n;
    	}
    	return o;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();


    return 0;
}