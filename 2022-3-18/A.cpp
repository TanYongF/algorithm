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

  bool checkIp4(const string &str){
      int len = str.size();
      vector<int> split;
      split.push_back(-1);
      for(int i = 0; i < len; i++) if(str[i] == '.') split.push_back(i);
      split.push_back(len);
      if(split.size() != 5) return false;
      for(int i = 0; i < 4; i++){
          string numstr = str.substr(split[i]+1, split[i+1]-split[i]-1);
          if(numstr.size() == 0) return false;
          int num = stoi(numstr);
          if(num == 0 and numstr.size() != 1) return false;
          if(num != 0 and (num > 255 or numstr[0] == '0')) return false;
      }   
      return true;
  }
bool checkIp6(const string &str){
  int len = str.size();
  vector<int> split;
  split.push_back(-1);
  for(int i = 0; i < len; i++) if(str[i] == ':') split.push_back(i);
  split.push_back(len);
  if(split.size() != 9) return false;
  for(int i = 0; i < 8; i++){
      string numstr = str.substr(split[i]+1, split[i+1]-split[i]-1);
      if(numstr.size() == 0 or numstr.size() > 4) return false;
      for(auto &ch : numstr){
          if(not ((ch >= 'a' and ch <= 'z')
                 or (ch >= '0' and ch <= '9')
                 or (ch >= 'A' and ch <= 'Z'))) return false;
      }
  }   
  return true;
    
}
int main(int argc, char * argv[]){
  string s = "2001:db8:85a3:0:0:8A2E:0370:7334";
  cout << checkIp6(s);

	// Solution s = Solution();
	// cout << (~1) << endl;


    return 0;
}