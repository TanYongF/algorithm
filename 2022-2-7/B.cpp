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
    long long smallestNumber(long long num) {
      long long ans = 0;
      map<char,int> mp;
      bool flag = false;
      string str;
      if(num < 0){
      	flag = true;
      	num = -num;
      }
      string s = to_string(num);
      for(char &c : s) mp[c]++;
      if(flag){
        for(auto it = mp.rbegin(); it != mp.rend(); it++) str += string(it->second, it->first);
      }else{
      	for(int i = 1; i < 9; i++){
      		if(mp.count('0' + i)){
      			str += ('0' + i);
      			mp['0'+i]--;
      		}
      	}
      	for(auto it = mp.begin(); it != mp.end(); it++){
      		str += string(it->second, it->first);
      	}
      }
      // cout << str << endl;
      	for(int i = 0; i < (int)str.size(); i++) ans = ans * 10 + (str[i] - '0');
    	
    	if(flag) return ans * -1;
    	else return ans;
      // if(flag) return stoul()
      // return num;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	cout << s.smallestNumber(9999101111);
	/* code */
	// cout << ULONG_MAX << endl;

    return 0;
}