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
 

//  vector<string> split(const string &str, char &flag){
//     int i = 0, j = 0;
//     vector<string> ans;
//     while(i < str.length() and j < str.length()){
//         while(i < str.length() and str[i] == flag) i++;
//         j = i;
//         while(j < str.length() and str[j] != flag) j++;
//         if(i < str.length()) ans.push_back(str.substr(i, j - i););
//         i = j;
//     }
//     return ans;
// }
class Solution {
public:
    string capitalizeTitle(string title) {
    	int j = 0;
    	int len = title.size();
    	for(auto &ch : title){
    		ch = tolower(ch);
    	}
    	for(int i = 0; i < title.size(); i++){
    		if(title[i] == ' ') continue;
    		// title[i] += 32;
    		 j =i;
    		 while(j < len and title[j] != ' ') j++;
    		 if(j - i > 2) title[i] = toupper(title[i]);
    		 i = j;
    	}
    	return title;
        
    }
};


int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}