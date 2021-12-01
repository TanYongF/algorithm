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
typedef pair<int,int> P;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int j = 1; j < n; ++j) {
            q.emplace(0, j);
        }
        for (int _ = 1; _ < k; ++_) {
            auto [i, j] = q.top();
            q.pop();
            if (i + 1 < j) {
                q.emplace(i + 1, j);
            }
        }
        return {arr[q.top().first], arr[q.top().second]};
    }
};

int main(int argc, char * argv[]){

	Solution s = Solution();
	/* code */


    return 0;
}