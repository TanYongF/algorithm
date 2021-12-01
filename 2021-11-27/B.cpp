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
    int minimumBuckets(string street) {
    	int len = street.size();
    	if(len == 1) return street[0] == '.' ? 0 : -1;
    	for(int i = 0; i < len; i++){
    		if(i == 0){
    			if(street[i] == 'H'){
    				if(street[i + 1] == 'H') return -1;
    				else street[i+1] = 'B';
    			}else{
    				continue;
    			}
    		}else if(i == len - 1){
    			if(street[i] == 'B') continue;
    			else if(street[i] == 'H'){
    				if(street[i-1] == 'H') return -1;
    				else if(street[i-1] == 'B') continue;
    				else if(street[i-1] == '.') street[i-1] = 'B';
    			}
    		}else{
    			if(street[i] == 'H'){
    				if(street[i-1] == 'H' and street[i+1] == 'H') return -1;
    				if(street[i-1] == 'B') continue;
    				else if(street[i+1] == '.') {
    					street[i+1] = 'B';
    					continue;
    				}
    				else if(street[i-1] == '.') street[i-1] = 'B';   
    			}
    		}
    	}
    	int ans =0 ;
    	for(auto it : street) if(it == 'B') ans++;

    	// cout << street << " " << ans <<endl;
    	return ans;
        
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	string str ;
	int T = 100;
	while(true){
		cin >> str;
		cout << s.minimumBuckets(str);
	}
	/* code */


    return 0;
}