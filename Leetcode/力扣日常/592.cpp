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
    int gcd(int m, int n){
        return m % n ? gcd(n, m % n) : n;
    }
    int gbs(int m, int n){
        return m * n / gcd(m, n);
    }
    
    vector<pair<int,int>> num;
    vector<int> sign;
    int common = 1; 
    void insert(const string &s){
        // cout << s << endl;
        int len = s.size(), idx = 0;
        for(idx = 0; idx < len; idx++) if(s[idx] == '/') break;
        int num1 = stoi(s.substr(0, idx));
        int num2 = stoi(s.substr(idx + 1));
        sign.push_back(num1 < 0 ? -1 : 1);
        common = gbs(common, abs(num2));
        num.push_back({num1, num2});
    }
    
    void split(const string &expression){
        int i = 0, j = 0, len = expression.size();
        while(j < len){
            j = i + 1;
            while(j < len and expression[j] != '+' and expression[j] != '-') j++;
            if(i < len) insert(expression.substr(i, j - i));
            // insert(item);
            i = j;
        }
    } 
    string fractionAddition(string expression) {
        split(expression);
        int sonNum = 0, fatherNum = common;
        for(auto &[sn, fn] : num)  sonNum += sn * (common / fn);
        if(sonNum == 0) return "0/1";
        int gcdNum = gcd(sonNum, fatherNum);
        return to_string(sonNum / gcdNum) + "/" + to_string(fatherNum / gcdNum);
    }
};



int main(int argc, char * argv[]){

    Solution s = Solution();
    string expression = "-1/2+1/2+1/3";
    cout << s.fractionAddition(expression);
    /* code */


    return 0;
}