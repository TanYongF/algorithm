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
    string removeKdigits(string num, int k) {
        int len = num.size();
        if(k == len) return 0;
        priority_queue<pair<int,int>> pq;
        int del = 0, end = 0;
        while(del < k){
            while(end < len and pq.size() < k){
                pq.push({num[end] - '0', end});
                end++;
            }
            auto [val, idx] = pq.top();
            pq.pop();
            num[idx] = ' ';
            del++;
        }
        string ans = 0;
        for(auto &ch : num){
            if(ch != ' ') ans.push_back(ch);
        }
        cout << ans;
        return ans;
    }
};
int main(int argc, char * argv[]){

	Solution s = Solution();
	string str;
	int k;
	cin >> str >> k;
	cout << s.removeKdigits(str, k);
    return 0;
}
