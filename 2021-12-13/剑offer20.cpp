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
    bool isInteger(string s){
        bool hasSign = false;
        if(s.size() == 0) return false;
        if(s[0] == '-'|| s[0] == '+' ) hasSign = true;
        for(int i= 1; i < s.size(); i++){
            if(s[i] <= '9' and s[i] >= '0') continue;
            else return false; 
        }
        return true;
    }
    bool isPoint(string s){
        int len = s.size();
        if(s.size() <= 1) return false;
        bool hasSign = false, hasDot = false;
        if(s[0] == '-' or s[0] == '+') hasSign = true;
        cout << s;
        for(int i = (hasSign ? 1 : 0); i < s.size(); i++){
            if(s[i] = '.'){
                if(i == len - 1 or hasDot) return false;
                hasDot = true;
            }
            if(s[i] <= '9' and s[i] >= '0') continue;
            else return false;
        }
        return false;
    }
    bool isNumber(string s) {

        return false;

    }
};

int main(int argc, char * argv[]){

    Solution s = Solution();
    cout << s.isPoint("+.43");
    cout << s.isPoint(".");
    cout << s.isPoint(".4.5");
    /* code */


    return 0;
}